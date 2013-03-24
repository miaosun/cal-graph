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

 Loja::Loja(string desig, string mor, Zona *zon){
 
	designacao=desig;
	morada=mor;
	zona=zon;
	codLoja++;
 
 }
 
 // GETS Loja

string Loja::getDescricao() const {
	return descricao;
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

void Loja::setDescrica(string desc) {
	descricao=desc;
}

void Loja::setMorada(string m) {
	morada=m;
}

void Loja::setZona(Zona* zon) {
	zona=zon;
}


// IMPRIME

void Cliente::imprimeLoja() const {
	cout << "\nLoja numero: " << codLoja << endl ;
	cout << "Descricao: " << descricao << endl;	
	cout << "Morada: " << morada << endl;
	//cout << "Zona: " << zona.info() << endl;
	
}

// OPERATOR ==
bool Cliente::operator== (const Loja& x) const{
	if(getCodLoja() == x.getCodLoja())
		return true;	
	else return false;
}