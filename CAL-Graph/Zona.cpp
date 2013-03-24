/*
 * 	FICHEIRO: Zona.h
 *	PROJECTO: Projecto CAL - Loja de Comercio Electronico (T3)
 *	DESCRICAO: Implementacao da classe Zona
 *  TURMA / GRUPO: Turma 2MIEIC2 / Grupo D
 *  AUTORES:
 *  - Jorge Miguel Reis
 *  - Miao Sun
 *  - Vitor Castro
 */

#include "Zona.h"

Zona::Zona(unsigned int codZona, string Localidade)
{
	this->codZona = codZona;
	this->localizacao = localizacao;
}

Zona::~Zona(){}

string Zona::getLocalizacao() const
{
	return localizacao;
}

void Zona::setLocalizacao(string localizacao)
{
	this->localizacao = localizacao;
}

unsigned int Zona::getCodZona() const
{
	return this->codZona;
}

void Zona::setCodZona(unsigned int codZona)
{
	this->codZona = codZona;
}
