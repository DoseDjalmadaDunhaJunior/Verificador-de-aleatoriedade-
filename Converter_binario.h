//
// Created by jose on 23/09/2020.
//

#ifndef CHAVE_C_CONVERTER_BINARIO_H
#define CHAVE_C_CONVERTER_BINARIO_H
#include <iostream>
using namespace std;

class Converter_binario {
public:

    void recebe(char* vetor, int* vet) {
        populadecimal(vetor);
        convertebinario(vetor);

        for (int i = 0; i < 40016; i++) {
            vet[i] = vetbin[i];
        }
    }


private:
    // a função abaixo converte o vetor char num correspondente ao caractere na tabela acii
    void populadecimal(char* vetor){
        int oi;
        for (int i = 0; vetor[i] != 0 ; i++) {;
            oi = vetor[i];
            vet1[i] = oi;
        }
    }

    //aqui converte cada decimal em binario
    void binario(int num, int* bin){
        if(num > 254){
            bin[0] = 1;
            num = num - 255;
        }
        else{
            bin[0] = 0;
        }
        if(num > 127){
            bin[1] = 1;
            num = num - 128;
        }else{
            bin[1] = 0;
        }
        if(num > 63){
            bin[2] = 1;
            num = num - 64;
        }
        else{
            bin[2] = 0;
        }
        if(num > 31){
            bin[3] = 1;
            num = num - 32;
        }
        else{
            bin[3] = 0;
        }
        if(num > 15){
            bin[4] = 1;
            num = num - 16;
        }
        else{
            bin[4] = 0;
        }
        if(num > 7){
            bin[5] = 1;
            num = num - 8;
        }
        else{
            bin[5] = 0;
        }
        if(num > 3){
            bin[6] = 1;
            num = num - 4;
        }
        else{
            bin[6] = 0;
        }
        if(num > 1){
            bin[7] = 1;
            num = num - 2;
        }
        else{
            bin[7] = 0;
        }
        if(num == 1){
            bin[8] = 1;
        }
        else{
            bin[8] = 0;
        }

    }

    //ele esta andando corretamente para transformar os numeros em binario e salva no vetor vetbin
    void convertebinario(char* vetor) {
        int bin[9];
        int i = 0;
        for (i = 0; vetor[i] != 0; i++) {
            binario(vet1[i], bin);
            if (i == 0) {
                for (int j = 0; j < 9; j++) {
                    vetbin[j] = bin[j];
                }
            } else {
                int j = 0;
                for (j = 0; j < 9; j++) {
                    vetbin[(i*9) + j] = bin[j];
                }
            }
        }
    }

    int vetbin[40016];

    int vet1[5002];
};


#endif //CHAVE_C_CONVERTER_BINARIO_H
