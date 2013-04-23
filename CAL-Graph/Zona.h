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
	 * \param licalizacao uma string que vai atribuir valor ao membro-dado designação.
	*/
	Zona(string designacao);

	//! Destrutor que liberta o recurso de memoria foi alocado
	~Zona();
	//! Membro-fucao para retornar o valor do membro-dado designação
	/** um membro-funcao const para garantir a nao modificacao de nenhum membro-dado.
	 * \return uma string com conteudo do membro-dado designação. */
	string getDesignacao() const;
	//! Membro-função para retornar o valor do membro-dado codZona
	/** É um membro-função const para garantir a não modificação de nenhum membro-dado.
	 * \return um unsgined int com valor do membro-dado codZona. */
	unsigned int getCodZona() const;
	//! Membro-fucao para retornar o valor do membro-dado loja
	/** um membro-funcao const para garantir a nao modificacao de nenhum membro-dado.
	 * \return um apontador para a loja da zona. */
	Loja* getLoja() const;
	//! Membro-funcao para setar o membro-dado designação de um objeto tipo Zona ja instanciado
	/** \param designação o conteudo da string a ser atribuida ao membro-dado designação. */
	void setDesignacao(string designacao);
	//! Membro-função estatico para setar o membro-dado estatico countZonas
	/** \param n e um inteiro com conteúdo a ser atribuido ao membro-dado estatico countZonas. */
	static void setCount(unsigned int n) {countZonas = n;}
	//! Membro-função para setar o membro-dado loja de um objeto tipo Zona já instanciado
	/** \param lj é um apontador para uma loja a ser atribuida ao membro-dado loja. */
	void setLoja(Loja* lj);
	//! Membro-função estatico para retornar o valor do membro-dado estatico countZonas
	/**
	 * \return um inteiro com conteúdo do membro-dado estatico countZonas. */
	static unsigned int getCount() {return countZonas;}
	//! Membro-função que imprime no ecrã os membros-dado de um objeto tipo Zona
	/**
	 * Membro-função para imprimir no ecrã o conteúdo dos membros-dado de um objeto tipo Cliente no formato,
	 * \n Zona número: \n designação: \n
	 */
	void info() const;

	//! Overloading do operador de comparação == para objetos do tipo Zona
	/**
	 * Uma zona é igual a outro se seus nomes são iguais.
	 * \return um booleano que é true se uma zona for igual a outra e false caso contrário.
	 */
	bool operator==(const Zona & x) const;

};

#endif /* ZONA_H_ */
