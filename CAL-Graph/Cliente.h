/*
 * 	FICHEIRO: Cliente.h
 *	PROJECTO: Projecto CAL - Loja de Comercio Electronico (T3)
 *	DESCRICAO: Definicao da classe Cliente
 *  TURMA / GRUPO: Turma 2MIEIC2 / Grupo D
 *  AUTORES:
 *  - Jorge Miguel Reis
 *  - Miao Sun
 *  - Vitor Castro
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

#include "Loja.h"
#include "Zona.h"
#include <iostream>
#include <string>

using namespace std;

class Cliente {
	const unsigned int codCliente;
	static unsigned int countClientes;
	const unsigned int NIF;
	string nome;
	string morada;
	string contacto;
	string email;
	Zona * zona;

public:
	//! Construtor que inicializa todos os membros-dado
	/**
	 * \param nome � uma string que vai atribuir valor ao membro-dado nome.
	 * \param morada � uma string que vai atribuir valor ao membro-dado morada.
	 * \param contacto � uma string que vai atribuir valor ao membro-dado contacto.
	 * \param email � uma string que vai atribuir valor ao membro-dado email.
	 * \param nif � um inteiro que vai atribuir valor ao membro-dado estatico nif.
	 * \param zona � um apontador de Zona que vai atribuir valor ao membro-dado zona.
	 */
	Cliente(string nome, string morada, string contacto, string email, unsigned int nif, Zona *zona);
	//! Construtor que inicializa todos os membros-dado
	/**
	 * \param nome � uma string que vai atribuir valor ao membro-dado nome.
	 * \param morada � uma string que vai atribuir valor ao membro-dado morada.
	 * \param contacto � uma string que vai atribuir valor ao membro-dado contacto.
	 * \param email � uma string que vai atribuir valor ao membro-dado email.
	 * \param nif � um inteiro que vai atribuir valor ao membro-dado estatico nif.
	 * \param cod � um inteiro que vai atribuir valor ao membro-dado codCliente.
	 * \param zona � um apontador de Zona que vai atribuir valor ao membro-dado zona.
	 */
	Cliente(string nome, string morada, string contacto, string email, unsigned int nif, unsigned int cod, Zona *zon);
	//! Membro-fun��o para retornar o valor do membro-dado codCliente
	/** � um membro-fun��o const para garantir a n�o modifica��o de nenhum membro-dado.
	 * \return um unsigned int com valor do membro-dado codCliente. */
	unsigned int getCodCliente() const;
	//! Membro-fun��o para retornar o valor do membro-dado nome
	/** � um membro-fun��o const para garantir a n�o modifica��o de nenhum membro-dado.
	 * \return uma string com valor do membro-dado nome. */
	string getNome() const;
	//! Membro-fun��o para retornar o valor do membro-dado NIF
	/** � um membro-fun��o const para garantir a n�o modifica��o de nenhum membro-dado.
	 * \return um unsgined int com valor do membro-dado NIF. */
	unsigned int getNIF() const;
	//! Membro-fun��o para retornar o n�mero de clientes j� cadastrados
	/** \return um int com a quantidade de clientes j� cadastrados. */
	static int getNumClientes();
	//! Membro-fun��o para retornar o valor do membro-dado morada
	/** � um membro-fun��o const para garantir a n�o modifica��o de nenhum membro-dado.
	 * \return uma string com valor do membro-dado morada. */
	string getMorada() const;
	//! Membro-fun��o para retornar o valor do membro-dado contacto
	/** � um membro-fun��o const para garantir a n�o modifica��o de nenhum membro-dado.
	 * \return uma string com valor do membro-dado contacto. */
	string getContacto() const;
	//! Membro-fun��o para retornar o valor do membro-dado email
	/** � um membro-fun��o const para garantir a n�o modifica��o de nenhum membro-dado.
	 * \return uma string com valor do membro-dado email. */
	string getEmail() const;
	//! Membro-fun��o para retornar o valor do membro-dado zona
	/** � um membro-fun��o const para garantir a n�o modifica��o de nenhum membro-dado.
	 * \return um apontador de Zona com valor do membro-dado zona. */
	Zona * getZona() const;
	//! Membro-fun��o para setar o membro-dado nome de um objeto tipo Pessoa j� instanciado
	/** \param nome � o conte�do da string a ser atribuida ao membro-dado nome. */
	void setNome(string nome);
	//! Membro-fun��o para setar o membro-dado morada de um objeto tipo Pessoa j� instanciado
	/** \param morada � o conte�do da string a ser atribuida ao membro-dado morada. */
	void setMorada(string morada);
	//! Membro-fun��o para setar o membro-dado contacto de um objeto tipo Pessoa j� instanciado
	/** \param contacto � o conte�do da string a ser atribuida ao membro-dado contacto. */
	void setContacto(string contacto);
	//! Membro-fun��o para setar o membro-dado email de um objeto tipo Pessoa j� instanciado
	/** \param email � o conte�do da string a ser atribuida ao membro-dado email. */
	void setEmail(string email);
	//! Overloading do operador de compara��o == para objetos do tipo Cliente
	/**
	 * Um cliente � igual a outro se seus nomes s�o iguais ou se seus NIF's s�o iguais.
	 * \return um booleano que � true se um cliente for igual a outro e false caso contr�rio.
	 */
	bool operator==(const Cliente & x) const;
	//! Membro-fun��o estatico para setar o membro-dado estatico countClientes
	/** \param n e um inteiro com conte�do a ser atribuido ao membro-dado estatico countClientes. */
	static void setCount(unsigned int n) {countClientes = n;}
	//! Membro-fun��o estatico para retornar o valor do membro-dado estatico countClientes
	/**
	 * \return um inteiro com conte�do do membro-dado estatico countClientes. */
	static unsigned int getCount() {return countClientes;}
	//! Membro-fun��o que imprime no ecr� os membros-dado de um objeto tipo Cliente
	/**
	 * Membro-fun��o para imprimir no ecr� o conte�do dos membros-dado de um objeto tipo Cliente no formato,
	 * \n Cliente n�mero: \n Nome: \n Morada: \n Contacto: \n Email: \n NIF: \n
	 */
	void imprimeCliente() const;
	void resumo() const;

	//TODO falta updates
};


#endif /* CLIENTE_H_ */
