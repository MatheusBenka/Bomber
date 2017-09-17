#ifdef __linux__
#include "GL/glut.h"
#else
#include "stdafx.h"
#include "GL\glew.h"
#include "GL\freeglut.h"
#endif
#include<stdio.h>
#include <math.h>
#include <iostream>
#include "jogo.h"


#define cameraY_min  0
#define cameraY_max 130

bool Inicio = true;


int cameraX_min = 0;
//max X 310
int cameraX_max = 150;
Jogo jojo;
int faseAtual = 0;

void jogo() {

	glClearColor(0.0f, 0.6f, 0.0f, 0.7f);
	glClear(GL_COLOR_BUFFER_BIT);
	//definindo coordenadas da matriz da tela
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();  // carrega matriz identidade
	gluOrtho2D(cameraX_min, cameraX_max, cameraY_min , cameraY_max); // definindo os tamanhos
	
	
	
	if (Inicio) {
		jojo.desenharCenario(faseAtual);
		Inicio = false;
			
	}else {

		jojo.REdesenharCenario(faseAtual);
	}
	
	jojo.jojar();


	glutSwapBuffers();
}

void TeclasEspeciais(int tecla, int x, int y) {

	switch (tecla) {

	case GLUT_KEY_RIGHT:
		if (cameraX_max<310) {
			cameraX_max += 1.0;
			cameraX_min += 1.0;
		}
		break;
	case GLUT_KEY_LEFT:
		if (cameraX_min>0) {
			cameraX_max -= 1.0;
			cameraX_min -= 1.0;
		}
		break;
		
	}
	glutPostRedisplay();
}


void TeclasNormais(unsigned char tecla, int x, int y) {
	switch (tecla) {
	case 27:
		cameraX_max = 150.0f;
		cameraX_min = 0.0f;
		break;


	case 'a':
	case 'A':
		jojo.setMoviX(-1);
		break;
	case 'D':
	case 'd':
		jojo.setMoviX(1);
		break;
	case 'w':
	case 'W':
		jojo.setMoviY(1);
		break;
	case 's':
	case 'S':
		jojo.setMoviY(-1);
		break;

	}



	glutPostRedisplay();

}


int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutCreateWindow("BomberKid");
	glutDisplayFunc(jogo);
	glutSpecialFunc(TeclasEspeciais);
	glutKeyboardFunc(TeclasNormais);
	glutMainLoop();
	return 0;
}


