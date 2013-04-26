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
	cout << "Designacao: ";
	getline(cin,desig);

	for(unsigned int i=0; i<produtos.size();i++) {
		if(produtos[i]->getDesignacao()==desig) {
			//excepcao todo
			cout << "Produto ja existe!" << endl;
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

void Loja::editProduto() {
	cout << "Produtos Disponiveis na Loja:" << endl;
	listaProduto();

	string desig;
	cout << "Editar Produto" << endl << endl;
	cout << "Designacao: ";
	getline(cin,desig);

	int ind = procuraProduto(desig);
	if(ind==-1)
		cout << "Produto nao existe!" << endl;
	else
	{
		produtos[ind]->update();
	}
}

void Loja::listaProduto() {
	for(unsigned int i=0; i<produtos.size();i++) {
		produtos[i]->resumo();
	}
	cout << endl;
}

int Loja::procuraProduto(string desig) {
	for(unsigned int i=0; i<produtos.size();i++) {
		if(produtos[i]->getDesignacao()==desig) {
			return i;
		}
	}
	return -1;
}

void Loja::removeProduto(unsigned int codProduto)
{
	cout << "Produtos Disponiveis na Loja:" << endl;
	listaProduto();

	string desig;
	cout << "Remover Produto" << endl << endl;
	cout << "Designacao: ";
	getline(cin,desig);

	int ind = procuraProduto(desig);
	if(ind==-1)
		cout << "Produto nao existe!" << endl;
	else
	{
		produtos.erase(produtos.begin()+ind);
		cout << "Produto removido com sucesso!" << endl;
	}
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


vector<string> Loja::editLoja()
{
	vector<string> opcoes;
	stringstream ss;
	opcoes.push_back("Escolha o que editar:");
	opcoes.push_back("");
	ss<<"1 - Editar Nome: "<<this->nome;
	opcoes.push_back(ss.str());
	ss.str("");
	ss<<"2 - Editar Morada: "<<this->morada;
	opcoes.push_back(ss.str());
	ss.str("");

	return opcoes;
}
