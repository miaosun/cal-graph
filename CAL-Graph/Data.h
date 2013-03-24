/*
 * 	FICHEIRO: Data.h
 *	PROJECTO: Projecto CAL - Loja de Comercio Electronico (T3)
 *	DESCRICAO: Definicao da classe Data
 *  TURMA / GRUPO: Turma 2MIEIC2 / Grupo D
 *  AUTORES:
 *  - Jorge Miguel Reis
 *  - Miao Sun
 *  - Vitor Castro
 */

#ifndef DATA_H_
#define DATA_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;
//! Classe Data
/**
 * Possui três membros-dado do tipo inteiro para armazenamento do dia, mes e ano da data.\n
 * Se for atribuida um valor de data inválido, seja dia, mes ou nao ao objeto di tipo Data é gerada
 * uma exceção do tipo DataException. Os lançamentos das excecões ocorrem por datas negativas
 * combinações de dias e meses inexistentes e anos bissextos.
 */
class Data {
	int dia;
	int mes;
	int ano;
public:
	//! Construtor que inicializa todos os membros-dado
	/**
	 * \param dia é um inteiro que vai atribuir valor ao membro-dado dia.
	 * \param mes é um inteiro que vai atribuir valor ao membro-dado mes.
	 * \param ano é um inteiro que vai atribuir valor ao membro-dado ano.
	 */
	Data(int dia, int mes, int ano);
	//! Construtor vazio
	Data();
	//! Destrutor virtual
	virtual ~Data();
	//! Membro-função que seta todos os membros-dado do objeto Data já instanciado
	/**
	 * \param dia é um inteiro que seta o membro-dado dia.
	 * \param mes é um inteiro que seta o membro-dado mes.
	 * \param ano é um inteiro que seta o membro-dado ano.
	 */
	void setData(int dia, int mes, int ano);
	//! Membro-função para setar o membro-dado dia de um objeto tipo Data já instanciado
	/** \param dia é valor do inteiro a ser atribuido ao membro-dado dia. */
	void setDia(int dia);
	//! Membro-função para setar o membro-dado mes de um objeto tipo Data já instanciado
	/** \param mes é valor do inteiro a ser atribuido ao membro-dado mes. */
	void setMes(int mes);
	//! Membro-função para setar o membro-dado ano de um objeto tipo Data já instanciado
	/** \param ano é valor do inteiro a ser atribuido ao membro-dado ano. */
	void setAno(int ano);
	//! Membro-função para retornar o valor do membro-dado dia
	/** \return um inteiro com valor do membro-dado dia. */
	int getDia() const;
	//! Membro-função para retornar o valor do membro-dado mes
	/** \return um inteiro com valor do membro-dado dia. */
	int getMes() const;
	//! Membro-função para retornar o valor do membro-dado ano
	/** \return um inteiro com valor do membro-dado dia. */
	int getAno() const;
	//! Membro-função para retornar todos os valores do objeto em formato string
	/** \return uma string no formato dd/mm/aaaa. */
	string getData() const;
	//! Overloading do operador de comparação < para objetos do tipo Data
	/**
	 * Uma data é menor que a outra se seu ano é menor que o ano da outra data ou, se os anos forem iguais
	 * e um mes for menor que outro ou, se os anos e os meses forem iguais e um dia for menor que outro.
	 * \return um booleano que é true se uma data for menor que outra e false caso contrário.
	 */
	bool operator<(const Data& x) const;

};

#endif /* DATA_H_ */
