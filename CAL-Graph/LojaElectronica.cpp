/*
 * LojaElectronica.cpp
 *
 *  Created on: 23 de Mar de 2013
 *      Author: Miao
 */


#include "LojaElectronica.h"


LojaElectronica::LojaElectronica()
{

}

LojaElectronica::~LojaElectronica(){}

void LojaElectronica::welcome()
{
	stringstream o;
		for(unsigned int i=0; i<79; i++)
			o<<"*";
		o<<endl;
		for (unsigned int i=0; i<3; i++)
		{
			o<<"*";
			for(unsigned int j=0; j<77; j++)
				o<<" ";
			o<<"*"<<endl;
		}
		o<<"*                   *          * * *      ********     *                      *\n";
		o<<"*                   *         *     *         *      *   *                    *\n";
		o<<"*                   *        *       *        *     *     *                   *\n";
		o<<"*                   *        *       *        *     *******                   *\n";
		o<<"*                   *         *     *     *   *     *     *                   *\n";
		o<<"*                   ******     * * *       * *      *     *                   *\n";
		for (unsigned int i=0; i<3; i++)
		{
			o<<"*";
			for(unsigned int j=0; j<77; j++)
				o<<" ";
			o<<"*"<<endl;
		}
		o<<"*    ***** *     *****  **** ***** ****   ****  *    * *****  ****   *        *\n";
		o<<"*    *     *     *     *       *   *   * *    * **   *   *   *      *  *      *\n";
		o<<"*    ***** *     ***** *       *   *   * *    * * *  *   *   *     *    *     *\n";
		o<<"*    *     *     *     *       *   ****  *    * *  * *   *   *     ******     *\n";
		o<<"*    *     *     *     *       *   *   * *    * *   **   *   *     *    *     *\n";
		o<<"*    ***** ***** *****  ****   *   *    * ****  *    * *****  **** *    *     *\n";
		for (unsigned int i=0; i<3; i++)
		{
			o<<"*";
			for(unsigned int j=0; j<77; j++)
				o<<" ";
			o<<"*"<<endl;
		}
		for(unsigned int i=0; i<79; i++)
			o<<"*";
		cout<<o.str()<<endl<<endl;
		system("pause");
}

void LojaElectronica::showMenu(string titulo, vector<string> opcoes)
{

}

void LojaElectronica::menuPrincipal()
{

}

void LojaElectronica::menuEncomenda()
{

}

void LojaElectronica::menuCliente()
{

}

void LojaElectronica::menuProduto()
{

}

void LojaElectronica::addCliente()
{

}

void LojaElectronica::removeCliente(unsigned int codCliente)
{

}

void LojaElectronica::addProduto()
{

}

void LojaElectronica::removeProduto(unsigned int codProduto)
{

}

/*
 *
 *    fica para depois
 *
 *
 */
void LojaElectronica::startLojaElectronica()
{
	cout<<"Hello, Loja Electronica!"<<endl;
	welcome();
}