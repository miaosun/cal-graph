/*
 * 	FICHEIRO: LojaElectronica.h
 *	PROJECTO: Projecto CAL - Loja de Comercio Electronico (T3)
 *	DESCRICAO: Implementacao da classe LojaElectronica
 *  TURMA / GRUPO: Turma 2MIEIC2 / Grupo D
 *  AUTORES:
 *  - Jorge Miguel Reis
 *  - Miao Sun
 *  - Vitor Castro
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

void LojaElectronica::addZona()
{

}

void LojaElectronica::removeZona(unsigned int codZona)
{

}

void LojaElectronica::addLoja()
{

}

void LojaElectronica::removeLoja(unsigned int codLoja)
{

}

void LojaElectronica::addEncomenda()
{

}

void LojaElectronica::removeEncomenda(unsigned int codEncomenda)
{

}

void LojaElectronica::listaClientes()
{

}

void LojaElectronica::listaProdutos()
{

}

void LojaElectronica::listaLojas()
{

}

void LojaElectronica::listaEncomendas()
{

}

void LojaElectronica::loadClientes(string filename)
{

}

void LojaElectronica::saveClientes(string filename)
{

}

void LojaElectronica::loadProdutos(string filename)
{

}

void LojaElectronica::saveProdutos(string filename)
{

}

void LojaElectronica::loadZonas(string filename)
{

}

void LojaElectronica::saveZonas(string filename)
{

}

void LojaElectronica::loadEncomendas(string filenmae)
{

}

void LojaElectronica::saveEncomendas(string filename)
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
