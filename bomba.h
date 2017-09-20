#pragma once
class Bomba{
private:
	int posicaoX_min, posicaoX_max, posicaoY_max, posicaoY_min;
	bool viva;
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
		viva = false;
	}
	void setando(int x,int y){
		printf("entrando tbm\n");
		posicaoX_min = x;
		posicaoY_min = y;
		posicaoX_max = x+8;
		posicaoY_max = y+8;
		viva = true;
	}
	
	bool getVivo(){
		return viva;
	}
};

//fazer animacao