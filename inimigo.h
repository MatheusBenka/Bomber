#pragma once
class Inimigo{
private:
	int x_mini,x_med,y_mini,x_max,y_max;
	int linhas[3];
	int colunas[3];
	bool vivo;
	bool andaLinha;
	int moviX,moviY;
	int linhaAtual;
	int colunaAtual;
	
public:
	void setando(int y,int x,int linhaMeio,int colunaMeio,bool linha){
		andaLinha = linha;
		linhaAtual = linhaMeio;
		colunaAtual = colunaMeio;
		if(andaLinha){							
			colunas[0] = colunaMeio-1;
			colunas[1] = colunaMeio;
			colunas[2] = colunaMeio+1;						
		}else{
			if(linhaMeio>1){
				linhas[0] = linhaMeio-1;
				linhas[1] = linhaMeio;
				linhas[2] = linhaMeio+1;
			}else{
				linhas[0] = linhaMeio;
				linhas[1] = linhaMeio+1;
				linhas[2] = linhaMeio+1;
				
			}	
		
		}							
		x_mini = x;
		y_mini = y;
		x_max = x+8;
		x_med = x+4;
		y_max = y+8;
		vivo = true;
	}
	
	void desenhar(){
		
		glColor3f(1.0, 0.2, 0.6);
			glBegin(GL_TRIANGLES);
			glVertex2f(x_mini + moviX, y_mini + moviY);
			glVertex2f(x_med + moviX, y_max + moviY);
			glVertex2f(x_max +moviX, y_mini+moviY);
			glEnd();
	}
	
	bool getVivo(){
		return vivo;
	}
	
	void setVivo(bool v){
		vivo = v;
	}
	
	int getColunaAtual(){
		return colunaAtual;
	}	
	
	int getLinhaAtual(){
		return linhaAtual;
	}
};










