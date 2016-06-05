/*classe que armazena as palavras contidas no dicionário
A necessidade de usar esta classe prende se no facto de tornar a procura das palavras mais rápida,
esta classe vai armazenar todas as palavras obedecendo a um conjunto de restriçoes "......"
Uma das vantagens de usar esta classe é nao termos que abrir o fiecheiro cada vez que quisermos ir buscar 
ou fazer uma comparação com uma palavra, pois as palavras que nos interessam , ou seja, obedecem as restrições 
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
    
    //funçoes:
    void insere(string word);      //insere uma palavra na lista   
    string getData();              //devolve a palavra guardada no no actual atraves da função getDataEl
    void setData(string word);     //função que quando chamada copia a palavra dada como parametro para a variavel da lista palavra    
    Lista_palavras* getproximo();  //vai buscar o proximo elemento
    void setproximo(Lista_palavras* );//permite alterar o proximo
    string getDataEl();            // faz return da palavra armazenada no nó
    
    
    /*travessia*/
    
    void proximo();//Passa para o proximo nó
    void reset(); //volta para o inicio da lista
    
    boolean isEnd();  //condiçao de paragem, função que determina quando deve ser parada a inserção de palavras   
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
//função que vai introduzir as palavras na lista atraves das funçoes auxiliares
//sendo tambem feita a travessia da lista
void Lista_palavras::insere(string word) {
  P_actual->setData(word);                              //introduz a palavra que entrar como parametro na função setData no nó actual da lista 
  P_actual->setproximo(new Lista_palavras(P_inicio)); //"travessia da lista"  O ponteiro actual vai agora apontar para um novo nó,
                                                      //esse novo no passa entao a ser o actual
  P_actual = P_actual->getproximo();                  //retorna o ponteiro proximo de actual
}
//==============================================================================

string Lista_palavras::getDataEl() {//retorna a palavra guardada no nó pretendido
  return palavra;
}
//==============================================================================
string Lista_palavras::getData() {// chama a função getdataEl e retorna a palavra no nó actual;
  return P_actual->getDataEl();
}
//==============================================================================
void Lista_palavras::setData(string word) {
  palavra=word;                     //copia word "palavra dada como parametro" para a variavel na lista
}
//==============================================================================
Lista_palavras* Lista_palavras::getproximo() {//função para ter acesso ao proximo no
  return P_proximo;
}
//==============================================================================
void Lista_palavras::setproximo(Lista_palavras* link) {//aceder ao proximo
  P_proximo = link;
}
//==============================================================================
void Lista_palavras::proximo() {// função usada para fazer a travessia da lista, ir passando actual para o seu seguinte e assim sucessivamenbte
  P_actual = P_actual->getproximo();
}
//==============================================================================

boolean Lista_palavras::isEnd() {// funçao que determina quando chegamos ao fim da lista, condição de paragem para a travessia
  return P_actual->getproximo() == NULL ? 1 : 0;//operador ternario, devolve 1 se null, 0 se nao null
}
//==============================================================================
void Lista_palavras::reset() {// funçao que ao ser chamada faz com que o ponteiro actual "P_actual" aponte para o inicio da lista
  P_actual = P_inicio;
}
//==============================================================================
