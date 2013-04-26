/*
 * 	FICHEIRO: Encomenda.cpp
 *	PROJECTO: Projecto CAL - Loja de Comercio Electronico (T3)
 *	DESCRICAO: Implementacao da classe Encomenda
 *  TURMA / GRUPO: Turma 2MIEIC2 / Grupo D
 *  AUTORES:
 *  - Jorge Miguel Reis
 *  - Miao Sun
 *  - Vitor Castro
 */

#include "Encomenda.h"
#include <cstdio>

//inicializacao de variavel estatica
unsigned int Encomenda::countEncomendas=0;


Encomenda::Encomenda(string date, Loja *loj, Cliente * clie, Produto * prod): codEncomenda(++countEncomendas) {
	data=date;
	cliente=clie;
	produto=prod;
	loja=loj;
}

Encomenda::Encomenda(string date, Loja *loj, Cliente * clie, Produto * prod, unsigned int cod): codEncomenda(cod) {
	data=date;
	cliente=clie;
	produto=prod;
	loja=loj;
}

// GETS Encomendas

string Encomenda::getData() const {
	return data;
}

Cliente* Encomenda::getCliente() const {
	return cliente;
}

Loja* Encomenda::getLoja() const {
	return loja;
}

Produto* Encomenda::getProduto() const {
	return produto;
}

unsigned int Encomenda::getcodEncomenda()const{

	return codEncomenda;
}

// SETS

void Encomenda::setData(string date) {
	data=date;
}

void Encomenda::setCliente(Cliente *cli) {
	cliente=cli;
}

void Encomenda::setProduto(Produto *prod) {
	produto=prod;
}


// IMPRIME

void Encomenda::imprimeEncomendas() const {
	cout << "\nEncomenda numero: " << codEncomenda << endl ;
	cout << "Data: " << data;
	cliente->resumo();
	cout << "\nDados do Produto: " << endl;
	produto->info();
}

void Encomenda::resumo() const {
	cout << "Encomenda "<<codEncomenda<<" | "<< cliente->getNome()<<" | "<<"Produto: "<<produto->getDesignacao()<<" | "<<"Loja: "<< loja->getNome()<<endl;
}


// OPERATOR ==
bool Encomenda::operator== (const Encomenda& x) const{
	if(getcodEncomenda() == x.getcodEncomenda())
		return true;	
	else return false;
}
