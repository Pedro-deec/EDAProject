void gotoxy( int x, int y ){//net
     COORD coord;
     coord.X = (short)x;
     coord.Y = (short)y;
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//poe o cursor na posi��o x,y passados pra fun��o
}

//fun��o que recebe uma palavra com caracteres especiais e retorna a mesma palavra com os caracteres correctos
string mudar(string palavra){
       int i;
       for(i=0;i<palavra.length();i++){//percorre a palavra letra a letra e verifica se a letra e um caracter especial  
                                       //Variantes da letra A
                                       if(palavra[i]=='�' || palavra[i]=='�')
                                                               palavra[i]=(char)160;
                                       
                                       else if(palavra[i]=='�' || palavra[i]=='�')
                                                               palavra[i]=(char)133;
                                       
                                       else if(palavra[i]=='�' || palavra[i]=='�')
                                                               palavra[i]=(char)131;
                                                               
                                       else if(palavra[i]=='�' || palavra[i]=='�')
                                                               palavra[i]=(char)134;
                                                               
                                       //Variantes da letra E
                                       else if(palavra[i]=='�' || palavra[i]=='�')
                                                               palavra[i]=(char)130;
                                       else if(palavra[i]=='�' || palavra[i]=='�')
                                                               palavra[i]=(char)136;
                                       
                                       //Variantes da letra I
                                       else if(palavra[i]=='�' || palavra[i]=='�' )
                                                               palavra[i]=(char)161;
                                       //Variantes da letra O
                                       else if(palavra[i]=='�' || palavra[i]=='�')
                                                               palavra[i]=(char)162;
                                       else if(palavra[i]=='�' || palavra[i]=='�')
                                                               palavra[i]=(char)147;
                                       //Variantes da letra U
                                       else if(palavra[i]=='�' || palavra[i]=='�')
                                                               palavra[i]=(char)163;
                                       
       }
       return(palavra);
} 


//Fun��o que desenha "as caixas" do jogo
//Parametros:palavra que quer se seja desenhada, npalavra que funciona como um contador para que n�o aja sobreposi��o, cor a ser utilizada nas caixa
           //t=true significa que escreve a palavra dentro das caixas caso contrario immprime so a caixa
void draw(string palavra,int npalavra,int cor,boolean t){
     //fun�oes da biblioteca windows.h que preparam a consola para manipula��o
     HANDLE hConsole;
     hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
     int i;
     //cada caixa tem 3 caracteres na vertical e 2 na horizontal
     //uma caixa corresponde a uma letra da palavra
     for(i=0;i<(palavra.length()*5);i+=5){//o ciclo vai de 5 em 5 porque � a distancia do inicio duma caixa ao inicio da outra
                       SetConsoleTextAttribute(hConsole,cor); //fun��o que muda a cor da fonte na consola
                       
                       //desenha a parte lateral esquerda da caixa de acordo com as posi��es fornecidas
                       gotoxy(20+i,4+(npalavra*4));
                       cout<<char(219);
                       gotoxy(20+i,5+(npalavra*4));
                       cout<<char(219);
                       gotoxy(20+i,6+(npalavra*4));
                       cout<<char(219);
                       
                       
                       //desenha a parte superior da caixa de acordo com as posi��es fornecidas
                       gotoxy(21+i,4+(npalavra*4));
                       cout<<char(219);
                       gotoxy(22+i,4+(npalavra*4));
                       cout<<char(219);
     
     
                       
                       //desenha a parte lateral direita da caixa de acordo com as posi��es fornecidas
                       gotoxy(23+i,4+(npalavra*4));
                       cout<<char(219);
                       gotoxy(23+i,5+(npalavra*4));
                       cout<<char(219);
                       gotoxy(23+i,6+(npalavra*4));
                       cout<<char(219);
                       
                       
                       //desenha a parte inferior da caixa de acordo com as posi��es fornecidas
                       gotoxy(21+i,6+(npalavra*4));
                       cout<<char(219);
                       gotoxy(22+i,6+(npalavra*4));
                       cout<<char(219);
                       
                       //caso t=true 
                       if(t==true){
                                   //muda a cor do texto de novo para branco
                                   SetConsoleTextAttribute(hConsole,15);
                                   //vai para a posi��o onde deve escrever a letra
                                   gotoxy(21+i,5+(npalavra*4));
                                   //escreve
                                   cout<<palavra[(i/5)];                 
                       }
     }
}
//fun��o que desenha a caixa de jogo 
void drawContainer(string palavra,int npalavra){
     //fun�oes da biblioteca windows.h que preparam a consola para manipula��o
     HANDLE hConsole;
     hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
     int i;
     //muda a cor do texto para verde que corresponde ao numero 10
     SetConsoleTextAttribute(hConsole,10); 
     //desenha a parte lateral esquerda da caixa de acordo com as posi��es fornecidas
     gotoxy(20,4+(npalavra*4));
     cout<<char(219);
     gotoxy(20,5+(npalavra*4));
     cout<<char(219);
     gotoxy(20,6+(npalavra*4));
     cout<<char(219);
     
     for(i=0;i<palavra.length();i++){//o ciclo vai at� ao tamanho da palavra pois nao existe nenhuma palavra no jogo que seja maior que a palavra "base"
                                         //desenha a parte superior e inferior da caixa de acordo com as posi��es fornecidas
                                         gotoxy(21+i,4+(npalavra*4));
                                         cout<<char(219);
                                         gotoxy(22+i,4+(npalavra*4));
                                         cout<<char(219);
                                         gotoxy(21+i,6+(npalavra*4));
                                         cout<<char(219);
                                         gotoxy(22+i,6+(npalavra*4));
                                         cout<<char(219);
                       
                                        
     }
     //desenha a parte lateral esquerda da caixa de acordo com as posi��es fornecidas
     gotoxy(22+i,4+(npalavra*4));
     cout<<char(219);
     gotoxy(22+i,5+(npalavra*4));
     cout<<char(219);
     gotoxy(22+i,6+(npalavra*4));
     cout<<char(219);
     
     //muda a cor do texto de novo para branco
     SetConsoleTextAttribute(hConsole,15);
     //posiciona o curscor dentro da caixa
     gotoxy(21,5+(npalavra*4));
}



//fun��o que desenha painel de boas vindas
void drawfundo(){
     draw("PUZZLE",0,9,true);
     draw("DE",1,10,true);
     draw("PALAVRAS",2,12,true);
     gotoxy(20,16);
     cout<<"PRIMA ENTER PARA CONTINUAR...";
}
//fun��o que desenha o menu e devolve a op��o escolhida
int drawsegundo(){
     int n;
     draw("1-JOGAR",0,5,true);
     draw("2-ADICIONAR",1,6,true);
     draw("3-PODIO",2,7,true);
     gotoxy(20,16);
     cout<<"ESCOLHA A OPCAO";  
     cin>>n;
     return(n);
}
//fun��o que recebe uma string e caso esta tenha caracteres especiais utiliza o codigo da tabela ascii para os imprimir na consola
void imprimir(string palavra){
       int i;
       for(i=0;i<palavra.length();i++){
                                       //Variantes da letra A
                                       if(palavra[i]=='�' || palavra[i]=='�')
                                                               cout<<(char)160;
                                                               
                                       if(palavra[i]=='�' || palavra[i]=='�')
                                                               cout<<(char)134;
                                       
                                       else if(palavra[i]=='�' || palavra[i]=='�')
                                                               cout<<(char)133;
                                       
                                       else if(palavra[i]=='�' || palavra[i]=='�')
                                                               cout<<(char)131;
                                       //Variantes da letra E
                                       else if(palavra[i]=='�' || palavra[i]=='�')
                                                               cout<<(char)130;
                                       else if(palavra[i]=='�' || palavra[i]=='�')
                                                               cout<<(char)136;
                                       
                                       //Variantes da letra I
                                       else if(palavra[i]=='�' || palavra[i]=='�' )
                                                               cout<<(char)161;
                                       //Variantes da letra O
                                       else if(palavra[i]=='�' || palavra[i]=='�')
                                                               cout<<(char)162;
                                       else if(palavra[i]=='�' || palavra[i]=='�')
                                                               cout<<(char)147;
                                       //Variantes da letra U
                                       else if(palavra[i]=='�' || palavra[i]=='�')
                                                               cout<<(char)163;
                                       else
                                                               cout<<palavra[i];
       }
} 




//fun��o que l� a informa��o do ficheiro insere na lista as palavras e prepara a lista para um acesso mais rapido
Lista_palavras carregarInfo(){
     ifstream dicionarioIn(filename);//abre o ficheiro filename que est� definido no ficheiro includes.h
     Lista_palavras listaDicionario,listaAuxiliar;
     string aux,aux2;
     int i,maxTamanho=0;     
     if (dicionarioIn.is_open()){//se conseguiu abrir o ficheiro
        while(!dicionarioIn.eof()){//percorre o ficheiro at� o fim do ficheiro lendo palavra a palavra
                               dicionarioIn>>aux;//l� a palavra e guarda em aux;
                               if(aux.length()>2){//Palavra com menos de 3 letras nao contam para o programa logo � desnecessario adicion�las                           
                                                 if(aux2!=aux)//verifica se a ultima palavra inserida � igual � proxima a ser inserida caso seja ignora a palavra
                                                              listaDicionario.insere(aux);
                                                 
                                                 //calcular o tamanho da maior palavra para ajudar mais tarde na ordena��o
                                                 if(aux.length()>maxTamanho)
                                                                            maxTamanho=aux.length();  
                                                 aux2=aux;
                               }
                               }
        dicionarioIn.close();
     }
     //rdena��o da lista por tamanho
     for(i=3;i<(maxTamanho+1);i++)//i=3 pois o tamanho minimo das palavras e 3
                                  for(listaDicionario.reset(); !listaDicionario.isEnd(); listaDicionario.proximo())//percorre a lista
                                                               if(listaDicionario.getData().length()==i)//se for do tamanho correspondente � itera��o do ciclo anterior adiciona � nova lista
                                                                                                        listaAuxiliar.insere(listaDicionario.getData());
    
     
     
     return(listaAuxiliar);
                               
}
//conta ocorrencias da letra "x" na string palavra
int contarOcorr(string palavra,char a){
    int i,count=0;
    //percorre a palavra e conta o numero de ocorrencias
    for(i=0;i<palavra.length();i++)
                                   if(a==palavra[i])
                                                   count++;
    return(count);



}

//Fun��o que torna string em maiusculas
string stringToupper(string palavra){
       int i;
       //percorre toda a palavra
       for(i=0;i<palavra.length();i++)
                                      //usa a fun��o toupper da biblioteca ctype.h para transformar todas as letras em maiusculas
                                      palavra[i]=toupper(palavra[i]);
       return(palavra);
}

//retira caracteres especiais para a comparacao com a palavra base
string stripChars(string palavra){
       int i;
       for(i=0;i<palavra.length();i++){//percorre a palavra e retira os acentos ficando so a letra
                                       //Variantes da letra A
                                       if(palavra[i]=='�' || palavra[i]=='�' || palavra[i]=='�' || palavra[i]=='�' || palavra[i]=='�' || palavra[i]=='�' || palavra[i]=='�' || palavra[i]== '�')
                                                               palavra[i]='a';
                                       //Variantes da letra E
                                       if(palavra[i]=='�' || palavra[i]=='�' || palavra[i]=='�' || palavra[i]=='�')
                                                               palavra[i]='e';
                                       //Variantes da letra I
                                       if(palavra[i]=='�' || palavra[i]=='�' )
                                                               palavra[i]='i';
                                       //Variantes da letra O
                                       if(palavra[i]=='�' || palavra[i]=='�' || palavra[i]=='�' || palavra[i]=='�')
                                                               palavra[i]='o';
                                       //Variantes da letra U
                                       if(palavra[i]=='�' || palavra[i]=='�')
                                                               palavra[i]='u';
       }
       return(palavra);
}   
     

//compara palavras para o jogo
boolean comparaPalavras(string str1,string str2){
        //str1=palavra "base"
        //str2=palavra secundaria <= em tamanho � palavra base
        int i,count=0;
        size_t found;//variavel auxiliar para a utiliza��o da fun��o find
        //retira os caracteres especiais da palavra e p�e tudo a maiusculas
        str1=stringToupper(stripChars(str1));
        str2=stringToupper(stripChars(str2));
        
        for(i=0;i<str2.length();i++){//percorre a palavra secundaria
                                     found=str1.find(str2[i]);//verifica se a letra "i" esta na palavra base
                                     //se estiver e se o numero de ocorrencias da letra "i" for igual na palavra base e secundaria incrementa o contador
                                     if (found!=string::npos && contarOcorr(str2,str2[i])==contarOcorr(str1,str2[i]))
                                                             count++;
                                                                                                                    
        }
        //se o contador for ao igual ao tamanho da palvra secundaria significa que a condi��o a cima se verificou em todas as letras da palavra secund�ria
        //logo a palavra secundaria pode ser usada para o jogo
        if(count==str2.length())
                              return(true);
        return(false);
                                     
}
  
  
//Fun��o que encontra a palavra base
string palavraBase(Lista_palavras lista, int contador){//recebe a lista de palavras e o numero de palavras
       int numero=0,i=1,r;
       srand ( time(NULL) );//fun��o que inicializa a fun��o de "random" reinicializa��o dos valores do random
       string palavra;
       //diminuir o intervalor da fun��o random para tornar a pesquisa mais rapida
       r=contador/32000;
       r=contador/(r);
       //a fun��o random nao utiliza uma gama de numeros grande o suficiente logo ir� ser usada mais do que uma vez
       //randmax � cerca de 32000 e o numero de palavras usando o ficheiro fornecido � cerca de 90000
       
       do{
           do{        
              //visto que a fun��o random nao utiliza uma gama de numero grande o suficiente ir� ser usada 3 vezes
              numero=(rand() % r + 1);
              numero+=(rand() % r + 1);
              numero+=(rand() % r + 1);   
           }while(numero>contador);         
                    
          i=0;
          //percorre toda a lista at� encontrar a palavra correspondente � posi��o calculada em cima
          for(lista.reset(); !lista.isEnd(); lista.proximo()){
                                                             if(i==numero)
                                                                          palavra=lista.getData();
                                                             i++;
          }
          
       }while(palavra.length()>6);
       
       
       return(stripChars(palavra));
}      

//sorteia as letras da palavra "base"
string sortPalavra(string palavra){
        int i,rd,rd2,size=palavra.length();
        char c;
        for(i=0;i<palavra.length();i++){
                                        //encontrar duas posi��es aleat�rias
                                        rd=(rand() % size + 0);
                                        rd2=(rand() % size + 0);
                                        
                                        //trocar as letras
                                        c=palavra[rd];
                                        palavra[rd]=palavra[rd2];
                                        palavra[rd2]=c;
        }
        return(palavra);
}
//Fun��o jogar:esta fun��o � chamada sempre que se inicia um novo jogo quer seja por desistencia ou por o utilizador passar de nivel
int Jogar(Lista_palavras lista){
    //variaveis do tipo time_t que pertence � biblioteca time.h
    time_t tstart, tend;
    
    
    //fun�oes da biblioteca windows.h que preparam a consola para manipula��o
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    
    int contador=0,sair=0,npalavra,erro=0,bkpoint=1,palavrasCorrectas=0;
    
    Lista_palavras listaDeJogo;
    string palavra,test, palavramist;
    char c=' ';
    //contar numero de palavras
    for(lista.reset(); !lista.isEnd(); lista.proximo())
            contador++;
    
    //encontrar palavra base
    
    do{
            palavra=palavraBase(lista,contador);
    }while(palavra.length()<5);
  
    //Sortear Palavra "base" e guardar em palavramist para ficar com a palavra base normal guardada em palavra
    palavramist=sortPalavra(palavra);
  
    //encontrar palavras para o jogo
    for(lista.reset(); !lista.isEnd(); lista.proximo()){//percorre toda a lista
                       if(lista.getData().length()>palavra.length())//como a lista esta ordenada por tamanho encontrando uma palavra com mais letras do que a palavra base 
                                                                    //significa que pode deixar de procurar pois nao vai encontrar mais palavras para o jogo                
                                                                                         break;
                       if(comparaPalavras(palavra,lista.getData())==true)//se a palavra for "correspondente" a palavra "base" adiciona � lista de jogo
                                                                        listaDeJogo.insere(mudar(lista.getData()));
    }
    
    
    
    
    
    contador=0;
    //Percorre toda lista de Jogo
    for(listaDeJogo.reset(); !listaDeJogo.isEnd(); listaDeJogo.proximo()){
                             draw(listaDeJogo.getData(),contador,9,false);//desenha o tabuleiro de jogo para cada palavra
                             contador++;//conta o numero de palavras
    }
    //desenha a palavra "base" j� ordenada de forma aleat�ria
    draw(palavramist,contador,14,true);
    
    //desenha a caixa de jogo
    drawContainer(palavra,contador+1);
    npalavra=contador+1;
    //come�a a contar o tempo
    tstart = time(0);
    while(sair==0){
                   erro=0;
                   cin>>test;
                   
                   //se o utilizador escrever sh significa que quer trocar a ordem das letras
                   if(test=="sh"){//troca                   
                                                         //volta a escrever a palavra "base" mas reordenada
                                                         draw(sortPalavra(palavramist),npalavra-1,14,true);
                                                         //apaga tudo o que estiver escrito na caixa de jogo
                                                         gotoxy(21,5+(npalavra*4));
                                                         SetConsoleTextAttribute(hConsole,0);
                                                         cout<<palavramist;
                                                         //volta a por o cursor no inicio da caixa
                                                         gotoxy(21,5+(npalavra*4));
                                                         //volta a mudar a cor do texto para branco
                                                         SetConsoleTextAttribute(hConsole,15);
                        
                                                        
                   }
                   else if (test=="help"){             //para nao ficarmos tempo demais a testar as palavras
                                          
                                          //apaga tudo o que estiver escrito na caixa de jogo
                                          gotoxy(21,5+(npalavra*4));
                                          SetConsoleTextAttribute(hConsole,0);
                                          cout<<palavra;
                                          //D� a ajuda ao utilizador
                                          SetConsoleTextAttribute(hConsole,15);
                                          gotoxy(1, 0);
                                          cout<<"Pediu ajuda, serao subtraidos 10 pontos da sua pontuacao total, \n  a palavra final deste nivel e:    " ;
                                          cout<< palavra;
                                          //tira 10 pontos � pontua�ao por ter usado ajuda
                                          pontucao=pontucao-10;  
                                          
                                          //coloca o cursor outra vez na caixa de jogo 
                                           gotoxy(21,5+(npalavra*4));  
                                           SetConsoleTextAttribute(hConsole,15);}
                 
                   //caso o utilizador queira jogar
                   else{
                        contador=0;
                        //percorre a lista de jogo
                        for(listaDeJogo.reset(); !listaDeJogo.isEnd(); listaDeJogo.proximo()){
                                                 string aux= listaDeJogo.getData();      
                                                 aux = stripChars(aux); 
                                                                                        if(aux==test){
                                                                                                         //apaga qualquer mensagem que tenha sido escrita no ecra
                                                                                                         SetConsoleTextAttribute(hConsole,0);
                                                                                                         gotoxy(21,5+(npalavra*4)+4);
                                                                                                         cout<<"                     ";
                                                                                                                         
                                                                                                         //incrementa a pontua��o:5 pontos por letra
                                                                                                         pontucao+=(5*test.length());
                                                                                                         //erro=1:palavra encontrada
                                                                                                         erro=1;
                                                                                                         //incrementa o numero de palavras encontradas
                                                                                                         palavrasCorrectas++;
                                                                                                         //escreve a palavra no tabuleiro de jogo
                                                                                                         draw(stripChars(listaDeJogo.getData()),contador,9,true);
                                                                                                         //se encontrou uma palavra que use as letras todas pela primeira vez
                                                                                                         if(test.length()==palavra.length() && bkpoint==1)
                                                                                                                                                          //sair=1:pode passar de nivel  
                                                                                                                                                          sair=1;}
                                                 //contador=posi��o da palavra na lista     
                                                 contador++;
                        }
                        
                        if(sair!=1)
                        if(palavra==test){//significa que o utilizador acertou na palavra base, o programa so vai correr as instru��es seguintes
                                          //se ocorreu um erro na verifica��o da palavra na lista, detect�mos que estava a acontecer com algumas palavras acentuadas, portanto introduzimos esta instru��o para solucionar o problema                                              
                          //apaga qualquer mensagem que tenha sido escrita no ecra
                          SetConsoleTextAttribute(hConsole,0);
                          gotoxy(21,5+(npalavra*4)+4);
                          cout<<"                     ";
                                                                                                                         
                          //incrementa a pontua��o:5 pontos por letra
                           pontucao+=(5*test.length());
                          //erro=1:palavra encontrada
                          erro=1;
                          //incrementa o numero de palavras encontradas
                          palavrasCorrectas++;
                          //escreve a palavra no tabuleiro de jogo
                          for(listaDeJogo.reset(); !listaDeJogo.isEnd(); listaDeJogo.proximo())
                                                  if(stripChars(listaDeJogo.getData())==test)
                                                  draw(stripChars(listaDeJogo.getData()),contador,9,true);
                            
                          //se encontrou uma palavra que use as letras todas pela primeira vez
                          if(test.length()==palavra.length() && bkpoint==1)
                          sair=1;  //sair=1:pode passar de nivel  
                          } 
                        
                        // muda a cor do texto para branco
                        SetConsoleTextAttribute(hConsole,15);
                        if(erro==0){//erro=0:palavra nao encontrada
                               //vai para a posicao e escreve a mensagem                                                                                
                               gotoxy(21,5+(npalavra*4)+4);
                               cout<<"PALAVRA NAO EXISTE";
                        }
                        //apaga qualquer mensagem que tenha sido escrita no ecra
                        gotoxy(21,5+(npalavra*4));
                        SetConsoleTextAttribute(hConsole,0);
                        cout<<palavra;
                         //volta a por o cursor no inicio da caixa de jogo
                        gotoxy(21,5+(npalavra*4));
                        // muda a cor do texto para branco
                        SetConsoleTextAttribute(hConsole,15);
                        //se passou de nivel:
                        if(sair==1){
                               //vai para a posicao e escreve a mensagem 
                               gotoxy(21,5+(npalavra*4)+4);
                               cout<<"A SUA PONTUACAO ACTUAL E:  " <<pontucao << " \n PASSOU DE NIVEL PRETENDE AVANCAR PARA O PROXIMO ?(s/n)";
                               cin>>c;
                               if(c=='n'){//se deseja continuar
                                         //reinicializa as variveis
                                         sair=0;
                                         bkpoint=0;
                                         
                                         //apaga qualquer mensagem que tenha sido escrita no ecra
                                         SetConsoleTextAttribute(hConsole,0);
                                         gotoxy(21,5+(npalavra*4)+4);
                                         cout<<"                                                   ";
                                          //volta a por o cursor no inicio da caixa de jogo
                                         gotoxy(21,5+(npalavra*4));
                                         // muda a cor do texto para branco
                                         SetConsoleTextAttribute(hConsole,15);
                               }
                        }
                        
                        //se completou o tabuleiro
                        if(palavrasCorrectas==npalavra-1)
                                                    sair=2;
                        
                        //volta a contar o tempo
                        tend = time(0);
                        //se ja passaram 3 minutos
                        if(difftime(tend, tstart)>(180))
                                     sair=1;
                        //se ja passaram 3 minutos mas ja encontrou uma palavra que utilize todas as palavras     
                        if(difftime(tend, tstart)>(180) && c=='n')
                                     sair=2;          
                   
                      
                      }               
    }
    //se passou de nivel
    if(c=='s' || sair==2)
            return(1);
    //se perdeu
    if(sair==1)
    return(2);
    
    return(0);
}
//fun��o que escreve as pontu��es mais altas
void printpodio(){
     string nome;
     int pont;
     
     //abre o ficheiro pontfile que est� definido no ficheiro includes.h
     ifstream pontin (pontfile);
     if (pontin.is_open()){
        while(!pontin.eof()){//percorre o ficheiro e escreve no ecr�
                               pontin>>nome>>pont;
                               cout<<"Nome: "<<nome<<" Pontucao:"<<pont<<"\n";
        }
     pontin.close();
     }
}

//fun��o que verifica se o utilizador est� no quadro de pontua��es mais altas
void escreve(){
     //estrutura para guardar os dados do ficheiro num array
     struct pontos{
            int ponto;
            string name;
     }arr[10];//o array tem tamanho 10 porque so mostra as 10 pontua��es mais altas
     
                  //inicializar o array para evitar conflitos
                  for(int h=0; h<9; h++){
                  arr[h].ponto=0;
                  arr[h].name='AAA';}
                  
     //variavel auxiliar para utiliza��o no bubblesort
     pontos aux;
      
      //abre o ficheiro pontfile que est� definido no ficheiro includes.h
     ifstream pontin (pontfile);
     int i=0,j,r;
     if (pontin.is_open()){//percorre o ficheiro e adiciona ao array "arr"
        while(!pontin.eof()){
                               pontin>>arr[i].name>>arr[i].ponto;
                               i++;
        }
     pontin.close();
     }
     //i � o numero de pontua��es que existem no ficheiro
     r=i;
     string nome;
     //abre o ficheiro pontfile que est� definido no ficheiro includes.h
     ofstream pontout (pontfile);
     cout<<"Insira o nome de jogador \n";
     cin>>nome;
     //se a pontua��o do utilizador for maior que o ultimo jogador no quadro de pontua��es
     if(pontucao>arr[i-1].ponto){
                               //troca as informa��es do ultimo jogador no quadro de pontua��es pelas informa��es do utilizador
                               arr[9].ponto=pontucao;
                               arr[9].name=nome;
                               //algoritmo de ordena��o bubblesort para reordenar o array
                               for(i=0;i<10;i++)
                                                for(j=0;j<10;j++)
                                                                 if(arr[i].ponto>arr[j].ponto){
                                                                                               aux=arr[i];
                                                                                               arr[i]=arr[j];
                                                                                               arr[j]=aux;
                                                                 }
        
                               //escreve o novo quadro de pontua��es no ficheiro
                               if (pontout.is_open()){
                                                     for(i=0;i<9;i++)
                                                                     pontout<<arr[i].name<<" "<<arr[i].ponto<<"\n";
                                                     pontout<<arr[9].name<<" "<<arr[9].ponto;
                               pontout.close();
                               }
     }
     system("CLS");
     //imprime o quadro de pontua��es
     printpodio();
     
     
     
}
//fun��o que adiciona palavra ao ficheiro com a lista de palavras
void adicionarpalavra(){
     string palavra;
     cout<<"Introduza a palavra:\n";
     cin>>palavra;
     //escreve palavra no ficheiro
     ofstream palout (filename, ios::ate | ios::out | ios::in);
     palout<<palavra<<"\n";
     palout.close();
}
     
     
     
     
                   
                   
                   
                   
