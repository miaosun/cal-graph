/*
 * 	FICHEIRO: Produto.h
 *	PROJECTO: Projecto CAL - Loja de Comercio Electronico (T3)
 *	DESCRICAO: Definicao da classe Produto
 *  TURMA / GRUPO: Turma 2MIEIC2 / Grupo D
 *  AUTORES:
 *  - Jorge Miguel Reis
 *  - Miao Sun
 *  - Vitor Castro
 */

#ifndef PRODUTO_H_
#define PRODUTO_H_

#include <string>
#include <iostream>
#include <sstream>
#include <stdio.h>

using namespace std;

class Produto {
	static unsigned int countProdutos;
	const unsigned int codProduto;
	string designacao;
	unsigned int stock;
	double preco;
public:
	//! Construtor que inicializa membros-dado
	/**
	 * \param stock �um int que vai atribuir valor ao membro-dado stock.
	 * \param designacao �uma string que vai atribuir valor ao membro-dado designacao.
	 * \param preco �um double que vai atribuir valor ao membro-dado preco.
	 */
	Produto(string desig, int stock, double p);
	//! Membro-fun玢o para retornar o valor do membro-dado codPeca
	/** �um membro-fun玢o const para garantir a n鉶 modifica玢o de nenhum membro-dado.
	 * \return um unsigned int com conte鷇o do membro-dado codProduto. */
	unsigned int getCodProduto() const;
	//! Membro-fun玢o para retornar o valor do membro-dado preco
	/** �um membro-fun玢o const para garantir a n鉶 modifica玢o de nenhum membro-dado.
	 * \return um double com conte鷇o do membro-dado preco. */
	double getPreco() const;
	//! Membro-fun玢o para retornar o valor do membro-dado stock
	/** �um membro-fun玢o const para garantir a n鉶 modifica玢o de nenhum membro-dado.
	 * \return um unsigned int com conte鷇o do membro-dado stock. */
	unsigned int getStock() const;
	//! Membro-fun玢o para retornar o valor do membro-dado designacao
	/** �um membro-fun玢o const para garantir a n鉶 modifica玢o de nenhum membro-dado.
	 * \return uma string com conte鷇o do membro-dado designacao. */
	string getDesignacao() const;
	//! Membro-fun玢o para setar o membro-dado stock de um objeto tipo Produto j�instanciado
	/** \param stock �um unsigned int com conte鷇o a ser atribuido ao membro-dado stock. */
	void setStock(unsigned int stock);
	//! Membro-fun玢o para setar o membro-dado preco de um objeto tipo Produto j�instanciado
	/** \param preco �um double com conte鷇o a ser atribuido ao membro-dado preco. */
	void setPreco(double preco);
	//! Membro-fun玢o para setar o membro-dado designacao de um objeto tipo Produto j�instanciado
	/** \param designacao �uma string com conte鷇o a ser atribuido ao membro-dado designacao. */
	void setDesignacao(string designacao);
	//! Overloading do operador de compara玢o == para objetos do tipo Peca
	/**
	 * Um produto �igual a outro se seus codigos s鉶 iguais ou se sua designacao sao iguais.
	 * \return um booleano que �true se um produto for igual a outro e false caso contr醨io.
	 */
	bool operator == (const Produto &p1) const;
	//! Membro-fun玢o para decrementar o valor do membro-dado stock de um objeto tipo Peca j�instanciado
	void decStock();
	//! Membro-fun玢o que imprime no ecr�os membros-dado de um objeto tipo Produto
	/**
	 * Membro-fun玢o para imprimir no ecr�o conte鷇o dos membros-dado de um objeto tipo Produto no formato,
	 * \n Produto n鷐ero: \n Designacao: \n Quantidade em stock: \n Preco: \n
	 */
	void info() const;
	//! Membro-fun玢o estatico para setar o membro-dado estatico countProdutos
	/** \param n e um inteiro com conte鷇o a ser atribuido ao membro-dado estatico countProdutos. */
	static void setCount(unsigned int n)  {countProdutos = n;}

	string toString();
	void resumo();
	void update();

	//TODO falta updates
};

#endif /* PRODUTO_H_ */
