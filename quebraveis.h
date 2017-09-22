#pragma once
class bloquinhoQuebravel {
private:
	bool inteiro;
	int mini_X, max_X, mini_Y, max_Y;

public:
	bloquinhoQuebravel() {
		inteiro = false;
	}
	void setInteiro(bool valor) {
		inteiro = valor;
	}
	bool getInteiro() {
		return inteiro;
	}

	void setando(int x, int y) {
		mini_X = x;
		mini_Y = y;
		max_X = x + 10;
		max_Y = y + 10;
	}
	void desenhar() {

		glColor3f(0.5, 0.0, 0.0);
		glBegin(GL_QUADS);
		glVertex2f(mini_X, mini_Y);
		glVertex2f(mini_X, max_Y);
		glVertex2f(max_X,max_Y);
		glVertex2f(max_X, mini_Y);
		glEnd();
	}

	
};