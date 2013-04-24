/*
 *     FICHEIRO: Loja.h
 *    PROJECTO: Projecto CAL - Loja de Comercio Electronico (T3)
 *    DESCRICAO: Definicao da classe Loja
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
#include "Produto.h"

#include <stdlib.h>
#include <vector>
#include <sstream>
#include <fstream>

class Zona;

using namespace std;
class Loja
{
	const unsigned int codLoja;
	static unsigned int countLojas;
	string nome;
	string morada;
	vector <Produto *> produtos;

public:
	//! Construtor que inicializa todos os membros-dado
	/**
	 * \param nome �uma string que vai atribuir valor ao membro-dado nome.
	 * \param morada �uma string que vai atribuir valor ao membro-dado morada.
	 * \param zona �um apontador para a zona da loja
	 */
	Loja(string nome, string mor);

	//! Construtor que inicializa todos os membros-dado, inclu韓do c骴igo
	/**
	 * \param nome �uma string que vai atribuir valor ao membro-dado nome.
	 * \param morada �uma string que vai atribuir valor ao membro-dado morada.
	 * \param zona �um apontador para a zona da loja
	 * \param cod �um inteiro que vai atribuir valor ao membro-dado codLoja.
	 */
	Loja(string nome, string mor, unsigned int cod);

	//! Membro-funcao para retornar o valor do membro-dado codLoja
	/**  um membro-funcao const para garantir a nao modificao de nenhum membro-dado.
	 * \return um unsgined int com valor do membro-dado codLoja. */
	unsigned int getCodLoja() const;

	//! Membro-funcao para retornar o valor do membro-dado nome
	/**  um membro-funcao const para garantir a nao modificao de nenhum membro-dado.
	 * \return uma string com valor do membro-dado nome. */
	string getNome() const;

	//! Membro-funcao para retornar o valor do membro-dado morada
	/**  um membro-funcao const para garantir a nao modificao de nenhum membro-dado.
	 * \return uma string com valor do membro-dado morada. */
	string getMorada() const;

	//! Membro-funcao para retornar o valor do membro-dado produtos que contem todos os produtos de uma loja
	/**  um membro-funcao const para garantir a nao modificao de nenhum membro-dado.
	 * \return um apontador para produtos */
	vector <Produto *> getProdutos() const;

	//! Membro-funo para setar o membro-dado nome de um objeto tipo Loja j instanciado
	/** \param nome  o contedo da string a ser atribuida ao membro-dado nome. */
	void setNome(string nome);

	//! Membro-funo para setar o membro-dado morada de um objeto tipo Loja j instanciado
	/** \param morada  o contedo da string a ser atribuida ao membro-dado morada. */
	void setMorada(string morada);

	void addProduto();

	void removeProduto(unsigned int codProduto);

	//! Overloading do operador de comparao == para objetos do tipo Loja
	/**
	 * Uma loja  igual a outra se seus codLojas forem iguais
	 * \return um booleano que  true se uma loja for igual a outra e false caso contrrio.
	 */
	bool operator==(const Loja & x) const;

	//! Membro-funo estatico para setar o membro-dado estatico countLojas
	/** \param n e um inteiro com contedo a ser atribuido ao membro-dado estatico countLojas. */
	static void setCount(unsigned int n) {countLojas = n;}
	//! Membro-funo estatico para retornar o valor do membro-dado estatico countClientes
	/**
	 * \return um inteiro com contedo do membro-dado estatico countLojas. */
	static unsigned int getCount() {return countLojas;}

	//! Membro-funo que imprime no ecr os membros-dado de um objeto tipo Loja
	/**
	 * Membro-funo para imprimir no ecr o contedo dos membros-dado de um objeto tipo Loja no formato,
	 * \n Loja nmero: \n nome: \n Morada: \n Zona: \n
	 */
	void imprimeLoja() const;

	string toString();

};


#endif /* LOJA_H_ */
