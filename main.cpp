#include "Converter_binario.h"
#include "Monobit.h"
#include "LongTest.h"
#include "PokerTest.h"
#include "RunTest.h"


static char vet[5002][20];
static char ver[5002];
int vetbin[40016];

// na tabela ascii 39 == '

/** a função abaixo copia uma linha especifica num vetor de mesmo tamanho, a função disso é verificar
 * se os calculos estão ok
 */
void copia_vetor(int n){
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

// quando retorna 1 quer dizer que esta certo
int main() {
    populaV();

    for (int i = 0; i < 20; i++) {
        cout << "teste para a linha: " << i << endl;
        copia_vetor(i);
        Converter_binario a;
        a.recebe(ver, vetbin);
        Monobit b;
        if (b.teste(vetbin) == 1) {
            cout << "MonobitTest: Aprovado" << endl;
        } else {
            cout << "MonobitTest: Reprovado" << endl;
        }
        LongTest t;
        if (t.longo(vetbin) == 1) {
            cout << "LongTest: Aprovado" << endl;
        } else {
            cout << "LongTest: Reprovado" << endl;

        }
        PokerTest c;
        if (c.poker(vetbin) == 1) {
            cout << "PokerTest: Aprovado" << endl;
        } else {
            cout << "PokerTest: Reprovado" << endl;
        }
        RunTest d;
        if (d.run(vetbin) == 1) {
            cout << "RunTest: Aprovado" << endl;
        } else {
            cout << "RunTest: Reprovado" << endl;
        }
puts("");
    }
    return 0;
}
