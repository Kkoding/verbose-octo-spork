/*
Copyright 2017 Lee Taek Hee (Korea Polytech University)

This program is free software: you can redistribute it and/or modify
it under the terms of the What The Hell License. Do it plz.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY.
*/

#include "stdafx.h"
#include <iostream>
#include "Dependencies\glew.h"
#include "Dependencies\freeglut.h"

#include "Renderer.h"

Renderer *g_Renderer = NULL;

CObj * g_Obj = NULL;

const float fTime = 0.1;

void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);

	// Renderer Test
	g_Renderer->DrawSolidRect(0, 0, 0, 4, 1, 0, 1, 1);

	CSceneMgr::Instance()->Render(*g_Renderer);

	glutSwapBuffers();
}

void Idle(void)
{
	CSceneMgr::Instance()->Update(fTime);
	CSceneMgr::Instance()->AddObj(rand() % 500 - 250, 250 - rand() % 500);
	RenderScene();
}

void MouseInput(int button, int state, int x, int y)
{
	//static bool button_state = false;
	//if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	//	button_state = true;
	//if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	//{
	//	if (button_state)
	//		CSceneMgr::Instance()->AddObj(x - 250, 250 - y);
	//	button_state = false;
	//}
	RenderScene();
}

void KeyInput(unsigned char key, int x, int y)
{
	RenderScene();
}

void SpecialKeyInput(int key, int x, int y)
{
	RenderScene();
}

int main(int argc, char **argv)
{
	// Initialize GL things

	srand((unsigned)time(NULL));
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Game Software Engineering KPU");

	glewInit();
	if (glewIsSupported("GL_VERSION_3_0"))
		std::cout << " GLEW Version is 3.0\n ";

	else
		std::cout << "GLEW 3.0 not supported\n ";


	// Initialize Renderer
	g_Renderer = new Renderer(500, 500);

	////////////
	g_Obj = new CMonster();

	if (!g_Renderer->IsInitialized())
	{
		std::cout << "Renderer could not be initialized.. \n";
	}

	glutDisplayFunc(RenderScene);
	glutIdleFunc(Idle);
	glutKeyboardFunc(KeyInput);
	glutMouseFunc(MouseInput);
	glutSpecialFunc(SpecialKeyInput);

	glutMainLoop();

	delete g_Renderer;

	return 0;
}

