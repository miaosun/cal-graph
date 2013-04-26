/*
 * 	FICHEIRO: Encomenda.h
 *	PROJECTO: Projecto CAL - Loja de Comercio Electronico (T3)
 *	DESCRICAO: Definicao da classe Encomenda
 *  TURMA / GRUPO: Turma 2MIEIC2 / Grupo D
 *  AUTORES:
 *  - Jorge Miguel Reis
 *  - Miao Sun
 *  - Vitor Castro
 */

#ifndef ENCOMENDA_H_
#define ENCOMENDA_H_

#include "Cliente.h"

class Encomenda
{
	const unsigned int codEncomenda;
	static unsigned int countEncomendas;
	string data;
	Cliente *cliente;
	Loja *loja;
	Produto *produto;

public:
	//! Construtor que inicializa todos os membros-dado
	/**
	 * \param data e uma string que vai atribuir valor ao membro-dado data.
	 * \param loj e um apontador para a loja que trata a encomenda.
	 * \param cliente e um apontador para o cliente que faz a encomenda.
	 * \param produto  e um apontador para o produto que se e pretendido na encomenda
	 */
	Encomenda(string date, Loja *loj, Cliente *clie, Produto *prod);
	//! Construtor que inicializa todos os membros-dado
	/**
	 * \param data e uma string que vai atribuir valor ao membro-dado data.
	 * \param loj e um apontador para a loja que trata a encomenda.
	 * \param cliente e um apontador para o cliente que faz a encomenda.
	 * \param produto e um apontador para o produto que se e pretendido na encomenda
	 * \param cod e um inteiro que vai atribuir valor ao membro-dado codEncomenda.
	 */
	Encomenda(string date, Loja *loj, Cliente *clie, Produto *prod, unsigned int cod);
	//! Membro-funcao para retornar o valor do membro-dado codEncomenda
	/** e um membro-funcao const para garantir a nao modificacao de nenhum membro-dado.
	 * \return um unsgined int com valor do membro-dado codEncomenda. */
	unsigned int getcodEncomenda() const;


	//! Membro-funcao para retornar o valor do membro-dado data
	/** e um membro-funcao const para garantir a nao modificacao de nenhum membro-dado.
	 * \return uma string com valor do membro-dado data. */
	string getData() const;

	//! Membro-funcao para retornar o valor do membro-dado cliente
	/** e um membro-funcao const para garantir a nao modificacao de nenhum membro-dado.
	 * \return um apontador para o cliente para o qual se destina a encomenda */
	Cliente* getCliente() const;

	//! Membro-funcao para retornar o valor do membro-dado loja
	/** e um membro-funcao const para garantir a nao modificacao de nenhum membro-dado.
	 * \return um apontador para a loja que trata a encomenda */
	Loja* getLoja() const;

	//! Membro-funcao para retornar o valor do membro-dado produto
	/** e um membro-funcao const para garantir a nao modificacao de nenhum membro-dado.
	 * \return um apontador para o produto pretendido na encomenda */
	Produto* getProduto() const;

	//! Membro-funcao para setar o membro-dado data de um objeto tipo Encomenda ja instanciado
	/** \param data e o conteudo da string a ser atribuida ao membro-dado data. */
	void setData(string date);

	//! Membro-funcao para setar o membro-dado data de um objeto tipo Encomenda ja instanciado
	/** \param Cliente e o conteudo do apontador para Cliente a ser atribuida ao membro-dado Cliente. */
	void setCliente(Cliente * cli);

	//! Membro-funcao para setar o membro-dado produto de um objeto tipo Encomenda ja instanciado
	/** \param Produto e o conteudo do apontador para Produto a ser atribuida ao membro-dado Produto. */
	void setProduto(Produto * prod);

	//! Overloading do operador de comparacao == para objetos do tipo Encomenda
	/**
	 * Uma encomenda e igual a outra se os Ids forem iguais
	 * \return um booleano que e true se uma encomenda for igual a outra e false caso contrario.
	 */
	bool operator==(const Encomenda & x) const;

	//! Membro-funcao estatico para setar o membro-dado estatico countEncomendas
	/** \param n e um inteiro com conteudo a ser atribuido ao membro-dado estatico countEncomendas. */
	static void setCount(unsigned int n) {countEncomendas = n;}

	//! Membro-funcao estatico para retornar o valor do membro-dado estatico countEncomendas
	/**
	 * \return um inteiro com conteudo do membro-dado estatico countEncomendas. */
	static unsigned int getCount() {return countEncomendas;}
	//! Membro-funcao que imprime no ecra membros-dado de um objeto tipo Cliente
	/**
	 * Membro-funcao para imprimir no ecra conteudo dos membros-dado de um objeto tipo Cliente no formato,
	 * \n Encomenda numero: \n Descricao: \n Quantidade: \n Data: \n Hora: \n Cliente: \n Produto: \n
	 */
	void imprimeEncomendas() const;
	void resumo() const;

};


#endif /* ENCOMENDA_H_ */
