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

using namespace std;

vector<string> split(char delim, string s)
{
	size_t cutAt;
	vector<string> result;
	while( (cutAt = s.find_first_of(delim)) != s.npos )
	{
		if( cutAt > 0 )
		{
			result.push_back( s.substr( 0, cutAt ) );
		}
		s = s.substr( ++cutAt );
	}
	return result;
}

bool isDouble(const string& s)
{
  istringstream i(s);
  double temp;
  return ( (i >> temp) ? true : false );
}

bool isDigit(const string& s)
{
	istringstream i(s);
	int temp;
	return ( (i >> temp) ? true : false );
}

int intinput()
{
	string s;
	int i=0;
	getline(cin, s);
	while(!isDigit(s))
	{
		cout<<"A opcao nao e valida, tenta novamente: ";
		getline(cin, s);
	};

	i = atoi(s.c_str());
	return i;
}



#endif /* FUNCOES_H_ */