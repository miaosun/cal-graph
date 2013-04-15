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

	int nif;
	string nome,morada,contacto,email;

	cout << "Nome: " << endl;
	cin>>nome;

	cout << "Morada: " << endl;
	cin>>morada;

	cout << "Telefone: "<< endl;
	cin>>contacto;

	cout << "Email: " << endl;
	cin>>email;

	cout << "NIF: " << endl;
	cin>>nif;

	Cliente *c=new Cliente(nome,morada,contacto,email,nif);

	clientes.push_back(c);


}

void LojaElectronica::removeCliente(unsigned int codCliente)
{
 //TO DO? Este obriga nos a saber o codigo de todos os clientes... pode ser mais confuso :S
	//temporariamente uso o metodo abaixo
}

void LojaElectronica::removeCliente(string nome)
{
	bool encontrou=false;

	for(unsigned int i=0;i<clientes.size();i++)
		if (clientes[i]->getNome() == nome) {
			encontrou=true;
			clientes.erase(clientes.begin() + i);
			break;

		}

	if(encontrou==false){

		throw Excepcao("\n Não existe nenhum candidato com esse nome \n");

	} else cout<<"Cliente Eliminado com sucesso";
}

Cliente *LojaElectronica::ProcuraCandidato_nome(string nome)
{
	for (unsigned int i=0; i < clientes.size(); i++)
	{
		if (nome == clientes.at(i)->getNome())
		{
			return clientes.at(i);

		}
	}


	throw Excepcao("\n Não existe nenhum candidato com esse nome \n");
	return NULL;
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

	cout<<"Add Encomenda vamos ver o q sai daqui -.-";

	Graph<int> myGraph;

	int idNo=0;
	int X=0;
	int Y=0;
	string zona;

	idNo=0;
	X=741;
	Y=199;

	myGraph.addVertex(idNo);

	idNo=1;
	X=512;
	Y=316;

	myGraph.addVertex(idNo);

	int idAresta=0;
	int idNoOrigem=0;
	int idNoDestino=0;
	int custo=0;
	int tempo=0;
	string aresta;

	idAresta=0;
	idNoOrigem=1;
	idNoDestino=4;
	custo=140;
	tempo=1201;

	double custo_tempo=0.0;
	custo_tempo=(custo*60)/tempo;

	myGraph.addEdge(idNoOrigem, idNoDestino, custo_tempo);

	idAresta=1;
	idNoOrigem=6;
	idNoDestino=205;
	custo=1082;
	tempo=1;

	custo_tempo=0.0;
	custo_tempo=(custo*60)/tempo;

	myGraph.addEdge(idNoOrigem, idNoDestino, custo_tempo);

	int a=myGraph.getNumVertex();
	cout<<"aaaaaaaaaaaaa"<<a;

}

void LojaElectronica::removeEncomenda(unsigned int codEncomenda)
{

}

void LojaElectronica::listaClientes()
{
	if(clientes.size()==0 ) throw Excepcao("\n Não existem candidadtos no sistema \n");

		for (unsigned int i=0; i < clientes.size(); i++)
				{
					clientes[i]->imprimeCliente();
				}

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
