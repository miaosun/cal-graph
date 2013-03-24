/*
 * 	FICHEIRO: Loja.h
 *	PROJECTO: Projecto CAL - Loja de Comercio Electronico (T3)
 *	DESCRICAO: Implementacao da classe Loja
 *  TURMA / GRUPO: Turma 2MIEIC2 / Grupo D
 *  AUTORES:
 *  - Jorge Miguel Reis
 *  - Miao Sun
 *  - Vitor Castro
 */

#include "Loja.h"
#include <cstdio>

unsigned int Loja::countLojas=0;

 Loja::Loja(string desig, string mor, Zona *zon):codLoja(++countLojas) {
	designacao=desig;
	morada=mor;
	zona=zon;
 }
 
 // GETS Loja

string Loja::getDesignacao() const {
	return designacao;
}

string Loja::getMorada() const {
	return morada;
}

Zona* Loja::getZona() const {
	return zona;
}

unsigned int Loja::getCodLoja() const{

return codLoja;

}

// SETS Loja

void Loja::setDesignacao(string desc) {
	designacao=desc;
}

void Loja::setMorada(string m) {
	morada=m;
}

void Loja::setZona(Zona* zon) {
	zona=zon;
}


// IMPRIME

void Loja::imprimeLoja() const {
	cout << "\nLoja numero: " << codLoja << endl ;
	cout << "Descricao: " << designacao << endl;
	cout << "Morada: " << morada << endl;
	//cout << "Zona: " << zona.info() << endl;
	
}

// OPERATOR ==
bool Loja::operator== (const Loja& x) const{
	if(getCodLoja() == x.getCodLoja())
		return true;	
	else return false;
}
