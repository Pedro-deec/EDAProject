using namespace std;
typedef unsigned char boolean;
#include "include.h"
#include "classes.h"
int pontucao;
#include "funcs.h"
int main (){
    int sair=0,n;
    string c;
    Lista_palavras ListaPrincipal;
    //fun��o para desenhar menu de Boas Vindas    
    drawfundo();
    //fun��o da libraria coniio.h que ler um caracter
    getch();
    //fun��o para carregar e preparar a informa��o para o jogo 
    ListaPrincipal=carregarInfo();
    //ciclo que permite voltar sempre ao menu 
    while(sair==0){
                   pontucao=0;
                   do{
                      system("CLS");
                      n=drawsegundo();
                   }while(n<0 || n>3);
                   system("CLS");
                   if(n==1){
                           do{
                              //fun��o para come�ar a jogar
                              sair=Jogar(ListaPrincipal);
                              system("CLS");
                           }while(sair==1); //quando a fun��o jogar devolve um valor diferente de 1 acaba o jogo
                            escreve();
                   }
                   if(n==2)
                           adicionarpalavra();
                   if(n==3)
                           printpodio();
                    getch();
                   //reinicializa��o das variaveis
                   sair=0;
                   n=0;
                   
                   }
    getch();
    
    
}
