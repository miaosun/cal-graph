/*
 * 	FICHEIRO: Produto.cpp
 *	PROJECTO: Projecto CAL - Loja de Comercio Electronico (T3)
 *	DESCRICAO: Implementacao da classe Produto
 *  TURMA / GRUPO: Turma 2MIEIC2 / Grupo D
 *  AUTORES:
 *  - Jorge Miguel Reis
 *  - Miao Sun
 *  - Vitor Castro
 */

#include "Produto.h"

unsigned int Produto::countProdutos = 0;

Produto::Produto(string d, int s,double p): codProduto(++countProdutos) {
	designacao=d;
	stock=s;
	preco=p;
}

unsigned int Produto::getCodProduto() const{
	return codProduto;
}
unsigned int Produto::getStock() const{
	return stock;
}

double Produto::getPreco() const{
	return preco;
}

string Produto::getDesignacao() const{
	return designacao;
}

void Produto::setStock(unsigned int stock){
	this->stock = stock;
}

void Produto::setPreco(double preco){
	this->preco = preco;
}

void Produto::setDesignacao(string designacao){
	this->designacao = designacao;
}

bool Produto::operator == (const Produto &p1) const{
	if(codProduto == p1.getCodProduto() || (designacao == p1.getDesignacao() ))
		return true;
	else return false;
}

void Produto::decStock() {
	stock--;
}


// IMPRIME

void Produto::info() const {
	cout << "Produto numero: " << codProduto << endl ;
	cout << "Designacao: " << designacao << endl;
	cout << "Quantidade em Stock: " << stock << endl;
	cout << "Preco: " << preco << endl;
}

void Produto::resumo() {
	cout << "Produto " << codProduto << " | " << designacao << " | "<< "Preco: " << preco << " | "<< "Stock: " << stock << endl;
}


string Produto::toString() {
	stringstream ss;
	ss<<"|"<<this->getDesignacao()<<"|"<<this->getPreco()<<"|"<<this->getStock()<<"|";
	return ss.str();
}

void Produto::update() {
	string temp;
	int temp2;
	int escolha=-1;

	cout << "Informacao a alterar: " << endl;
	cout << "1-Designacao\n2-Stock\n3-Preco\n(0-Voltar)" << endl;
	while(escolha!=0 && escolha!=1 && escolha!=2 && escolha!=3) {
		cout << "Escolha: ";
		fflush(stdin);
		cin >> escolha;
	}

	switch(escolha){
	case 0: break;
	case 1:
	{
		cout << "Nova Designacao: ";
		fflush(stdin);
		getline(cin,temp);
		setDesignacao(temp);
		cout << "Designacao editada!" << endl;
		break;
	}
	case 2:
	{
		cout << "Novo Stock: ";
		fflush(stdin);
		cin >> temp2;
		setStock(temp2);
		cout << "Stock editado!" << endl;
		break;
	}
	case 3:
	{
		cout << "Novo Preco: ";
		fflush(stdin);
		cin >> temp2;
		setPreco(temp2);
		cout << "Preco editado!" << endl;
		break;
	}
	default :
	{
		cout << "Numero errado! Tente novamente.." << endl;
		break;
	}
	}
}
