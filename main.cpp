#include "Converter_binario.h"
#include "Monobit.h"
#include "LongTest.h"

static char vet[5002][20];
static char ver[5002];
int vetbin[40016];

// na tabela ascii 39 == '

/** a função abaixo copia uma linha especifica num vetor de mesmo tamanho, a função disso é verificar
 * se os calculos estão ok
 */
void copia_vetor(int n){
    int c = 0; // contador
    for (int i = 0; (i < 5002)  ; i++) {
        ver[i] = vet[i+1][n];
        if(ver[i] == 39){
            ver[i] = 0;
        }
    }
}
/**
 * A função abaixo popula a matriz de forma precisa
 */
void populaV(){
    FILE *arq;
    int c = 0; // é um contador para saber quantas aspas ja foram
    arq = fopen("Chaves de Criptografia.txt", "r");
    int i = 0, j = 0;
    for (i ; (i < 5002) && (j < 20); i++) {
            fscanf(arq, "%c", &vet[i][j]);
            //fread(&vet[i][j], sizeof(char), 5002,arq);
            if(j == 2){
                //cout<<"valor de i = "<<i<<"\n"<<"vetor = "<<vet[i][j]<<endl;
                if(i > 0){
                    vet[i-1][j] = vet[i][j];
                }
            }

            if(vet[i][j] == 39){
                c++;
            }
            if(c == 2){
               j++;
               i = -2;
               c = 0;
            }
    }
    fclose(arq);
}

void teste(){
    FILE *arq;
    int c = 0; // é um contador para saber quantas aspas ja foram
    arq = fopen("Chaves de Criptografia.txt", "r");
    int i = 0, j = 0;
    for (i = 0; (i < 5002) ; i++) {
        fscanf(arq, "%c", &ver[i]);
        //cout<<ver[i]<<endl;
    }
    fclose(arq);
}

void escreve(){
    FILE *arq;
    arq = fopen("Chaves.txt", "w");
    fprintf(arq,"oi");
    fclose(arq);
}

void imprime(){
        //cout<<vet[0]<<endl;
        cout<<ver<<endl;
}

// quando retorna 1 quer dizer que esta certo
int main() {
    //teste();
    populaV();
    copia_vetor(0);
    Converter_binario a;
    a.recebe(ver,vetbin);
    Monobit b;
    cout<<b.teste(vetbin)<<endl;
    LongTest t;
    cout<<t.longo(vetbin)<<endl;
    return 0;
}
