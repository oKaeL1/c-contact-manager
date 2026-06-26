#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define COR_VERDE    "\033[32m"
#define COR_VERMELHO "\033[31m"
#define COR_AMARELO  "\033[33m"
#define COR_RESET    "\033[0m"
struct Contato{
 char* nome;
 int telefone;


};

struct Agenda{
    int topo;
    struct Contato lista[48];


};

void adicionarContatoLista(struct Agenda* agendaDoUsuario, char* prompt, int* telefone){


    agendaDoUsuario->topo++;


    agendaDoUsuario->lista[agendaDoUsuario->topo].nome=malloc(sizeof(char)*(strlen(prompt)+1));
    strcpy(agendaDoUsuario->lista[agendaDoUsuario->topo].nome,prompt);
    agendaDoUsuario->lista[agendaDoUsuario->topo].telefone=*telefone;



}

void pegarPrompt(int* escolha){

    scanf("%d", escolha);
    int c;

    while((c=getchar())!='\n' && c!=EOF){}






}

void pegarNome(char* nome){
    fgets(nome,100,stdin);
    nome[strcspn(nome,"\n")]='\0';




}


void pegarTelefone(int* telefone){

    scanf("%d",telefone);
    int c;
    while((c=getchar())!='\n' && c!=EOF){}

}

void mostrarMenu(){
        printf("1 - Adicionar contato \n");
        printf("2 - Listar contatos\n");
        printf("3 - Buscar contato pelo nome\n");
        printf("4 - Sair\n");
}

void adicionarContato(struct Agenda* agendaDoUsuario){
            char nome[100];
            int telefone=0;
            printf("DIGITE O NOME E TELEFONE:\n");
            pegarNome(nome);
            pegarTelefone(&telefone);

            if(agendaDoUsuario->topo<47){
            adicionarContatoLista(agendaDoUsuario,nome,&telefone);
            } else{
                printf("Limites de contatos atingido (48)\n");
            }

}

void listarContatos( struct Agenda* agendaDoUsuario){

            for(int i=0;i<(agendaDoUsuario->topo)+1;i++){
                printf("############################\n");
                printf("NOME:%s\n",agendaDoUsuario->lista[i].nome);
                printf("NÚMERO:%d \n", agendaDoUsuario->lista[i].telefone);
                printf("############################\n");
            }

}

void buscarContato(struct Agenda* agendaDoUsuario){

            char nomeAux[100];
            pegarNome(nomeAux);
            int encontrado=0;
            for(int i=0;i<agendaDoUsuario->topo+1;i++){
                if(strcmp(nomeAux,agendaDoUsuario->lista[i].nome)==0){
                    printf("%sContato encontrado!\n", COR_VERDE);
                    printf("############################\n");
                    printf("NOME:%s\n",agendaDoUsuario->lista[i].nome);
                    printf("NÚMERO:%d \n", agendaDoUsuario->lista[i].telefone);
                    printf("############################ %s\n", COR_RESET);
                    encontrado=1;

                }
            }
            if(!encontrado)printf("%sContato não encontrado%s!", COR_VERMELHO,COR_RESET);


}


void menu(){
        int real=1;

        int escolha=0;



        struct Agenda agendaDoUsuario;

        agendaDoUsuario.topo=-1;


        while(real){
        mostrarMenu();
        pegarPrompt(&escolha);


        switch(escolha){

        case 1:
            adicionarContato(&agendaDoUsuario);
        break;

        case 2:
            listarContatos(&agendaDoUsuario);
        break;

        case 3:
            buscarContato(&agendaDoUsuario);

            break;

        case 4:
            real=0;
                for(int i=0;i<agendaDoUsuario.topo+1;i++){
                free(agendaDoUsuario.lista[i].nome);
                }

        break;

        default:
            printf("Número inválido, tente novamente");



        }
        }


}





int main(){





        menu();

        return 0;


}
