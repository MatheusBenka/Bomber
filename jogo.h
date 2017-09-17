#pragma once
#include "field.h"
#include "jogador.h"

class Jogo{
private :
	campinho campoJogo[3];
	Jogador player;
	
public :
	void desenharCenario(int faseAtual){
		campoJogo[faseAtual].desenharBordas();
		campoJogo[faseAtual].desenharCenarioFixo();
		campoJogo[faseAtual].desenharQuebraveis(faseAtual);
	}
	
	void REdesenharCenario(int faseAtual){
		campoJogo[faseAtual].desenharBordas();
		campoJogo[faseAtual].desenharCenarioFixo();
		campoJogo[faseAtual].REdesenharQuebraveis();
	}
	
	void jojar() {
		player.desenhaBoneco();
	}
	
	void setMoviX(int incrementoMovi) {
		player.setMoviX(incrementoMovi);
	}

	void setMoviY(int incrementoMovi) {
		player.setMoviY(incrementoMovi);
	}
	
	void colisao(){
		/*
			coordY = 120 - (i*10);
			coordX = j*10;
		
		*/
		
		//Fixo = 
	
	}
	
	
};