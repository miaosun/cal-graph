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

/*
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
 */
void LojaElectronica::addCliente()
{
	int nif;
	string nome,morada,contacto,email,zona;

	cout << "Nome: " << endl;
	getline(cin,nome);
	cout << "Morada: " << endl;
	getline(cin,morada);
	cout << "Telefone: "<< endl;
	fflush(stdin);
	cin>>contacto;
	cout << "Email: " << endl;
	getline(cin,email);
	cout << "NIF: " << endl;
	fflush(stdin);
	cin>>nif;

	listaZonas();

	cout << "Defina a designacao da Zona do Cliente: ";
	fflush(stdin);
	getline(cin,zona);

	Zona *zonaCliente=procuraZona(zona);
	//TODO excepcao

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
		throw Excepcao("\n Nao existe nenhum cliente com esse nome \n");
	} else cout<<"Cliente Eliminado com sucesso";
}

Cliente *LojaElectronica::ProcuraCliente_nome(string nome)
{
	for (unsigned int i=0; i < clientes.size(); i++)
	{
		if (nome == clientes.at(i)->getNome())
			return clientes.at(i);
	}

	throw Excepcao("\n Nao existe nenhum cliente com esse nome \n");
	return NULL;
}


Zona* LojaElectronica::procuraZona(string designacao) {
	vector<Vertex<Zona*> *>::iterator it = myGraph.getVertexSet().begin();

	for(;it != myGraph.getVertexSet().end();it++) {
		if((*it)->getInfo()->getDesignacao()==designacao)
			return (*it)->getInfo();
	}
	return NULL;
}
Zona* LojaElectronica::procuraZona(unsigned int id) {
	vector<Vertex<Zona*> *>::iterator it = myGraph.getVertexSet().begin();

	for(;it != myGraph.getVertexSet().end();it++) {
		if((*it)->getInfo()->getCodZona()==id)
			return (*it)->getInfo();
	}
	return NULL;
}


Loja* LojaElectronica::procuraLoja(unsigned int id) {
	vector<Vertex<Zona*> *>::iterator it = myGraph.getVertexSet().begin();

	for(;it != myGraph.getVertexSet().end();it++) {
		if((*it)->getInfo()->getLoja()->getCodLoja()==id)
			return (*it)->getInfo()->getLoja();
	}
	return NULL;
}



void LojaElectronica::addZona()
{
	string designacao;

	cout << "Designacao da Zona: " << endl;
	fflush(stdin);
	getline(cin,designacao);

	//verifica se ja existe alguma zona c mesma designacao
	if(procuraZona(designacao)!=NULL) {
		//TODO excepcao! tratar
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
		cout << "Insira a designacao de uma Zona a qual ligar: ";
		fflush(stdin);
		getline(cin,desig);

		Zona *z2 = procuraZona(desig);
		if(z2==NULL) {
			//TODO excepcao! tratar (voltar a pedir)
		}

		cout << "Distancia: ";
		fflush(stdin);
		cin >> dist;

		addArestaBidireccional(z1,z2,dist);

		cout << "Deseja inserir mais alguma distancia a outra zona? (S/N): ";
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
	string nome, morada, zona;

	cout << "Nome: " << endl;
	getline(cin,nome);
	cout << "Morada: " << endl;
	getline(cin,morada);

	listaZonas();
	cout << "Defina a Zona onde pertence a loja: " << endl;
	getline(cin,zona);

	Loja *l1=new Loja(nome,morada);
	Zona *zonaLoja=procuraZona(zona); //TODO excepcao

	zonaLoja->setLoja(l1);
}

void LojaElectronica::removeLoja(unsigned int codLoja)
{
	bool enc=false;

	vector<Vertex<Zona*> *>::iterator it = myGraph.getVertexSet().begin();

	for(;it != myGraph.getVertexSet().end();it++) {
		if((*it)->getInfo()->getLoja()->getCodLoja()==codLoja) {
			(*it)->getInfo()->setLoja(NULL);
			enc=true;
			break;
		}
	}
	if(enc==true){
		throw Excepcao("\n Nao existe nenhuma loja com esse ID \n");
	} else cout<<"Loja Eliminada com sucesso";


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


	//Caminho de No Origem ate ao menor Custo
	vector<Zona*> path = myGraph.getPath(noOrigem, noMenor);

	for(unsigned int j=0;j<path.size();j++){
		cout<<"Path: "<<path[j]->getDesignacao()<<endl;
	}
}

void LojaElectronica::removeEncomenda(unsigned int codEncomenda)
{


}

void LojaElectronica::listaClientes()
{
	if(clientes.size()==0 ) throw Excepcao("\n Nao existem clientes no sistema \n");

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
	/*
	if(lojas.size()==0 ) throw Excepcao("\n N鉶 existem lojas no sistema \n");

	for (unsigned int i=0; i < lojas.size(); i++)
	{
		lojas[i]->imprimeLoja();
	} */
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
	vector<string> v;
	ifstream file;
	string line;
	unsigned int id, idzona;
	string nome;
	string morada;

	file.open(filename.c_str());

	if (file.is_open()) {
		getline(file, line);
		Loja::setCount(atoi(line.c_str()));

		while(! file.eof() ){

			getline(file, line);
			v=split('|', line);

			idzona = atoi(v[0].c_str());
			id = atoi(v[1].c_str());
			nome=v[2];
			morada=v[3];

			Loja *l1 = new Loja(nome,morada,id);
			Zona *z = procuraZona(idzona);
			z->setLoja(l1);
		}
		file.close();
	}
}

void LojaElectronica::saveLojas(string filename) {
	vector<Vertex<Zona*> *>::iterator it = myGraph.getVertexSet().begin();

	ofstream myfile(filename.c_str());
	if(myfile.is_open())
	{
		myfile << Loja::getCount();

		for(; it!=myGraph.getVertexSet().end(); it++)
			myfile << "|" << (*it)->getInfo()->getCodZona()<<"|"<< (*it)->getInfo()->getLoja()->toString() << endl;
		myfile.close();
	}
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
	string linha;
	vector<string> v;
	stringstream s;
	ifstream myfile (filename.c_str());
	if(myfile.is_open())
	{
		getline(myfile, linha);
		Zona::setCount(atoi(linha.c_str()));
		/*
		 * falta implementar a excepcao
		 */

		while(!myfile.eof() ){
			getline(myfile, linha);
			if(linha=="") break;
			v=split('|', linha);
			//int idLoja = atoi(v[2].c_str());
			cout<<"test: "<< v[1].c_str()<<endl;
			Zona *z = new Zona(atoi(v[0].c_str()), v[1].c_str());
			myGraph.addVertex(z);
		}
		cout<<endl<<endl<<"Vertices importadas com sucesso!"<<endl<<endl;
		myfile.close();
	}
	else
	{
		cout<<"Nao foi possivel abrir o ficheiro "<<filename<<"!"<<endl<<endl;
	}
	/*	unsigned int nVertices;
	string linha;
	vector<string> v;
	stringstream s;
	ifstream myfile (filename.c_str());
	if(myfile.is_open())
	{
		getline(myfile, linha);
		s<<linha;
		s>>nVertices;

		if(nVertices>0)
		{
			for(unsigned int i=0; i<nVertices; i++)
			{
				getline(myfile, linha);
				v=split('|', linha);
				cout<<"test: "<< v[1].c_str()<<endl;
				//int idLoja = atoi(v[2].c_str());
				Zona *z = new Zona(atoi(v[0].c_str()), v[1].c_str());
				myGraph.addVertex(z);
			}

			cout<<endl<<endl<<"Vertices importadas com sucesso!"<<endl<<endl;

		}
		myfile.close();
	}
	else
	{
		cout<<"Nao foi possivel abrir o ficheiro "<<filename<<"!"<<endl<<endl;
	}
	 */
}

void LojaElectronica::saveVertices(string filename)
{
	vector<Vertex<Zona*> *>::iterator it;

	ofstream myfile (filename.c_str());
	if(myfile.is_open())
	{
		myfile << Zona::getCount();

		for(it=myGraph.getVertexSet().begin(); it!=myGraph.getVertexSet().end(); it++)
			myfile<<(*it)->getInfo()->toString()<<endl;

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
		while(!myfile.eof())
		{
			getline(myfile, linha);
			if(linha=="") break;
			v=split('|', linha);

			Zona *z1 = procuraZona(atoi(v[0].c_str()));
			Zona *z2 = procuraZona(atoi(v[1].c_str()));
			double peso = atof(v[2].c_str());

			myGraph.addEdge(z1, z2, peso, 0);

		}
		myfile.close();
		cout<<endl<<endl<<"Edges importadas com sucesso!"<<endl<<endl;
	}
	else
	{
		cout<<"Nao foi possivel abrir o ficheiro "<<filename<<"!"<<endl<<endl;
	}
}

void LojaElectronica::saveEdges(string filename)
{
	vector<Vertex<Zona*> *>::iterator it;
	ofstream myfile (filename.c_str());
	if(myfile.is_open())
	{
		for(it=myGraph.getVertexSet().begin(); it!=myGraph.getVertexSet().end(); it++)
		{
			vector<Edge<Zona*> > vedges = (*it)->getAdj();
			vector<Edge<Zona*> >::iterator ited;
			for(ited=vedges.begin(); ited!=vedges.end(); ited++)
			{
				myfile<<"|"<<(*it)->getInfo()->getCodZona()<<"|"<<ited->getDest()->getInfo()->getCodZona()<<"|"<<ited->getWeight()<<"|";

			}
		}

		myfile.close();
		cout<<endl<<endl<<"Edges exportadas com sucesso!"<<endl;
	}
	else
	{
		cout<<"Nao foi possivel abrir o ficheiro!"<<endl<<endl;
		system("pause");
	}

}


void LojaElectronica::windows(){

	//configurar uma janela
	GraphViewer *gv = new GraphViewer(600, 600, true);
	//gv->setBackground("abc.jpg");
	gv->createWindow(600, 600);

	//configurar a cor dos n�s
	gv->defineVertexColor("blue");

	//configurar a cor das arestas
	gv->defineEdgeColor("black");

	//criar um n� com ID=0


	for(unsigned int i=0;i<myGraph.getVertexSet().size();i++){

		gv->addNode(myGraph.getVertexSet()[i]->getInfo()->getCodZona());
		cout<<myGraph.getVertexSet()[i]->getInfo()->getDesignacao();
		gv->setVertexLabel(myGraph.getVertexSet()[i]->getInfo()->getCodZona(), myGraph.getVertexSet()[i]->getInfo()->getDesignacao());
		gv->rearrange();
	}


	/*gv->addNode(1);
		gv->addNode(2);
		gv->addNode(3);

		//atribuir as novas altera��es ao grafo
		gv->rearrange();


		//Nota: para criar uma aresta deve utilizar o seguinte comando:
		// para arestas bidireccionais
		gv->addEdge(0,0,1,EdgeType::UNDIRECTED);
		gv->addEdge(1,0,2,EdgeType::UNDIRECTED);
		gv->addEdge(2,1,3,EdgeType::UNDIRECTED);
		gv->addEdge(3,2,3,EdgeType::UNDIRECTED);
		// para arestas direccionais
		//gv->addEdge(0,0,1, EdgeType::DIRECTED);


		gv->setEdgeLabel(2,"isto � uma aresta");

		gv->setVertexColor(2,"green");
		gv->setEdgeColor(2,"yellow");*/

	gv->rearrange();
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
