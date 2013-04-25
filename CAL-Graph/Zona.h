/*
 * 	FICHEIRO: Zona.h
 *	PROJECTO: Projecto CAL - Loja de Comercio Electronico (T3)
 *	DESCRICAO: Definicao da classe Zona
 *  TURMA / GRUPO: Turma 2MIEIC2 / Grupo D
 *  AUTORES:
 *  - Jorge Miguel Reis
 *  - Miao Sun
 *  - Vitor Castro
 */

#ifndef ZONA_H_
#define ZONA_H_

#include "Loja.h"

#include <string>
using namespace std;

class Zona
{
	const unsigned int codZona;
	static unsigned int countZonas;
	string designacao;
	Loja *loja;

public:
	//! Construtor que inicializa membros-dado
	/**
	 * \param licalizacao uma string que vai atribuir valor ao membro-dado designacao.
	 */
	Zona(string designacao);
	Zona(unsigned int codZona, string designacao);

	//! Destrutor que liberta o recurso de memoria foi alocado
	~Zona();
	//! Membro-fucao para retornar o valor do membro-dado designacao
	/** um membro-funcao const para garantir a nao modificacao de nenhum membro-dado.
	 * \return uma string com conteudo do membro-dado designacao. */
	string getDesignacao() const;
	//! Membro-funcao para retornar o valor do membro-dado codZona
	/** � um membro-funcao const para garantir a nao modificacao de nenhum membro-dado.
	 * \return um unsgined int com valor do membro-dado codZona. */
	unsigned int getCodZona() const;
	//! Membro-fucao para retornar o valor do membro-dado loja
	/** um membro-funcao const para garantir a nao modificacao de nenhum membro-dado.
	 * \return um apontador para a loja da zona. */
	Loja* getLoja() const;
	//! Membro-funcao para setar o membro-dado designacao de um objeto tipo Zona ja instanciado
	/** \param designacao o conteudo da string a ser atribuida ao membro-dado designacao. */
	void setDesignacao(string designacao);
	//! Membro-funcao estatico para setar o membro-dado estatico countZonas
	/** \param n e um inteiro com conteudo a ser atribuido ao membro-dado estatico countZonas. */
	static void setCount(unsigned int n) {countZonas = n;}
	//! Membro-funcao para setar o membro-dado loja de um objeto tipo Zona ja instanciado
	/** \param lj e um apontador para uma loja a ser atribuida ao membro-dado loja. */
	void setLoja(Loja* lj);
	//! Membro-funcao estatico para retornar o valor do membro-dado estatico countZonas
	/**
	 * \return um inteiro com conteudo do membro-dado estatico countZonas. */
	static unsigned int getCount() {return countZonas;}


	//! Overloading do operador de comparacao == para objetos do tipo Zona
	/**
	 * Uma zona e igual a outra se seus nomes sao iguais.
	 * \return um booleano que e true se uma zona for igual a outra e false caso contrario.
	 */
	bool operator==(const Zona & x) const;

	//! Overloading do operador de exibicaoo << para objetos do tipo Peca
	/**
	 * \return um ostream com conteudo dos membros-dado codPeca, designacao, loja e stock.
	 */
	friend ostream & operator << (ostream & o, const Zona & z);

	string toString();

};

#endif /* ZONA_H_ */
