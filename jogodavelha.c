#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 10

//##################################################################################################

/*
Descrição: Função apenas para printar uma linha de vários '='.
Entrada:   Tamanho do tabuleiro.
Saída:     Imprime uma linha de '=' de acordo com o tamanho necessário.
*/

void linha(int num){
	//dicionario de dados
	int i; 			//auxiliar para o 'for' de impressão.

	//corpo:
		//imprimindo '=' para dividir o tabuleiro.(Obs.: (num * 3) + 1 é o número necessário de '=' para cobrir o tamanho do tabuleiro.
	for(i = 0; i < (num * 3) + 1; i++)
		printf("=");

	printf("\n"); //Pulando linha após for.
}

//##################################################################################################

/*
Descrição: Função que imprime o tabuleiro na tela dos jogadores.
Entrada:   A matriz do tabuleiro, e o tamanho do tabuleiro escolhido.
Saída:     Imprime na tela o tabuleiro.
*/

void tabuleiro(char tab[][N], int num){
	//dicionario de dados
	int i,j;	 	//Indices para percorrer a matriz e afins.

	//Corpo:
		//imprimindo indices para facilitar a localização dos jogadores.
	printf("   "); 	//Espaços para deixar mais esteticamente bonito.
	for(i = 0; i < num; i++)
		printf("  %d", i);
	printf("  j");	//indice j
	printf("\n"); 	//Pulando linha após for.

		//chamando função da barra de '=', para iniciar o tabuleiro.
	printf("    "); 	//Espaços para deixar mais esteticamente bonito.
	linha(num);

		//imprimindo a matriz.
	for(i = 0; i < num; i++){
		printf("  %d", i);				//Imprimindo indice da linha atual.
		printf(" ");					//Espaço para deixar mais esteticamente bonito.
		for(j = 0; j < num; j++){
			printf("|");				//Barrinha para separar as áreas do tabuleiro.
			printf(" %c", tab[i][j]);	//Imprimindo o valor na posição especifica da matriz.
			}
		printf("|");					//Barrinha do fim da lateral esquerda.
		printf("\n"); 					//Pulando linha após for.
		}

		//chamando função da barra de '=', para terminar o tabuleiro.
	printf("  i "); 	//Espaços para deixar mais esteticamente bonito.
	linha(num);
	puts(""); 			//pulando linha
}

//##################################################################################################

/*
Descrição: Checa se a jogada é regular.
Entrada:   Tabuleiro, tamanho do tabuleiro, ambos indices[i][j] da jogada, e qual jogador.
Saida: 	   Retorna 0 para falso, 1 para verdadeiro.
*/

int checa_jogada(char tab[][N],int num, int i, int j,int humano){
	//corpo:
		//checa se a possição existe dentro do tabuleiro.
	//Caso qualquer um dos indices forem maiores que o tamanho do tabuleiro ou menores que 0, eles não existem.
	if(i < 0 || i >= num){
		if(humano == 1){
			printf("Indice inválido! ");
			}
		return 0;	//0 = Jogada Reprovada!
		}
	if(j < 0 || j >= num){
		if(humano == 1){
			printf("Indice inválido! ");
			}
		return 0;	//0 = Jogada Reprovada!
		}
		//checa se essa posição está "vazia".
	if(tab[i][j] == ' '){
		printf("Boa jogada!\n\n"); //pulando duas linhas por estetica.
		return 1;	//1 = Jogada Aprovada!
	} else if(tab[i][j] == 'X') {
		if(humano == 1){
			printf("O 'X' já ocupa a posição! ");
			}
		return 0;	//0 = Jogada Reprovada!
	} else if(tab[i][j] == 'O') {
		if(humano == 1){
			printf("A 'O' já ocupa a posição! ");
			}
		return 0;	//0 = Jogada Reprovada!
	}
	return 0;
}

//##################################################################################################

/*
Descrição: Modularidade da função principal de checagem de vitoria, para as checagens das diagonais curvas.
Entrada:   Tabuleiro, e o tamanho do tabuleiro.
Saída: 	   Retorna 0 por padrão ou 1 caso alguém vença.
*/

int checa_vitoria_curva(char tab[][N], int num){
	//dicionario de dados
	int i,j; 		//indices para matriz
	int checa_x; 	//variavel para checar se o X ganhou
	int checa_o;	//variavel para checar se o O ganhou
	//corpo:
	//checa diagonal curva superior
	j = 1;
	checa_x = 0; //Sempre zerando os checa, para não acumular as checagens.
	checa_o = 0; //idem
	for(i = 0; i < num; i++){
		if(tab[i][j] == 'X'){
			checa_x++;    //Aumenta caso o espeço esteja preenchido
			if(checa_x == num){ //Caso todos os espaços estejam preenchidos
				return 1; //vitoria
			}
		} else if(tab[i][j] == 'O'){
			checa_o++;    //Aumenta caso o espeço esteja preenchido
			if(checa_o == num){ //Caso todos os espaços estejam preenchidos
				return 1; //vitoria
			}
		}
		if(j != num-1){ //j cresce até o ultimo indice do tabuleiro, depois decresce.
			j++;
		} else {
			j--;
		}
	}

	return 0; //sem vitoria
}

//##################################################################################################

/*
Descrição: Modularidade da função principal de checagem de vitoria, para as checagens das diagonais menores que convergem para o meio.
Entrada:   Tabuleiro, e o tamanho do tabuleiro.
Saída: 	   Retorna 0 por padrão ou 1 caso alguém vença.
*/

int checa_vitoria_meio(char tab[][N], int num){
	//Dicionario de dados
	int i,j; 		//indices para matriz
	int checa_x; 	//variavel para checar se o X ganhou
	int checa_o;	//variavel para checar se o O ganhou
	//corpo:
	//checa diagonais menores que convergem para o meio inferior
	i = ((num-1)/2); //i = metade do tabuleiro.
	checa_x = 0; //Sempre zerando os checa, para não acumular as checagens.
	checa_o = 0; //idem
	for(j = 0; j < num;  j++){
		if(tab[i][j] == 'X'){
			checa_x++;    //Aumenta caso o espeço esteja preenchido
			if(checa_x == num){ //Caso todos os espaços estejam preenchidos
				return 1; //vitoria
			}
		} else if(tab[i][j] == 'O'){
			checa_o++;    //Aumenta caso o espeço esteja preenchido
			if(checa_o == num){ //Caso todos os espaços estejam preenchidos
				return 1; //vitoria
			}
		}
		if(j < ((num-1)/2)){ //i cresce até a metade do tabuleiro, depois decresce.
			i++;
		} else {
			i--;
		}
	}

	//checa diagonais menores que convergem para o meio superior
	i = ((num-1)/2); //i = metade do tabuleiro.
	checa_x = 0; //Sempre zerando os checa, para não acumular as checagens.
	checa_o = 0; //idem
	for(j = 0; j < num;  j++){
		if(tab[i][j] == 'X'){
			checa_x++;    //Aumenta caso o espeço esteja preenchido
			if(checa_x == num){ //Caso todos os espaços estejam preenchidos
				return 1; //vitoria
			}
		} else if(tab[i][j] == 'O'){
			checa_o++;    //Aumenta caso o espeço esteja preenchido
			if(checa_o == num){ //Caso todos os espaços estejam preenchidos
				return 1; //vitoria
			}
		}
		if(j < ((num-1)/2)){ //i decresce até a metade do tabuleiro, depois cresce.
			i--;
		} else {
			i++;
		}
	}

	//checa diagonais menores que convergem para o meio da direta
	j = ((num-1)/2); //j = metade do tabuleiro.
	checa_x = 0; //Sempre zerando os checa, para não acumular as checagens.
	checa_o = 0; //idem
	for(i = 0; i < num; i++){
		if(tab[i][j] == 'X'){
			checa_x++;    //Aumenta caso o espeço esteja preenchido
			if(checa_x == num){ //Caso todos os espaços estejam preenchidos
				return 1; //vitoria
			}
		} else if(tab[i][j] == 'O'){
			checa_o++;    //Aumenta caso o espeço esteja preenchido
			if(checa_o == num){ //Caso todos os espaços estejam preenchidos
				return 1; //vitoria
			}
		}
		if(i < ((num-1)/2)){ //j cresce até a metade do tabuleiro, depois decresce.
			j++;
		} else {
			j--;
		}
	}

	//checa diagonais menores que convergem para o meio da esquerda
	j = ((num-1)/2); //j = metade do tabuleiro.
	checa_x = 0; //Sempre zerando os checa, para não acumular as checagens.
	checa_o = 0; //idem
	for(i = 0; i < num; i++){
		if(tab[i][j] == 'X'){
			checa_x++;    //Aumenta caso o espeço esteja preenchido
			if(checa_x == num){ //Caso todos os espaços estejam preenchidos
				return 1; //vitoria
			}
		} else if(tab[i][j] == 'O'){
			checa_o++;    //Aumenta caso o espeço esteja preenchido
			if(checa_o == num){ //Caso todos os espaços estejam preenchidos
				return 1; //vitoria
			}
		}
		if(i < ((num-1)/2)){ //j decresce até a metade do tabuleiro, depois cresce.
			j--;
		} else {
			j++;
		}
	}

	return 0; //Sem vitoria	
}

//##################################################################################################

/*
Descrição: Função principal para checar de acordo com o tabuleiro, se algum dos jogadores ganhou.
Entrada:   Tabuleiro, e tamanho do tabuleiro
Saida:	   retorna 1 caso haja algum vencedor, ou 0, caso o contrário.
*/

int checa_vitoria(char tab[][N], int num){
	//dicionario de dados
	int i,j; 		//indices para matriz
	int checa_x; 	//variavel para checar se o X ganhou
	int checa_o;	//variavel para checar se o O ganhou
	//corpo:
	//checando linhas
		//checa linha por linha, zera contagem após checar uma linha.
	for(i = 0; i < num; i++){
		checa_x = 0; //Sempre zerando os checa, para não acumular as checagens.
		checa_o = 0; //idem
		for(j = 0; j < num; j++){
			if(tab[i][j] == 'X'){
				checa_x++;    //Aumenta caso o espeço esteja preenchido
				if(checa_x == num){ //Caso todos os espaços estejam preenchidos
					printf("Vitoria na Linha[%d]!\n", i);
					return 1; //vitoria
				}
			} else if(tab[i][j] == 'O'){
				checa_o++;    //Aumenta caso o espeço esteja preenchido
				if(checa_o == num){ //Caso todos os espaços estejam preenchidos
					printf("Vitoria na Linha[%d]!\n", i);
					return 1; //vitoria
				}
			}
		}
	}
	//checa colunas
		//checa coluna por coluna, zera contagem após checar uma linha.
	for(j = 0; j < num; j++){
		checa_x = 0; //Sempre zerando os checa, para não acumular as checagens.
		checa_o = 0; //idem
		for(i = 0; i < num; i++){
			if(tab[i][j] == 'X'){
				checa_x++;    //Aumenta caso o espeço esteja preenchido
				if(checa_x == num){ //Caso todos os espaços estejam preenchidos
					printf("Vitoria na Coluna[%d]!\n", j);
					return 1; //vitoria
				}
			} else if(tab[i][j] == 'O'){
				checa_o++;    //Aumenta caso o espeço esteja preenchido
				if(checa_o == num){ //Caso todos os espaços estejam preenchidos
					printf("Vitoria na Coluna[%d]!\n", j);
					return 1; //vitoria
				}
			}
		}
	}
	//checa diagonal superior
	checa_x = 0; //Sempre zerando os checa, para não acumular as checagens.
	checa_o = 0; //idem
	for(i = 0; i < num; i++){
		if(tab[i][i] == 'X'){
			checa_x++;    //Aumenta caso o espeço esteja preenchido
			if(checa_x == num){ //Caso todos os espaços estejam preenchidos
				puts("Vitoria na Diagonal!");
				return 1; //vitoria
			}
		} if(tab[i][i] == 'O'){
			checa_o++;    //Aumenta caso o espaço esteja preenchido
			if(checa_o == num){ //Caso todos os espaços estejam preenchidos
				puts("Vitoria na Diagonal!");
				return 1; //vitoria
			}
		}
	}
	//checa diagonal inferior
	j = num - 1;
	checa_x = 0; //Sempre zerando os checa, para não acumular as checagens.
	checa_o = 0; //idem
	for(i = 0; i < num; i++){
		if(tab[i][j] == 'X'){
			checa_x++;    //Aumenta caso o espeço esteja preenchido
			if(checa_x == num){ //Caso todos os espaços estejam preenchidos
				puts("Vitoria na Diagonal!");
				return 1; //vitoria
			}
		} else if(tab[i][j] == 'O'){
			checa_o++;    //Aumenta caso o espaço esteja preenchido
			if(checa_o == num){ //Caso todos os espaços estejam preenchidos
				puts("Vitoria na Diagonal!");
				return 1; //vitoria
			}
		}
		j--;
	}
	//chamando outras checagens
		//checagem da diagonal curva
		if(checa_vitoria_curva(tab,num) == 1){
			puts("Vitoria na Diagonal curva");
			return 1; //vitoria
		}

		//checagem da diagonais menores que convergem para o meio.
		if(num % 2 != 0){ //essa checagem só vale para tabuleiros de tamanho ímpar, pois possuem uma posição central.
			if(checa_vitoria_meio(tab, num) == 1){
				puts("Vitoria na Diagonal convergindo para o meio!");
				return 1; //vitoria
				}
			}
	return 0; //Sem vitoria
}

//##################################################################################################

/*
Descrição: Função responsável por gerar as jogadas do computador, que serão aleatórias.
Entrada:   Tamanho do tabuleiro
Saída: 	   Algum número aleatório entre 0 e (num-1).
*/

int gera_numero(int num, int vezes){
	//dicionario de dados
	int indice; //indice que será retornado para a variavel
	int i;		//Auxiliar do for
	//corpo:
	//inicializa o gerador de números pseudo-aleatorios
	srand(time(NULL));

	//Gera número inteiro entra 0 e Num.
	for(i = 0; i < vezes; i++) //for para evitar repetições de números
		indice = rand() % num;
	return indice;
}

//##################################################################################################

/*
Descrição: Função para organizar a chamada da(s): jogadas, checagens de vitoria e impressão do tabuleiro.
Entrada:   recebe o tabuleiro.
Saída:     retorna caso alguém vença.
*/

int org_jogadas(char tab[][N], int num){
	//dicionario de dados
	int i,j; 		//Indices para percorrer a matriz e afins.
	int checa;  	//Variavel apenas para checar a veracidade da jogada.
	int jogadas;	//Variavel que conta jogadas
	int jogadores; 	//Quantidade de jogadores
	//corpo:
	//perguntando quantos jogadores jogarão
	do {
		puts("Um ou dois jogadores humanos?");
		scanf("%d", &jogadores);
	} while(jogadores < 1 || jogadores > 2);

	//Saudações
	puts("Bom jogo! Divirta-se!");
	//Imprimindo o tabuleiro
	tabuleiro(tab, num);
	//recebendo jogadas
	for(jogadas = 0;jogadas < (num * num);){
		//recebendo a jogada do jogador X
		do{
			checa = 0; 	//Começa como falso naturalmente.
			printf("Jogador X, em que indice(i, j) deseja jogar? ");
			scanf("%d %d", &i, &j);
			
			//checando se a posição está disponivel.
			if(checa_jogada(tab,num,i,j,1) == 1){
				tab[i][j] = 'X';
				checa = 1;
				jogadas++;
			} else {
				puts("Jogue novamente.");
				} 
		} while(checa != 1);

		//Imprimindo o tabuleiro
		tabuleiro(tab, num);

		if(jogadas >= (num*2) - 1){ //número minimo de jogadas para que alguém possa ganhar
			if(checa_vitoria(tab,num) == 1){
				puts("Jogador X Ganhou!");
				return 0;
				}
			}
		if(jogadores == 2){
			//recebendo a jogada do jogador O
			do{
				checa = 0; 	//Começa como falso naturalmente.
				printf("Jogador O, em que indice(i, j) deseja jogar? ");
				scanf("%d %d", &i, &j);
				//checando se a posição está disponivel.
				if(checa_jogada(tab,num,i,j,1) == 1){
					tab[i][j] = 'O';
					checa = 1;
					jogadas++;
				} else {
					puts("Jogue novamente.");
					} 
			} while(checa != 1);
			
			//Imprimindo o tabuleiro
			tabuleiro(tab, num);

			if(jogadas >= (num*2) - 1){ //número minimo de jogadas para que alguém possa ganhar
				if(checa_vitoria(tab,num) == 1){
					puts("Jogador O Ganhou!");
					return 0;
					}
				}
			} else { //jogada do Computador
				do{
					checa = 0; 	//Começa como falso naturalmente.
					i = gera_numero(num,1);
					j = gera_numero(num,2);
					//checando se a posição está disponivel.
					if(checa_jogada(tab,num,i,j,0) == 1){
						tab[i][j] = 'O';
						checa = 1;
						jogadas++;
						}
				} while(checa != 1);
				printf("Jogada do Computador na [%d][%d]\n", i,j);
				//Imprimindo o tabuleiro
				tabuleiro(tab, num);

				if(jogadas >= (num*2) - 1){ //número minimo de jogadas para que alguém possa ganhar
					if(checa_vitoria(tab,num) == 1){
						puts("Computador Ganhou!");
						return 0;
						}
					}
				}
		} //fim do for de jogadas.
	
	//Se passar pelo for, então ninguém ganhou.
	puts("Deu Velha! Nenhum dos jogadores ganhou!");
	return 0;
}

//##################################################################################################

/*
Descrição: Jogo da Velha extendido, com tamanho minimo de 4x4, e maximo de 9x9. Organiza o inicio de todo o jogo.
Entrada:   Tamanho do tabuleiro.
Saida: 	   O jogo em sí.
*/

int main(void){
	//dicionario de dados
	char tab[10][10];	//Matriz do tabuleiro.
	int num;	 	 	//Número do tamanho do tabuleiro.
	int i,j;			//Indices para varrer a matriz.
	int novamente;		//Checagem para jogar novamente.
	//corpo:
	do{
		//Recebendo o tamanho do tabuleiro.
		do {
			puts("Jogador, qual o Tamanho do Tabuleiro desejado?(Sendo 3 < n < 10)");
			scanf("%d", &num);
			if(num <= 3 || num >= 10)
				puts("Tamanho do Tabuleiro inválido!");
			} while(num <= 3 || num >= 10);

		//Deixando a matriz preenchida com espaços.
		for(i = 0; i < num; i++)
			for(j = 0; j < num; j++)
				tab[i][j] = ' ';

		//Chamando a função desencadeando o inicio do jogo.
		org_jogadas(tab,num);

		//Verificando se o jogador que jogar novamente.
		puts("Deseja jogar novamente?(sim = 1; não = 0)");
		scanf("%d", &novamente);
		} while(novamente == 1);
	//Agradecendo 
	puts("Obrigado por jogar!");
	return 0;
}

//##################################################################################################
