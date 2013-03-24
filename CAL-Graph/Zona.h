/*
 * Zona.h
 *
 *  Created on: 23 de Mar de 2013
 *      Author: Miao
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
