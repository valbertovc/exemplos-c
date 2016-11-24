/*
 * Este código é uma tradução do jogo batalha naval da linguagem Java para a Linguagem C.
 * Fonte: http://www.javaprogressivo.net/2012/09/jogo-batalha-naval-em-java.html
 *
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

// Configuração do jogo.
const int LINHAS = 25;                 // Linhas do tabuleiro
const int COLUNAS = 25;                // Colunas do tabuleiro
const int NUM_NAVIOS = 3;              // Número de navios
const int COORD_NAVIOS = 2;            // Coordenadas (x,y) do navio (ponto no tabuleiro)
const char SIMBOLO_AGUA = '?';         // Símbolo inicial do tabuleiro (água)
const char SIMBOLO_TIRO_ERRADO = 'x';  // Símboro que representa o tiro errado
const char SIMBOLO_TIRO_CERTO = 'N';   // Símbolo que representa o tiro no navio (certo)
const int VALOR_INICIAL = -1;          // Valor inicial de cada elemento do tabuleiro (água)
const int VALOR_TIRO_ERRADO = 0;       // Valor preenchido no local do tiro errado
const int VALOR_TIRO_CERTO = 1;        // Valor preenchido no local do tiro certo


/*
 * Preenche o tabuleiro inteiro com o valor inicial
 */
void inicializaTabuleiro(int (&tabuleiro)[LINHAS][COLUNAS]) {
    for(int linha=0; linha<LINHAS; linha++)
        for(int coluna=0; coluna<COLUNAS; coluna++)
            tabuleiro[linha][coluna]=VALOR_INICIAL;
}

/*
 * Exibe o tabuleiro com os valores atuais das jogadas.
 */
void mostraTabuleiro(int (&tabuleiro)[LINHAS][COLUNAS]) {

    //Cabeçalho
    cout << "" << endl;
    cout << setw(3) << "   ";
    for(int coluna=0; coluna<COLUNAS; coluna++){
        cout << setw(3) << coluna+1;
    }
    cout << "" << endl;
    cout << "" << endl;

    //Conteúdo
    for(int linha=0; linha<LINHAS; linha++){
        cout << setw(3) << linha+1;
        for(int coluna=0 ; coluna < COLUNAS ; coluna++ ){
            if(tabuleiro[linha][coluna]==VALOR_INICIAL){
                cout << setw(3) << SIMBOLO_AGUA;
            }else if(tabuleiro[linha][coluna]==VALOR_TIRO_ERRADO){
                cout << setw(3) << SIMBOLO_TIRO_ERRADO;
            }else if(tabuleiro[linha][coluna]==VALOR_TIRO_CERTO){
                cout << setw(3) << SIMBOLO_TIRO_CERTO;
            }
        }
        cout << "" << endl;
    }
}


/*
 * Função utilitária para gerar um número randômico dentro de um intervalo.
 */
int random(int min, int max) {
   static bool first = true;
   if ( first ) {
      srand(time(NULL));
      first = false;
   }
   return min + rand() % (max - min);
}

/*
 * Inicia os navios em posições aleatórias.
 */
void iniciaNavios(int (&navios)[NUM_NAVIOS][COORD_NAVIOS]) {
    for(int navio=0 ; navio < NUM_NAVIOS ; navio++){
        navios[navio][0]=random(0,LINHAS);
        navios[navio][1]=random(0,COLUNAS);

        //agora vamos checar se esse par não foi sorteado
        //se foi, so sai do do...while enquanto sortear um diferente
        for(int anterior=0 ; anterior < navio ; anterior++){
            if( (navios[navio][0] == navios[anterior][0])&&(navios[navio][1] == navios[anterior][1]) )
                do{
                    navios[navio][0]=random(0,LINHAS);
                    navios[navio][1]=random(0,COLUNAS);
                }while( (navios[navio][0] == navios[anterior][0])&&(navios[navio][1] == navios[anterior][1]) );
        }

    }
}

void darTiro(int tiro[]){
    int entrada;
    cout << "\nLinha: ";
    std::cin >> entrada;
    tiro[0] = entrada;
    tiro[0]--;

    cout << "Coluna: ";
    std::cin >> entrada;
    tiro[1] = entrada;
    tiro[1]--;
}

/*
 * Verifica se o tiro acertou algum navio.
 */
bool acertou(int tiro[], int (&navios)[NUM_NAVIOS][COORD_NAVIOS]){
    for(int navio=0 ; navio<NUM_NAVIOS ; navio++){
        if( tiro[0]==navios[navio][0] && tiro[1]==navios[navio][1]){
            return true;
        }
    }
    return false;
}

/*
 * Exibe dica: número de tentativas e último tiro.
 */
void dica(int tiro[], int (&navios)[NUM_NAVIOS][COORD_NAVIOS], int tentativa){
    int linha=0, coluna=0;
    for(int fila=0 ; fila < 3 ; fila++){
        if(navios[fila][0]==tiro[0])
            linha++;
        if(navios[fila][1]==tiro[1])
            coluna++;
    }
    cout << "\n" << tentativa << " Tentativas. Ultimo tiro: "
        << tiro[0]+1 << ", " << tiro[1]+1 << endl;

}

/*
 * Exibe o tabuleiro para o programador.
 */
void mostraTabuleiroProgramador(int (&navios)[NUM_NAVIOS][COORD_NAVIOS], int (&tabuleiro)[LINHAS][COLUNAS]) {

    //Cabeçalho
    cout << "" << endl;
    cout << setw(3) << "   ";
    for(int coluna=0; coluna<COLUNAS; coluna++){
        cout << setw(3) << coluna+1;
    }
    cout << "" << endl;
    cout << "" << endl;

    //Conteúdo
    for(int linha=0; linha<LINHAS; linha++){
        cout << setw(3) << linha+1;
        for(int coluna=0 ; coluna < COLUNAS ; coluna++ ){
            int coord_atual[2] = {linha, coluna};
            if (acertou(coord_atual, navios)) {
              cout << setw(3) << 'N';
            } else {
              cout << setw(3) << '-';
            }
        }
        cout << "" << endl;
    }
}

/*
 * Altera o tabuleiro com o valor do tiro.
 */
void alteraTabuleiro(int tiro[], int (&navios)[NUM_NAVIOS][COORD_NAVIOS], int (&tabuleiro)[LINHAS][COLUNAS]){
    if(acertou(tiro,navios))
        tabuleiro[tiro[0]][tiro[1]]=VALOR_TIRO_CERTO;
    else
        tabuleiro[tiro[0]][tiro[1]]=VALOR_TIRO_ERRADO;
}

/*
 * Função principal do jogo.
 */
int main() {
    int tabuleiro[LINHAS][COLUNAS];
    int navios[NUM_NAVIOS][COORD_NAVIOS];
    int tiro[2];
    int tentativas=0, acertos=0;

    inicializaTabuleiro(tabuleiro);
    iniciaNavios(navios);

    cout << "" << endl;

    do {
        mostraTabuleiroProgramador(navios, tabuleiro);
        mostraTabuleiro(tabuleiro);
        darTiro(tiro);
        tentativas++;

        if(acertou(tiro,navios)) {
            cout << "\nVocê acertou o tiro(" << tiro[0]+1 << ", " << tiro[1]+1 << ")\n";
            acertos++;
        }
        dica(tiro,navios,tentativas);
        alteraTabuleiro(tiro,navios,tabuleiro);
    } while(acertos!=NUM_NAVIOS);

    cout << "\n\n\nJogo terminado. Você acertou os 3 navios em " << tentativas << " tentativas\n\n\n";
    mostraTabuleiro(tabuleiro);
    return 1;
}

/*

public static void inicializaTabuleiro(int[][] tabuleiro){
        for(int linha=0 ; linha < 5 ; linha++ )
            for(int coluna=0 ; coluna < 5 ; coluna++ )
                tabuleiro[linha][coluna]=-1;
    }

public static void mostraTabuleiro(int[][] tabuleiro){
    System.out.println("\t1 \t2 \t3 \t4 \t5");
    System.out.println();

    for(int linha=0 ; linha < 5 ; linha++ ){
        System.out.print((linha+1)+"");
        for(int coluna=0 ; coluna < 5 ; coluna++ ){
            if(tabuleiro[linha][coluna]==-1){
                System.out.print("\t"+"~");
            }else if(tabuleiro[linha][coluna]==0){
                System.out.print("\t"+"*");
            }else if(tabuleiro[linha][coluna]==1){
                System.out.print("\t"+"X");
            }

        }
        System.out.println();
    }

}

public static void iniciaNavios(int[][] navios){
    Random sorteio = new Random();

    for(int navio=0 ; navio < 3 ; navio++){
        navios[navio][0]=sorteio.nextInt(5);
        navios[navio][1]=sorteio.nextInt(5);

        //agora vamos checar se esse par não foi sorteado
        //se foi, so sai do do...while enquanto sortear um diferente
        for(int anterior=0 ; anterior < navio ; anterior++){
            if( (navios[navio][0] == navios[anterior][0])&&(navios[navio][1] == navios[anterior][1]) )
                do{
                    navios[navio][0]=sorteio.nextInt(5);
                    navios[navio][1]=sorteio.nextInt(5);
                }while( (navios[navio][0] == navios[anterior][0])&&(navios[navio][1] == navios[anterior][1]) );
        }

    }
}

public static void darTiro(int[] tiro){
    Scanner entrada = new Scanner(System.in);

    System.out.print("Linha: ");
    tiro[0] = entrada.nextInt();
    tiro[0]--;

    System.out.print("Coluna: ");
    tiro[1] = entrada.nextInt();
    tiro[1]--;

}

public static boolean acertou(int[] tiro, int[][] navios){
    for(int navio=0 ; navio<navios.length ; navio++){
        if( tiro[0]==navios[navio][0] && tiro[1]==navios[navio][1]){
            System.out.printf("Você acertou o tiro (%d,%d)\n",tiro[0]+1,tiro[1]+1);
            return true;
        }
    }
    return false;
}

public static void dica(int[] tiro, int[][] navios, int tentativa){
    int linha=0, coluna=0;
    for(int fila=0 ; fila < navios.length ; fila++){
        if(navios[fila][0]==tiro[0])
            linha++;
        if(navios[fila][1]==tiro[1])
            coluna++;
    }
    System.out.printf("\nDica %d: \nlinha %d -> %d navios\n" +
                             "coluna %d -> %d navios\n",tentativa,tiro[0]+1,linha,tiro[1]+1,coluna);
}

public static void alteraTabuleiro(int[] tiro, int[][] navios, int[][] tabuleiro){
    if(acertou(tiro,navios))
        tabuleiro[tiro[0]][tiro[1]]=1;
    else
        tabuleiro[tiro[0]][tiro[1]]=0;
}
*/
