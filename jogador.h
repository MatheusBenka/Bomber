#pragma once
#include "quebraveis.h"
class Jogador {
private:
	int posicaoX_min, posicaoX_max, posicaoY_max, posicaoY_min, moviX, moviY;
	bool morto;
	int linha,coluna;
public:
	Jogador() {
		posicaoX_min = 11;
		posicaoX_max = 19;
		posicaoY_min = 111;
		posicaoY_max = 119;
		moviX = 0;
		moviY = 0;
		morto = false;
		linha = 1;
		coluna = 1;
	}

	void desenhaBoneco() {
		if(!morto){
			glColor3f(1.0, 0.0, 0.0);
			glBegin(GL_QUADS);
			glVertex2f(posicaoX_min + moviX, posicaoY_min + moviY);
			glVertex2f(posicaoX_min + moviX, posicaoY_max + moviY);
			glVertex2f(posicaoX_max + moviX, posicaoY_max + moviY);
			glVertex2f(posicaoX_max + moviX, posicaoY_min + moviY);
			glEnd();
		}else{
			glColor3f(1.0, 1.0, 1.0);
			glBegin(GL_QUADS);
			glVertex2f(posicaoX_min + moviX, posicaoY_min + moviY);
			glVertex2f(posicaoX_min + moviX, posicaoY_max + moviY);
			glVertex2f(posicaoX_max + moviX, posicaoY_max + moviY);
			glVertex2f(posicaoX_max + moviX, posicaoY_min + moviY);
			glEnd();
		}
		
	}
		
	void reset(){		
		posicaoX_min = 11;
		posicaoX_max = 19;
		posicaoY_min = 111;
		posicaoY_max = 119;
		moviX = 0;
		moviY = 0;
		morto = false;
		linha = 1;
		coluna = 1;
	}

	int getColunaAtual(){
		return coluna;
	}
	
	int getLinhaAtual(){
		return linha;
	}
	
	void setLinha(int nova){
		linha=nova;
	}
	
	void setColuna(int nova){
		coluna=nova;
	}
	
	void setVida(bool v){
		morto = v;
	}
	
	bool getVida(){
		return morto;
	}
	
	void setMoviY(int incrementoMovi) {
		moviY += incrementoMovi;
	}
	
	void setMoviX(int incrementoMovi) {
		moviX += incrementoMovi;
	}
	
	int getMiniX(){
		return posicaoX_min;
	}
	
	int getMiniY(){
		return posicaoY_min;
	}
	
	int getMaxX(){
		return posicaoX_max;
	}
	
	int getMaxY(){
		return posicaoY_max;
	}
	
	int getMoviX(){
		return moviX;
	}
	
	int getMoviY(){
		return moviY;
	}
	
	int getLadoDireito(){
		return posicaoX_max + moviX ;
	}
	
	int getLadoEsquerdo(){
		return posicaoX_min + moviX;
	}
	
	int getCima(){
		return posicaoY_max +moviY;
	}
		
	int getBaixo(){
		return posicaoY_min +moviY;
	}
};

//criar sprites