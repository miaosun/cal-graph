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

