#include "GridMaker.h"

void GridMaker::MakeGrid(string source)
{
	xml_document sceneDoc;
	sceneDoc.load_file(source.c_str());

	sceneDoc.child("Scene").remove_child("Grid");
	xml_node grid = sceneDoc.child("Scene").append_child("Grid");

	float cellWidth = sceneDoc.child("Scene").attribute("cellWidth").as_float();
	float cellHeight = sceneDoc.child("Scene").attribute("cellHeight").as_float();

	int i = 0;
	for (xml_node gameObject = sceneDoc.child("Scene").child("GameObject");
		gameObject;
		gameObject = gameObject.next_sibling("GameObject"), i++)
	{
		float positionX = gameObject.attribute("positionX").as_float();
		float positionY = gameObject.attribute("positionY").as_float();

		int cellX = 0;
		if (positionX <= (cellWidth / 2) && positionX >= -(cellWidth / 2)) cellX = 0;
		else if (positionX > (cellWidth / 2)) cellX = (positionX + (cellWidth / 2) - 1) / cellWidth;
		else if (positionX < -(cellWidth / 2)) cellX = (positionX - (cellWidth / 2) + 1) / cellWidth;

		int cellY = 0;
		if (positionY <= (cellHeight / 2) && positionY >= -(cellHeight / 2)) cellY = 0;
		else if (positionY > cellHeight / 2) cellY = (positionY + (cellHeight / 2) - 1) / cellHeight;
		else if (positionY < -(cellHeight / 2)) cellY = (positionY - (cellHeight / 2) + 1) / cellHeight;

		xml_node child = grid.append_child("GameObject");
		child.append_attribute("cellX").set_value(cellX);
		child.append_attribute("cellY").set_value(cellY);
	}

	sceneDoc.save_file(source.c_str());
}