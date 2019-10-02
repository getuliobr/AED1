#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct{
    char numero[16];
    char whatsapp[2]; // S ou N;    
}Telefone;

typedef struct{
    char cep[11];
    int numero;
    char estado[3];
}Endereco;

typedef struct{
    char* nome;
    // char nome[40];
    int idade;
    char* email;
    Endereco endereco;
    Telefone* telefones[4];
    int qtdeContatos; // quantidade de contatos armazenados
}Pessoa;

typedef struct{
    char* descricao;
    Pessoa** pessoas;
    int tamVetor; // tamanho do vetor de pessoas
    int qtdePessoas; // quantidade de pessoas armazenadas
}Agenda;

Agenda* agenda_novo(char* desc){
    Agenda* saida = (Agenda*) calloc(1,sizeof(Agenda));
    saida->descricao = (char*)calloc(strlen(desc),sizeof(char));
    strcpy(saida->descricao,desc);
    saida->qtdePessoas = 0;
    saida->tamVetor = 0;
}
Pessoa* pessoa_novo(char* nome, int idade, char* email){
    Pessoa* novo = (Pessoa*) malloc(sizeof(Pessoa));
    novo->nome = (char*) calloc(strlen(nome) + 1, sizeof(char) );
    strcpy(novo->nome, nome);
    novo->idade = idade;
    novo->email = (char*) calloc(strlen(email) + 1, sizeof(char) );
    strcpy(novo->email, email);
    novo->qtdeContatos = 0;

    return novo;
}

void pessoa_defineEndereco(Pessoa* p, char* cep, int num, char* estado){
    strcpy(p->endereco.cep, cep);
    p->endereco.numero = num;
    strcpy(p->endereco.estado, estado);
}

void pessoa_cadastrarContato(Pessoa* p, char* numero, char* flagWhats){
    
    Telefone* contato = (Telefone*) malloc(sizeof(Telefone));
    strcpy(contato->numero, numero);
    strcpy(contato->whatsapp, flagWhats);

    p->telefones[p->qtdeContatos++] = contato;
}

void agenda_verificaReduzTamanho(Agenda* agenda){
    int size;
    if(agenda->qtdePessoas < agenda->tamVetor/4){

        if(agenda->tamVetor > 5) size = agenda->tamVetor/2;
        else return;

        Pessoa* vetorAux = (Pessoa *)calloc(size,sizeof(Pessoa)); 

        for(int i=0;i<agenda->qtdePessoas;i++)
            vetorAux[i] = *(agenda->pessoas[i]);

        free(agenda->pessoas);
        *(agenda->pessoas) = vetorAux;
    }
}
int agenda_consultaPorEstado(Agenda* agenda, char* estado, Telefone** referencia){
    int qntdeEstado = 0;
    for(int i=0, j=0;i<agenda->qtdePessoas;i++){
        if(strcmp(agenda->pessoas[i]->endereco.estado,estado)==0){
            qntdeEstado++;
            *referencia[j++] = **(agenda->pessoas[i]->telefones);
        }
    }
    return qntdeEstado;
}


void agenda_inserirPessoa(Agenda* agenda, Pessoa* p){
    agenda->pessoas++;
    int i;
    if(agenda->tamVetor == agenda->qtdePessoas && agenda->tamVetor != 0) agenda->tamVetor = agenda->tamVetor*2;
    else if(agenda->tamVetor == 0) agenda->tamVetor =  5;
    Pessoa* vetorAux = (Pessoa *)calloc(agenda->tamVetor,sizeof(Pessoa)); 
    for(i=0;i<agenda->qtdePessoas;i++)
        vetorAux[i] = *(agenda->pessoas[i]);
    vetorAux[i] = *p;
    free(agenda->pessoas);
    agenda->pessoas = &vetorAux;
}

Pessoa* agenda_removerPessoa(Agenda* agenda, char* email){
    int indexRemover = -1;
    Pessoa* saida = (Pessoa*) calloc(1,sizeof(Pessoa)); 
    for(int i=0;i<agenda->qtdePessoas;i++) 
        if(strcmp(agenda->pessoas[i]->email,email)==0){
            indexRemover = i;
            saida = agenda->pessoas[i];
            break;
        }
    Pessoa* vetorAux = (Pessoa *)calloc(agenda->tamVetor,sizeof(Pessoa)); 
    
    for(int i=0,j=0;i<agenda->qtdePessoas;i++){
        if(strcmp(agenda->pessoas[i]->email,email)!=0){
            vetorAux[j++] = *(agenda->pessoas[i]);
        }else agenda->qtdePessoas = agenda->qtdePessoas - 1;
    }
    agenda_verificaReduzTamanho(agenda);
    return saida;
}

void pessoa_desalocar(Pessoa* p){
    free(p);
}


