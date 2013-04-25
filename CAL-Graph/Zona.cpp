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

Zona::Zona(string Localidade):codZona(++countZonas)
{
	this->designacao = Localidade;
	this->loja=NULL;
}

Zona::Zona(unsigned int cod, string designacao): codZona(cod)
{
	this->designacao = designacao;
}

Zona::~Zona(){}

string Zona::getDesignacao() const
{
	return designacao;
}

unsigned int Zona::getCodZona() const {
	return codZona;
}

Loja* Zona::getLoja() const
{
	return loja;
}

void Zona::setDesignacao(string designacao)
{
	this->designacao = designacao;
}

void Zona::setLoja(Loja* lj)
{
	this->loja = lj;
}
// IMPRIME


// OPERATOR ==
bool Zona::operator== (const Zona& x) const{
	if(getDesignacao() == x.getDesignacao())
		return true;
	else return false;
}

ostream & operator << (ostream & o, const Zona & z){
	o << "Id Zona: "  << z.getCodZona() << " | Designacao: " << z.getDesignacao();
	o << " | Loja: " << z.getLoja()->getNome();
	return o;
}


string Zona::toString()
{
	stringstream ss;
	ss<<"|"<<this->codZona<<"|"<<this->designacao<<"|";
	return ss.str();
}

