#pragma once
class Bomba{
private:
	int posicaoX_min, posicaoX_max, posicaoY_max, posicaoY_min;
	int linha,coluna;
	bool viva,setada;
public:
	void desenha() {
		glColor3f(1.0, 1.0, 0.0);
		glBegin(GL_QUADS);
		glVertex2f(posicaoX_min,posicaoY_min);
		glVertex2f(posicaoX_min,posicaoY_max);
		glVertex2f(posicaoX_max, posicaoY_max);
		glVertex2f(posicaoX_max, posicaoY_min);
		glEnd();
		
	}
	void estourar(){		
		printf("estourando linha %d %d %d  coluna %d %d %d\n",linha-1,linha,linha+1,coluna-1,coluna,coluna+1);
		if(linha%2!=0){
			if(linha>1){
				glColor3f(1.0, 1.0, 1.0);
				glBegin(GL_QUADS);
				glVertex2f(posicaoX_min, posicaoY_min +10);
				glVertex2f(posicaoX_min, posicaoY_max +10);
				glVertex2f(posicaoX_max, posicaoY_max +10);
				glVertex2f(posicaoX_max, posicaoY_min +10);
				glEnd();
			}
			if(linha<11){				
				glColor3f(1.0, 1.0, 1.0);
				glBegin(GL_QUADS);
				glVertex2f(posicaoX_min,posicaoY_min-10);
				glVertex2f(posicaoX_min,posicaoY_max-10);
				glVertex2f(posicaoX_max, posicaoY_max-10);
				glVertex2f(posicaoX_max, posicaoY_min-10);
				glEnd();
			}			
		}
		if(coluna%2!=0){
			if(coluna>1){
				glColor3f(1.0, 1.0, 1.0);
				glBegin(GL_QUADS);
				glVertex2f(posicaoX_min + 10, posicaoY_min);
				glVertex2f(posicaoX_min + 10, posicaoY_max);
				glVertex2f(posicaoX_max + 10, posicaoY_max);
				glVertex2f(posicaoX_max + 10, posicaoY_min);
				glEnd();				
			}
			if(coluna<29){
				glColor3f(1.0, 1.0, 1.0);
				glBegin(GL_QUADS);
				glVertex2f(posicaoX_min - 10, posicaoY_min);
				glVertex2f(posicaoX_min - 10, posicaoY_max);
				glVertex2f(posicaoX_max - 10, posicaoY_max);
				glVertex2f(posicaoX_max - 10, posicaoY_min);
				glEnd();
			}
			
		}		
		viva = false;
	}
	void setando(int x,int y){		
		posicaoX_min = x;
		posicaoY_min = y;
		posicaoX_max = x+8;
		posicaoY_max = y+8;
		viva = true;
	}
	void Coordenadas(int x,int y){
		linha = y;
		coluna = x;
	}
	int getLinha(){
		return linha;
	}
	int getColuna(){
		return coluna;
	}
	bool setSetada(bool s){
		setada = s;
	}
	bool getSetada(){
		return setada;
	}
	bool getVivo(){
		return viva;
	}
	void setVivo(bool v){
		viva = v;
	}
	void MostrarCoordenadas(){
		printf("linha %d coluna %d",linha,coluna);
	}
};

//fazer animacao