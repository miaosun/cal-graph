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


unsigned int Zona::countZonas=0;

Zona::Zona(string Localidade, Loja* lj):codZona(++countZonas)
{

	this->localizacao = Localidade;
	this->loja=lj;
}

Zona::~Zona(){}

string Zona::getLocalizacao() const
{
	return localizacao;
}

unsigned int Zona::getCodZona() const {
	return codZona;
}

Loja* Zona::getLoja() const
{
	return loja;
}

void Zona::setLocalizacao(string localizacao)
{
	this->localizacao = localizacao;
}

void Zona::setLoja(Loja* lj)
{
	this->loja = lj;
}
// IMPRIME

void Zona::info() const {
	cout << "\n Zona numero: " << codZona << endl ;
	cout << "Localização: " << localizacao << endl;

}
/*
unsigned int Zona::getCodZona() const
{
	return this->codZona;
}

void Zona::setCodZona(unsigned int codZona)
{
	this->codZona = codZona;
}*/
