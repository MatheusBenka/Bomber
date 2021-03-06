#ifdef __linux__
#include "GL/glut.h"
#else
#include "stdafx.h"
#include "GL\glew.h"
#include "GL\freeglut.h"
#endif
#include <stdio.h>
#include <math.h>
#include <iostream>
#include "jogo.h"


#define cameraY_min  0
#define cameraY_max 130

bool Inicio = true;
bool blockTOP = false;
bool blockDOWN = false;
bool blockLEFT = false;
bool blockRIGHT = false;


int cameraX_min = 0;
//max X 310
int cameraX_max = 150;
Jogo jojo;

int auxVoltas;
bool morreu = false;

void jogo() {
	
	glClearColor(0.0f, 0.6f, 0.0f, 0.7f);
	glClear(GL_COLOR_BUFFER_BIT);
	
	//definindo coordenadas da matriz da tela
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();  // carrega matriz identidade
	gluOrtho2D(cameraX_min, cameraX_max, cameraY_min , cameraY_max); // definindo os tamanhos
	
	if(!morreu){
	if (Inicio) {
		jojo.desenharCenario();
		Inicio = false;
			
	}else {

		jojo.REdesenharCenario();
		
	}
	
	morreu = jojo.jojar();
		
	}else{
		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_QUADS);
		glVertex2f(0,70);
		glVertex2f(0, 100);
		glVertex2f(290,100);
		glVertex2f(290, 70);
		glEnd();
		
	}
	//if(morreu){
	//	glutPostRedisplay(); 	
//	}
	
	glutSwapBuffers();
}


void resetarBlocks(){
	blockTOP = false;	
	blockDOWN = false;
    blockLEFT = false;
    blockRIGHT = false;

}

void TeclasEspeciais(int tecla, int x, int y) {
	if(!morreu){
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
	
}


void TeclasNormais(unsigned char tecla, int x, int y) {
	bool horizontal;
	bool vertical;
	if(!morreu){
		
	jojo.colisaoFixos(&blockTOP,&blockDOWN,&blockLEFT,&blockRIGHT);	
	jojo.colisaoQuebraveis(&blockTOP,&blockDOWN,&blockLEFT,&blockRIGHT);
	
	switch (tecla) {
	case 27:
		cameraX_max = 150.0f;
		cameraX_min = 0.0f;
		break;


	case 'a':
	case 'A':
			if(!blockLEFT){
				jojo.setMoviX(-1);
				if(jojo.colisaoBORDALeft(10)){
					jojo.setMoviX(1);
				}else{
				if(jojo.getPosiESQPlayer()<220 && cameraX_min>0){
					cameraX_max -= 1.0;
					cameraX_min -= 1.0;
				} 
					
				}
			}
			
			
		break;
	case 'D':
	case 'd':
			if(!blockRIGHT){
			jojo.setMoviX(1);
			if(jojo.colisaoBORDARight(300)){
				jojo.setMoviX(-1);
			}else{
				if(jojo.getPosiDIRPlayer()>70 && cameraX_max<310){
					cameraX_max += 1.0;
						cameraX_min += 1.0;
				} 
				
			}
			}
		break;
	case 'w':
	case 'W':
			if(!blockTOP){
			jojo.setMoviY(1);
			if(jojo.colisaoBORDATOP(120)){
				jojo.setMoviY(-1);
			}
			}
		break;
				
	case 's':
	case 'S':
			if(!blockDOWN){
				
			jojo.setMoviY(-1);
			if(jojo.colisaoBORDADOWN(10)){
				jojo.setMoviY(1);
			}
			}
		break;
			
			
	case 'b':
	case 'B':
			jojo.dropBomb();
		break;	

	}

	resetarBlocks();

	glutPostRedisplay();
	}	
	switch (tecla) {
	case 'r':
	case 'R':
		Inicio = true;
		morreu = false;
		cameraX_min = 0;
		cameraX_max = 150;
		glutPostRedisplay();
		break;
	}
	
	
}


int main(int argc, char **argv){
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
//melhorar o layout

