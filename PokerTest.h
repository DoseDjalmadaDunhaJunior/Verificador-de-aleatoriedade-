//
// Created by jose on 25/09/2020.
//

#ifndef CHAVE_CPP_POKERTEST_H
#define CHAVE_CPP_POKERTEST_H
#include <iostream>
using namespace std;

/**
 * Divida o fluxo de 20.000 bits em 5.000 segmentos consecutivos de 4 bits
 * Conte e armazene o número de ocorrências dos 16 valores de 4 bits possíveis. Denote f (i)
 * como o número de cada valor de 4 bits i, onde 0 ≤ i ≤ 15.
 */

class PokerTest {
public:
    int poker(int* vetor){
       copia(vetor);
       int c = 0;
        for (int i = 0; i < 5000; i+=4) {
            populaAnao(i);
            contaUm(c);
            c++;
        }
        return contaRepeticao();
    }

private:

    void copia(int* vetor){
        for (int i = 0; i < 40016; i++) {
            vetbit[i] = vetor[i];
        }
    }

    //po = posição
    void populaAnao(int po){
        for (int i = 0; i < 4; i++) {
            minivet[i] = 0;
            minivet[i] = vetbit[po];
            po++;
        }
    }

    //ele conta a quantidade de 1 dos conjuntos de 4 bites e coloca o resultado num vetor
    void contaUm(int po){
        int c = 0;
        for (int i = 0; i < 4; i++) {
            if(minivet[i] == 1){
                c++;
            }
        }
        contUm[po] = c;
    }

    // aqui ele conta se ha alguma repetição
    int contaRepeticao(){
        int c = 0;
        for (int i = 0; i < 5000; i++) {
            for (int j = 0; j < 5000; j++) {
                if(contUm[i] == contUm[j]){
                    c++;
                }
                if(c > 15){
                    return 0;
                }
            }
            c = 0;
        }
        return 1;
    }

    int contUm[5000];
    int vetbit[40016];
    int minivet[5];
};


#endif //CHAVE_CPP_POKERTEST_H
