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
	cout << "\nProduto numero: " << codProduto << endl ;
	cout << "Designação: " << designacao << endl;
	cout << "Quantidade em Stock: " << stock << endl;
	cout << "Preço: " << preco << endl;
}
