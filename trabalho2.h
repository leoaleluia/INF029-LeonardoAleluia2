#ifndef TRABALHO2_ESTRUTURAVETORES_H
#define TRABALHO2_ESTRUTURAVETORES_H

// Constantes de retorno que substituem os textos (strings)
enum { 
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS = -11, 
    NOVO_TAMANHO_INVALIDO, 
    NUMERO_INEXISTENTE,
    ESTRUTURA_AUXILIAR_VAZIA, 
    TAMANHO_INVALIDO, 
    SEM_ESPACO_DE_MEMORIA, 
    POSICAO_INVALIDA,
    JA_TEM_ESTRUTURA_AUXILIAR, 
    SEM_ESTRUTURA_AUXILIAR, 
    SEM_ESPACO, 
    SUCESSO 
};

// Estrutura para a parte final do trabalho (Lista Encadeada)
typedef struct reg {
    int conteudo;
    struct reg *prox;
} No;

// Assinaturas das funções que você vai desenvolver no trabalho2.c
int criarEstruturaAuxiliar(int posicao, int tamanho);
int inserirNumeroEmEstrutura(int posicao, int valor);
int excluirNumeroDoFinaldaEstrutura(int posicao);
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor);
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]);
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]);
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]);
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]);
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho);
int getQuantidadeElementosEstruturaAuxiliar(int posicao);

// Funções da Lista Encadeada
No *montarListaEncadeadaComCabecote();
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[]);
void destruirListaEncadeadaComCabecote(No **inicio);

// Funções de controle do ciclo de vida do programa
void inicializar();
void finalizar();
void dobrar(int *x);

#endif // TRABALHO2_ESTRUTURAVETORES_H