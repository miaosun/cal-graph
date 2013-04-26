/*
 * Excepcao.h
 *
 *  Created on: 26 de Abr de 2013
 *      Author: Reis
 */

#ifndef EXCEPCAO_H_
#define EXCEPCAO_H_

#include <string>

using namespace std;

//Classe Excepcao utilizada para excepcoes. Retorna uma mensagem para o utilizador com a excepcao
class Excepcao{
private:
	string message;
public:
	Excepcao( string mens ){message=mens;};
	string getMessage() { return message; };
};

#endif /* EXCEPCAO_H_ */
