/*
 *  FICHEIRO: Data.cpp
 * 	PROJECTO: Projecto AEDA - Gestao de uma Oficina Mecanica (T1)
 *	DESCRICAO: Implementacao da Classe Data
 *  TURMA / GRUPO: Turma 2MIEIC3 / Grupo 1
 *  AUTORES:
 *  - Gustavo Henrique da Silva Sobral
 *  - Jorge Miguel Marques dos Reis
 */

#include "Data.h"
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Exception.h"

using namespace std;

void dataValida(int dia, int mes, int ano){
	if((dia < 1) || (dia > 31))
		throw DataException("Dia invalido");
	else if ((mes < 1) || (mes > 12))
		throw DataException("Mes invalido");
	else if(ano < 0)
		throw DataException("Ano invalido");
	else if((ano%4 == 0) && (dia > 29) && (mes == 2))
		throw DataException("Dia invalido para o mes de Fevereiro");
	else if((dia > 28) && (mes == 2))
		throw DataException("Dia invalido para o mes de Fevereiro");
	else if(dia > 30 && (mes == 4  || mes == 6 || mes == 9 || mes == 11))
		throw DataException("Dia invalido para este mes");
}

Data::Data() {dia = 0; mes = 0; ano = 0;}

Data::~Data() {}

Data::Data(int dia, int mes, int ano){
	//dataValida(dia,mes,ano);
	this->dia = dia;
	this->mes = mes;
	this->ano = ano;
}

void Data::setData(int dia, int mes, int ano){
	dataValida(dia,mes,ano);
	this->dia = dia;
	this->mes = mes;
	this->ano = ano;
}

void Data::setDia(int dia){
	if(mes != 0)
		dataValida(dia, mes, true);
	else if (ano != 0)
		dataValida(dia, true, ano);
	else if (mes != 0 && ano != 0)
		dataValida(dia, mes, ano);
	else dataValida(dia, true, true);

	this->dia = dia;
}

void Data::setMes(int mes){
	if(dia != 0)
		dataValida(dia, mes, true);
	else if (ano != 0)
		dataValida(true, mes, ano);
	else if (mes != 0 && ano != 0)
		dataValida(dia, mes, ano);
	else dataValida(true , mes , true);

	this->mes = mes;
}

void Data::setAno(int ano){
	if(dia != 0)
		dataValida(dia, true, ano);
	else if (mes != 0)
		dataValida(true, mes, ano);
	else if (dia != 0 && mes != 0)
		dataValida(dia, mes, ano);
	else dataValida(true , true , ano);

	this->ano = ano;
}

int Data::getDia() const{
	return dia;
}

int Data::getMes() const{
	return mes;
}

int Data::getAno() const{
	return ano;
}

string Data::getData() const{
	stringstream c;
	c << dia << "/" << mes << "/" << ano;
	return c.str();
}

bool Data::operator< (const Data& x) const{
	if(ano < x.ano)
		return true;
	else if((ano == x.ano) && (mes < x.mes))
		return true;
	else if ((ano == x.ano) && (mes == x.mes) && (dia < x.dia))
		return true;
	else return false;
}
