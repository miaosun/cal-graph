/*
 * 	FICHEIRO: Cliente.h
 *	PROJECTO: Projecto CAL - Loja de Comercio Electronico (T3)
 *	DESCRICAO: Implementacao da classe Cliente
 *  TURMA / GRUPO: Turma 2MIEIC2 / Grupo D
 *  AUTORES:
 *  - Jorge Miguel Reis
 *  - Miao Sun
 *  - Vitor Castro
 */

#include "Cliente.h"
#include <cstdio>

using namespace std;

//inicializacao de variavel estatica
unsigned int Cliente::countClientes=0;


Cliente::Cliente(string nm, string mrd, string c, string e, unsigned int n): NIF(n),codCliente(++countClientes) {
	nome=nm;
	morada=mrd;
	contacto=c;
	email=e;
}

// GETS CLIENTE

string Cliente::getNome() const {
	return nome;
}

string Cliente::getMorada() const {
	return morada;
}

string Cliente::getContacto() const {
	return contacto;
}

string Cliente::getEmail() const {
	return email;
}

unsigned int Cliente::getCodCliente() const {
	return codCliente;
}

unsigned int Cliente::getNIF() const {
	return NIF;
}

int Cliente::getNumClientes() {
	return countClientes;
}

// SETS CLIENTE

void Cliente::setNome(string nm) {
	nome=nm;
}

void Cliente::setMorada(string m) {
	morada=m;
}

void Cliente::setContacto(string c) {
	contacto=c;
}

void Cliente::setEmail(string e) {
	email=e;
}


// IMPRIME

void Cliente::imprimeCliente() const {
	cout << "\nCliente numero: " << codCliente << endl ;
	cout << "Nome: " << nome << endl;
	cout << "NIF: " << NIF << endl;
	cout << "Morada: " << morada << endl;
	cout << "Contacto: " << contacto << endl;
	cout << "Email: " << email<< endl;
}


// OPERATOR ==
bool Cliente::operator== (const Cliente& x) const{
	if(getNome() == x.getNome())
		return true;
	else if(getNIF() == x.getNIF())
		return true;
	else return false;
}