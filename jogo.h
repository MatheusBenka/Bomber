#pragma once
#include "field.h"
#include "jogador.h"

class Jogo{
private :
	campinho campoJogo;
	Jogador player;
	bool vivo;
	Bomba bombinha;
	int auxTempoBomba;
public :
	void desenharCenario(){
		campoJogo.zerarQuebraveis();
		player.reset();
		campoJogo.desenharBordas();
		campoJogo.desenharCenarioFixo();
		campoJogo.gerarQuebraveis();
	}
	
	void REdesenharCenario( ){
		campoJogo.desenharBordas();
		campoJogo.desenharCenarioFixo();
		campoJogo.REdesenharQuebraveis();
		if(bombinha.getVivo() && auxTempoBomba>0){
            bombinha.desenha();				
			auxTempoBomba--;
			glutPostRedisplay();
		}else{
			if(bombinha.getSetada()){
				bombinha.estourar();
				campoJogo.quebrar(bombinha.getLinha(),bombinha.getColuna());
				player.setVida(morrer());
				bombinha.Coordenadas(0,0);
				bombinha.setVivo(false);
				bombinha.setSetada(false);
				glutPostRedisplay();
			}
			
		}
	}
	
	bool jojar() {
		player.desenhaBoneco();
		return player.getVida();
	}
	
	bool morrer(){
		if(bombinha.getLinha() == player.getLinhaAtual() && bombinha.getColuna() ==  player.getColunaAtual()){
			return true;
		}
		if(bombinha.getLinha()+1 ==player.getLinhaAtual() && bombinha.getColuna() ==  player.getColunaAtual() ){
			return true;
		}
		if(bombinha.getLinha()-1 ==player.getLinhaAtual() && bombinha.getColuna() ==  player.getColunaAtual() ){
			return true;
		}
		if(bombinha.getLinha() == player.getLinhaAtual() && bombinha.getColuna()+1 ==  player.getColunaAtual()){
			return true;
		}
		if(bombinha.getLinha() == player.getLinhaAtual() && bombinha.getColuna()-1 ==  player.getColunaAtual()){
			return true;
		}
		
			return false;
		
	}
	
	void setMoviX(int incrementoMovi) {
		player.setMoviX(incrementoMovi);
	}

	void setMoviY(int incrementoMovi) {
		player.setMoviY(incrementoMovi);
	}

	void colisaoFixos(bool * top,bool * down,bool * left,bool * right){	
		Fixo matriz [5][14];
		int i,linha,coluna;
				
		for(i=0;i<14;i++){
			matriz[0][i] = campoJogo.getLinhaFixo(0,i);
		}
		for(i=0;i<14;i++){
			matriz[1][i] = campoJogo.getLinhaFixo(1,i);
		}
		for(i=0;i<14;i++){
			matriz[2][i] = campoJogo.getLinhaFixo(2,i);
		}
		for(i=0;i<14;i++){
			matriz[3][i] = campoJogo.getLinhaFixo(3,i);
		}
		for(i=0;i<14;i++){
			matriz[4][i] = campoJogo.getLinhaFixo(4,i);
		}
		
		
		linha = qualLinhaFixosTaOPlayer();
		coluna = qualColunaFixosTaOPlayer();
				
		
		//printf("linha : %d e coluna : %d\n",linha,coluna);  
		if(linha >= 4){
			
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
	
	void colisaoQuebraveis(bool * top,bool * down,bool * left,bool * right,char sentido){	
		int matriz [31];
		int i,linha,coluna;
				
		
		linha = qualLinhaTaOPlayerCampoTodo(sentido);
		coluna = qualColunaTaOPlayerCampoTodo(sentido);
		player.setLinha(linha);		
		player.setColuna(coluna);
		//resolver linha e coluna 0 0
		printf("aqui ta o player linha : %d coluna : %d\n",linha,coluna);  
		
		if(campoJogo.getMatrizCampo(linha,coluna+1) == 3 )
			*right = true;
		if(campoJogo.getMatrizCampo(linha,coluna-1)==3)
			*left = true;
		if(campoJogo.getMatrizCampo(linha+1,coluna)==3)
			*down = true;
		if(campoJogo.getMatrizCampo(linha-1,coluna)==3)
			*top = true;
				
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
		
		bombinha.setando(player.getLadoEsquerdo(),player.getBaixo());
		bombinha.Coordenadas(player.getColunaAtual(),player.getLinhaAtual());
		bombinha.MostrarCoordenadas();
		auxTempoBomba = 150;
		bombinha.setSetada(true);
	}
	
	int qualLinhaFixosTaOPlayer(){
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

	int qualColunaFixosTaOPlayer(){
		int i,j;
		
		for(i=30,j=0;i<300;i+=20,j++){
			if(player.getLadoEsquerdo() <=i)
				return j;
		}		
	}
	
	int qualLinhaTaOPlayerCampoTodo(char sentido){
		int i,j;
		
		if(player.getCima()>=110 ){
			return 1;
		}
		if(player.getCima()<=20){
			return 11;
		}else{
				for(i=100,j=2;i>10;i-=10,j++){
					if(player.getBaixo()>i && player.getCima() <i+10){						
							return j;
					}		
			}
		}
		return player.getLinhaAtual();
	}
	
	int qualColunaTaOPlayerCampoTodo(char sentido){
		int i,j;
		
		if(player.getLadoEsquerdo()<=20 ){
			return 1;	
		}
		if(player.getLadoEsquerdo()>=290){
			return 29;
		}else{
				for(i=20,j=2;i<=290;i+=10,j++){
					if(player.getLadoEsquerdo()>i && player.getLadoDireito()<=i+10){						
							return j;
					}		
			}
		}
		return player.getColunaAtual();
	}
	
	bool testarMoviHoriz(Fixo parede){
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