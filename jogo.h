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
	
	void colisao(int faseAtual, bool * top,bool * down,bool * left,bool * right){	
		Fixo matriz [5][14];
		int i,linha,coluna;
				
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
		
		
		linha = qualLinhaTaOPlayer();
		coluna = qualColunaTaOPlayer();
				
		
		printf("linha : %d e coluna : %d\n",linha,coluna);  
		if(linha >= 4){
			printf("onde");
			*right = testarMoviLados(matriz[4][coluna]);
			
			*down = testarMoviHoriz(matriz[linha][coluna]);
			*top = testarMoviHoriz(matriz[linha-1][coluna]);
			if(coluna==14){
							*left = testarMoviLados(matriz[linha][coluna-1]);
			}else{
				*left = testarMoviLados(matriz[4][coluna]);
			}
		}else{
			switch(linha){
				case 0:		
					printf("ta");
					*down = testarMoviHoriz(matriz[linha][coluna]);
					*right = testarMoviLados(matriz[linha][coluna]);
					*left = testarMoviLados(matriz[linha][coluna-1]);
					break;
				case 1:
				case 2:
				case 3:
					
					if(coluna==0){
						*right = testarMoviLados(matriz[linha-1][coluna]);
						*right = testarMoviLados(matriz[linha][coluna]);
						*down = testarMoviHoriz(matriz[linha][coluna]);
						*top = testarMoviHoriz(matriz[linha-1][coluna]);
						
						break;
					}else{
						if(coluna==14){
							*left = testarMoviLados(matriz[linha][coluna-1]);
							break;
						}else{
							printf("entrado aqui");
							*left = testarMoviLados(matriz[linha][coluna-1]);
							*right = testarMoviLados(matriz[linha][coluna]);	
							*down = testarMoviHoriz(matriz[linha][coluna]);
							*top = testarMoviHoriz(matriz[linha-1][coluna]);
						}						
					}
					
					break;
			}
		}
			
		
				
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
		
		bombinha.setando(player.getMiniX(),player.getMiniY());
	}
	
	int qualLinhaTaOPlayer(){
		if(player.getCima() >=100)			
			return 0;
		if(player.getCima() < 100 && player.getCima() >=80)
			return 1;
		if(player.getCima() < 80 && player.getCima() >=60)
			return 2;
		if(player.getCima() < 60 && player.getCima() >=40)
			return 3;
		if(player.getCima() < 40 && player.getCima() >=20)
			return 4;
		if(player.getCima() <=20)
			return 5;
	}	
	int qualColunaTaOPlayer(){
		if(player.getLadoEsquerdo() <=30)
			return 0;
		if(player.getLadoEsquerdo() >30 && player.getLadoEsquerdo() <=50)
			return 1;
		if(player.getLadoEsquerdo() > 50 && player.getLadoEsquerdo() <=70)
			return 2;
		if(player.getLadoEsquerdo() > 70 && player.getLadoEsquerdo() <=90)
			return 3;
		if(player.getLadoEsquerdo() > 90 && player.getLadoEsquerdo() <=110)
			return 4;
		if(player.getLadoEsquerdo() > 110 && player.getLadoEsquerdo() <=130)
			return 5;
		if(player.getLadoEsquerdo() > 130 && player.getLadoEsquerdo() <=150)
			return 6;
		if(player.getLadoEsquerdo() > 150 && player.getLadoEsquerdo() <=170)
			return 7;
		if(player.getLadoEsquerdo() > 170 && player.getLadoEsquerdo() <=190)
			return 8;
		if(player.getLadoEsquerdo() > 190 && player.getLadoEsquerdo() <=210)
			return 9;
		if(player.getLadoEsquerdo() > 210 && player.getLadoEsquerdo() <=230)
			return 10;
		if(player.getLadoEsquerdo() > 230 && player.getLadoEsquerdo() <=250)
			return 11;
		if(player.getLadoEsquerdo() > 250 && player.getLadoEsquerdo() <=270)
			return 12;
		if(player.getLadoEsquerdo() > 270 && player.getLadoEsquerdo() <=290)
			return 13;
		if(player.getLadoEsquerdo() > 290)
			return 14;
	}
	
	bool testarMoviHoriz(Fixo parede){
		//printf("testando se ");
		//printf(" isso : %d eh >= a %d\n",player.getLadoDireito(),parede.getMini_x()); 
		//printf("tbm se isso : %d eh <= a %d\n",player.getLadoDireito(),parede.getMax_x()); 
		
		if(player.getLadoDireito()>=parede.getMini_x() && player.getLadoDireito()<=parede.getMax_x()){			
			return true;	
		}else{
			if(player.getLadoEsquerdo()>=parede.getMini_x() && player.getLadoEsquerdo()<=parede.getMax_x()){
				return true;	
			}else{
				return false;
			}
		}
		
	}
	
	bool testarMoviLados(Fixo parede){	
		if(player.getBaixo()>=parede.getMini_y() && player.getBaixo()<=parede.getMax_y()){			
			return true;			
		}else{
			if(player.getCima()>=parede.getMini_y() && player.getCima()<=parede.getMax_y()){
				return true;
			}else{
				return false;
			}
		}
		
	}
	int getPosiESQPlayer(){
		return player.getLadoEsquerdo();
	}
	int getPosiDIRPlayer(){
		return player.getLadoDireito();
	}
};























