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


Encomenda::Encomenda(string desc, int quant, string date, string hor, Cliente * clie, Produto * prod): codEncomenda(++countEncomendas) {
	descricao=desc;
	quantidade=quant;
	data=date;
	hora=hor;
	cliente=clie;
	produto=prod;

}

// GETS Encomendas

string Encomenda::getDescricao() const {
	return descricao;
}

unsigned int Encomenda::getQuantidade() const {
	return quantidade;
}

string Encomenda::getData() const {
	return data;
}

string Encomenda::getHora() const {
	return hora;
}

Cliente* Encomenda::getCliente() const {
	return cliente;
}

Produto* Encomenda::getProduto() const {
	return produto;
}

int Encomenda::getNumEncomendas() {
	return countEncomendas;
}

unsigned int Encomenda::getcodEncomenda()const{

	return codEncomenda;
}

// SETS

void Encomenda::setDescricao(string desc) {
	descricao=desc;
}

void Encomenda::setQuantidade(int quant) {
	quantidade=quant;
}

void Encomenda::setHora(string hor) {
	hora=hor;
}

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
	cout << "Descrição: " << descricao << endl;
	cout << "Quantidade: " << quantidade << endl;
	cout << "Data: " << data << endl;
	cout << "Hora: " << hora << endl;
	cout << "\nDados do Cliente: ";
	//cout << "Cliente: " << cliente->imprimeCliente() << endl;
	/*cout << "\nDados do Produto: ";
	cout << "Cliente: " << produto->.info() << endl;*/
}


// OPERATOR ==
bool Encomenda::operator== (const Encomenda& x) const{
	if(getcodEncomenda() == x.getcodEncomenda())
		return true;	
	else return false;
}
