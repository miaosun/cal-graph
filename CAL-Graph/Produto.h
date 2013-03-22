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

using namespace std;

class Produto {
	static unsigned int countProdutos;
	const unsigned int codProduto;
	string designacao;
	unsigned int stock;
public:
	//! Construtor que inicializa membros-dado
	/**
	 * \param stock � um int que vai atribuir valor ao membro-dado stock.
	 * \param designacao � uma string que vai atribuir valor ao membro-dado designacao.
	 */
	Produto(string desig, int stock);
	//! Membro-fun��o para retornar o valor do membro-dado codPeca
	/** � um membro-fun��o const para garantir a n�o modifica��o de nenhum membro-dado.
	 * \return um unsigned int com conte�do do membro-dado codProduto. */
	unsigned int getCodProduto() const;
	//! Membro-fun��o para retornar o valor do membro-dado stock
	/** � um membro-fun��o const para garantir a n�o modifica��o de nenhum membro-dado.
	 * \return um unsigned int com conte�do do membro-dado stock. */
	unsigned int getStock() const;
	//! Membro-fun��o para retornar o valor do membro-dado designacao
	/** � um membro-fun��o const para garantir a n�o modifica��o de nenhum membro-dado.
	 * \return uma string com conte�do do membro-dado designacao. */
	string getDesignacao() const;
	//! Membro-fun��o para setar o membro-dado stock de um objeto tipo Produto j� instanciado
	/** \param stock � um unsigned int com conte�do a ser atribuido ao membro-dado stock. */
	void setStock(unsigned int stock);
	//! Membro-fun��o para setar o membro-dado designacao de um objeto tipo Produto j� instanciado
	/** \param designacao � uma string com conte�do a ser atribuido ao membro-dado designacao. */
	void setDesignacao(string designacao);
	//! Overloading do operador de compara��o == para objetos do tipo Peca
	/**
	 * Um produto � igual a outro se seus codigos s�o iguais ou se sua designacao sao iguais.
	 * \return um booleano que � true se um produto for igual a outro e false caso contr�rio.
	 */
	bool operator == (const Produto &p1) const;
	//! Membro-fun��o para decrementar o valor do membro-dado stock de um objeto tipo Peca j� instanciado
	void decStock();

	//TODO falta updates
};

#endif /* PRODUTO_H_ */