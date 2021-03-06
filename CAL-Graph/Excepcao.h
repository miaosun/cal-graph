/*
 * 	FICHEIRO: Excepcao.h
 *	PROJECTO: Projecto CAL - Loja de Comercio Electronico (T3)
 *	DESCRICAO: Implementacao da classe Excepcao
 *  TURMA / GRUPO: Turma 2MIEIC2 / Grupo D
 *  AUTORES:
 *  - Jorge Miguel Reis
 *  - Miao Sun
 *  - Vitor Castro
 */

#ifndef EXCEPCAO_H_
#define EXCEPCAO_H_

#include <string>

using namespace std;

//Classe Excepcao utilizada para excepcoes. Retorna uma mensagem para o utilizador com a excepcao
class Excepcao{
private:
	string message;
public:
	Excepcao( string mens ){message=mens;};
	string getMessage() { return message; };
};

#endif /* EXCEPCAO_H_ */
