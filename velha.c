#include<stdio.h> 
#include<stdbool.h>
#include<stdlib.h>
void x_o(bool val, char ***mat, int l, int c){
	if(val){
		for(int i = l-2, j = c-2, cont = 0;cont < 5;i++, j++, cont++ )
			(*mat)[i][j] = '\\';
		for(int i = l+2, j = c-2, cont = 0; cont < 5; i--, j++, cont++)
			(*mat)[i][j] = '/';
		(*mat)[l][c] = 'X';
		return;
	}
	for(int j = c-2, cont = 0; cont < 5; j++, cont++){
		(*mat)[l-2][j] = '_';
		(*mat)[l+2][j] = '_';
	}
	for(int i = l-1, cont = 0; cont < 4; i++, cont++){
		(*mat)[i][c-3] = '|';
		(*mat)[i][c+3] = '|';
	}
	return;
}
int qual(char x){
	if(x == '_')
		return 2;
	return 1;
}
int verificar (char ***mat){
	for(int i = 0; i < 3; i++){
		if((*mat)[4+6*i][7] != ' '&& (*mat)[4+6*i][7] == (*mat)[4+6*i][19] && (*mat)[4+6*i][19] == (*mat)[4+6*i][31]){
			return qual((*mat)[4+2*i][7]);
		}else if((*mat)[4][7+12*(i%3)] != ' '&& (*mat)[4][7+12*(i%3)] == (*mat)[10][7+12*(i%3)] && (*mat)[10][7+12*(i%3)] == (*mat)[16][7+12*(i%3)]){
			return qual((*mat)[4][7+12*(i%3)]);
		}
	}
	if((*mat)[16][7] != ' ' && (*mat)[16][7] == (*mat)[10][19] && (*mat)[10][19] == (*mat)[4][31]){
		return qual((*mat)[16][7]);
	}else if((*mat)[4][7] != ' ' && (*mat)[4][7] == (*mat)[10][19] && (*mat)[10][19] == (*mat)[16][31]){
		return qual((*mat)[4][7]);
	}
	return 0;
}
bool inserir(char ****mat, int pos, bool tipo, int i){
	system("clear");
	if((*mat)[i][4+6*(pos/3)][7+12*(pos%3)] == ' '){
		for(; i < 10; i++)
			x_o(tipo, &((*mat)[i]), 2+6*(pos/3), 5+12*(pos%3));
		return false;
	}
	return true;
}
int main(){
	int x = -2;
	char ***jogo = malloc(sizeof(char**)*10);
	while(x == -2){
		system("clear");  //limpa o terminal
		for(int i = 0; i < 10; i++){   //reinicia o tabuleiro de cada uma das jogadas das rodadas
			jogo[i] = malloc(sizeof(char*)*17);
			for(int j = 0;j < 17; j++ ){  //inicia as linhas
				jogo[i][j] = malloc(sizeof(char)*35);
				for(int k = 0; k < 35; k++){  //inicia as celulas das linhas
					if(j == 5 && k == 11 || j == 11 && k == 11 || j == 5 && k == 23 || j == 11 && k == 23){
						jogo[i][j][k] = '+';
					}else if(j == 5 || j == 11){
						jogo[i][j][k] = '-';
					}else if(k == 11 || k == 23){
						jogo[i][j][k] = '|';
					}else{
						jogo[i][j][k] = ' ';
					}
				}
			}
		}
		int vencedor = 0;
		bool tipo = true;  //true = X false = O
		char insert = ' ';
		int i = 1;
		for(; i < 10 && vencedor == 0; i++){  //executa cada uma das jogadas das 9 rodadas ou até alguem ganhar
			for(int j = 0;j < 17 && vencedor == 0; j++ ){  //printa o tabuleiro atual
				for(int k = 0; k < 35 && vencedor == 0; k++){
					printf("%c", jogo[i][j][k]);  
				}
				printf("\n");
			}
			scanf(" %c", &insert);
			if(insert >= 'a' && insert <= 'i'){
				if(inserir(&jogo, (int)(insert - 'a'), tipo, i)){
					i--;
					printf("A posicao %c ja está preenchida\n", insert);
				}else{
					vencedor = verificar(&(jogo[i]));
				}
			}else if(insert>= 'A' && insert <= 'I'){
				if(inserir(&jogo, (int)(insert - 'A'), tipo, i)){
					i--;
					printf("A posicao %c ja está preenchida\n", insert);
				}else{
					vencedor = verificar(&(jogo[i]));
				}
			}else{
				system("clear");
				printf("\033[1;31m!!!DIGITE UM VALOR VALIDO (A - I)!!!\033[0m\n");
				i--;
			}
			tipo = !tipo;
		}
		if(vencedor == 1)
			printf("VENCEDOR FOI O X\n");
		else if(vencedor == 2)
			printf("VENCEDOR FOI O O\n");
		else
				printf("DEU VELHA\n");
		if(i >= 10)
			i--;
		for(int j = 0;j < 17; j++ ){
			for(int k = 0; k < 35; k++){
				printf("%c", jogo[i][j][k]);
			}
			printf("\n");
		}
		printf("Recomeçar -->  Digite -2\nFinalizar --> Digite -1\nAnalizar jogadas --> Digite valores de 1-10\n");
		scanf(" %d", &x);
		while(x != -1 && x != -2){
			system("clear");
			if(x <= i+1 && x > 0){
				if(x == i){
					if(vencedor == 1)
						printf("VENCEDOR FOI O X\n");
					else if(vencedor == 2)
						printf("VENCEDOR FOI O O\n");
					else
						printf("DEU VELHA\n");
				}
				for(int j = 0;j < 17; j++ ){
					for(int k = 0; k < 35; k++){
						printf("%c", jogo[x-1][j][k]);
					}
					printf("\n");
				}
			}else{
				printf("Digite um valor valido\n");
			}	
			printf("Recomeçar -->  Digite -2\nFinalizar --> Digite -1\nAnalizar jogadas --> Digite valores de 1-10\n");
			scanf(" %d", &x);
		}
	}
}

/*
           |    \   /    |
           |     \ /     |
           |      x      |
           |     / \     |
           |    /   \    |
-----------+-------------+-----------
           |    _____    |
           |   |     |   |
	   |   |     |   |
           |   |     |   |
           |   |_____|   |
-----------+-------------+-----------
           |             |
           |             |
           |             |
           |             |
           |             |  
	 */
