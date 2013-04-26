/*
 * 	FICHEIRO: funcoes.h
 *	PROJECTO: Projecto CAL - Loja de Comercio Electronico (T3)
 *	DESCRICAO: Implementacao das funcoes auxiliares
 *  TURMA / GRUPO: Turma 2MIEIC2 / Grupo D
 *  AUTORES:
 *  - Jorge Miguel Reis
 *  - Miao Sun
 *  - Vitor Castro
 */

#ifndef FUNCOES_H_
#define FUNCOES_H_

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

using namespace std;

vector<string> split(char delim, string s);

bool isDouble(const string& s);

bool isDigit(const string& s);

int intinput();

int pesquisaSequencial(vector<string> v, string s);

string dataActual();

string doubleToString(double d);

#endif /* FUNCOES_H_ */
