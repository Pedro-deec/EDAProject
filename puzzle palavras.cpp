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
    //função para desenhar menu de Boas Vindas    
    drawfundo();
    //função da libraria coniio.h que ler um caracter
    getch();
    //função para carregar e preparar a informação para o jogo 
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
                              //função para começar a jogar
                              sair=Jogar(ListaPrincipal);
                              system("CLS");
                           }while(sair==1); //quando a função jogar devolve um valor diferente de 1 acaba o jogo
                            escreve();
                   }
                   if(n==2)
                           adicionarpalavra();
                   if(n==3)
                           printpodio();
                    getch();
                   //reinicialização das variaveis
                   sair=0;
                   n=0;
                   
                   }
    getch();
    
    
}
