#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"

int main(){
    Agenda* a1 = agenda_novo("pessoal");

    Pessoa* p1 = pessoa_novo("Joao", 30, "joao@gmail.com");
    Pessoa* p2 = pessoa_novo("Maria", 20, "maria@gmail.com");

    pessoa_defineEndereco(p1, "88.888-88", 100, "PR");
    pessoa_defineEndereco(p2, "99.999-99", 200, "SP");
    

    pessoa_cadastrarContato(p1, "(44) 91111-1111", "S");
    pessoa_cadastrarContato(p1, "(41) 92222-2222", "S");
    pessoa_cadastrarContato(p1, "(44) 3033-1234", "N");

    pessoa_cadastrarContato(p2, "(44) 94444-4444", "S");
    pessoa_cadastrarContato(p2, "(44) 95555-5555", "S");

    Telefone vetPR[100],vetSP[100];
    int qtdeTelefones;
    qtdeTelefones = agenda_consultaPorEstado(a1, "PR", &vetPR);
    printf("%d\n",qtdeTelefones);
    qtdeTelefones = agenda_consultaPorEstado(a1, "SP", &vetSP);
    printf("%d\n",qtdeTelefones);
    agenda_inserirPessoa(a1, p1);
    agenda_inserirPessoa(a1, p2);

    Pessoa* removido = agenda_removerPessoa(a1, "joao@gmail.com");

    pessoa_desalocar(removido);

}