/*classe que armazena as palavras contidas no dicion�rio
A necessidade de usar esta classe prende se no facto de tornar a procura das palavras mais r�pida,
esta classe vai armazenar todas as palavras obedecendo a um conjunto de restri�oes "......"
Uma das vantagens de usar esta classe � nao termos que abrir o fiecheiro cada vez que quisermos ir buscar 
ou fazer uma compara��o com uma palavra, pois as palavras que nos interessam , ou seja, obedecem as restri��es 
vao ser armazenadas na lista e ordenadas por tamanho.
*/
class Lista_palavras {
  
  private:
    Lista_palavras *P_inicio, *P_actual, *P_proximo;//ponteiro para o incio , para o actual e para o proximo no da lista, ponteiro anterior
    string palavra;                                 //variavel onde fica armazenada a palavra em cada no da lista
  
  public:    
    
    //contrutores
    Lista_palavras();         
    Lista_palavras(Lista_palavras* ); 
    
    //fun�oes:
    void insere(string word);      //insere uma palavra na lista   
    string getData();              //devolve a palavra guardada no no actual atraves da fun��o getDataEl
    void setData(string word);     //fun��o que quando chamada copia a palavra dada como parametro para a variavel da lista palavra    
    Lista_palavras* getproximo();  //vai buscar o proximo elemento
    void setproximo(Lista_palavras* );//permite alterar o proximo
    string getDataEl();            // faz return da palavra armazenada no n�
    
    
    /*travessia*/
    
    void proximo();//Passa para o proximo n�
    void reset(); //volta para o inicio da lista
    
    boolean isEnd();  //condi�ao de paragem, fun��o que determina quando deve ser parada a inser��o de palavras   
};
//==============================================================================

Lista_palavras::Lista_palavras() {//construtor por defeito
  P_actual = P_inicio = this;
  P_proximo = NULL;
}
//==============================================================================
Lista_palavras::Lista_palavras(Lista_palavras* inicio) { //construtor por parametros
  P_inicio = inicio;
  P_proximo = NULL;
}
//==============================================================================
//fun��o que vai introduzir as palavras na lista atraves das fun�oes auxiliares
//sendo tambem feita a travessia da lista
void Lista_palavras::insere(string word) {
  P_actual->setData(word);                              //introduz a palavra que entrar como parametro na fun��o setData no n� actual da lista 
  P_actual->setproximo(new Lista_palavras(P_inicio)); //"travessia da lista"  O ponteiro actual vai agora apontar para um novo n�,
                                                      //esse novo no passa entao a ser o actual
  P_actual = P_actual->getproximo();                  //retorna o ponteiro proximo de actual
}
//==============================================================================

string Lista_palavras::getDataEl() {//retorna a palavra guardada no n� pretendido
  return palavra;
}
//==============================================================================
string Lista_palavras::getData() {// chama a fun��o getdataEl e retorna a palavra no n� actual;
  return P_actual->getDataEl();
}
//==============================================================================
void Lista_palavras::setData(string word) {
  palavra=word;                     //copia word "palavra dada como parametro" para a variavel na lista
}
//==============================================================================
Lista_palavras* Lista_palavras::getproximo() {//fun��o para ter acesso ao proximo no
  return P_proximo;
}
//==============================================================================
void Lista_palavras::setproximo(Lista_palavras* link) {//aceder ao proximo
  P_proximo = link;
}
//==============================================================================
void Lista_palavras::proximo() {// fun��o usada para fazer a travessia da lista, ir passando actual para o seu seguinte e assim sucessivamenbte
  P_actual = P_actual->getproximo();
}
//==============================================================================

boolean Lista_palavras::isEnd() {// fun�ao que determina quando chegamos ao fim da lista, condi��o de paragem para a travessia
  return P_actual->getproximo() == NULL ? 1 : 0;//operador ternario, devolve 1 se null, 0 se nao null
}
//==============================================================================
void Lista_palavras::reset() {// fun�ao que ao ser chamada faz com que o ponteiro actual "P_actual" aponte para o inicio da lista
  P_actual = P_inicio;
}
//==============================================================================
