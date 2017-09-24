#pragma once
class Inimigo{
private:
	int x_mini,x_med,y_mini,x_max,y_max;
	int linhas[3];
	int colunas[3];
	bool vivo;
public:
	void setando(int x,int y,int linha,int coluna){
		if(coluna%2==0){
			
		}
		if(linha>1){
			linhas[0] = linha-1;
			linhas[1] = linha;
			linhas[2] = linha+1;
		}
		
		colunas[0] = coluna-1;
		colunas[1] = coluna;
		colunas[2] = coluna+1;
				
		x_mini = x;
		y_mini = y;
		x_max = x+8;
		y_max = y+8;
	}
	
	void desenhar(int moviX,int moviY){
		glColor3f(1.0, 0.0, 0.0);
			glBegin(GL_TRIANGLES);
			glVertex2f(x_mini + moviX, y_mini + moviY);
			glVertex2f(x_med + moviX, y_max + moviY);
			glVertex2f(x_max + moviX, y_mini + moviY);
			glEnd();
	}
	
};