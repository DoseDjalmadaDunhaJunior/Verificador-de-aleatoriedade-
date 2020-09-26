//
// Created by jose on 25/09/2020.
//

#ifndef CHAVE_CPP_RUNTEST_H
#define CHAVE_CPP_RUNTEST_H
#include <iostream>
using namespace std;

class RunTest {
public:
    void run(int* vetbit){
        copia(vetbit);
    }
private:

    void contaUm(){
        int anterior = 0;
        int c = 0;
        for (int i = 0; i < 40016; i++) {
            if((vet[i] == 1) && (anterior == 0)){
                c++;
            }
        }
    }

    void contaZero(){
        int anterior = 0;
        for (int i = 0; i < 40016; i++) {

        }
    }


    void copia(int* vetor){
        for (int i = 0; i < 40016; i++) {
            vet[i] = vetor[i];
        }
    }
    int cont1 = 0; // tem que ter só 1
    int dist1 = 0; // distancia para numero 1
    int cont2 = 0; // tem que ter só 2
    int dist2 = 0; // distancia para numero 2
    int cont3 = 0; // tem que ter só 3
    int dist3 = 0; // distancia para numero 3
    int cont4 = 0; // tem que ter só 4
    int dist4 = 0; // distancia para numero 4
    int cont5 = 0; // tem que ter só 5
    int dist5 = 0; // distancia para numero 5
    int cont6 = 0; // tem que ter 6 ou +
    int dist6 = 0; // distancia para numero 6 ou +
    int vet[40016];
};


#endif //CHAVE_CPP_RUNTEST_H
