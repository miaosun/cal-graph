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
#include "Produto.h"

using namespace std;

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
	 * \param data é uma string que vai atribuir valor ao membro-dado data.
	 * \param loj é um apontador para a loja que trata a encomenda.
	 * \param cliente é um apontador para o cliente que faz a encomenda.
	 * \param produto é um apontador para o produto que se é pretendido na encomenda
	 */
	Encomenda(string date, Loja *loj, Cliente *clie, Produto *prod);
	//! Construtor que inicializa todos os membros-dado
	/**
	 * \param data é uma string que vai atribuir valor ao membro-dado data.
	 * \param loj é um apontador para a loja que trata a encomenda.
	 * \param cliente é um apontador para o cliente que faz a encomenda.
	 * \param produto é um apontador para o produto que se é pretendido na encomenda
	 * \param cod é um inteiro que vai atribuir valor ao membro-dado codEncomenda.
	 */
	Encomenda(string date, Loja *loj, Cliente *clie, Produto *prod, unsigned int cod);
	//! Membro-função para retornar o valor do membro-dado codEncomenda
	/** É um membro-função const para garantir a não modificação de nenhum membro-dado.
	 * \return um unsgined int com valor do membro-dado codEncomenda. */
	unsigned int getcodEncomenda() const;


	//! Membro-função para retornar o valor do membro-dado data
	/** É um membro-função const para garantir a não modificação de nenhum membro-dado.
	 * \return uma string com valor do membro-dado data. */
	string getData() const;

	//! Membro-função para retornar o valor do membro-dado cliente
	/** É um membro-função const para garantir a não modificação de nenhum membro-dado.
	 * \return um apontador para o cliente para o qual se destina a encomenda */
	Cliente* getCliente() const;

	//! Membro-função para retornar o valor do membro-dado loja
	/** É um membro-função const para garantir a não modificação de nenhum membro-dado.
	 * \return um apontador para a loja que trata a encomenda */
	Loja* getLoja() const;

	//! Membro-função para retornar o valor do membro-dado produto
	/** É um membro-função const para garantir a não modificação de nenhum membro-dado.
	 * \return um apontador para o produto pretendido na encomenda */
	Produto* getProduto() const;

	//! Membro-função para setar o membro-dado data de um objeto tipo Encomenda já instanciado
	/** \param data é o conteúdo da string a ser atribuida ao membro-dado data. */
	void setData(string date);

	//! Membro-função para setar o membro-dado data de um objeto tipo Encomenda já instanciado
	/** \param Cliente é o conteúdo do apontador para Cliente a ser atribuida ao membro-dado Cliente. */
	void setCliente(Cliente * cli);

	//! Membro-função para setar o membro-dado produto de um objeto tipo Encomenda já instanciado
	/** \param Produto é o conteúdo do apontador para Produto a ser atribuida ao membro-dado Produto. */
	void setProduto(Produto * prod);

	//! Overloading do operador de comparação == para objetos do tipo Encomenda
	/**
	 * Uma encomenda é igual a outra se os Ids forem iguais
	 * \return um booleano que é true se uma encomenda for igual a outra e false caso contrário.
	 */
	bool operator==(const Encomenda & x) const;

	//! Membro-função estatico para setar o membro-dado estatico countEncomendas
	/** \param n e um inteiro com conteúdo a ser atribuido ao membro-dado estatico countEncomendas. */
	static void setCount(unsigned int n) {countEncomendas = n;}

	//! Membro-função estatico para retornar o valor do membro-dado estatico countEncomendas
	/**
	 * \return um inteiro com conteúdo do membro-dado estatico countEncomendas. */
	static unsigned int getCount() {return countEncomendas;}
	//! Membro-função que imprime no ecrã os membros-dado de um objeto tipo Cliente
	/**
	 * Membro-função para imprimir no ecrã o conteúdo dos membros-dado de um objeto tipo Cliente no formato,
	 * \n Encomenda número: \n Descricao: \n Quantidade: \n Data: \n Hora: \n Cliente: \n Produto: \n
	 */
	void imprimeEncomendas() const;
	void resumo() const;

	//TODO falta updates
};


#endif /* ENCOMENDA_H_ */
