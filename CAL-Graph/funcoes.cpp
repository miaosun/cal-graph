/*
 * funcoes.cpp
 *
 *  Created on: 25 de Abr de 2013
 *      Author: Reis
 */

#include "funcoes.h"


vector<string> split(char delim, string s){
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

int pesquisaSequencial(vector<string> v, string s)
{
	for(unsigned int i=0; i < v.size(); i++) {
		if(v[i] == s)
			return 1;
	}
	return -1;
}


string dataActual()
{
	time_t x;
	x = time(NULL);
	//TimeDate ob(x);
	return ctime(&x);
}
