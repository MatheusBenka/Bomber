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
#include "field.h"
#include <time.h>

#define cameraY_min  0
#define cameraY_max 130

bool Inicio = true;
campinho campoJogo;

int cameraX_min = 0;
//max X 310
int cameraX_max = 150;



void jogo() {

	glClearColor(0.0f, 0.6f, 0.0f, 0.7f);
	glClear(GL_COLOR_BUFFER_BIT);
	//definindo coordenadas da matriz da tela
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();  // carrega matriz identidade
	gluOrtho2D(cameraX_min, cameraX_max, cameraY_min , cameraY_max); // definindo os tamanhos
	
	campoJogo.desenharCenarioFixo();
	campoJogo.desenharBordas(cameraX_min, cameraX_max);
	
	if (Inicio) {
		
		int	auxConstrucaoX,auxConstrucaoY,auxRand;
		auxConstrucaoX = 20;
		auxConstrucaoY = 110;
		int i,j;
		for (i = 1; i<12; i++) {
			if(i>1){
				auxConstrucaoX = 10;
			}else{
				auxConstrucaoX = 20;
			}
			srand(time(NULL));
			for (j = 1; j < 30; j++) {
				if (campoJogo.getMatrizCampo(i,j) == 2 ) {
					auxConstrucaoX += 20;
					continue;
				}else {
					auxRand = rand()%200;		
					
					if (auxRand% 2 != 0) {
						printf(" i x j : %d x %d\n",i,j);
						campoJogo.desenharQuebraveis(i,j,auxConstrucaoX,auxConstrucaoY);
						printf("colocar quebravel no %d x %d\n",i,j);
						campoJogo.setValorMatrizCampo(i,j ,3);
						auxConstrucaoX += 20;
						
					}
				}
				
			}

			auxConstrucaoY -= 20;
		}
		//campoJogo.desenharQuebraveis();
		//Inicio = false;
		
		campoJogo.mostrarMatrizCampo();
	}
	/*
	else {

		campoJogo.reDesenharQuebraveis();
	}
	*/
	campoJogo.jogar();


	glutSwapBuffers();
}

void TeclasEspeciais(int tecla, int x, int y) {

	switch (tecla) {

	case GLUT_KEY_RIGHT:
		//if (cameraX_max<310) {
			cameraX_max += 1.0;
			cameraX_min += 1.0;
		//}
		break;
	case GLUT_KEY_LEFT:
		//if (cameraX_min>0) {
			cameraX_max -= 1.0;
			cameraX_min -= 1.0;
		//}
		break;
		/*
		case GLUT_KEY_UP:
		bolado.setTransY(0.1);
		break;
		case GLUT_KEY_DOWN:
		bolado.setTransY(-0.1);
		break;
		case GLUT_KEY_PAGE_DOWN:
		bolado.setEscx (-0.2);
		bolado.setEscy (-0.2);
		break;
		case GLUT_KEY_PAGE_UP:
		bolado.setEscx (0.2);
		bolado.setEscy (0.2);
		break;
		*/
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
		campoJogo.setMoviX(-1);
		break;
	case 'D':
	case 'd':
		campoJogo.setMoviX(1);
		break;
	case 'w':
	case 'W':
		campoJogo.setMoviY(1);
		break;
	case 's':
	case 'S':
		campoJogo.setMoviY(-1);
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


