/*
 * funcoes.h
 *
 *  Created on: 25 de Abr de 2013
 *      Author: Miao
 */

#ifndef FUNCOES_H_
#define FUNCOES_H_

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "Exception.h"
using namespace std;

vector<string> split(char delim, string s);

bool isDouble(const string& s);

bool isDigit(const string& s);

int intinput();

int pesquisaSequencial(vector<string> v, string s);

string dataActual();


#endif /* FUNCOES_H_ */
