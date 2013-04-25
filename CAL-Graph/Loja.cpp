/*
 * 	FICHEIRO: Loja.h
 *	PROJECTO: Projecto CAL - Loja de Comercio Electronico (T3)
 *	DESCRICAO: Implementacao da classe Loja
 *  TURMA / GRUPO: Turma 2MIEIC2 / Grupo D
 *  AUTORES:
 *  - Jorge Miguel Reis
 *  - Miao Sun
 *  - Vitor Castro
 */

#include "Loja.h"
#include <cstdio>

unsigned int Loja::countLojas=0;

Loja::Loja(string nm, string mor):codLoja(++countLojas) {
	nome=nm;
	morada=mor;

}

Loja::Loja(string nm, string mor, unsigned int cod):codLoja(cod) {
	nome=nm;
	morada=mor;
}
// GETS Loja

string Loja::getNome() const {
	return nome;
}

string Loja::getMorada() const {
	return morada;
}


unsigned int Loja::getCodLoja() const{

	return codLoja;

}

vector <Produto *> Loja::getProdutos() const{

	return produtos;
}

// SETS Loja

void Loja::setNome(string nm) {
	nome=nm;
}

void Loja::setMorada(string m) {
	morada=m;
}


void Loja::addProduto()
{
	string desig;
	int stock;
	double preco;
	cout << "Inserir Produto" << endl << endl;
	cout << "Designa玢o: ";
	getline(cin,desig);

	for(unsigned int i=0; i<produtos.size();i++) {
		if(produtos[i]->getDesignacao()==desig) {
			//excepcao todo
			cout << "Produto j�existe!" << endl;
			return;
		}
	}

	cout << "Preco: ";
	fflush(stdin);
	cin >> preco;
	cout << "Stock: ";
	fflush(stdin);
	cin >> stock;

	Produto *p = new Produto(desig,stock,preco);
	produtos.push_back(p);
	cout << "Produto adicionado com sucesso!"<< endl;
}

void Loja::removeProduto(unsigned int codProduto)
{
	cout << "Produtos Disponiveis na Loja:" << endl;
	for(unsigned int i=0; i<produtos.size();i++) {
		produtos[i]->resumo();
	}
	cout << endl;

	string desig;
	cout << "Remover Produto" << endl << endl;
	cout << "Designa玢o: ";
	getline(cin,desig);

	for(unsigned int i=0; i<produtos.size();i++) {
		if(produtos[i]->getDesignacao()==desig) {
			produtos.erase(produtos.begin()+i);
			cout << "Produto eliminado com sucesso!" << endl;
			return;
		}
	}
	cout << "Produto nao existe!" << endl;
}

// IMPRIME

ostream & operator << (ostream & o, const Loja & l){
	o << "Id Loja: "  << l.getCodLoja() << " | Nome: " << l.getNome();
	o << " | Morada: " << l.getMorada();
	return o;
}


void Loja::imprimeLoja() const {
	cout << "\nLoja numero: " << codLoja << endl ;
	cout << "Nome: " << nome << endl;
	cout << "Morada: " << morada << endl;
	cout<<"Produtos Existentes na Loja:"<<endl;
	if(produtos.size()==0) cout<<"Loja sem produtos de momento"<<endl;
	else
		for(unsigned int i=0;i<produtos.size();i++)
			produtos[i]->info();

}

string Loja::toString() {
	stringstream ss;
	ss<<"|"<<this->codLoja<<"|"<<this->nome<<"|"<<this->morada<<"|";
	return ss.str();
}

// OPERATOR ==
bool Loja::operator== (const Loja& x) const{
	if(getCodLoja() == x.getCodLoja())
		return true;	
	else return false;
}
