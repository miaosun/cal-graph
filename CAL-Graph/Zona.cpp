/*
 * Zona.cpp
 *
 *  Created on: 23 de Mar de 2013
 *      Author: Miao
 */

#include "Zona.h"

Zona::Zona(string Localidade)
{
	this->localizacao = localizacao;
}

Zona::~Zona(){}

string Zona::getLocalizacao()
{
	return localizacao;
}

void Zona::setLocalizacao(string localizacao)
{
	this->localizacao = localizacao;
}

