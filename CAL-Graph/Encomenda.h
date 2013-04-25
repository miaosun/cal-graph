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
//#include "Produto.h"

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
	 * \param data �uma string que vai atribuir valor ao membro-dado data.
	 * \param loj �um apontador para a loja que trata a encomenda.
	 * \param cliente �um apontador para o cliente que faz a encomenda.
	 * \param produto �um apontador para o produto que se �pretendido na encomenda
	 */
	Encomenda(string date, Loja *loj, Cliente *clie, Produto *prod);
	//! Construtor que inicializa todos os membros-dado
	/**
	 * \param data �uma string que vai atribuir valor ao membro-dado data.
	 * \param loj �um apontador para a loja que trata a encomenda.
	 * \param cliente �um apontador para o cliente que faz a encomenda.
	 * \param produto �um apontador para o produto que se �pretendido na encomenda
	 * \param cod �um inteiro que vai atribuir valor ao membro-dado codEncomenda.
	 */
	Encomenda(string date, Loja *loj, Cliente *clie, Produto *prod, unsigned int cod);
	//! Membro-fun玢o para retornar o valor do membro-dado codEncomenda
	/** �um membro-fun玢o const para garantir a n鉶 modifica玢o de nenhum membro-dado.
	 * \return um unsgined int com valor do membro-dado codEncomenda. */
	unsigned int getcodEncomenda() const;


	//! Membro-fun玢o para retornar o valor do membro-dado data
	/** �um membro-fun玢o const para garantir a n鉶 modifica玢o de nenhum membro-dado.
	 * \return uma string com valor do membro-dado data. */
	string getData() const;

	//! Membro-fun玢o para retornar o valor do membro-dado cliente
	/** �um membro-fun玢o const para garantir a n鉶 modifica玢o de nenhum membro-dado.
	 * \return um apontador para o cliente para o qual se destina a encomenda */
	Cliente* getCliente() const;

	//! Membro-fun玢o para retornar o valor do membro-dado loja
	/** �um membro-fun玢o const para garantir a n鉶 modifica玢o de nenhum membro-dado.
	 * \return um apontador para a loja que trata a encomenda */
	Loja* getLoja() const;

	//! Membro-fun玢o para retornar o valor do membro-dado produto
	/** �um membro-fun玢o const para garantir a n鉶 modifica玢o de nenhum membro-dado.
	 * \return um apontador para o produto pretendido na encomenda */
	Produto* getProduto() const;

	//! Membro-fun玢o para setar o membro-dado data de um objeto tipo Encomenda j�instanciado
	/** \param data �o conte鷇o da string a ser atribuida ao membro-dado data. */
	void setData(string date);

	//! Membro-fun玢o para setar o membro-dado data de um objeto tipo Encomenda j�instanciado
	/** \param Cliente �o conte鷇o do apontador para Cliente a ser atribuida ao membro-dado Cliente. */
	void setCliente(Cliente * cli);

	//! Membro-fun玢o para setar o membro-dado produto de um objeto tipo Encomenda j�instanciado
	/** \param Produto �o conte鷇o do apontador para Produto a ser atribuida ao membro-dado Produto. */
	void setProduto(Produto * prod);

	//! Overloading do operador de compara玢o == para objetos do tipo Encomenda
	/**
	 * Uma encomenda �igual a outra se os Ids forem iguais
	 * \return um booleano que �true se uma encomenda for igual a outra e false caso contr醨io.
	 */
	bool operator==(const Encomenda & x) const;

	//! Membro-fun玢o estatico para setar o membro-dado estatico countEncomendas
	/** \param n e um inteiro com conte鷇o a ser atribuido ao membro-dado estatico countEncomendas. */
	static void setCount(unsigned int n) {countEncomendas = n;}

	//! Membro-fun玢o estatico para retornar o valor do membro-dado estatico countEncomendas
	/**
	 * \return um inteiro com conte鷇o do membro-dado estatico countEncomendas. */
	static unsigned int getCount() {return countEncomendas;}
	//! Membro-fun玢o que imprime no ecr�os membros-dado de um objeto tipo Cliente
	/**
	 * Membro-fun玢o para imprimir no ecr�o conte鷇o dos membros-dado de um objeto tipo Cliente no formato,
	 * \n Encomenda n鷐ero: \n Descricao: \n Quantidade: \n Data: \n Hora: \n Cliente: \n Produto: \n
	 */
	void imprimeEncomendas() const;
	void resumo() const;

	//TODO falta updates
};


#endif /* ENCOMENDA_H_ */
