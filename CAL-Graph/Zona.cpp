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

Zona::Zona(unsigned int codZona, string designacao, Loja *loja)
{
	this->codZona = codZona;
	this->designacao = designacao;
	this->loja = loja;
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

void Zona::info() const {
	cout << "\n Zona numero: " << codZona << endl ;
	cout << "Designação: " << designacao << endl;

}

// OPERATOR ==
bool Zona::operator== (const Zona& x) const{
	if(getDesignacao() == x.getDesignacao())
		return true;
	else return false;
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

string Zona::toString()
{
	stringstream ss;
	ss<<"|"<<this->codZona<<"|"<<this->designacao<<"|"<<this->loja->getCodLoja()<<"|";
	return ss.str();
}
