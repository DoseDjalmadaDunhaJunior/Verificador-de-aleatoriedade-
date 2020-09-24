//
// Created by jose on 24/09/2020.
//

#ifndef CHAVE_CPP_LONGTEST_H
#define CHAVE_CPP_LONGTEST_H

//não pode ter uma sequencia de zeros ou uns maior que 34
class LongTest {
public:
    int longo(int* vet){
        int anterior = 2;
        for (int i = 0; i < 40016; i++) {
            if(vet[i] == 1){
                if(anterior != 1){
                um = 0;
                }
                um++;
                anterior = 1;
            }
            else{
                if(anterior != 0){
                    zero = 0;
                }
                zero++;
                anterior = 0;
            }
            if((zero > 33)|| (um > 33)){
                return 0;
            }
        }
        return 1;
    }

private:

    int um = 0;
    int zero = 0;
};


#endif //CHAVE_CPP_LONGTEST_H
