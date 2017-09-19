#pragma once
#include "field.h"
#include "jogador.h"

class Jogo{
private :
	campinho campoJogo[3];
	Jogador player;
	bool vivo;
	Bomba bombinha;
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
		if(bombinha.getVivo()){
			bombinha.desenha();
		}
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
	
	int colisao(int faseAtual, bool * top,bool * down,bool * left,bool * right){	
		Fixo matriz [5][14];
		int i;
				
		for(i=0;i<14;i++){
			matriz[0][i] = campoJogo[faseAtual].getLinhaFixo(0,i);
		}
		for(i=0;i<14;i++){
			matriz[1][i] = campoJogo[faseAtual].getLinhaFixo(1,i);
		}
		for(i=0;i<14;i++){
			matriz[2][i] = campoJogo[faseAtual].getLinhaFixo(2,i);
		}
		for(i=0;i<14;i++){
			matriz[3][i] = campoJogo[faseAtual].getLinhaFixo(3,i);
		}
		for(i=0;i<14;i++){
			matriz[4][i] = campoJogo[faseAtual].getLinhaFixo(4,i);
		}
		printf("matriz[0][0] valores %d \n",matriz[0][0].getMini_x());		
	
				
	}
	bool colisaoBORDALeft(int valor){
		if(player.getMiniX() + player.getMoviX() <=valor ){
			return true;
		}else{
			return false;
		}
	}
	
	bool colisaoBORDARight(int valor){
		if(player.getMaxX() + player.getMoviX() >=valor){
			return true;
		}else{
			return false;
		}
	}
	bool colisaoBORDATOP(int valor){
		if(player.getMaxY() + player.getMoviY()>=valor){
			return true;
		}else{
			return false;
		}
	}
	bool colisaoBORDADOWN(int valor){
		if(player.getMiniY() + player.getMoviY()<=valor ){
			return true;
		}else{
			return false;
		}
	}
	
	void dropBomb(){
		printf("entrando");
		bombinha.setando(player.getMiniX(),player.getMiniY());
	}
	
};