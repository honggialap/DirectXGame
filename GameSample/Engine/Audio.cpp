#include "Audio.h"
#include "Debug.h"


CSoundClip::~CSoundClip()
{
	if (_secondaryBuffer != NULL)
	{
		_secondaryBuffer->Release();
		_secondaryBuffer = NULL;
	}
}


void CAudio::Initialize(HWND hWnd)
{
	HRESULT result;
	DSBUFFERDESC bufferDesc;
	WAVEFORMATEX waveFormat;

	// Initialize the direct sound interface pointer for the default sound device.
	result = DirectSoundCreate8(NULL, &_directSound, NULL);
	if (FAILED(result))
	{
		return;
	}

	// Set the cooperative level to priority so the format of the primary sound buffer can be modified.
	result = _directSound->SetCooperativeLevel(hWnd, DSSCL_PRIORITY);
	if (FAILED(result))
	{
		return;
	}

	// Setup the primary buffer description.
	bufferDesc.dwSize = sizeof(DSBUFFERDESC);
	bufferDesc.dwFlags = DSBCAPS_PRIMARYBUFFER | DSBCAPS_CTRLVOLUME;
	bufferDesc.dwBufferBytes = 0;
	bufferDesc.dwReserved = 0;
	bufferDesc.lpwfxFormat = NULL;
	bufferDesc.guid3DAlgorithm = GUID_NULL;

	// Get control of the primary sound buffer on the default sound device.
	result = _directSound->CreateSoundBuffer(&bufferDesc, &_primaryBuffer, NULL);
	if (FAILED(result))
	{
		return;
	}

	// Setup the format of the primary sound bufffer.
	// In this case it is a .WAV file recorded at 44,100 samples per second in 16-bit stereo (cd audio format).
	waveFormat.wFormatTag = WAVE_FORMAT_PCM;
	waveFormat.nSamplesPerSec = 44100;
	waveFormat.wBitsPerSample = 16;
	waveFormat.nChannels = 2;
	waveFormat.nBlockAlign = (waveFormat.wBitsPerSample / 8) * waveFormat.nChannels;
	waveFormat.nAvgBytesPerSec = waveFormat.nSamplesPerSec * waveFormat.nBlockAlign;
	waveFormat.cbSize = 0;

	// Set the primary buffer to be the wave format specified.
	result = _primaryBuffer->SetFormat(&waveFormat);
	if (FAILED(result))
	{
		return;
	}
}

void CAudio::Shutdown()
{
	for (auto secondaryBuffer : _secondaryBuffers)
	{
		delete secondaryBuffer.second;
		secondaryBuffer.second = nullptr;
	}
	_secondaryBuffers.clear();

	if (_primaryBuffer != NULL)
	{
		_primaryBuffer->Release();
		_primaryBuffer = NULL;
	}

	if (_directSound != NULL)
	{
		_directSound->Release();
		_directSound = NULL;
	}
}

void CAudio::LoadSoundClip(unsigned int id, std::string source)
{
	if (GetSoundClip(id) != nullptr)
	{
		int error;
		FILE* filePtr;
		unsigned int count;
		WaveHeaderType waveFileHeader;
		WAVEFORMATEX waveFormat;
		DSBUFFERDESC bufferDesc;
		HRESULT result;
		IDirectSoundBuffer* tempBuffer;
		unsigned char* waveData;
		unsigned char* bufferPtr;
		unsigned long bufferSize;

		// Open the wave file in binary.
		error = fopen_s(&filePtr, source.c_str(), "rb");
		if (error != 0)
		{
			return;
		}

		// Read in the wave file header.
		count = fread(&waveFileHeader, sizeof(waveFileHeader), 1, filePtr);
		if (count != 1)
		{
			return;
		}

		// Check that the chunk ID is the RIFF format.
		if ((waveFileHeader.chunkId[0] != 'R') || (waveFileHeader.chunkId[1] != 'I') ||
			(waveFileHeader.chunkId[2] != 'F') || (waveFileHeader.chunkId[3] != 'F'))
		{
			return;
		}

		// Check that the file format is the WAVE format.
		if ((waveFileHeader.format[0] != 'W') || (waveFileHeader.format[1] != 'A') ||
			(waveFileHeader.format[2] != 'V') || (waveFileHeader.format[3] != 'E'))
		{
			return;
		}

		// Check that the sub chunk ID is the fmt format.
		if ((waveFileHeader.subChunkId[0] != 'f') || (waveFileHeader.subChunkId[1] != 'm') ||
			(waveFileHeader.subChunkId[2] != 't') || (waveFileHeader.subChunkId[3] != ' '))
		{
			return;
		}

		// Check that the audio format is WAVE_FORMAT_PCM.
		if (waveFileHeader.audioFormat != WAVE_FORMAT_PCM)
		{
			return;
		}

		// Check that the wave file was recorded in stereo format.
		if (waveFileHeader.numChannels != 2)
		{
			return;
		}

		// Check that the wave file was recorded at a sample rate of 44.1 KHz.
		if (waveFileHeader.sampleRate != 44100)
		{
			return;
		}

		// Ensure that the wave file was recorded in 16 bit format.
		if (waveFileHeader.bitsPerSample != 16)
		{
			return;
		}

		// Check for the data chunk header.
		if ((waveFileHeader.dataChunkId[0] != 'd') || (waveFileHeader.dataChunkId[1] != 'a') ||
			(waveFileHeader.dataChunkId[2] != 't') || (waveFileHeader.dataChunkId[3] != 'a'))
		{
			return;
		}

		// Set the wave format of secondary buffer that this wave file will be loaded onto.
		waveFormat.wFormatTag = WAVE_FORMAT_PCM;
		waveFormat.nSamplesPerSec = 44100;
		waveFormat.wBitsPerSample = 16;
		waveFormat.nChannels = 2;
		waveFormat.nBlockAlign = (waveFormat.wBitsPerSample / 8) * waveFormat.nChannels;
		waveFormat.nAvgBytesPerSec = waveFormat.nSamplesPerSec * waveFormat.nBlockAlign;
		waveFormat.cbSize = 0;

		// Set the buffer description of the secondary sound buffer that the wave file will be loaded onto.
		bufferDesc.dwSize = sizeof(DSBUFFERDESC);
		bufferDesc.dwFlags = DSBCAPS_CTRLVOLUME;
		bufferDesc.dwBufferBytes = waveFileHeader.dataSize;
		bufferDesc.dwReserved = 0;
		bufferDesc.lpwfxFormat = &waveFormat;
		bufferDesc.guid3DAlgorithm = GUID_NULL;

		// Create a temporary sound buffer with the specific buffer settings.
		result = _directSound->CreateSoundBuffer(&bufferDesc, &tempBuffer, NULL);
		if (FAILED(result))
		{
			return;
		}

		_secondaryBuffers[id] = new CSoundClip();

		// Test the buffer format against the direct sound 8 interface and create the secondary buffer.
		result = tempBuffer->QueryInterface(IID_IDirectSoundBuffer8, (void**)&*_secondaryBuffers[id]->_secondaryBuffer);
		if (FAILED(result))
		{
			delete _secondaryBuffers[id];
			_secondaryBuffers.erase(id);
			return;
		}

		// Release the temporary buffer.
		tempBuffer->Release();
		tempBuffer = 0;

		// Move to the beginning of the wave data which starts at the end of the data chunk header.
		fseek(filePtr, sizeof(WaveHeaderType), SEEK_SET);

		// Create a temporary buffer to hold the wave file data.
		waveData = new unsigned char[waveFileHeader.dataSize];
		if (!waveData)
		{
			delete _secondaryBuffers[id];
			_secondaryBuffers.erase(id);
			return;
		}

		// Read in the wave file data into the newly created buffer.
		count = fread(waveData, 1, waveFileHeader.dataSize, filePtr);
		if (count != waveFileHeader.dataSize)
		{
			delete _secondaryBuffers[id];
			_secondaryBuffers.erase(id);
			return;
		}

		// Close the file once done reading.
		error = fclose(filePtr);
		if (error != 0)
		{
			delete _secondaryBuffers[id];
			_secondaryBuffers.erase(id);
			return;
		}

		// Lock the secondary buffer to write wave data into it.
		result = _secondaryBuffers[id]->_secondaryBuffer->Lock(0, waveFileHeader.dataSize, (void**)&bufferPtr, (DWORD*)&bufferSize, NULL, 0, 0);
		if (FAILED(result))
		{
			delete _secondaryBuffers[id];
			_secondaryBuffers.erase(id);
			return;
		}

		// Copy the wave data into the buffer.
		memcpy(bufferPtr, waveData, waveFileHeader.dataSize);

		// Unlock the secondary buffer after the data has been written to it.
		result = _secondaryBuffers[id]->_secondaryBuffer->Unlock((void*)bufferPtr, bufferSize, NULL, 0);
		if (FAILED(result))
		{
			delete _secondaryBuffers[id];
			_secondaryBuffers.erase(id);
			return;
		}

		// Release the wave data since it was copied into the secondary buffer.
		delete[] waveData;
		waveData = 0;
	}
}

pSoundClip CAudio::GetSoundClip(unsigned int id)
{
	if (_secondaryBuffers.find(id) != _secondaryBuffers.end())
		return _secondaryBuffers[id];
	else
		return nullptr;
}