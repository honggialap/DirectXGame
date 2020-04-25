#pragma once
#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

//scene - view component
class Controller
{
	//pScene scene;
	//pInputDevice inputDevice;
};

typedef Controller* pController;

class Controlable
{
public:
	pController controller;
};

typedef Controlable* pControlable;

#endif // !__CONTROLLER_H__
