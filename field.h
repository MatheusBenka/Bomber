#pragma once
#include "quebraveis.h"
#include "fixo.h"
#include "jogador.h"
#include "bomba.h"
#include "inimigo.h"

#include <time.h>

class campinho {
private:
	int qtdInimigos, qtdBlocosDestrutiveis;
	int matrizCampo[13][31];
	Fixo matrizFixos[5][14];
	bloquinhoQuebravel Blocos[13][31];
	Jogador player;
	Inimigo doMal[5];
public:

	campinho() {
		int i, j;
		matrizCampo[1][1] =1;		
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
		auxY = 110;
		int i, j;
		for (i = 0; i<5; i++) {
			auxX = 20;
			for (j = 0; j<14; j++) {
				matrizFixos[i][j].setando(auxX, auxY);
				matrizFixos[i][j].desenhaFixo();
				auxX += 20;
			}

			auxY -= 20;

		}
		//mostrarMatrizCampo();
		
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
	
	void mostrarMatrizCampoSegundaParte() {
		int i, j;
		printf("matriz do campo 2\n");
		for (i = 0; i <13; i++)
		{
			for (j = 14; j<31; j++)
			{
				printf(" %d ",matrizCampo[i][j]);
			}
			printf("\n");
		}


	}
	
	void desenharBordas() {
		int i;


		//borda esquerda	
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

		
			glColor3f(0.9, 0.9, 0.9);
			glBegin(GL_QUADS);
			glVertex2f(300, 0);
			glVertex2f(300, 130);
			glVertex2f(310, 130);
			glVertex2f(310, 0);
			glEnd();

			for (i = 130; i >= 10; i -= 10) {
				glColor3f(0.0, 0.0, 0.0);
				glBegin(GL_LINES);
				glLineWidth(100);
				glVertex2f(310, i);
				glVertex2f(300, i);
				glEnd();
			}

}
	
	void gerarInimigos(){
		int i,j,k,auxRand;		
		for(i=14;i<30;i++){
			srand((unsigned)time(0));
		
			if((rand()%5)%2 == 0 || i == 29){			
				printf("foi o 1");
				doMal[0].setando(110,i*10,1,i,true);
				break; 	
			}
			
		}
		
		// atualizar matriz com as coordenadas do inimigo
		j=i-1;
		for(i=0;i<3;i++){
			printf("pondo 6 na [1] [%d]\n",j);
			matrizCampo[1][j++] = 6;			
		}			
			
		
		for(i=3;i<16;i++){
			srand((unsigned)time(0));
			if(i%2==0){
				continue;
			}
			if((rand()%7)%2 == 0 || i==15){		
				printf("foi o 2");
				doMal[1].setando(80,i*10,4,i,false);
				break; 	
			}
		}
		
		
		// atualizar matriz com as coordenadas do inimigo
		(i>15?k=15:k=i);
		//if(i>15) k=15; else k = i;
		printf("ta pondo no k %d\n",k);
		for(i=0,j=3;i<3;i++,j++){
			printf("pondo 6 tbm na [%d] [%d]\n",j,k);
			matrizCampo[j][k] = 6;
		}	
			
		for(i=15;i<28;i++){
			srand((unsigned)time(0));
			if(i%2==0){
				continue;
			}
			if((rand()%7)%2 == 0 || i==27){		
				printf("foi o 2");
				doMal[2].setando(80,i*10,4,i,false);
				break; 	
			}
		}
		
		
		// atualizar matriz com as coordenadas do inimigo
		(i>15?k=15:k=i);
		//if(i>15) k=15; else k = i;
		printf("ta pondo no k %d\n",k);
		for(i=0,j=3;i<3;i++,j++){
			printf("pondo 6 tbm na [%d] [%d]\n",j,k);
			matrizCampo[j][k] = 6;
		}	
		
		for(i=9;i<22;i++){
			srand((unsigned)time(0));
			if((rand()%9)%2 == 0 || i == 21){				
				printf("foi o 3");
				doMal[3].setando(50,i*10,7,j,true);
				break; 	
			}
		}		
		j=i-1;
		for(i=0;i<3;i++)			
			matrizCampo[7][j++] = 6;
		
		
		for(i=1;i<17;i++){
			srand((unsigned)time(0));
			if((rand()%9)%2 == 0 || i == 16){				
				printf("foi o 3");
				doMal[4].setando(10,i*10,11,j,true);
				break; 	
			}
		}		
		j=i-1;
		for(i=0;i<3;i++)			
			matrizCampo[7][j++] = 6;
	}

	void desenharInimigos(){
		int i;
		for(i=0;i<5;i++){	
			if(doMal[i].getVivo()){
				doMal[i].desenhar();
			}
			
		}
	}

	void gerarQuebraveis() {
		int i,j,coordX,coordY;
		int seguidos;
		int auxRand;
		
			srand((unsigned)time(0));
		for(i=1;i<12;i++){
			for(j=1;j<30;j++){
				//nao criar quebravel no lugar onde inicia o player
				if(i==1 && j==1){
					continue;
				}
				//nao criar quebravel no na coluna abaxo do lugar onde inicia o player
				if(i==2 && j == 1){
					continue;
				}
				//nao criar quebravel no na coluna a frente do lugar onde inicia o player
				if(i==1 && j==2){
					continue;
				}
				//nao criar quebraveis onde tem fixos
				if(i%2 == 0 && j%2==0){
					continue;
				}
				
				//nao criar quebraveis onde tem inimigos
				if(matrizCampo[i][j] == 6){
					printf("ta entrando aqui senhor\n");
					continue;
				}
				auxRand = rand()%200;
				if(auxRand%2 != 0){
					coordY = 120 - (i*10);
					coordX = j*10; 
					Blocos[i][j].setInteiro(true);
					matrizCampo[i][j] = 3;
					Blocos[i][j].setando(coordX,coordY);
					Blocos[i][j].desenhar();
				}
			}
		}
		
	}

	void zerarQuebraveis(){
		int i,j;
		for(i=1;i<12;i++){
			for(j=1;j<30;j++){				
				if(i==1 && j==1){
					continue;
				}				
				if(i==2 && j == 1){
					continue;
				}			
				if(i==1 && j==2){
					continue;
				}				
				if(i%2 == 0 && j%2==0){
					continue;
				}								
				if(matrizCampo[i][j] == 6){
					continue;
				}				
					Blocos[i][j].setInteiro(false);
					matrizCampo[i][j] = 0;
					Blocos[i][j].setando(0,0);
					
				}
			}		
	}
	
	void quebrar(int linha,int coluna){
		Blocos[linha][coluna+1].setInteiro(false); 
		matrizCampo[linha][coluna+1] = 0;
		
		Blocos[linha][coluna-1].setInteiro(false); 
		matrizCampo[linha][coluna-1] = 0;
		
		Blocos[linha+1][coluna].setInteiro(false); 
		matrizCampo[linha+1][coluna] = 0;
		
		Blocos[linha-1][coluna].setInteiro(false); 
		matrizCampo[linha-1][coluna] = 0;
	}
	
	void REdesenharQuebraveis() {
		int i, j;
		for (i = 0; i < 12; i++) {
			for (j = 0; j < 30; j++) {
				if (Blocos[i][j].getInteiro()) {
					Blocos[i][j].desenhar();
					
				}
			}

		}
		mostrarMatrizCampo();
		printf("\n");
		mostrarMatrizCampoSegundaParte();
	}
	
	void setValorMatrizCampo(int x,int y,int valor){
		matrizCampo[x][y] = valor;
	}
	
	int getMatrizCampo(int x, int y){
		return matrizCampo[x][y];
	}
	
	//Fixo getFixo(int x, int y){
	//	return matrizFixos[x][y];
	//}
	int retornaLinhaInimigo(int qual){
		return doMal[qual].getLinhaAtual();		
	}
	
	int retornaColunaInimigo(int qual){
		return doMal[qual].getColunaAtual();		
	}
	
	Fixo getLinhaFixo(int x,int y){
		return matrizFixos[x][y];
	}
	
};

//criar mais fases // talvez....
