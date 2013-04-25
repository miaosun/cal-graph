/*
 * 	FICHEIRO: Exception.h
 *	PROJECTO: Projecto CAL - Loja de Comercio Electronico (T3)
 *	DESCRICAO: Definicao das classes Exception
 *  TURMA / GRUPO: Turma 2MIEIC2 / Grupo D
 *  AUTORES:
 *  - Jorge Miguel Reis
 *  - Miao Sun
 *  - Vitor Castro
 */

#ifndef EXCEPTION_H_
#define EXCEPTION_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;
//! Classe Exception
/**
 * Classe mãe de todas as exceções utilizadas no sistema.\n
 * Possui um membro-dado do tipo string para armazenar o motivo do lançamento da exceção.
 */
class Exception {
	string motivoDaExcecao;
public:
	//! Construtor que inicializa o membro-dado
	/** \param motivoDaExcecao é a string que vai atribuir valor ao membro-dado motivoDaExcecao.*/
	Exception(string motivoDaExcecao){
		this->motivoDaExcecao = motivoDaExcecao;
	};
	//! Membro-função para retornar o valor do membro-dado motivoDaExcecao
	/** \return um string com valor do membro-dado motivoDaExcecao. */
	string getMotivoDaExcecao() const{
		return motivoDaExcecao;
	}
};

//! Classe DataException
/** Sub classe da classe Exception para exceções da classe Data. */
class DataException: public Exception{
public:
	//! Construtor que inicializa o membro-dado herdado da classe mãe
	/** \param motivoDaExcecao é a string que vai atribuir valor ao membro-dado motivoDaExcecao.*/
	DataException(string motivoDaExcecao) : Exception(motivoDaExcecao){};
};

//class PecaException: public Exception{
//public:
//	//! Construtor que inicializa o membro-dado herdado da classe mãe
//	/** \param motivoDaExcecao é a string que vai atribuir valor ao membro-dado motivoDaExcecao.*/
//	PecaException(string motivoDaExcecao) : Exception(motivoDaExcecao){};
//};

class NotFound {};
//class BadIterator { };
//
//class NoMoreSpace { };
//
//class BadPosition { };
//
//class ErroInterno { };
//
//class Underflow { };
//
//class Overflow { };
//
//class BadArgs { };

#endif /* EXCEPTION_H_ */
