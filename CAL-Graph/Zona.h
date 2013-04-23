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
	 * \param licalizacao uma string que vai atribuir valor ao membro-dado designa��o.
	*/
	Zona(string designacao);

	//! Destrutor que liberta o recurso de memoria foi alocado
	~Zona();
	//! Membro-fucao para retornar o valor do membro-dado designa��o
	/** um membro-funcao const para garantir a nao modificacao de nenhum membro-dado.
	 * \return uma string com conteudo do membro-dado designa��o. */
	string getDesignacao() const;
	//! Membro-fun��o para retornar o valor do membro-dado codZona
	/** � um membro-fun��o const para garantir a n�o modifica��o de nenhum membro-dado.
	 * \return um unsgined int com valor do membro-dado codZona. */
	unsigned int getCodZona() const;
	//! Membro-fucao para retornar o valor do membro-dado loja
	/** um membro-funcao const para garantir a nao modificacao de nenhum membro-dado.
	 * \return um apontador para a loja da zona. */
	Loja* getLoja() const;
	//! Membro-funcao para setar o membro-dado designa��o de um objeto tipo Zona ja instanciado
	/** \param designa��o o conteudo da string a ser atribuida ao membro-dado designa��o. */
	void setDesignacao(string designacao);
	//! Membro-fun��o estatico para setar o membro-dado estatico countZonas
	/** \param n e um inteiro com conte�do a ser atribuido ao membro-dado estatico countZonas. */
	static void setCount(unsigned int n) {countZonas = n;}
	//! Membro-fun��o para setar o membro-dado loja de um objeto tipo Zona j� instanciado
	/** \param lj � um apontador para uma loja a ser atribuida ao membro-dado loja. */
	void setLoja(Loja* lj);
	//! Membro-fun��o estatico para retornar o valor do membro-dado estatico countZonas
	/**
	 * \return um inteiro com conte�do do membro-dado estatico countZonas. */
	static unsigned int getCount() {return countZonas;}
	//! Membro-fun��o que imprime no ecr� os membros-dado de um objeto tipo Zona
	/**
	 * Membro-fun��o para imprimir no ecr� o conte�do dos membros-dado de um objeto tipo Cliente no formato,
	 * \n Zona n�mero: \n designa��o: \n
	 */
	void info() const;

	//! Overloading do operador de compara��o == para objetos do tipo Zona
	/**
	 * Uma zona � igual a outro se seus nomes s�o iguais.
	 * \return um booleano que � true se uma zona for igual a outra e false caso contr�rio.
	 */
	bool operator==(const Zona & x) const;

};

#endif /* ZONA_H_ */
