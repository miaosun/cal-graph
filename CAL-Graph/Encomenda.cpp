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


Encomenda::Encomenda(string desc, int quant, string date, string hor, Cliente * clie, Produto * prod) {
	descricao=desc;
	quantidade=quant;
	data=date;
	hora=hor;
	cliente=clie;
	produto=prod;
	countEncomenda++;
}

// GETS Encomendas

string Encomenda::getDescricao() const {
	return descricao;
}

int Encomenda::getQuantidade() const {
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

// SETS CLIENTE

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
	cout << "Cliente: " << cliente.info() << endl;
	cout << "\nDados do Produto: ";
	cout << "Cliente: " << produto.info() << endl;
}


// OPERATOR ==
bool Cliente::operator== (const Cliente& x) const{
	if(getNome() == x.getNome())
		return true;
	else if(getNIF() == x.getNIF())
		return true;
	else return false;
}
