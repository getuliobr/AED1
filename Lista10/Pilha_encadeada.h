#include <stdio.h>
#include <stdlib.h>



typedef enum boolean{false=0, true=1} Boolean;
typedef int Tipo;

/**
 * Registro utilizado para acomodar cada elemento da pilha (Nó).
 */
typedef struct no{
    Tipo dado;
    struct no* prox;
}No;

/**
 * Estrutura usada para representar e armazenar a PILHA com alocação encadeada.
 */
typedef struct{
    No* topo;
    int qtde;
}Pilha;

Pilha* pilha_criar();
Boolean pilha_push(Pilha* p, Tipo elemento);
Tipo* pilha_pop1(Pilha* p);
Boolean pilha_pop2(Pilha* p, Tipo* end);
void pilha_destruir(Pilha* p);
void pilha_imprimir(Pilha* p);
int pilha_posicao(Pilha* p, Tipo elemento);
int pilha_tamanho(Pilha* p);
//FUNÇÕES ADICIONAIS
int pilha_pushAll(Pilha* p, Tipo* vetor, int tam);
Pilha* pilha_inverter(Pilha* p);
Pilha* pilha_clone(Pilha* p);


/**
 * Cria a pilha e devolve seu endereço.
 * @return o endereço da pilha criada e inicializada.
 */
Pilha* pilha_criar(){
    Pilha* saida = (Pilha *)malloc(sizeof(Pilha));
    saida->qtde=0;
    saida->topo=NULL;
    return saida;
}

/**
 * Desaloca a pilha <p>.
 */
void pilha_destruir(Pilha* p){
    No* temp = p->topo;
    No* passado;
    while(temp != NULL){
        passado = temp;
        temp = temp->prox;
        free(passado);
    }
    free(p);
}

/**
 * Insere o elemento <elemento> no topo da pilha <p>.
 * @param p: Endereço da Pilha em que o elemento será inserido.
 * @param elemento: Elemento a ser inserido na pilha.
 * @return true se a inserção foi realizada com sucesso e false caso contrário
 */
Boolean pilha_push(Pilha* p, Tipo elemento){
    No* no = (No *)malloc(sizeof(No));
    no->dado=elemento;
    no->prox=p->topo;
    p->topo=no;
    p->qtde++;
    return true;
}


/**
 * Remove o topo da Pilha <p>, aloca um espaço dinamicamente para armazenar o * elemento removido e devolve o endereço do elemento.
 * @param p: Endereço da Pilha.
 * @return Endereço do elemento removido ou NULL caso contrário.
 */
Tipo* pilha_pop1(Pilha* p){
    No* temp = p->topo;
    if(temp != NULL){
        Tipo* saida = (Tipo *)malloc(sizeof(Tipo));
        *saida = temp->dado;
        p->topo = temp->prox;
        p->qtde--;
        free(temp);
        return saida;
    }
    return NULL;
}

/**
 * Remove o topo da Pilha <p>, e armazena o elemento removido no endereço 
 * <end> recebido por parâmetro.
 * @param p: Endereço da Pilha.
 * @param end: Endereço de memória onde será armazenado o elemento removido
 * @return true se a remoçao foi realizada com sucesso e false caso contrário
 */
Boolean pilha_pop2(Pilha* p, Tipo* end){
    No* saida = p->topo;
    if(saida != NULL){
        *end = saida->dado;
        p->topo = saida->prox;
        free(saida);
        return true;
    }
    return false;
}


/**
 * Imprime na saída padrão os elementos da pilha
 * @param p: Endereço da Pilha.
 */
void pilha_imprimir(Pilha* p){
    No* s = p->topo;
    printf("[");
    while(s != NULL){
        printf("%d",s->dado);
        s = s->prox;
        if(s != NULL) printf(",");
    }
    printf("]\n");
}

/**
 * Devolve a posição do elemento <elemento> na pilha <p>
 * @param p: Endereço da Pilha.
 * @param elemento: Elemento a ser encontrado
 * @return posição do <elemento> em <p> ou -1 caso contrário
 */
int pilha_posicao(Pilha* p, Tipo elemento){
    int pos = -1;
    No* s = p->topo;
    while(s != NULL){
        pos++;
        if(s->dado==elemento) return pos;
        s = s->prox;
    }
    return -1;
}

/**
 * Devolve o tamanho da pilha <p>
 * @param p: Endereço da Pilha.
 * @return quantidade de elementos da pilha <p>
 */
int pilha_tamanho(Pilha* p){
    return p->qtde;
}

//FUNÇÕES ADICIONAIS

/**
 * Insere todos os elementos do vetor <vetor> na pilha <p>
 * @param p: Endereço da Pilha.
 * @param vetor: Endereço do vetor
 * @param tam: tamanho do <vetor>
 * @return quantidade de elementos inseridos na pilha <p>
 */
int pilha_pushAll(Pilha* p, Tipo* vetor, int tam){
    for(int i=0;i<tam;i++)
        pilha_push(p,vetor[i]);
    return tam;    
}

/**
 * Inverte a pilha <p>
 * @param p: Endereço da Pilha.
 */
Pilha* pilha_inverter(Pilha* p){
    Pilha* s = pilha_criar();
    No* temp = p->topo;
    while(temp != NULL){
        pilha_push(s,temp->dado);
        temp = temp->prox;
    }
    pilha_destruir(p);
    return s;
}

/**
 * Cria um clone da pilha <p>
 * @param p: Endereço da Pilha.
 * @return Endereço da pilha clonada.
 */

Pilha* pilha_clone(Pilha* p){
    Pilha* s = pilha_criar();
    s = pilha_inverter(pilha_inverter(p));
    return s;
}
