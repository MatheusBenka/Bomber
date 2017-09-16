#pragma once
#include "quebraveis.h"
#include "fixo.h"
#include "jogador.h"

#include <time.h>

class campinho {
private:
	int qtdInimigos, qtdBlocosDestrutiveis;
	int matrizCampo[13][31];
	Fixo matrizFixos[5][14];
	bloquinhoQuebravel Blocos[13][31];
	Jogador player;
public:

	campinho() {
		int i, j;
		matrizCampo[1][1] =1;
		printf("isso\n");
		for (i = 2; i < 12; i++) {
			for (j = 2; j < 30; j++) {
				if (i%2 == 0 && j % 2 == 0) {
					matrizCampo[i][j] = 2;
				}
				
			}
		}
		
		for(i =0 ;i<31;i++){
			matrizCampo[0][i] = 8;
			matrizCampo[12][i] = 8;
		}
		
		for(i =0 ;i<13;i++){
			matrizCampo[i][0] = 8;
			matrizCampo[i][30] = 8;
		}	
	}
	void desenharCenarioFixo() {
		int auxX, auxY;
		auxY = 20;
		int i, j;
		for (i = 0; i<5; i++) {
			auxX = 20;
			for (j = 0; j<14; j++) {
				matrizFixos[i][j].setando(auxX, auxY);
				matrizFixos[i][j].desenhaFixo();
				auxX += 20;
			}

			auxY += 20;

		}
		mostrarMatrizCampo();
		
	}
	
	void mostrarMatrizCampo() {
		int i, j;
		printf("matriz do campo\n");
		for (i = 0; i <13; i++)
		{
			for (j = 0; j<15; j++)
			{
				printf(" %d ",matrizCampo[i][j]);
			}
			printf("\n");
		}


	}
	
	void desenharBordas(int cameraX_min, int cameraX_max) {
		int i;


		//borda esquerda	
		if (cameraX_min<10) {
			glColor3f(0.9, 0.9, 0.9);
			glBegin(GL_QUADS);
			glVertex2f(0, 0);
			glVertex2f(0, 130);
			glVertex2f(10, 130);
			glVertex2f(10, 0);
			glEnd();

			for (i = 130; i >= 10; i -= 10) {
				glColor3f(0.0, 0.0, 0.0);
				glBegin(GL_LINES);
				glLineWidth(100);
				glVertex2f(0, i);
				glVertex2f(10, i);
				glEnd();
			}
		}


		//borda cima
		glColor3f(0.9, 0.9, 0.9);
		glBegin(GL_QUADS);
		glVertex2f(10, 130);
		glVertex2f(310, 130);
		glVertex2f(310, 120);
		glVertex2f(10, 120);
		glEnd();

		for (i = 10; i <= 310; i += 10) {
			glColor3f(0.0, 0.0, 0.0);
			glBegin(GL_LINES);
			glLineWidth(100);
			glVertex2f(i, 130);
			glVertex2f(i, 120);
			glEnd();
		}


		glColor3f(0.9, 0.9, 0.9);
		glBegin(GL_QUADS);
		glVertex2f(10, 10);
		glVertex2f(310, 10);
		glVertex2f(310, 0);
		glVertex2f(10, 0);
		glEnd();

		for (i = 10; i <= 310; i += 10) {
			glColor3f(0.0, 0.0, 0.0);
			glBegin(GL_LINES);
			glLineWidth(100);
			glVertex2f(i, 10);
			glVertex2f(i, 0);
			glEnd();
		}

		if (cameraX_max>300) {


			glColor3f(0.9, 0.9, 0.9);
			glBegin(GL_QUADS);
			glVertex2f(300, 0);
			glVertex2f(300, 130);
			glVertex2f(310, 130);
			glVertex2f(310, 0);
			glEnd();

			for (i = 130; i >= 10; i -= 10) {
				//printf("desenhando i %d linhas\n",i);
				glColor3f(0.0, 0.0, 0.0);
				glBegin(GL_LINES);
				glLineWidth(100);
				glVertex2f(310, i);
				glVertex2f(300, i);
				glEnd();
			}

		}






	}

	void jogar() {
		player.desenhaBoneco();
	}

	void setMoviX(int incrementoMovi) {
		player.setMoviX(incrementoMovi);
	}

	void setMoviY(int incrementoMovi) {
		player.setMoviY(incrementoMovi);
	}

	void desenharQuebraveis(int posicaoX,int posicaoY,int coordX,int coordY) {
		Blocos[posicaoX][posicaoY].setInteiro(true);
		Blocos[posicaoX][posicaoY].setando(coordX,coordY);
		Blocos[posicaoX][posicaoY].desenhar();
	}


	void reDesenharQuebraveis() {
		int i, j;
		for (i = 0; i < 11; i++) {
			for (j = 0; j < 29; j++) {
				if (Blocos[i][j].getInteiro()) {
					Blocos[i][j].desenhar();
					
				}
			}

		}
		mostrarMatrizCampo();
	}
	
	void setValorMatrizCampo(int x,int y,int valor){
		matrizCampo[x][y] = valor;
	}
	
	int getMatrizCampo(int x, int y){
		return matrizCampo[x][y];
	}
};