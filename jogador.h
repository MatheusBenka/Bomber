#pragma once
class Jogador {
private:
	int posicaoX_min, posicaoX_max, posicaoY_max, posicaoY_min, moviX, moviY;
public:
	Jogador() {

		posicaoX_min = 11;
		posicaoX_max = 19;
		posicaoY_min = 111;
		posicaoY_max = 119;
		moviX = 0;
		moviY = 0;
	}

	void desenhaBoneco() {
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_QUADS);
		glVertex2f(posicaoX_min + moviX, posicaoY_min + moviY);
		glVertex2f(posicaoX_min + moviX, posicaoY_max + moviY);
		glVertex2f(posicaoX_max + moviX, posicaoY_max + moviY);
		glVertex2f(posicaoX_max + moviX, posicaoY_min + moviY);
		glEnd();

		glEnd();
	}

	void setMoviX(int incrementoMovi) {
		moviX += incrementoMovi;
	}

	void setMoviY(int incrementoMovi) {
		moviY += incrementoMovi;
	}
	

	void colisao() {
		
	
	}
};