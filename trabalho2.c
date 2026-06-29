#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "trabalho2.h"


int *vetorPrincpial[10];
int tamanhosDasEstruturas[10];
int qtdElementosNasEstruturas[10];

int criarEstruturaAuxiliar(int posicao, int tamanho){
    if(posicao < 1 || posicao > 10){
        return POSICAO_INVALIDA;
    }else if(vetorPrincpial[posicao - 1] != NULL){
        return JA_TEM_ESTRUTURA_AUXILIAR;
    }else{
        if(tamanho < 1){
            return TAMANHO_INVALIDO;
        }else{
            vetorPrincpial[posicao - 1] = (int *) malloc(tamanho * sizeof(int));
            if(vetorPrincpial[posicao - 1] == NULL){
                return SEM_ESPACO_DE_MEMORIA;
            }
            tamanhosDasEstruturas[posicao - 1] = tamanho;
            qtdElementosNasEstruturas[posicao - 1] = 0;
            return SUCESSO;
        }
    }
    return SUCESSO;
}

int inserirNumeroEmEstrutura(int posicao, int valor){
    if(posicao < 1 || posicao > 10){
        return POSICAO_INVALIDA;
    }else{
        if(vetorPrincpial[posicao - 1] != NULL){
            if(tamanhosDasEstruturas[posicao - 1] > qtdElementosNasEstruturas[posicao - 1]){
                int indiceLivre = qtdElementosNasEstruturas[posicao -1];
                vetorPrincpial[posicao - 1][indiceLivre] = valor;
                qtdElementosNasEstruturas[posicao - 1]++;  
                return SUCESSO;
            }else{
               return SEM_ESPACO;
            }
        }else{
            if(vetorPrincpial[posicao - 1] == NULL){
                return SEM_ESTRUTURA_AUXILIAR;
            }
        }
    }
}




int excluirNumeroDoFinaldaEstrutura(int posicao){
    if(posicao < 1 || posicao > 10){
        return POSICAO_INVALIDA;
    }else if(vetorPrincpial[posicao - 1] == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }else if(vetorPrincpial[posicao - 1] != NULL && qtdElementosNasEstruturas[posicao - 1] == 0){
        return ESTRUTURA_AUXILIAR_VAZIA;
    }else{
        int indiceExcluir = qtdElementosNasEstruturas[posicao - 1] -1;
        vetorPrincpial[posicao - 1][indiceExcluir] = 0;
        qtdElementosNasEstruturas[posicao - 1]--;
        return SUCESSO;
    }
}


int excluirNumeroEspecificoDeEstrutura(int posicao, int valor){
    int achou = 0;
    if(posicao < 1 || posicao > 10){
        return POSICAO_INVALIDA;
    }else if(vetorPrincpial[posicao - 1] == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }else if(vetorPrincpial[posicao - 1] != NULL && qtdElementosNasEstruturas[posicao - 1] == 0){
        return ESTRUTURA_AUXILIAR_VAZIA;
    }else{
        if(vetorPrincpial[posicao - 1] != NULL && qtdElementosNasEstruturas[posicao - 1] >= 1 ){
            for(int i = 0; i < qtdElementosNasEstruturas[posicao - 1]; i++){
                if(vetorPrincpial[posicao - 1][i] == valor){
                    achou = 1;
                    for(int j = i; j < qtdElementosNasEstruturas[posicao - 1] - 1; j++){
                        vetorPrincpial[posicao - 1][j] = vetorPrincpial[posicao - 1][j + 1];
                    }
                    qtdElementosNasEstruturas[posicao - 1]--;
                    return SUCESSO;
                }
            }
        }
        return NUMERO_INEXISTENTE;
    }
}


int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]){
    if(posicao < 1 || posicao > 10){
        return POSICAO_INVALIDA;
    }else if(vetorPrincpial[posicao - 1] == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }else{
        for(int i = 0; i < qtdElementosNasEstruturas[posicao - 1]; i++){
            vetorAux[i] = vetorPrincpial[posicao - 1][i];
        }
        for(int i = 0; i < qtdElementosNasEstruturas[posicao - 1]; i++){
            printf("%d", vetorAux[i]);
        }
        return SUCESSO;
    }
}

int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]){
    int numMaior = 0;
    if(posicao < 1 || posicao > 10){
        return POSICAO_INVALIDA;
    }else if(vetorPrincpial[posicao - 1] == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }else{
        for(int i = 0; i < qtdElementosNasEstruturas[posicao - 1]; i++){
            vetorAux[i] = vetorPrincpial[posicao - 1][i];
        }
        for(int i = 0; i < qtdElementosNasEstruturas[posicao - 1]; i++){
                for(int j = 0; j < qtdElementosNasEstruturas[posicao - 1] - 1 - i; j++){
                    if(vetorAux[j] > vetorAux[j + 1]){
                        numMaior = vetorAux[j];
                        vetorAux[j] = vetorAux[j+1];
                        vetorAux[j+1] = numMaior;
                    }
                }
        }
        for(int i = 0; i < qtdElementosNasEstruturas[posicao - 1]; i++){
            printf("%d", vetorAux[i]);
        }
        return SUCESSO;
    }
}

int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]){
    int qte = 0;
    int k = 0;
    for(int i = 0; i < 10; i++){
        if(vetorPrincpial[i] != NULL && qtdElementosNasEstruturas[i] > 0){
            for(int j = 0; j < qtdElementosNasEstruturas[i]; j++){
                vetorAux[k] = vetorPrincpial[i][j];
                k++;
            }
        }
    }
    if(k == 0){
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }
    for(int i = 0; i < k; i++){
        printf("%d", vetorAux[i]);
    }
    return SUCESSO;
}

int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]){
    
}