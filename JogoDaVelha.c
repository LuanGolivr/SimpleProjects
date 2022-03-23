#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int inicialMenu();
int game();
int tagGame();
void printGame();
int getCordenates();
bool verification();
int assignCoordinates();
bool winner();

int main (){
    int playAgain = 0;
    do 
    {
        printf("Bem vindo ao Jogo Da Velha  !!!!\n");
        inicialMenu();
        printf("Fim de jogo!!\nDeseja jogar mais uma vez ??\n");
        printf("0 - Jogar Novamente\n1 - Finalizar jogo\n");
        scanf("%d", &playAgain);
    } while(!playAgain);

    system("CLS");
    return 0;
}

int inicialMenu(){
    
    int decision;
    do
    {
        printf("Escolha uma das opcoes abaixo: \n");
        printf("1 - Comecar o jogo:\n2 - Sair do jogo!!\n\n");
        scanf("%d", &decision);
    } while (decision <= 0 || decision > 2);

    if (decision == 1 ){
        game(decision);
    }

    return 0;
}

int game(int decision){
    int jogoDaVelha [3][3];
    int i;
    int j;

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            jogoDaVelha[i][j] = 5;
        }
    }

    int player1 = 1;
    int player2 = 0;

    tagGame(jogoDaVelha, player1, player2);
    printGame(jogoDaVelha);
    
    return 0;
}

int tagGame(int jogoDaVelha[3][3], int player1, int player2){
    int coordenatesX;
    int coordenatesY;
    int numberOfElements = 0;
    bool endGame = false;
    bool situation = false;
    system("CLS");

    while (!endGame){
        do {
            printGame(jogoDaVelha);
            coordenatesX = getCordenates();
            coordenatesY = getCordenates();
            situation = verification(player1 , (coordenatesX-1), (coordenatesY-1) , jogoDaVelha);
        }while(!situation);

        endGame = winner(player1, jogoDaVelha);
        if (endGame){
            break;
        }

        numberOfElements = numberOfElements + 1;
        if (numberOfElements == 9){
            endGame = true;
            break;
        }
        system("CLS");

        do {
            printGame(jogoDaVelha);
            coordenatesX = getCordenates();
            coordenatesY = getCordenates();
            situation = verification(player2 ,(coordenatesX-1), (coordenatesY-1) , jogoDaVelha);
        }while(!situation);
        endGame = winner(player2, jogoDaVelha);
        numberOfElements = numberOfElements + 1;
        if (numberOfElements == 9){
            endGame = true;
        }
        system("CLS");
    }

    return 0;
}

void printGame(int jogoDaVelha[3][3]){
    printf("    1    2    3\n");
    int i;
    int j;

    for (i = 0; i < 3; i++){
        printf("%d ", i+1);
        for (j = 0; j < 3; j++){
            if (jogoDaVelha[i][j] == 1){
                printf("  X  ");
            }
            else if (jogoDaVelha[i][j] == 0){
                printf("  O  ");
            }
            else
            {
                printf("     ");
            }
        }
        printf("\n\n");
    }
}

int getCordenates(){
    int coordenada;
    
    do {
        printf("\nEscolha a cordenada : \n");
        scanf("%d", &coordenada);
    } while (1 > coordenada  || coordenada > 3);

    return coordenada;
}

bool verification (int player, int coordenateX, int coordenateY, int jogoDaVelha[3][3]){
    bool result = false;
    if (jogoDaVelha[coordenateX][coordenateY] != 0 && jogoDaVelha[coordenateX][coordenateY] != 1){
        result = true;
        assignCoordinates(player, coordenateX, coordenateY, jogoDaVelha);
    }
    else {
        printf("Coordenada invalida\n");
    }

    return result;
}

int assignCoordinates(int player, int coordenatesX, int coordenatesY, int jogoDaVelha[3][3]){
    jogoDaVelha[coordenatesX][coordenatesY] = player;
    return 0;
}

bool winner(int player, int jogoDaVelha[3][3]){
    int countLine;
    int countColumn;
    int i;
    int j;

    for (i = 0; i < 3; i++){
        countLine = 0;
        countColumn = 0;
        for (j = 0; j < 3; j++){
            if (jogoDaVelha[i][j] == player){
                countLine = countLine + 1;
            }

            if (jogoDaVelha[j][i] == player){
                countColumn = countColumn + 1;
            }
        }
        if (countLine == 3 || countColumn == 3){
            return true;
        }
    }


    if (player == jogoDaVelha[0][0] && player == jogoDaVelha[1][1] && player== jogoDaVelha[2][2]){
        return true;
    }

    if (player == jogoDaVelha[0][2] && player == jogoDaVelha[1][1] && player == jogoDaVelha[2][0]){
        return true;
    }

    return false;
}

