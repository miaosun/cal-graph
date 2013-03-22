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

using namespace std;

class Produto {
	static unsigned int countProdutos;
	const unsigned int codProduto;
	string designacao;
	unsigned int stock;
public:
	//! Construtor que inicializa membros-dado
	/**
	 * \param stock é um int que vai atribuir valor ao membro-dado stock.
	 * \param designacao é uma string que vai atribuir valor ao membro-dado designacao.
	 */
	Produto(string desig, int stock);
	//! Membro-função para retornar o valor do membro-dado codPeca
	/** É um membro-função const para garantir a não modificação de nenhum membro-dado.
	 * \return um unsigned int com conteúdo do membro-dado codProduto. */
	unsigned int getCodProduto() const;
	//! Membro-função para retornar o valor do membro-dado stock
	/** É um membro-função const para garantir a não modificação de nenhum membro-dado.
	 * \return um unsigned int com conteúdo do membro-dado stock. */
	unsigned int getStock() const;
	//! Membro-função para retornar o valor do membro-dado designacao
	/** É um membro-função const para garantir a não modificação de nenhum membro-dado.
	 * \return uma string com conteúdo do membro-dado designacao. */
	string getDesignacao() const;
	//! Membro-função para setar o membro-dado stock de um objeto tipo Produto já instanciado
	/** \param stock é um unsigned int com conteúdo a ser atribuido ao membro-dado stock. */
	void setStock(unsigned int stock);
	//! Membro-função para setar o membro-dado designacao de um objeto tipo Produto já instanciado
	/** \param designacao é uma string com conteúdo a ser atribuido ao membro-dado designacao. */
	void setDesignacao(string designacao);
	//! Overloading do operador de comparação == para objetos do tipo Peca
	/**
	 * Um produto é igual a outro se seus codigos são iguais ou se sua designacao sao iguais.
	 * \return um booleano que é true se um produto for igual a outro e false caso contrário.
	 */
	bool operator == (const Produto &p1) const;
	//! Membro-função para decrementar o valor do membro-dado stock de um objeto tipo Peca já instanciado
	void decStock();

	//TODO falta updates
};

#endif /* PRODUTO_H_ */
