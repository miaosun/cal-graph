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
	 * \param nome e uma string que vai atribuir valor ao membro-dado nome.
	 * \param morada e uma string que vai atribuir valor ao membro-dado morada.
	 * \param contacto e uma string que vai atribuir valor ao membro-dado contacto.
	 * \param email e uma string que vai atribuir valor ao membro-dado email.
	 * \param nif e um inteiro que vai atribuir valor ao membro-dado estatico nif.
	 * \param zona e um apontador de Zona que vai atribuir valor ao membro-dado zona.
	 */
	Cliente(string nome, string morada, string contacto, string email, unsigned int nif, Zona *zona);
	//! Construtor que inicializa todos os membros-dado
	/**
	 * \param nome e uma string que vai atribuir valor ao membro-dado nome.
	 * \param morada e uma string que vai atribuir valor ao membro-dado morada.
	 * \param contacto e uma string que vai atribuir valor ao membro-dado contacto.
	 * \param email e uma string que vai atribuir valor ao membro-dado email.
	 * \param nif e um inteiro que vai atribuir valor ao membro-dado estatico nif.
	 * \param cod e um inteiro que vai atribuir valor ao membro-dado codCliente.
	 * \param zona e um apontador de Zona que vai atribuir valor ao membro-dado zona.
	 */
	Cliente(string nome, string morada, string contacto, string email, unsigned int nif, unsigned int cod, Zona *zon);
	//! Membro-funcao para retornar o valor do membro-dado codCliente
	/** �um membro-funcao const para garantir a nao modificacao de nenhum membro-dado.
	 * \return um unsigned int com valor do membro-dado codCliente. */
	unsigned int getCodCliente() const;
	//! Membro-funcao para retornar o valor do membro-dado nome
	/** e um membro-funcao const para garantir a nao modificacao de nenhum membro-dado.
	 * \return uma string com valor do membro-dado nome. */
	string getNome() const;
	//! Membro-funcao para retornar o valor do membro-dado NIF
	/** e um membro-funcao const para garantir a nao modificacao de nenhum membro-dado.
	 * \return um unsgined int com valor do membro-dado NIF. */
	unsigned int getNIF() const;
	//! Membro-funcao para retornar o numero de clientes ja cadastrados
	/** \return um int com a quantidade de clientes ja cadastrados. */
	static int getNumClientes();
	//! Membro-funcao para retornar o valor do membro-dado morada
	/** e um membro-funcao const para garantir a nao modificacao de nenhum membro-dado.
	 * \return uma string com valor do membro-dado morada. */
	string getMorada() const;
	//! Membro-funcao para retornar o valor do membro-dado contacto
	/** e um membro-funcao const para garantir a nao modificacao de nenhum membro-dado.
	 * \return uma string com valor do membro-dado contacto. */
	string getContacto() const;
	//! Membro-funcao para retornar o valor do membro-dado email
	/** e um membro-funcao const para garantir a nao modificacao de nenhum membro-dado.
	 * \return uma string com valor do membro-dado email. */
	string getEmail() const;
	//! Membro-funcao para retornar o valor do membro-dado zona
	/** e um membro-funcao const para garantir a nao modificacao de nenhum membro-dado.
	 * \return um apontador de Zona com valor do membro-dado zona. */
	Zona * getZona() const;
	//! Membro-funcao para setar o membro-dado nome de um objeto tipo Pessoa ja instanciado
	/** \param nome e conteudo da string a ser atribuida ao membro-dado nome. */
	void setNome(string nome);
	//! Membro-funcao para setar o membro-dado morada de um objeto tipo Pessoa ja instanciado
	/** \param morada e o conteudo da string a ser atribuida ao membro-dado morada. */
	void setMorada(string morada);
	//! Membro-funcao para setar o membro-dado contacto de um objeto tipo Pessoa ja instanciado
	/** \param contacto e o conteudo da string a ser atribuida ao membro-dado contacto. */
	void setContacto(string contacto);
	//! Membro-funcao para setar o membro-dado email de um objeto tipo Pessoa ja instanciado
	/** \param email e o conteudo da string a ser atribuida ao membro-dado email. */
	void setEmail(string email);

	void setZona(Zona *z);
	//! Overloading do operador de comparacao == para objetos do tipo Cliente
	/**
	 * Um cliente e igual a outro se seus nomes sao iguais ou se seus NIF's sao iguais.
	 * \return um booleano que e true se um cliente for igual a outro e false caso contrario.
	 */
	bool operator==(const Cliente & x) const;
	//! Membro-funcao estatico para setar o membro-dado estatico countClientes
	/** \param n e um inteiro com conteudo a ser atribuido ao membro-dado estatico countClientes. */
	static void setCount(unsigned int n) {countClientes = n;}
	//! Membro-funcao estatico para retornar o valor do membro-dado estatico countClientes
	/**
	 * \return um inteiro com conteudo do membro-dado estatico countClientes. */
	static unsigned int getCount() {return countClientes;}
	//! Membro-funcao que imprime no ecra membros-dado de um objeto tipo Cliente
	/**
	 * Membro-funcao para imprimir no ecra conteudo dos membros-dado de um objeto tipo Cliente no formato,
	 * \n Cliente numero: \n Nome: \n Morada: \n Contacto: \n Email: \n NIF: \n
	 */
	//void imprimeCliente() const;
	vector<string> imprimeCliente() const;
	void resumo() const;

	vector<string> editCliente();


	//TODO falta updates
};


#endif /* CLIENTE_H_ */
