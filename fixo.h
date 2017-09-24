#pragma once
class Fixo {
private :
	int mini_X, max_X, mini_Y, max_Y;

public :

	void desenhaFixo(){
		
		glColor3f(0.9, 0.9, 0.9);
		glBegin(GL_QUADS);
		glVertex2f(mini_X, mini_Y);
		glVertex2f(mini_X, max_Y);
		glVertex2f(max_X,max_Y);
		glVertex2f(max_X, mini_Y);
		glEnd();
	}

	int getMini_x() {
		return mini_X;
	}
	
	int getMini_y() {
		return mini_Y;
	}
	
	int getMax_x() {
		return max_X;
	}
	
	int getMax_y() {
		return max_Y;
	}

	void setando(int x, int y) {
		mini_X = x;
		mini_Y = y - 10 ;
		max_X = x + 10;
		max_Y = y;
	}

	void mostrarCoordenadas() {
		printf(" mini x : %d max X : %d  mini Y : %d  max y : %d\n\n", mini_X, max_X, mini_Y, max_Y);
		

	}

};
