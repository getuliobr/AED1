#include <stdio.h>
#include <stdlib.h>
#define IOOR -1347 //index out of range

// DADOS
typedef struct{
    int **m;
    int linhas;
    int colunas;
} Matriz;

typedef struct{
    int *vetor;
    int tamanho;
} Vetor;


//OPERAÇÕES (PROTÓTIPOS)

Matriz *matriz_cria(int linhas, int colunas); //
int matriz_atribui(Matriz *m, int lin, int col, int valor); //
int matriz_acessa1(Matriz *m, int lin, int col);
int matriz_acessa2(Matriz *m, int lin, int col, int *end);
void matriz_imprime(Matriz *m); //
void matriz_destroi(Matriz *m);//
void printVetor(int* vetor, int tamanho);//
int matriz_linhas(Matriz* m);
int matriz_colunas(Matriz* m);
void matriz_map2(Matriz* m, int (*funcao)(int));
Vetor* matriz_vetor_linha(Matriz* m, int coluna);
Vetor* matriz_vetor_coluna(Matriz* m, int coluna);
Matriz* matriz_multiplica(Matriz* a, Matriz* b);
int matriz_ehQuadrada(Matriz* m);
int matriz_ehDiagonal(Matriz* m);
int matriz_ehIdentidade(Matriz* m);
Matriz* matriz_transposta(Matriz* m);
Matriz* matriz_oposta(Matriz* m);
//OPERAÇÕES (IMPLEMENTAÇÃO)

void printVetor(int* vetor, int tamanho){
    printf("[");
    for(int i=0;i<tamanho;i++)
        if(i != tamanho - 1) printf("%d,",vetor[i]);
        else printf("%d",vetor[i]);
    printf("]");
}

Matriz *matriz_cria(int linhas, int colunas){
    Matriz *mat = (Matriz *)malloc(sizeof(Matriz));
    mat->m = (int **)calloc(linhas, sizeof(int *));
    int i;
    for (i = 0; i < linhas; i++){
        mat->m[i] = (int *)calloc(colunas, sizeof(int));
    }
    mat->linhas = linhas;
    mat->colunas = colunas;
    return mat;
}

int matriz_atribui(Matriz *m, int lin, int col, int valor){
    if(!(lin < m->linhas && lin >= 0 && col < m->colunas && col >= 0)) return -1;
    m->m[lin][col] = valor;
    return 0;
}

void matriz_imprime(Matriz *m){
    printf("[\n");
    for(int i=0;i<m->linhas;i++){
        printf("  ");
        printVetor(m->m[i],m->colunas);
        if(i<m->linhas-1) printf(",\n");
    }
    printf("\n]\n");
}

void matriz_destroi(Matriz *m){
    for(int i=0;i<m->linhas;i++)
        free(m->m[i]);
    free(m->m);
    free(m);
}

int matriz_acessa1(Matriz *m, int lin, int col){
    if(!(lin < m->linhas && lin >= 0 && col < m->colunas && col >= 0)) return IOOR;
    return m->m[lin][col];
}

int matriz_acessa2(Matriz *m, int lin, int col, int *end){
    if(!(lin < m->linhas && lin >= 0 && col < m->colunas && col >= 0)) return -1;
    *end = m->m[lin][col];
    return 0;
}

int matriz_linhas(Matriz* m){
    return m->linhas;
}

int matriz_colunas(Matriz* m){
    return m->colunas;
}

void matriz_map(Matriz* m, int (*funcao)(int)){
    for(int i=0;i<m->linhas;i++){
        for(int j=0;j<m->colunas;j++){
            m->m[i][j] = funcao(m->m[i][j]);
        }
    }
}

Vetor* matriz_vetor_linha(Matriz* m, int linha){
    Vetor *mat = (Vetor *)malloc(sizeof(Vetor));
    mat->vetor =  (int *)malloc(sizeof(int) * m->colunas);
    for(int i=0;i<m->colunas;i++){
        mat->vetor[i] = m->m[linha][i];
    }
    return mat;
}

Vetor* matriz_vetor_coluna(Matriz* m, int coluna){
    Vetor *mat = (Vetor *)malloc(sizeof(Vetor));
    mat->vetor =  (int *)malloc(sizeof(int) * m->linhas);
    for(int i=0;i<m->linhas;i++){
        mat->vetor[i] = m->m[i][coluna];
    }
    return mat;
}


Matriz* matriz_multiplica(Matriz* a, Matriz* b){
    int aux = 0;
    int lA = a->linhas;
    int lB = b->linhas;
    int cB = b->colunas;
    Matriz* c = matriz_cria(lA,cB);
    if(lA != cB){
        c->linhas = -1;
        c->colunas = -1;
        return c;
    }
    for(int i=0; i<lA; i++){
        for(int j=0; j<cB; j++){
            c->m[i][j]=0;
            for(int X=0; X<lB; X++){
                aux += a->m[i][X] * b->m[X][j];
            }
            c->m[i][j]=aux;
            aux=0;
        }
    }
    return c;
}

int matriz_ehQuadrada(Matriz* m){
    if(m->linhas == m->colunas) return 1;
    return 0;
}

int matriz_ehDiagonal(Matriz* m){
    if(!matriz_ehQuadrada(m)) return 0;
    for(int i=0;i<m->linhas;i++){
        for(int j=0;j<m->colunas;i++){
            if(i==j) continue;
            if(m->m[i][j] != 0) return 0;
        }
    }
    return 1;
}

int matriz_ehIdentidade(Matriz* m){
    if(!matriz_ehQuadrada(m)) return 0;
    for(int i=0;i<m->linhas;i++){
        for(int j=0;j<m->colunas;i++){
            if(i==j && i==1) continue;
            else return 0;
            if(m->m[i][j] != 0) return 0;
        }
    }
    return 1;
}

Matriz* matriz_transposta(Matriz* m){
    Matriz* c = matriz_cria(m->colunas,m->linhas);
    for(int i=0;i<m->linhas;i++){
        for(int j=0;j<m->colunas;j++){
            c->m[j][i] = m->m[i][j];
        }
    }
    return c;
}

Matriz* matriz_oposta(Matriz* m){
    Matriz* c = matriz_cria(m->linhas,m->colunas);
    for(int i=0;i<m->linhas;i++){
        for(int j=0;j<m->colunas;j++){
            c->m[i][j] = -(m->m[i][j]);
        }
    }
    return c;
}