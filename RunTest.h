//
// Created by jose on 25/09/2020.
//

#ifndef CHAVE_CPP_RUNTEST_H
#define CHAVE_CPP_RUNTEST_H

/**
 * Uma corrida é definida como uma sequência máxima de bits consecutivos de todos ou zeros,
 * que faz parte do fluxo de amostra de 20.000 bits.
 * As incidências de execuções (para zeros consecutivos e consecutivos)
 * de todos os comprimentos (> = 1) no fluxo de amostra devem ser contadas e armazenadas.

 O teste é aprovado se
 o número de execuções ocorridas (de comprimentos de 1 a 6) estiver dentro do intervalo correspondente especificado abaixo.
 Isso deve valer para zeros e uns; ou seja, todas as 12 contagens devem estar no intervalo especificado.

 O teste é aprovado se
 o número de execuções ocorridas (de comprimentos de 1 a 6) estiver dentro do intervalo correspondente especificado abaixo.
 Isso deve valer para zeros e uns; ou seja, todas as 12 contagens devem estar no intervalo especificado.
 Para o propósito deste teste, corridas maiores que 6 são consideradas como tendo comprimento 6.
 */
#include <iostream>
using namespace std;

class RunTest {
public:

    int run(int* vetbit){
        copia(vetbit);
        int zero = contaZero();
        int um = contaUm();

        if((zero == 1) && (um == 1)) {
            return 1;
        }
        else{
            return 0;
        }
    }

private:

    // anda com a distancia das variaveis
    void conferidaMarota(){
        if(cont1 != 0){
            dist1++;
        }
        if(cont2 != 0){
            dist2++;
        }
        if(cont3 != 0){
            dist3++;
        }
        if(cont4 != 0){
            dist4++;
        }
        if(cont5 != 0){
            dist5++;
        }
        if(cont6 != 0){
            dist6++;
        }
    }

    // zera as variaveis globais
    void zera(){
        cont1 = 0; // tem que ter só 1
        dist1 = 0; // distancia para numero 1
        cont2 = 0; // tem que ter só 2
        dist2 = 0; // distancia para numero 2
        cont3 = 0; // tem que ter só 3
        dist3 = 0; // distancia para numero 3
        cont4 = 0; // tem que ter só 4
        dist4 = 0; // distancia para numero 4
        cont5 = 0; // tem que ter só 5
        dist5 = 0; // distancia para numero 5
        cont6 = 0; // tem que ter 6 ou +
        dist6 = 0; // distancia para numero 6 ou +
    }

    // da uma conferida nos 1
    int contaUm(){
        int anterior = 0;
        zera();
        int c = 0;
        for (int i = 0; i < 40016; i++) {
            conferidaMarota();
            if(vet[i] == 0){
                anterior = 0;
                c++;
            }
            else{
                anterior = 1;
                if(c == 1){
                    if(cont1 > 0){
                        if((dist1 > 2266) && (dist1 < 2734)){
                            dist1 = 0;
                        }
                        else{
                            return 0;
                        }
                    }
                    cont1++;
                }
                else if(c == 2){
                    if(cont2 > 0){
                        if((dist2 > 1078) && (dist2 < 1422)){
                            dist2 = 0;
                        }
                        else{
                            return 0;
                        }
                    }
                    cont2++;
                }
                else if(c == 3){
                    if(cont3 > 0){
                        if((dist3 > 501) && (dist3 < 749)){
                            dist3 = 0;
                        }
                        else{
                            return 0;
                        }
                    }
                    cont3++;
                }
                else if(c == 4){
                    if(cont4 > 0){
                        if((dist4 > 222) && (dist4 < 403)){
                            dist4 = 0;
                        }
                        else{
                            return 0;
                        }
                    }
                    cont4++;
                }
                else if(c == 5){
                    if(cont5 > 0){
                        if((dist5 > 89) && (dist5 < 224)){
                            dist5 = 0;
                        }
                        else{
                            return 0;
                        }
                    }
                    cont5++;
                }
                else if(c >= 6){
                    if(cont6 > 0){
                        if((dist6 > 89) && (dist6 < 224)){
                            dist6 = 0;
                        }
                        else{
                            return 0;
                        }
                    }
                    cont6++;
                }
            }
        }
        return 1;
    }

    // da uma conferida nos 0
    int contaZero(){
        int anterior = 0;
        zera();
        int c = 0;
        for (int i = 0; i < 40016; i++) {
            conferidaMarota();
            if(vet[i] == 1){
                anterior = 1;
                c++;
            }
            else{
                anterior = 1;
                if(c == 1){
                    if(cont1 > 0){
                        if((dist1 > 2266) && (dist1 < 2734)){
                            dist1 = 0;
                        }
                        else{
                            return 0;
                        }
                    }
                    cont1++;
                }
                else if(c == 2){
                    if(cont2 > 0){
                        if((dist2 > 1078) && (dist2 < 1422)){
                            dist2 = 0;
                        }
                        else{
                            return 0;
                        }
                    }
                    cont2++;
                }
                else if(c == 3){
                    if(cont3 > 0){
                        if((dist3 > 501) && (dist3 < 749)){
                            dist3 = 0;
                        }
                        else{
                            return 0;
                        }
                    }
                    cont3++;
                }
                else if(c == 4){
                    if(cont4 > 0){
                        if((dist4 > 222) && (dist4 < 403)){
                            dist4 = 0;
                        }
                        else{
                            return 0;
                        }
                    }
                    cont4++;
                }
                else if(c == 5){
                    if(cont5 > 0){
                        if((dist5 > 89) && (dist5 < 224)){
                            dist5 = 0;
                        }
                        else{
                            return 0;
                        }
                    }
                    cont5++;
                }
                else if(c >= 6){
                    if(cont6 > 0){
                        if((dist6 > 89) && (dist6 < 224)){
                            dist6 = 0;
                        }
                        else{
                            return 0;
                        }
                    }
                    cont6++;
                }
            }
        }
        return 1;
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
