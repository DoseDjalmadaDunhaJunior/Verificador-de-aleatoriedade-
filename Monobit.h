//
// Created by jose on 24/09/2020.
//

#ifndef CHAVE_CPP_MONOBIT_H
#define CHAVE_CPP_MONOBIT_H
#include <iostream>
using namespace std;
class Monobit {
public:
    //se tiver mais de 9654 e menos de 10346 numeros 1 ta ok
    int teste(int* vet) {
        int n = conta(vet);
        if((n > 9654) && (n < 10346)){
            return 1;
        }
        return 0;
    }

private:
    int conta(int* vet){
        int c = 0;
        for (int i = 0; i < 40016; i++) {
            if(vet[i] == 1){
                c++;
            }
        }
        return c;
    }

};


#endif //CHAVE_CPP_MONOBIT_H
