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

int pesquisaSequencial(vector<string> v, string s){
	for(unsigned int i=0; i < v.size(); i++) {
		if(v[i] == s)
			return 1;
	}
	return -1;
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
		if (nome == clientes.at(i)->getNome())
			return clientes.at(i);

	throw Excepcao("\n Nao existe nenhum cliente com esse nome \n");
	return NULL;
}


Zona* LojaElectronica::procuraZona(string designacao) {
	vector<Vertex<Zona*> *> vs = myGraph.getVertexSet();
	vector<Vertex<Zona*> *>::iterator it = vs.begin();

	for(;it != vs.end();it++) {
		if((*it)->getInfo()->getDesignacao()==designacao)
			return (*it)->getInfo();
	}
	return NULL;
}
Zona* LojaElectronica::procuraZona(unsigned int id) {
	vector<Vertex<Zona*> *> vs = myGraph.getVertexSet();
	vector<Vertex<Zona*> *>::iterator it = vs.begin();

	for(;it != vs.end();it++) {
		if((*it)->getInfo()->getCodZona()==id)
			return (*it)->getInfo();
	}
	return NULL;
}


Loja* LojaElectronica::procuraLoja(unsigned int id) {
	vector<Vertex<Zona*> *> vs = myGraph.getVertexSet();
	vector<Vertex<Zona*> *>::iterator it = vs.begin();

	for(;it != vs.end();it++) {
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
	if(encontrou==false)
		throw Excepcao("\n Nao existe nenhuma zona com esse ID \n");
	else
		cout<<"Zona Eliminada com sucesso";
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
	vector<Vertex<Zona*> *> vs = myGraph.getVertexSet();
	vector<Vertex<Zona*> *>::iterator it = vs.begin();

	for(;it != vs.end();it++) {
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
	// TODO
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
	vector<string> vp = nomesProdutos();
	cout << "Produtos existentes:" << endl << endl;
	for(unsigned int i=0; i< vp.size(); i++)
		cout << vp[i];
}


vector<string> LojaElectronica::nomesProdutos(){

	string prod;
	vector<string> res;
	for (unsigned int i=0; i < myGraph.getVertexSet().size(); i++)
	{
		for(unsigned int j=0;j<myGraph.getVertexSet()[i]->getInfo()->getLoja()->getProdutos().size();j++) {
			prod=myGraph.getVertexSet()[i]->getInfo()->getLoja()->getProdutos()[j]->getDesignacao();
			if(pesquisaSequencial(res,prod)==-1)
				res.push_back(prod);
		}
	}
	return res;
}

void LojaElectronica::listaLojas()
{
	if(myGraph.getVertexSet().size()==0 ) throw Excepcao("\n Nao existem lojas no sistema \n");

	for (unsigned int i=0; i < myGraph.getVertexSet().size(); i++)
		cout << myGraph.getVertexSet()[i]->getInfo()->getLoja() << endl << endl;
}

void LojaElectronica::listaEncomendas()
{
	// TODO
}

void LojaElectronica::loadClientes(string filename)
{
	ifstream file;
	string line;
	vector<Cliente> vec_cliente;
	string nome,morada,contacto,email,NIB;
	unsigned int NIF, cod, codzona;

	file.open(filename.c_str());

	if (file.is_open()) {

		getline(file, line);
		Cliente::setCount(atoi(line.c_str()));
		while(!file.eof() ){

			getline(file, line);
			if(line == "") break;
			nome = line;

			getline(file, morada);
			getline(file, contacto);
			getline(file, email);
			getline(file, line);
			NIF = atoi(line.c_str());
			getline(file, line);
			cod = atoi(line.c_str());
			getline(file, line);
			codzona = atoi(line.c_str());

			Zona *z = procuraZona(codzona);
			Cliente *c1 = new Cliente(nome,morada,contacto,email,NIF, cod, z);
			clientes.push_back(c1);
		}
		file.close();
	}
}

void LojaElectronica::saveClientes(string filename)
{
	int i = 0;
	int tam = clientes.size();
	ofstream myfile(filename.c_str());
	if (myfile.is_open()) {
		myfile << Cliente::getCount() << endl;
		while (i < tam) {
			if(clientes[i] != NULL){
				myfile << clientes[i]->getNome() << endl;
				myfile << clientes[i]->getMorada() << endl;
				myfile << clientes[i]->getContacto() << endl;
				myfile << clientes[i]->getEmail() << endl;
				myfile << clientes[i]->getNIF() << endl;
				myfile << clientes[i]->getCodCliente() << endl;
				myfile << clientes[i]->getZona()->getCodZona() << endl;
			}
			i++;
		}
		myfile.close();
	}
}

void LojaElectronica::loadProdutos(string filename)
{
	ifstream file;
	string line;
	string desig;
	vector<string> v;
	unsigned int stock, idloja;
	double preco;

	file.open(filename.c_str());

	if (file.is_open()) {

		while(! file.eof() ){

			getline(file, line);
			if(line=="") break;
			v=split('|', line);

			idloja = atoi(v[0].c_str());
			desig = v[1];
			preco= atof(v[2].c_str());
			stock=atoi(v[3].c_str());

			Produto *p = new Produto(desig,stock,preco);
			Loja *l1 = procuraLoja(idloja);
			l1->getProdutos().push_back(p);
		}
		file.close();
	}
}
void LojaElectronica::saveProdutos(string filename)
{
	vector<Vertex<Zona*> *> vs = myGraph.getVertexSet();
	vector<Vertex<Zona*> *>::iterator it = vs.begin();

	ofstream myfile(filename.c_str());
	if(myfile.is_open())
	{
		for(; it!=vs.end(); it++) {
			for(unsigned int i=0;i<(*it)->getInfo()->getLoja()->getProdutos().size();i++) {
				myfile << "|" << (*it)->getInfo()->getLoja()->getCodLoja()<<"|";
				myfile << (*it)->getInfo()->getLoja()->getProdutos()[i]->toString() << endl;
			}
		}
		myfile.close();
	}
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
			if(line=="") break;
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
	vector<Vertex<Zona*> *> vs = myGraph.getVertexSet();
	vector<Vertex<Zona*> *>::iterator it = vs.begin();

	ofstream myfile(filename.c_str());
	if(myfile.is_open())
	{
		myfile << Loja::getCount();

		for(; it!=vs.end(); it++)
			myfile << "|" << (*it)->getInfo()->getCodZona()<<"|"<< (*it)->getInfo()->getLoja()->toString() << endl;
		myfile.close();
	}
}

void LojaElectronica::loadEncomendas(string filename)
{
	// TODO
}

void LojaElectronica::saveEncomendas(string filename)
{
	// TODO
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
}

void LojaElectronica::saveVertices(string filename)
{
	vector<Vertex<Zona*> *> vs = myGraph.getVertexSet();
	vector<Vertex<Zona*> *>::iterator it;

	ofstream myfile (filename.c_str());
	if(myfile.is_open())
	{
		myfile << Zona::getCount();

		for(it=vs.begin(); it!=vs.end(); it++)
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
	vector<Vertex<Zona*> *> vs = myGraph.getVertexSet();
	vector<Vertex<Zona*> *>::iterator it;
	ofstream myfile (filename.c_str());
	if(myfile.is_open())
	{
		for(it=vs.begin(); it!=vs.end(); it++)
		{
			vector<Edge<Zona*> > vedges = (*it)->getAdj();
			vector<Edge<Zona*> >::iterator ited;
			for(ited=vedges.begin(); ited!=vedges.end(); ited++)
				myfile<<"|"<<(*it)->getInfo()->getCodZona()<<"|"<<ited->getDest()->getInfo()->getCodZona()<<"|"<<ited->getWeight()<<"|";
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

	//criar os nos partir do vector vertexSet
	for(unsigned int i=0;i<myGraph.getVertexSet().size();i++){

		gv->addNode(myGraph.getVertexSet()[i]->getInfo()->getCodZona());
		gv->setVertexLabel(myGraph.getVertexSet()[i]->getInfo()->getCodZona(), myGraph.getVertexSet()[i]->getInfo()->getDesignacao());
		gv->rearrange();
	}

	//Nota: para criar uma aresta deve utilizar o seguinte comando:
	// para arestas bidireccionais

	/*gv->addEdge(0,0,1,EdgeType::UNDIRECTED);
		gv->addEdge(1,0,2,EdgeType::UNDIRECTED);
		gv->addEdge(2,1,3,EdgeType::UNDIRECTED);
		gv->addEdge(3,2,3,EdgeType::UNDIRECTED);*/
	// para arestas direccionais
	//vector<Vertex<Zona*> *>::iterator it;
	int idEdge=0;
	vector<Vertex<Zona*> *> vs = myGraph.getVertexSet();
	vector<Vertex<Zona*> *>::iterator it;
	cout<<"hello: "<<vs.size()<<endl;
	for(it=vs.begin(); it!=vs.end(); it++)
	{
		cout<<"entre por aqui?\n";
		//TODO  nao esta a funcionar
		vector<Edge<Zona*> > vedges = (*it)->getAdj();
		vector<Edge<Zona*> >::iterator ited;
		for(ited=vedges.begin(); ited!=vedges.end(); ited++)
		{
			gv->addEdge(idEdge, (*it)->getInfo()->getCodZona(), ited->getDest()->getInfo()->getCodZona(), EdgeType::UNDIRECTED);
			idEdge++;
		}
	}


	gv->rearrange();

	/*
		gv->setVertexColor(2,"green");
		gv->setEdgeColor(2,"yellow");
		gv->rearrange();
	 */

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
