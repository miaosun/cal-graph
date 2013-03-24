/*
 * 	FICHEIRO: Loja.h
 *	PROJECTO: Projecto CAL - Loja de Comercio Electronico (T3)
 *	DESCRICAO: Definicao da classe Loja
 *  TURMA / GRUPO: Turma 2MIEIC2 / Grupo D
 *  AUTORES:
 *  - Jorge Miguel Reis
 *  - Miao Sun
 *  - Vitor Castro
 */

#ifndef LOJA_H_
#define LOJA_H_

#include <iostream>
#include <string>

class Zona;

using namespace std;
class Loja
{
	const unsigned int codLoja;
	static unsigned int countLojas;
	string designacao;
	string morada;
	Zona * zona;

public:
	//! Construtor que inicializa todos os membros-dado
	/**
	 * \param designacao é uma string que vai atribuir valor ao membro-dado designacao.
	 * \param morada é uma string que vai atribuir valor ao membro-dado morada.
	 * \param zona é um apontador para a zona da loja
	 */
	Loja(string desig, string mor, Zona *zon);

	//! Membro-função para retornar o valor do membro-dado codLoja
	/** É um membro-função const para garantir a não modificação de nenhum membro-dado.
	 * \return um unsgined int com valor do membro-dado codLoja. */
	unsigned int getCodLoja() const;	 

	//! Membro-função para retornar o valor do membro-dado designacao
	/** É um membro-função const para garantir a não modificação de nenhum membro-dado.
	 * \return uma string com valor do membro-dado designacao. */
	string getDesignacao() const;	

	//! Membro-função para retornar o valor do membro-dado morada
	/** É um membro-função const para garantir a não modificação de nenhum membro-dado.
	 * \return uma string com valor do membro-dado morada. */
	string getMorada() const;

	//! Membro-função para retornar o valor do membro-dado zona
	/** É um membro-função const para garantir a não modificação de nenhum membro-dado.
	 * \return um apontador para a zona */
	Zona* getZona() const;

	//! Membro-função para setar o membro-dado nome de um objeto tipo Loja já instanciado
	/** \param designacao é o conteúdo da string a ser atribuida ao membro-dado designacao. */
	void setDesignacao(string desig);

	//! Membro-função para setar o membro-dado morada de um objeto tipo Loja já instanciado
	/** \param morada é o conteúdo da string a ser atribuida ao membro-dado morada. */
	void setMorada(string morada);

	//! Membro-função para setar o membro-dado zona de um objeto tipo Loja já instanciado
	/** \param zona é um apontador para a zona da loja */
	void setZona(Zona* zon);

	//! Overloading do operador de comparação == para objetos do tipo Loja
	/**
	 * Uma loja é igual a outra se seus codLojas forem iguais
	 * \return um booleano que é true se uma loja for igual a outra e false caso contrário.
	 */
	bool operator==(const Loja & x) const;

	//! Membro-função estatico para setar o membro-dado estatico countLojas
	/** \param n e um inteiro com conteúdo a ser atribuido ao membro-dado estatico countLojas. */
	static void setCount(unsigned int n) {countLojas = n;}
	//! Membro-função estatico para retornar o valor do membro-dado estatico countClientes
	/**
	 * \return um inteiro com conteúdo do membro-dado estatico countLojas. */
	static unsigned int getCount() {return countLojas;}

	//! Membro-função que imprime no ecrã os membros-dado de um objeto tipo Loja
	/**
	 * Membro-função para imprimir no ecrã o conteúdo dos membros-dado de um objeto tipo Loja no formato,
	 * \n Loja número: \n Designacao: \n Morada: \n Zona: \n 
	 */
	void imprimeLoja() const;

};


#endif /* LOJA_H_ */
