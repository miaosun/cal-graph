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
	 * \param stock e um int que vai atribuir valor ao membro-dado stock.
	 * \param designacao e uma string que vai atribuir valor ao membro-dado designacao.
	 * \param preco e um double que vai atribuir valor ao membro-dado preco.
	 */
	Produto(string desig, int stock, double p);
	//! Membro-funcao para retornar o valor do membro-dado codPeca
	/** e um membro-funcao const para garantir a nao modificacao de nenhum membro-dado.
	 * \return um unsigned int com conteudo do membro-dado codProduto. */
	unsigned int getCodProduto() const;
	//! Membro-funcao para retornar o valor do membro-dado preco
	/** e um membro-funcao const para garantir a nao modificacao de nenhum membro-dado.
	 * \return um double com conteudo do membro-dado preco. */
	double getPreco() const;
	//! Membro-funcao para retornar o valor do membro-dado stock
	/** e um membro-funcao const para garantir a nao modificacao de nenhum membro-dado.
	 * \return um unsigned int com conteudo do membro-dado stock. */
	unsigned int getStock() const;
	//! Membro-funcao para retornar o valor do membro-dado designacao
	/** e um membro-funcao const para garantir a nao modificacao de nenhum membro-dado.
	 * \return uma string com conteudo do membro-dado designacao. */
	string getDesignacao() const;
	//! Membro-funcao para setar o membro-dado stock de um objeto tipo Produto ja instanciado
	/** \param stock e um unsigned int com conteudo a ser atribuido ao membro-dado stock. */
	void setStock(unsigned int stock);
	//! Membro-funcao para setar o membro-dado preco de um objeto tipo Produto ja instanciado
	/** \param preco e um double com conteudo a ser atribuido ao membro-dado preco. */
	void setPreco(double preco);
	//! Membro-funcao para setar o membro-dado designacao de um objeto tipo Produto ja instanciado
	/** \param designacao e uma string com conteudo a ser atribuido ao membro-dado designacao. */
	void setDesignacao(string designacao);
	//! Overloading do operador de comparacao == para objetos do tipo Peca
	/**
	 * Um produto e igual a outro se seus codigos sao iguais ou se sua designacao sao iguais.
	 * \return um booleano que e true se um produto for igual a outro e false caso contr醨io.
	 */
	bool operator == (const Produto &p1) const;
	//! Membro-funcao para decrementar o valor do membro-dado stock de um objeto tipo Peca ja instanciado
	void decStock();
	//! Membro-funcao que imprime no ecra membros-dado de um objeto tipo Produto
	/**
	 * Membro-funcao para imprimir no ecra conteudo dos membros-dado de um objeto tipo Produto no formato,
	 * \n Produto numero: \n Designacao: \n Quantidade em stock: \n Preco: \n
	 */
	void info() const;
	//! Membro-funcao estatico para setar o membro-dado estatico countProdutos
	/** \param n e um inteiro com conteudo a ser atribuido ao membro-dado estatico countProdutos. */
	static void setCount(unsigned int n)  {countProdutos = n;}

	string toString();
	void resumo();
	void update();

	//TODO falta updates
};

#endif /* PRODUTO_H_ */
