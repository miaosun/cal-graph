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

//funcao split utilizado para os loads
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

		if(zonas[i]->getDesignacao()==localizacaoZona)
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

		throw Excepcao("\n Né‰¶ existe nenhum cliente com esse nome \n");

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

	throw Excepcao("\n Nao existe nenhum cliente com esse nome \n");
	return NULL;
}

void LojaElectronica::addProduto()
{

}

void LojaElectronica::removeProduto(unsigned int codProduto)
{


}


Zona* LojaElectronica::procuraZona(string designacao) {
	vector<Zona*>::iterator it = myGraph.getVertexSet().begin();

	for(;it!=myGraph.getVertexSet().end();it++) {
		if((*it)->getDesignacao()==designacao)
			return it;
	}
	return NULL;
}

void LojaElectronica::addZona()
{
	string designacao;

	cout << "Designaçao da Zona: " << endl;
	fflush(stdin);
	getline(cin,designacao);

	//verifica se já existe alguma zona c mesma designação
	if(procuraZona(designacao)!=NULL) {
		//TODO excepção! tratar
	}

	Zona *zona=new Zona(designacao);

	addZonaGrafo(zona);
}

void LojaElectronica::addZonaGrafo(Zona* z1) {
	myGraph.addVertex(z1);

	char resp;
	do {
		listaZonas();
		string desig;
		int dist;
		cout << "Insira a designacao de uma Zona à qual ligar: ";
		fflush(stdin);
		getline(cin,desig);

		Zona *z2 = procuraZona(desig);
		if(z2==NULL) {
			//TODO excepção! tratar (voltar a pedir)
		}

		cout << "Distância: ";
		fflush(stdin);
		cin >> dist;

		addArestaBidireccional(z1,z2,dist);

		cout << "Deseja inserir mais alguma distância a outra zona? (S/N): ";
		fflush(stdin);
		cin >> resp;
	} while(resp!='n' || resp != 'N');
}

void LojaElectronica::addArestaBidireccional(Zona* z1, Zona* z2, int dist) {
	myGraph.addEdge(z1,z2,dist);
	myGraph.addEdge(z2,z1,dist);
}

void LojaElectronica::removeZona(string desig)
{
	bool encontrou=false;

	for(unsigned int i=0;i<myGraph.getVertexSet().size();i++) {
		if(myGraph.getVertexSet()[i]->getInfo()->getDesignacao()==desig) {
			encontrou=true;
			myGraph.getVertexSet().erase(myGraph.getVertexSet().begin()+i);
			break;
		}
	}

	if(encontrou==false){

		throw Excepcao("\n Nao existe nenhuma zona com esse ID \n");

	} else cout<<"Zona Eliminada com sucesso";
}

void LojaElectronica::listaZonas()
{
	if(myGraph.getVertexSet().size()==0 ) throw Excepcao("\n Nao existem zonas no sistema \n");

	for (unsigned int i=0; i < myGraph.getVertexSet().size(); i++)
	{
		cout << myGraph.getVertexSet()[i]->getInfo() << endl << endl;
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

	Loja *c=new Loja(designacao,morada);

	lojas.push_back(c);

}

void LojaElectronica::removeLoja(unsigned int codLoja)
{
	/*
	bool encontrou=false;

	for(unsigned int i=0;i<lojas.size();codLoja++)
		if (lojas[i]->getCodLoja()==codLoja) {
			encontrou=true;
			lojas.erase(lojas.begin() + i);
			break;

		}

	if(encontrou==false){

		throw Excepcao("\n Né‰¶ existe nenhuma loja com esse ID \n");

	} else cout<<"Loja Eliminada com sucesso";
	 */
}

void LojaElectronica::addEncomenda()
{

	/*ifstream inFile;
		Graph<Zona> myGraph1;

		//Ler o ficheiro nos.txt
			inFile.open("nos.txt");

			if (!inFile) {
			    cerr << "Unable to open file datafile.txt";
			    exit(1);   // call system to stop
			}

			std::string   line;



			string nome, morada,  contacto,  email, zona,zonaCliente;
			unsigned int nif;

			string designacao, moradaLoja;



			while(std::getline(inFile, line))
				{
				    std::stringstream linestream(line);
				    std::string         data;

				    linestream >> zona;

				    //Zona *idNo=new Zona(zona);

				    Zona a("Lisbon");

				    std::getline(linestream, data, ';');  // read up-to the first ; (discard ;).
				    linestream >> nome;
				    std::getline(linestream, data, ';');  // read up-to the first ; (discard ;).
				    linestream >> morada;
				    std::getline(linestream, data, ';');  // read up-to the first ; (discard ;).
				    linestream >> contacto;
				    std::getline(linestream, data, ';');  // read up-to the first ; (discard ;).
				    linestream >> email;
				    std::getline(linestream, data, ';');  // read up-to the first ; (discard ;).
				    linestream >> zonaCliente;

				    Zona *ZonaX=new Zona(zonaCliente);

				    Cliente *cliente=new Cliente(nome,morada,contacto,email,2345678,ZonaX);

				    std::getline(linestream, data, ';');  // read up-to the first ; (discard ;).
					linestream >> designacao;
				    std::getline(linestream, data, ';');  // read up-to the first ; (discard ;).
					linestream >> moradaLoja;

					Zona *zon=new Zona(moradaLoja);

					Loja *loja=new Loja(designacao,moradaLoja,zon);

					std::getline(linestream, data, ';');



					myGraph1.addVertex(a);


				}

				inFile.close();*/


	Graph<Zona*> myGraph;
	Zona *a=new Zona("Lisbon");
	Zona *b=new Zona("Porto");
	Zona *c=new Zona("Coimbra");
	Zona *d=new Zona("Algarve");


	myGraph.addVertex(a);
	myGraph.addVertex(b);
	myGraph.addVertex(c);
	myGraph.addVertex(d);

	myGraph.addEdge(a, b, 3);
	myGraph.addEdge(b, a, 3);

	myGraph.addEdge(a, c, 1);
	myGraph.addEdge(c, a, 1);

	myGraph.addEdge(b, d, 7);
	myGraph.addEdge(d, a, 7);

	myGraph.addEdge(c, d, 10);
	myGraph.addEdge(d, c, 10);


	Zona *noOrigem =a;

	//Caminhos mais curtos a partir de noOrigem --> Grafos Pesados - Djikstra
	myGraph.dijkstraShortestPath(noOrigem);

	//Caminhos mais curtos a partir de noOrigem --> Grafos Nao Pesados
	//myGraph1.unweightedShortestPath(noOrigem);

	vector<Vertex<Zona*>* > vs = myGraph.getVertexSet();


	int menor=2000000000;
	Zona *noMenor=vs[0]->getInfo();


	//Ver qual o caminho mais curto de todos e guardar o menor

	for(unsigned int i=0;i<vs.size();i++){
		if(vs[i]->getInfo()!=noOrigem && vs[i]->getDist()<=menor){
			cout<<"Dijkstra: Distancia de: "<< a->getDesignacao() << " a "<<vs[i]->getInfo()->getDesignacao()<<":  "<<vs[i]->getDist()<<endl;
			menor=vs[i]->getDist();
			noMenor=vs[i]->getInfo();
		}
	}

	cout<<"Menor Custo: "<<menor<<endl;
	cout<<"No de Menor custo: "<<noMenor->getDesignacao()<<endl;



	//Caminho de No Origem atï¿½No menor Custo
	vector<Zona*> path = myGraph.getPath(noOrigem, noMenor);

	for(int j=0;j<path.size();j++){
		cout<<"Path: "<<path[j]->getDesignacao()<<endl;
	}


}

void LojaElectronica::removeEncomenda(unsigned int codEncomenda)
{


}

void LojaElectronica::listaClientes()
{
	if(clientes.size()==0 ) throw Excepcao("\n Né‰¶ existem clientes no sistema \n");

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

	if(lojas.size()==0 ) throw Excepcao("\n Né‰¶ existem lojas no sistema \n");

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
	/*
	ifstream file;
	string line;
	const unsigned int cod;
	string desig;
	unsigned int stock;
	double preco;

	file.open(filename.c_str());

	if (file.is_open()) {
		getline(file, line);
		//Produto::setCount(atoi(line.c_str()));

		while(! file.eof() ){

			getline(file, line);
			cod = atoi(line.c_str());
			...
		}
	} */
}
void LojaElectronica::saveProdutos(string filename)
{

}

void LojaElectronica::loadLojas(string filename)
{
	ifstream file;
	string line;
	unsigned int cod;
	string desig;
	string morada;

	file.open(filename.c_str());

	if (file.is_open()) {
		getline(file, line);
		Loja::setCount(atoi(line.c_str()));

		while(! file.eof() ){

			getline(file, line);
			cod = atoi(line.c_str());

			getline(file, desig);

			getline(file,morada);

			Loja *l1 = new Loja(desig,morada,cod);
			lojas.push_back(l1);
		}
		file.close();
	}
}

void LojaElectronica::saveLojas(string filename)
{
	int i = 0;
	int tam = lojas.size();
	ofstream myfile(filename.c_str());
	if (myfile.is_open()) {
		myfile << Loja::getCount() << endl;
		while (i < tam) {
			if(lojas[i] != NULL){
				myfile << lojas[i]->getCodLoja() << endl;
				myfile << lojas[i]->getNome() << endl;
				myfile << lojas[i]->getMorada() << endl;
			}
			i++;
		}
		myfile.close();
	}
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

///////////////////// loads e saves para grafo
void LojaElectronica::loadVertices(string filename)
{
	unsigned int nVertices;
	string linha;
	vector<string> v;
	stringstream s;
	ifstream myfile (filename.c_str());
	if(myfile.is_open())
	{
		getline(myfile, linha);
		s<<linha;
		s>>nVertices;

		/*
		 * falta implementar a excepcao
		 */

		if(nVertices>0)
		{
			for(unsigned int i=0; i<nVertices; i++)
			{
				getline(myfile, linha);
				v=split('|', linha);
				Zona *z(atoi(v[0].c_str()), v[1].c_str(), atoi(v[2].c_str()));
				myGraph.addVertex(z);  //info?
			}

			cout<<endl<<endl<<"Vertices importadas com sucesso!"<<endl<<endl;
		}
		myfile.close();
	}
	else
	{
		cout<<"Nao foi possivel abrir o ficheiro "<<filename<<"!"<<endl<<endl;
	}
}

void LojaElectronica::saveVertices(string filename)
{
	vector<Zona *>::iterator it;

	ofstream myfile (filename.c_str());
	if(myfile.is_open())
	{
		myfile<<myGraph.getVertexSet().size()<<endl;

		for(it=myGraph.getVertexSet().begin(); it!=myGraph.getVertexSet().end(); it++)
			myfile<<(*it)->toString()<<endl;

		myfile.close();
		cout<<endl<<endl<<"Vertices exportadas com sucesso!"<<endl;
	}
	else
	{
		cout<<"Nao foi possivel abrir o ficheiro!"<<endl<<endl;
		system("pause");
	}
}

void LojaElectronica::loadEdges(string filename)
{
	unsigned int nEdges;
	string linha;
	vector<string> v;
	stringstream s;
	ifstream myfile (filename.c_str());
	if(myfile.is_open())
	{
		getline(myfile, linha);
		s<<linha;
		s>>nEdges;

		/*
		 * falta implementar a excepcao
		 */

		if(nEdges>0)
		{
			for(unsigned int i=0; i<nEdges; i++)
			{
				getline(myfile, linha);
				v=split('|', linha);
				//do something with the following variables...
				int idzona1 = atoi(v[0].c_str());
				int idzona2 = atoi(v[1].c_str());
				double peso = atof(v[2].c_str());

				//myGraph.addEdge(idzona1, idzona2, peso, 0);
			}

			cout<<endl<<endl<<"Edges importadas com sucesso!"<<endl<<endl;
		}
		myfile.close();
	}
	else
	{
		cout<<"Nao foi possivel abrir o ficheiro "<<filename<<"!"<<endl<<endl;
	}
}

void LojaElectronica::saveEdges(string filename)
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
