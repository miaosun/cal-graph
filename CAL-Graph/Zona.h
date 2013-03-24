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
	string localizacao;
	//Loja *loja;

public:
	Zona(string localizacao);
	~Zona();
	string getLocalizacao();
	void setLocalizacao(string localizacao);

};

#endif /* ZONA_H_ */
