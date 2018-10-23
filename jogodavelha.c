#include <stdio.h>
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

		
}

//##################################################################################################
/*
Descrição: Checa se a jogada é regular
Entrada:   Tabuleiro, tamanho do tabuleiro, e indices jogados
Saida: 	   Retorna 0 para falso, 1 para verdadeiro
*/

int checa_jogada(char tab[][N],int num, int i, int j){
	//corpo:
		//checa se a possição existe dentro do tabuleiro.
	//Caso qualquer um dos indices forem maiores que o tamanho do tabuleiro ou menores que 0, eles não existem.
	if(i < 0 || i >= num){
		printf("Indice inválido! ");
		return 0;	//0 = Jogada Reprovada!
		}
	if(j < 0 || j >= num){
		printf("Indice inválido! ");
		return 0;	//0 = Jogada Reprovada!
		}
		//checa se essa posição está "vazia".
	if(tab[i][j] == ' '){
		puts("Boa jogada!");
		return 1;	//1 = Jogada Aprovada!
	} else if(tab[i][j] == 'X') {
		printf("O 'X' já ocupa a posição! ");
		return 0;	//0 = Jogada Reprovada!
	} else if(tab[i][j] == 'O') {
		printf("O 'O' já ocupa a posição! ");
		return 0;	//0 = Jogada Reprovada!
	}
	return 0;
}
//##################################################################################################

/*
Descrição: Checa de acordo com o tabuleiro, se algum dos jogadores ganhou.
Entrada:   Tabuleiro, e tamanho do tabuleiro
Saida:	   retorna 1 caso haja algum vencedor, ou 0, caso o contrário.
*/

int checa_vitoria(char tab[][N], int num){
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
				checa_x++;
				if(checa_x == num){
					return 1; //vitoria
				}
			} else if(tab [i][j] == 'O'){
				checa_o++;
				if(checa_o == num){
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
				checa_x++;
				if(checa_x == num){
					return 1; //vitoria
				}
			} else if(tab [i][j] == 'O'){
				checa_o++;
				if(checa_o == num){
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
			checa_x++;
			if(checa_x == num){
				return 1; //vitoria
			}
		} else if(tab [i][j] == 'O'){
			checa_o++;
			if(checa_o == num){
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
			checa_x++;
			if(checa_x == num){
				return 1; //vitoria
			}
		} else if(tab [i][j] == 'O'){
			checa_o++;
			if(checa_o == num){
				return 1; //vitoria
			}
		}
		j--;
	}

	//checa diagonal curva superior
	j = 1;
	checa_x = 0; //Sempre zerando os checa, para não acumular as checagens.
	checa_o = 0; //idem
	for(i = 0; i < num; i++){
		if(tab[i][j] == 'X'){
			checa_x++;
			if(checa_x == num){
				return 1; //vitoria
			}
		} else if(tab [i][j] == 'O'){
			checa_o++;
			if(checa_o == num){
				return 1; //vitoria
			}
		}
		if(j != num-1){
			j++;
		} else {
			j--;
		}
	}
	//checa diagonais menores que convergem para o meio
	if(num % 2 != 0){
		i = ((num-1)/2);
		for(j = 0; j < num;  j++){
			if(tab[i][j] == 'X'){
				checa_x++;
				if(checa_x == num){
					return 1; //vitoria
				}
			} else if(tab [i][j] == 'O'){
				checa_o++;
				if(checa_o == num){
					return 1; //vitoria
				}
			}
			if(j <= ((num-1)/2)){
				i++;
			} else {
				i--;
			}
		}
	}
	return 0; //Sem vitoria	
}
//##################################################################################################

/*
Descrição: Recebe as jogadas dos jogadores.
Entrada:   recebe o tabuleiro.
Saída:     retorna caso alguém vença.
*/

int org_jogadas(char tab[][N], int num){
	//dicionario de dados
	int i,j; 	//Indices para percorrer a matriz e afins.
	int checa;  //Variavel apenas para checar a veracidade da jogada.
	int jogadas;//Variavel que conta jogadas
	int jogadores; //Quantidade de jogadores
	//corpo:
	//perguntando quantos jogadores jogarão
	do {
		puts("Quantos jogares jogarão?");
		scanf("%d", &jogadores);
	} while(jogadores < 1 || jogadores > 2);
	//Imprimindo o tabuleiro
	tabuleiro(tab, num);
	//recebendo jogadas
	for(jogadas = 0;jogadas <= (num * num);){
		//recebendo a jogada do jogador X
		do{
			checa = 0; 	//Começa como falso naturalmente.
			printf("Jogador X, em que indice(i, j) deseja jogar? ");
			scanf("%d %d", &i, &j);
			
			//checando se a posição está disponivel.
			if(checa_jogada(tab,num,i,j) == 1){
				tab[i][j] = 'X';
				checa = 1;
				jogadas++;
			} else {
				puts("Jogue novamente.");
				} 
		} while(checa != 1);

		//Imprimindo o tabuleiro
		tabuleiro(tab, num);

		if(checa_vitoria(tab,num) == 1){
			puts("Jogador X Ganhou!");
			return 0;
		}
		if(jogadores == 2){
		//recebendo a jogada do jogador O
		do{
			checa = 0; 	//Começa como falso naturalmente.
			printf("Jogador O, em que indice(i, j) deseja jogar? ");
			scanf("%d %d", &i, &j);
			//checando se a posição está disponivel.
			if(checa_jogada(tab,num,i,j) == 1){
				tab[i][j] = 'O';
				checa = 1;
				jogadas++;
			} else {
				puts("Jogue novamente.");
				} 
		} while(checa != 1);
		
		//Imprimindo o tabuleiro
		tabuleiro(tab, num);

		if(checa_vitoria(tab,num) == 1){
			puts("Jogador O Ganhou!");
			return 0;
			}
		}
	}
	return 0;
}

//##################j) deseja j############################################################################

/*
Descrição: Função main, apenas para chamar todas as funções necessárias.
*/

int main(void){
	//dicionario de dados
	char tab[10][10];	//Matriz do tabuleiro.
	int num;	 	 	//Número do tamanho do tabuleiro.
	int i,j;			//Indices para varrer a matriz.
	
	//corpo:
		//Recebendo o tamanho do tabuleiro.
	do {
		printf("Jogador, qual o Tamanho do Tabuleiro desejado?(Sendo 3 < n < 10) ");
		scanf("%d", &num);
		if(num <= 3 || num >= 10)
			puts("Tamanho do Tabuleiro inválido!");
		puts(""); 			//pulando linha.
		} while(num <= 3 || num >= 10);

		//Deixando a matriz preenchida com espaços.
	for(i = 0; i < num; i++)
		for(j = 0; j < num; j++)
			tab[i][j] = ' ';
	
		//Chamando a função que desencadeia o inicio do jogo.
	org_jogadas(tab,num);

	return 0;
}

//##################################################################################################
