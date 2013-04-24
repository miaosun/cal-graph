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
	 * \param licalizacao uma string que vai atribuir valor ao membro-dado designaï¿½ï¿½o.
	 */
	Zona(string designacao);
	Zona(unsigned int codZona, string designacao, Loja *loja);

	//! Destrutor que liberta o recurso de memoria foi alocado
	~Zona();
	//! Membro-fucao para retornar o valor do membro-dado designaï¿½ï¿½o
	/** um membro-funcao const para garantir a nao modificacao de nenhum membro-dado.
	 * \return uma string com conteudo do membro-dado designaï¿½ï¿½o. */
	string getDesignacao() const;
	//! Membro-funï¿½ï¿½o para retornar o valor do membro-dado codZona
	/** ï¿½ um membro-funï¿½ï¿½o const para garantir a nï¿½o modificaï¿½ï¿½o de nenhum membro-dado.
	 * \return um unsgined int com valor do membro-dado codZona. */
	unsigned int getCodZona() const;
	//! Membro-fucao para retornar o valor do membro-dado loja
	/** um membro-funcao const para garantir a nao modificacao de nenhum membro-dado.
	 * \return um apontador para a loja da zona. */
	Loja* getLoja() const;
	//! Membro-funcao para setar o membro-dado designaï¿½ï¿½o de um objeto tipo Zona ja instanciado
	/** \param designaï¿½ï¿½o o conteudo da string a ser atribuida ao membro-dado designaï¿½ï¿½o. */
	void setDesignacao(string designacao);
	//! Membro-funï¿½ï¿½o estatico para setar o membro-dado estatico countZonas
	/** \param n e um inteiro com conteï¿½do a ser atribuido ao membro-dado estatico countZonas. */
	static void setCount(unsigned int n) {countZonas = n;}
	//! Membro-funï¿½ï¿½o para setar o membro-dado loja de um objeto tipo Zona jï¿½ instanciado
	/** \param lj ï¿½ um apontador para uma loja a ser atribuida ao membro-dado loja. */
	void setLoja(Loja* lj);
	//! Membro-funï¿½ï¿½o estatico para retornar o valor do membro-dado estatico countZonas
	/**
	 * \return um inteiro com conteï¿½do do membro-dado estatico countZonas. */
	static unsigned int getCount() {return countZonas;}


	//! Overloading do operador de comparaï¿½ï¿½o == para objetos do tipo Zona
	/**
	 * Uma zona ï¿½ igual a outro se seus nomes sï¿½o iguais.
	 * \return um booleano que ï¿½ true se uma zona for igual a outra e false caso contrï¿½rio.
	 */
	bool operator==(const Zona & x) const;

	//! Overloading do operador de exibição << para objetos do tipo Peca
	/**
	 * \return um ostream com conteúdo dos membros-dado codPeca, designacao, loja e stock.
	 */
	friend ostream & operator << (ostream & o, const Zona & z);

	string toString();

};

#endif /* ZONA_H_ */
