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

Zona * LojaElectronica::determinaZona(string morada){

	Zona *zona;

	string localizacaoZona;

	if(morada=="Porto"||morada=="Paranhos"||morada=="Gondomar"||morada=="Gaia"||morada=="Matosinhos")
		localizacaoZona="Porto";
	else if(morada=="Lisboa"||morada=="Amadora"||morada=="Alvalade"||morada=="Benfica")
	localizacaoZona="Lisboa";
	else if(morada=="Algarve"||morada=="Faro"||morada=="Portimao"||morada=="Quarteira")
		localizacaoZona="Algarve";
	else if(morada=="Leira")
			localizacaoZona="Leiria";
	else localizacaoZona="Inexistente";

	for(unsigned int i=0;i<zonas.size();i++){

		if(zonas[i]->getLocalizacao()==localizacaoZona)
			zona=zonas[i];
	}


	return zona;
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

	Zona *zonaCliente=determinaZona(morada);

	Cliente *c=new Cliente(nome,morada,contacto,email,nif,zonaCliente);

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

		throw Excepcao("\n Não existe nenhum cliente com esse nome \n");

	} else cout<<"Cliente Eliminado com sucesso";
}

Cliente *LojaElectronica::ProcuraCliente_nome(string nome)
{
	for (unsigned int i=0; i < clientes.size(); i++)
	{
		if (nome == clientes.at(i)->getNome())
		{
			return clientes.at(i);

		}
	}


	throw Excepcao("\n Não existe nenhum cliente com esse nome \n");
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

		string localizacao;

		cout << "Localizacao da Loja: " << endl;
		cin>>localizacao;


		Zona *zona=new Zona(localizacao);

		zona->info();

		zonas.push_back(zona);

}

void LojaElectronica::removeZona(unsigned int codZona)
{

	bool encontrou=false;

	for(unsigned int i=0;i<zonas.size();i++)
		if (zonas[i]->getCodZona()==codZona) {
			encontrou=true;
			zonas.erase(zonas.begin() + i);
			break;

		}

	if(encontrou==false){

		throw Excepcao("\n Não existe nenhuma zona com esse ID \n");

	} else cout<<"Zona Eliminada com sucesso";

}

void LojaElectronica::listaZonas()
{
	if(zonas.size()==0 ) throw Excepcao("\n Não existem zonas no sistema \n");

		for (unsigned int i=0; i < zonas.size(); i++)
				{
			zonas[i]->info();
				}

}

void LojaElectronica::addLoja()
{
	    string designacao;
	    string morada;

		cout << "Designacao: " << endl;
		cin>>designacao;

		cout << "Morada: " << endl;
		cin>>morada;

		Zona *zonaLoja=determinaZona(morada);

		Loja *c=new Loja(designacao,morada,zonaLoja);

		lojas.push_back(c);

}

void LojaElectronica::removeLoja(unsigned int codLoja)
{

	bool encontrou=false;

	for(unsigned int i=0;i<lojas.size();codLoja++)
		if (lojas[i]->getCodLoja()==codLoja) {
			encontrou=true;
			lojas.erase(lojas.begin() + i);
			break;

		}

	if(encontrou==false){

		throw Excepcao("\n Não existe nenhuma loja com esse ID \n");

	} else cout<<"Loja Eliminada com sucesso";
}

void LojaElectronica::addEncomenda()
{

	cout<<"Add Encomenda vamos ver o q sai daqui -.-";

	Graph<Zona> myGraph;

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
	if(clientes.size()==0 ) throw Excepcao("\n Não existem clientes no sistema \n");

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

	if(lojas.size()==0 ) throw Excepcao("\n Não existem lojas no sistema \n");

		for (unsigned int i=0; i < lojas.size(); i++)
				{
					lojas[i]->imprimeLoja();
				}
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
