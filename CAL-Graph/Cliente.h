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
	 * \param nome é uma string que vai atribuir valor ao membro-dado nome.
	 * \param morada é uma string que vai atribuir valor ao membro-dado morada.
	 * \param contacto é uma string que vai atribuir valor ao membro-dado contacto.
	 * \param email é uma string que vai atribuir valor ao membro-dado email.
	 * \param nif é um inteiro que vai atribuir valor ao membro-dado estatico nif.
	 * \param zona é um apontador de Zona que vai atribuir valor ao membro-dado zona.
	 */
	Cliente(string nome, string morada, string contacto, string email, unsigned int nif, Zona *zona);
	//! Construtor que inicializa todos os membros-dado
	/**
	 * \param nome é uma string que vai atribuir valor ao membro-dado nome.
	 * \param morada é uma string que vai atribuir valor ao membro-dado morada.
	 * \param contacto é uma string que vai atribuir valor ao membro-dado contacto.
	 * \param email é uma string que vai atribuir valor ao membro-dado email.
	 * \param nif é um inteiro que vai atribuir valor ao membro-dado estatico nif.
	 * \param cod é um inteiro que vai atribuir valor ao membro-dado codCliente.
	 * \param zona é um apontador de Zona que vai atribuir valor ao membro-dado zona.
	 */
	Cliente(string nome, string morada, string contacto, string email, unsigned int nif, unsigned int cod, Zona *zon);
	//! Membro-função para retornar o valor do membro-dado codCliente
	/** É um membro-função const para garantir a não modificação de nenhum membro-dado.
	 * \return um unsigned int com valor do membro-dado codCliente. */
	unsigned int getCodCliente() const;
	//! Membro-função para retornar o valor do membro-dado nome
	/** É um membro-função const para garantir a não modificação de nenhum membro-dado.
	 * \return uma string com valor do membro-dado nome. */
	string getNome() const;
	//! Membro-função para retornar o valor do membro-dado NIF
	/** É um membro-função const para garantir a não modificação de nenhum membro-dado.
	 * \return um unsgined int com valor do membro-dado NIF. */
	unsigned int getNIF() const;
	//! Membro-função para retornar o número de clientes já cadastrados
	/** \return um int com a quantidade de clientes já cadastrados. */
	static int getNumClientes();
	//! Membro-função para retornar o valor do membro-dado morada
	/** É um membro-função const para garantir a não modificação de nenhum membro-dado.
	 * \return uma string com valor do membro-dado morada. */
	string getMorada() const;
	//! Membro-função para retornar o valor do membro-dado contacto
	/** É um membro-função const para garantir a não modificação de nenhum membro-dado.
	 * \return uma string com valor do membro-dado contacto. */
	string getContacto() const;
	//! Membro-função para retornar o valor do membro-dado email
	/** É um membro-função const para garantir a não modificação de nenhum membro-dado.
	 * \return uma string com valor do membro-dado email. */
	string getEmail() const;
	//! Membro-função para retornar o valor do membro-dado zona
	/** É um membro-função const para garantir a não modificação de nenhum membro-dado.
	 * \return um apontador de Zona com valor do membro-dado zona. */
	Zona * getZona() const;
	//! Membro-função para setar o membro-dado nome de um objeto tipo Pessoa já instanciado
	/** \param nome é o conteúdo da string a ser atribuida ao membro-dado nome. */
	void setNome(string nome);
	//! Membro-função para setar o membro-dado morada de um objeto tipo Pessoa já instanciado
	/** \param morada é o conteúdo da string a ser atribuida ao membro-dado morada. */
	void setMorada(string morada);
	//! Membro-função para setar o membro-dado contacto de um objeto tipo Pessoa já instanciado
	/** \param contacto é o conteúdo da string a ser atribuida ao membro-dado contacto. */
	void setContacto(string contacto);
	//! Membro-função para setar o membro-dado email de um objeto tipo Pessoa já instanciado
	/** \param email é o conteúdo da string a ser atribuida ao membro-dado email. */
	void setEmail(string email);
	//! Overloading do operador de comparação == para objetos do tipo Cliente
	/**
	 * Um cliente é igual a outro se seus nomes são iguais ou se seus NIF's são iguais.
	 * \return um booleano que é true se um cliente for igual a outro e false caso contrário.
	 */
	bool operator==(const Cliente & x) const;
	//! Membro-função estatico para setar o membro-dado estatico countClientes
	/** \param n e um inteiro com conteúdo a ser atribuido ao membro-dado estatico countClientes. */
	static void setCount(unsigned int n) {countClientes = n;}
	//! Membro-função estatico para retornar o valor do membro-dado estatico countClientes
	/**
	 * \return um inteiro com conteúdo do membro-dado estatico countClientes. */
	static unsigned int getCount() {return countClientes;}
	//! Membro-função que imprime no ecrã os membros-dado de um objeto tipo Cliente
	/**
	 * Membro-função para imprimir no ecrã o conteúdo dos membros-dado de um objeto tipo Cliente no formato,
	 * \n Cliente número: \n Nome: \n Morada: \n Contacto: \n Email: \n NIF: \n
	 */
	void imprimeCliente() const;
	void resumo() const;

	//TODO falta updates
};


#endif /* CLIENTE_H_ */
