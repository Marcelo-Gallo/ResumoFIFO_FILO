#include "cFila.h"
#include <iostream>
using namespace std;

cFila::cFila() {
	inicio = NULL;
	fim = NULL;
	aux = NULL;
}

cFila::cFila(const cFila& orig) {
}

cFila::~cFila() {
}
void cFila::menu(){
	int opc;
	
	cout<<"\nO que deseja fazer com a fila: ";
	cout<<"\n[1]-Inserir elemento.";
	cout<<"\n[2]-Pesquisar elemento.";
	cout<<"\n[3]-Imprimir fila.";
	cout<<"\n[4]-Remover elemento.";
	cout<<"\n[5]-Encerrar sistema."<<endl;
	cin>>opc;
	
	switch (opc){
		case 1:
            this->inserir();
			this->menu();
            break;
        case 2:
            this->pesquisar();
			this->menu();
            break;
        case 3:
            this->imprimir();
			this->menu();
            break;
        case 4:
			this->remover();
			this->menu();
            break;
		case 5:
			cout<<"*=*=*=*=*=*=*ENCERRADO*=*=*=*=*=*=*";
			break;
        default:
            cout<<"Opção inexistente, tente novamente."<<endl;
			this->menu();
	}
}

void cFila::inserir(){
	
	cout<<"\nDigite o valor a ser inserido na fila: ";
	aux = (struct no*) malloc(sizeof(aux)); //malloc cria um espaço para um elemento do tipo "struct no";
	//O correto a dizer seria: malloc seleciona um endereco na memoria e reserva para um dado do tipo "struct no";
	cin>> aux->valor;
	//salva-se a entrada no atributo valor do struct no referente ao endereco de memoria corrente;
	if(inicio == NULL){ //se meu inicio for vazio, significa que a entrada será o primeiro elemento, sendo referenciado como inicio;
		inicio = aux;
	}
	else{
		fim->prox = aux; //caso a entrada não for o primeiro elemento, o ponteiro prox do ultimo elemento inserido receberá o endereco de memoria da entrada (aux nesse caso);
	}
	fim = aux; //independente de ser o primeiro elemento ou não, a entrada sempre atualizará o fim, sendo ela o atual fim da fila;
	fim->prox = NULL; //por ser o ultimo elemento, fim não possui um proximo elemento;
	cout<<"\nElemento inserido com sucesso!";
}

bool cFila::vazia(no *recebido){ //verificando se minha fila está vazia;
	if(recebido == NULL)
		return false;
	else
		return true;
}

void cFila::remover(){
	if(vazia(inicio)){ //com a verificacao, se for true significa que pode remover.
		aux = inicio; //uso aux pra me auxiliar, salvando o endereco de inicio;
		inicio = aux->prox; //meu atual inicio recebe o endereco do proximo elemento (aux contem o endereco do inicio antigo, então ele usa o prox pra indicar qual será o novo inicio);
		free(aux);
		cout<<"\nPrimeiro elemento removido com sucesso, lista atualizada: "<<endl;
		this->imprimir();
	}
	else
		cout<<"Fila vazia";
}

void cFila::imprimir(){
	cout << "\nFila: " << endl;
    for(aux = inicio; aux != NULL; aux = aux->prox){ //contador basico
		//para aux comencando no inicio, até que aux seja nulo, aux recebe o proximo dele
        cout << aux->valor << " "; //mostra os valores
        //cout << endl;
    }
}

void cFila::pesquisar(){
	int valorPesq;
    
    cout << "Digite o valor para pesquisar: ";
    cin >> valorPesq;
    
    for(aux = inicio; aux != NULL; aux = aux->prox){ //mesmo contador, porem fiz um if pra verificar valor por valor
        if(valorPesq == aux->valor){
            cout << "O valor está na fila." << endl;
        }
		else{
			cout<<"O valor não pertence a fila."<<endl;
		}
    }
}