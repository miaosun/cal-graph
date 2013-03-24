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
	
	string descricao;
	int quantidade;	
	string data;	
	string hora;
	Cliente *cliente;
	Produto *produto;
	
public:
//! Construtor que inicializa todos os membros-dado
	/**
	* \param descricao � uma string que vai atribuir valor ao membro-dado descricao.
	 * \param quantidade � um inteiro que vai atribuir valor ao membro-dado quantidade.
	 * \param data � uma string que vai atribuir valor ao membro-dado data.
	 * \param hora � uma string que vai atribuir valor ao membro-dado horaa.
	 * \param cliente � um apontador para o cliente que faz a encomenda.
	 * \param produto � um apontador para o produto que se � pretendido na encomenda
	 */
	Encomenda(string desc, int quant, string date, string hor, Cliente *clie, Produto *prod);
	//! Membro-fun��o para retornar o valor do membro-dado codEncomenda
	/** � um membro-fun��o const para garantir a n�o modifica��o de nenhum membro-dado.
	 * \return um unsgined int com valor do membro-dado codEncomenda. */
	unsigned int getcodEncomenda() const;
	
	//! Membro-fun��o para retornar o valor do membro-dado descricao
	/** � um membro-fun��o const para garantir a n�o modifica��o de nenhum membro-dado.
	 * \return uma string com valor do membro-dado descricao. */
	string getDescricao() const;
	
	//! Membro-fun��o para retornar o valor do membro-dado quantidade
	/** � um membro-fun��o const para garantir a n�o modifica��o de nenhum membro-dado.
	 * \return um unsgined int com valor do membro-dado quantidade. */
	unsigned int getQuantidade() const;
	
	//! Membro-fun��o para retornar o n�mero de encomendas j� efectuadas
	/** \return um int com a quantidade de encomendas j� realizadas. */
	static int getNumEncomendas();
	
	//! Membro-fun��o para retornar o valor do membro-dado data
	/** � um membro-fun��o const para garantir a n�o modifica��o de nenhum membro-dado.
	 * \return uma string com valor do membro-dado data. */
	string getData() const;
	
	//! Membro-fun��o para retornar o valor do membro-dado hora
	/** � um membro-fun��o const para garantir a n�o modifica��o de nenhum membro-dado.
	 * \return uma string com valor do membro-dado hora. */
	string getHora() const;
	
	//! Membro-fun��o para retornar o valor do membro-dado cliente
	/** � um membro-fun��o const para garantir a n�o modifica��o de nenhum membro-dado.
	 * \return um apontador para o cliente para o qual se destina a encomenda */
	Cliente* getCliente() const;
	
		//! Membro-fun��o para retornar o valor do membro-dado produto
	/** � um membro-fun��o const para garantir a n�o modifica��o de nenhum membro-dado.
	 * \return um apontador para o produto pretendido na encomenda */
	Produto* getProduto() const;
	
	//! Membro-fun��o para setar o membro-dado nome de um objeto tipo Encomenda j� instanciado
	/** \param descricao � o conte�do da string a ser atribuida ao membro-dado descricao. */
	void setDescricao(string desc);
	
	//! Membro-fun��o para setar o membro-dado quantidade de um objeto tipo Encomenda j� instanciado
	/** \param quantidade � o conte�do do inteiro a ser atribuido ao membro-dado quantidade. */
	void setQuantidade(int quant);
	
	//! Membro-fun��o para setar o membro-dado hora de um objeto tipo Encomenda j� instanciado
	/** \param hora � o conte�do da string a ser atribuida ao membro-dado hora. */
	void setHora(string hor);
	
	//! Membro-fun��o para setar o membro-dado data de um objeto tipo Encomenda j� instanciado
	/** \param data � o conte�do da string a ser atribuida ao membro-dado data. */
	void setData(string date);
	
	//! Membro-fun��o para setar o membro-dado data de um objeto tipo Encomenda j� instanciado
	/** \param Cliente � o conte�do do apontador para Cliente a ser atribuida ao membro-dado Cliente. */
	void setCliente(Cliente * cli);
	
	//! Membro-fun��o para setar o membro-dado produto de um objeto tipo Encomenda j� instanciado
	/** \param Produto � o conte�do do apontador para Produto a ser atribuida ao membro-dado Produto. */
	void setProduto(Produto * prod);
		
	//! Overloading do operador de compara��o == para objetos do tipo Encomenda
	/**
	 * Uma encomenda � igual a outra se os Ids forem iguais
	 * \return um booleano que � true se uma encomenda for igual a outra e false caso contr�rio.
	 */
	bool operator==(const Encomenda & x) const;
	
	//! Membro-fun��o estatico para setar o membro-dado estatico countEncomendas
	/** \param n e um inteiro com conte�do a ser atribuido ao membro-dado estatico countEncomendas. */
	static void setCount(unsigned int n) {countEncomendas = n;}
	
	//! Membro-fun��o estatico para retornar o valor do membro-dado estatico countEncomendas
	/**
	 * \return um inteiro com conte�do do membro-dado estatico countEncomendas. */
	static unsigned int getCount() {return countEncomendas;}
	//! Membro-fun��o que imprime no ecr� os membros-dado de um objeto tipo Cliente
	/**
	 * Membro-fun��o para imprimir no ecr� o conte�do dos membros-dado de um objeto tipo Cliente no formato,
	 * \n Encomenda n�mero: \n Descricao: \n Quantidade: \n Data: \n Hora: \n Cliente: \n Produto: \n
	 */
	void imprimeEncomendas() const;

	//TODO falta updates
};


#endif /* ENCOMENDA_H_ */
