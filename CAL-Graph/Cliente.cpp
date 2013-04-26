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

//inicializacao de variavel estatica
unsigned int Cliente::countClientes=0;


Cliente::Cliente(string nm, string mrd, string c, string e, unsigned int n,Zona *zon): NIF(n),codCliente(++countClientes) {
	nome=nm;
	morada=mrd;
	contacto=c;
	email=e;
	zona=zon;
}

Cliente::Cliente(string nm, string mrd, string c, string e, unsigned int n, unsigned int cod, Zona *zon): NIF(n),codCliente(cod) {
	nome=nm;
	morada=mrd;
	contacto=c;
	email=e;
	zona=zon;
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
Zona * Cliente::getZona() const {
	return zona;
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

void Cliente::setZona(Zona *z) {
	zona=z;
}

// IMPRIME
/*
void Cliente::imprimeCliente() const {
		cout << "\nCliente numero: " << codCliente << endl ;
		cout << "Nome: " << nome << endl;
		cout << "NIF: " << NIF << endl;
		cout << "Morada: " << morada << endl;
		cout << "Contacto: " << contacto << endl;
		cout << "Email: " << email<< endl;
		cout <<"CLIENTE DA ZONA: "<< zona->getDesignacao() << endl;
		cout <<"FIM DA FICHA DO CLIENTE"<<endl;
}
 */
vector<string> Cliente::imprimeCliente() const {
	vector<string> v;
	stringstream ss;
	ss << "Cliente numero: " << this->codCliente;
	v.push_back(ss.str());
	ss.str("");
	ss << "Nome: " << this->nome;
	v.push_back(ss.str());
	ss.str("");
	ss << "NIF: " << this->NIF;
	v.push_back(ss.str());
	ss.str("");
	ss << "Morada: " << this->morada;
	v.push_back(ss.str());
	ss.str("");
	ss << "Contacto: " << this->contacto;
	v.push_back(ss.str());
	ss.str("");
	ss << "Email: " << this->email;
	v.push_back(ss.str());
	ss.str("");
	ss <<"CLIENTE DA ZONA: "<< this->zona->getDesignacao();
	v.push_back(ss.str());
	ss.str("");

	return v;
}

vector<string> Cliente::editCliente()
{
	vector<string> opcoes;
	stringstream ss;
	opcoes.push_back("Escolha o que editar:");
	opcoes.push_back("");
	ss<<"1 - Editar Morada: "<<this->morada;
	opcoes.push_back(ss.str());
	ss.str("");
	ss<<"2 - Editar Contacto: "<<this->contacto;
	opcoes.push_back(ss.str());
	ss.str("");
	ss<<"3 - Editar Email: "<<this->email;
	opcoes.push_back(ss.str());
	ss.str("");
	ss<<"4 - Editar Zona: "<<this->zona->getDesignacao();
	opcoes.push_back(ss.str());
	ss.str("");

	return opcoes;
}

void Cliente::resumo() const {
	cout << "Cliente "<<codCliente<< " | "<<nome<< " | "<<"Zona: "<< zona->getDesignacao() << endl;
}


// OPERATOR ==
bool Cliente::operator== (const Cliente& x) const{
	if(getNome() == x.getNome())
		return true;
	else if(getNIF() == x.getNIF())
		return true;
	else return false;
}
