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

int algoritmo=1;


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
	//clear();
	unsigned int aux;
	for(unsigned int i=0; i<79; i++)
		cout<<"*";
	cout<<endl<<"*****";
	for(unsigned int i=0; i<69; i++)
		cout<<" ";
	cout<<"*****"<<endl<<"*****";
	for(unsigned int i=0; i<25; i++)
		cout<<" ";
	cout<<"-Loja Electronica- ";
	for(unsigned int i=0; i<25; i++)
		cout<<" ";
	cout<<"*****"<<endl<<"*****";
	for(unsigned int i=0; i<69; i++)
		cout<<" ";
	cout<<"*****"<<endl<<"*****";
	aux=69-titulo.length();
	if(aux%2==0)
	{
		for(unsigned int i=0; i<aux/2; i++)
			cout<<" ";
		cout<<titulo;
		for(unsigned int i=0; i<aux/2; i++)
			cout<<" ";
		cout<<"*****"<<endl;
	}
	else
	{
		aux=68-titulo.length();
		for(unsigned int i=0; i<aux/2; i++)
			cout<<" ";
		cout<<titulo;
		for(unsigned int i=0; i<aux/2+1; i++)
			cout<<" ";
		cout<<"*****"<<endl;
	}
	cout<<"*****";
	for(unsigned int i=0; i<69; i++)
		cout<<" ";
	cout<<"*****"<<endl;
	for(unsigned int i=0; i<79; i++)
		cout<<"*";
	cout<<endl<<"*";
	for(unsigned int i=0; i<77; i++)
		cout<<" ";
	cout<<"*"<<endl;
	for(unsigned int i=1; i<=opcoes.size(); i++)
	{
		cout<<"*   "<<opcoes.at(i-1);
		aux=74-opcoes.at(i-1).length();
		for (unsigned int j=0; j<aux; j++)
			cout<<" ";
		cout<<"*"<<endl;
	}
	aux=14-opcoes.size();
	for (unsigned int i=0; i<aux; i++)
	{
		cout<<"*";
		for(unsigned int j=0; j<77; j++)
			cout<<" ";
		cout<<"*"<<endl;
	}
	for(unsigned int i=0; i<79; i++)
		cout<<"*";
	cout<<endl<<endl;
}

void LojaElectronica::menuPrincipal()
{
	int op;
	vector<string> opcoes;
	opcoes.push_back("Escolha uma das seguintes opcoes:");
	opcoes.push_back("");

	opcoes.push_back("1 - Gestao de Clientes");
	opcoes.push_back("2 - Gestao de Encomendas");
	opcoes.push_back("3 - Gestao de Zonas");
	opcoes.push_back("4 - Gestao de Lojas");
	opcoes.push_back("5 - Escolha Algoritmo Pesquisa no Grafo");
	opcoes.push_back("6 - Mapa de Zonas");
	opcoes.push_back("");
	opcoes.push_back("0 - Gravar e sair");

	showMenu("Menu Principal", opcoes);
	cout<<"    Opcao: ";
	op=intinput();

	switch(op)
	{
	case 1:
		menuCliente(); //vai para menu cliente
		menuPrincipal(); //volta ao menu principal
		break;
	case 2:
		menuEncomenda(); //vai para menu encomenda
		menuPrincipal(); //volta ao menu principal
		break;
	case 3:
		menuZona();
		menuPrincipal();
		break;
	case 4:
		menuLoja();
		menuPrincipal();
		break;
	case 5:
		escolhaAlgoritmo();
		system("PAUSE");
		menuPrincipal();
		break;
	case 6:
		Mapa();
		system("PAUSE");
		menuPrincipal();
		break;
	case 0:
		saveProdutos("produtos.txt");
		saveLojas("lojas.txt");
		saveClientes("clientes.txt");
		saveVertices("nos.txt");
		saveEdges("arestas.txt");
		saveEncomendas("encomendas.txt");
		break;
	default:
		cout<<"Opcao invalida! Insira uma das opcoes disponiveis"<<endl;
		menuPrincipal();
	}
}

void LojaElectronica::escolhaAlgoritmo() {
	cout << "Qual o Algoritmo de Pesquisa a utilizar:" << endl;
	cout << "1 - Menor distancia da loja que possui esse produto ao cliente (Grafo Pesado - Dijkstra)" << endl;
	cout << "2 - Menor numero de zonas a atravessar, entre a loja que possui esse produto e a residancia do cliente (Grafo nao Pesado)" << endl;
	int i;
	do {
		cout << "Escolha: ";
		fflush(stdin);
		cin >> i;
	}while(i!=1 || i!=2);

	if(i==1)
		algoritmo=1;
	else
		algoritmo=2;
}

void LojaElectronica::menuEncomenda()
{
	unsigned int op, cod;
	Encomenda *e;
	vector<string> opcoes;
	string filename;
	opcoes.push_back("Escolha uma das seguintes opcoes:");
	opcoes.push_back("");
	opcoes.push_back("1 - Adicionar Encomenda");//opcao 1
	if(encomendas.size()>0)
	{
		opcoes.push_back("2 - Listar Encomenda");//opcao 2
		opcoes.push_back("3 - Remover uma Encomenda");//opcao 4
	}
	opcoes.push_back("");
	opcoes.push_back("0 - Voltar atras");//opcao 7

	showMenu("Gestao de Encomendas", opcoes);
	cout<<"    Opcao: ";
	op=intinput();
	system("cls");

	if(encomendas.size()>0)
	{
		switch(op)
		{
		case 1:
			try{
				cout<<"addEncomenda: "<<endl;
				addEncomenda();
			}
			catch(Excepcao &ex) {
				cout << ex.getMessage() << endl;
			}
			menuEncomenda();
			break;
		case 2:
			listaEncomendas();
			system("pause");
			menuEncomenda();//volta ao menu Encomenda
			break;
		case 3://apagar Encomenda
			listaEncomendas();
			cout<<endl<<"Introduza o ID da Encomenda que pretende apagar: ";
			cod=intinput();
			try
			{
				e = procuraEncomenda(cod);
				removeEncomenda(e->getcodEncomenda());
			}
			catch (Excepcao &e)
			{
				cout<<e.getMessage();
			}
			system("pause");
			menuEncomenda();
			break;
		case 0:
			break;
		default:
			cout<<"Opcao invalida! Insira uma das opcoes disponiveis"<<endl;
			system("pause");
			menuEncomenda();
		}
	}
	else
	{
		switch(op)
		{
		case 1:
			try{
				cout<<"addEncomenda: "<<endl;
				addEncomenda();
			}
			catch(Excepcao &ex) {
				cout << ex.getMessage() << endl;
			}
			menuEncomenda();
			break;
		case 0:
			break;
		default:
			cout<<"Opcao invalida! Insira uma das opcoes disponiveis"<<endl;
			system("pause");
			menuEncomenda();
		}
	}
}

void LojaElectronica::menuCliente()
{
	unsigned int op;
	Cliente *c;
	vector<string> opcoes;
	string nome;
	string filename;
	opcoes.push_back("Escolha uma das seguintes opcoes:");
	opcoes.push_back("");
	opcoes.push_back("1 - Adicionar Cliente");//opcao 1
	if(clientes.size()>0)
	{
		opcoes.push_back("2 - Ver detalho dum Cliente");//opcao 2
		opcoes.push_back("3 - Editar um Cliente");//opcao 3
		opcoes.push_back("4 - Remover um Cliente");//opcao 4
	}

	opcoes.push_back("");
	opcoes.push_back("0 - Voltar atras");

	showMenu("Gestao de Clientes", opcoes);
	cout<<"    Opcao: ";
	op=intinput();
	system("cls");

	if(clientes.size()>0)
	{
		switch(op)
		{
		case 1:
			try {
				addCliente();
			}
			catch(Excepcao &e) {
				cout << e.getMessage() << endl;
			}
			system("PAUSE");
			menuCliente();
			break;
		case 2:
			listaClientes();
			cout<<endl<<"Introduza o nome do Cliente que pretende ver os detalhes: ";
			fflush(stdin);
			getline(cin,nome);
			try
			{
				c = ProcuraCliente_nome(nome);
				showMenu("Detalhes do Cliente", c->imprimeCliente());
			}
			catch (Excepcao &e)
			{
				cout << e.getMessage() << endl;
			}
			system("pause");
			menuCliente();//volta ao menu Cliente
			break;
		case 3://editar Cliente
			listaClientes();
			cout<<endl<<"Introduza o nome do Cliente que pretende ver os detalhes: ";
			fflush(stdin);
			getline(cin,nome);
			try
			{
				c = ProcuraCliente_nome(nome);
				editCliente(c);
				cout<<"\nAlteracao com sucesso!\n";
			}
			catch (Excepcao &e)
			{
				cout<<e.getMessage()<<endl;
			}
			system("pause");
			menuCliente();
			break;
		case 4://apagar Cliente
			listaClientes();
			cout<<endl<<"Introduza o nome do Cliente que pretende ver os detalhes: ";
			fflush(stdin);
			getline(cin,nome);
			try {
				c = ProcuraCliente_nome(nome);
				showMenu("Detalhes do Cliente", c->imprimeCliente());
				removeCliente(c->getNome());
			}
			catch (Excepcao &e)
			{
				cout<<e.getMessage()<<endl;
			}
			system("pause");
			menuCliente();
			break;
		case 0:
			break;
		default:
			cout<<"Opcao invalida! Insira uma das opcoes disponiveis"<<endl;
			system("pause");
			menuCliente();
		}
	}
	else
	{
		switch(op)
		{
		case 1:
			try {
				addCliente();
			}
			catch(Excepcao &e) {
				cout << e.getMessage() << endl;
			}
			system("PAUSE");
			menuCliente();
			break;
		case 0:
			break;
		default:
			cout<<"Opcao invalida! Insira uma das opcoes disponiveis"<<endl;
			system("pause");
			menuCliente();
		}
	}
}


void LojaElectronica::menuZona()
{
	unsigned int op;
	string designacao;
	Zona *z;
	vector<string> opcoes;
	opcoes.push_back("Escolha uma das seguintes opcoes:");
	opcoes.push_back("");
	opcoes.push_back("1 - Adicionar uma Zona");
	if(myGraph.getVertexSet().size()>0)
	{
		opcoes.push_back("2 - Remover uma Zona");
		opcoes.push_back("3 - Adicionar Ligacao entre Zonas");
		opcoes.push_back("4 - Remover Ligacao entre Zonas");
	}
	opcoes.push_back("");
	opcoes.push_back("0 - Voltar atras");

	showMenu("Menu Zona", opcoes);
	cout<<"    Opcao: ";
	op=intinput();
	if(myGraph.getVertexSet().size()>0)
	{
		switch(op)
		{
		case 1:
			try{
				addZona();
			}
			catch(Excepcao &e)
			{
				cout<<e.getMessage();
			}
			menuZona();
			break;
		case 2:
			listaZonas();
			cout<<endl<<"Introduza a Designacao da Zona que pretende apagar: ";
			fflush(stdin);
			getline(cin, designacao);
			try
			{
				z = procuraZona(designacao);
				removeZona(z->getDesignacao());
			}
			catch (Excepcao &e)
			{
				e.getMessage();
			}
			system("pause");
			menuZona();
			break;
		case 3:
			listaZonas();
			cout<<endl<<"Introduza a Designacao da Zona que pretende adicionar ligacao: ";
			fflush(stdin);
			getline(cin, designacao);
			try
			{
				z = procuraZona(designacao);
				addAresta(z);
			}
			catch (Excepcao &e)
			{
				cout<<e.getMessage()<<endl;
			}
			system("pause");
			menuZona();
			break;
		case 4:
			listaZonas();
			cout<<endl<<"Introduza a Designacao da Zona que pretende remover ligacao: ";
			fflush(stdin);
			getline(cin, designacao);
			try
			{
				z = procuraZona(designacao);
				removeAresta(z);
			}
			catch (Excepcao &e)
			{
				cout<<e.getMessage()<<endl;
			}
			system("pause");
			menuZona();
			break;
		case 0:
			break;
		default:
			cout<<"Opcao invalida! Insira uma das opcoes disponiveis"<<endl;
			system("pause");
			menuZona();
		}
	}
	else
	{
		switch(op)
		{
		case 1:
			try{
				addZona();
			}
			catch(Excepcao &e)
			{
				cout<<e.getMessage();
			}
			menuZona();
			break;
		case 0:
			break;
		default:
			cout<<"Opcao invalida! Insira uma das opcoes disponiveis"<<endl;
			system("pause");
			menuZona();
		}
	}
}

void LojaElectronica::editLoja(Loja *l)
{
	string nome, morada;
	int op;

	vector<string> opcoes;
	opcoes = l->editLoja();
	opcoes.push_back("");
	opcoes.push_back("0 - Voltar atras");

	showMenu("Editar Loja", opcoes);
	cout<<"    Opcao: ";
	op=intinput();
	system("cls");

	switch(op)
	{
	case 1: //editar nome
		cout<<"Novo nome da Loja: ";
		getline(cin, nome);
		l->setNome(nome);
		break;
	case 2: //editar morada
		cout<<"Nova morada da Loja: ";
		getline(cin, morada);
		l->setMorada(morada);
		break;
	case 0: //voltar atras
		return;
		break;
	default:
		editLoja(l);
	}
}

void LojaElectronica::menuLoja()
{
	unsigned int op, cod;
	string filename;
	Loja *l;
	vector<string> opcoes;
	opcoes.push_back("Escolha uma das seguintes opcoes:");
	opcoes.push_back("");
	opcoes.push_back("1 - Adicionar uma Loja");
	try
	{
		if(listaLojas()>0)
		{
			opcoes.push_back("2 - Editar uma Loja");
			opcoes.push_back("3 - Remover uma Loja");
			opcoes.push_back("4 - Gerir Produtos duma Loja");
		}
	}
	catch(Excepcao &e){}

	opcoes.push_back("");
	opcoes.push_back("0 - Voltar atras");

	showMenu("Menu Loja", opcoes);
	cout<<"    Opcao: ";
	op=intinput();
	try{
		if(listaLojas()>0)
		{
			switch(op)
			{
			case 1:
				try
				{
					addLoja();
				}
				catch (Excepcao &e)
				{
					cout<<e.getMessage();
				}
				menuLoja();
				break;
			case 2:
				cout<<endl<<"Introduza o Codigo da Loja que pretende editar: ";
				cod=intinput();
				try
				{
					l = procuraLoja(cod);
					editLoja(l);
				}
				catch (Excepcao &e)
				{
					cout<<e.getMessage();
				}
				system("pause");
				menuLoja();
				break;
			case 3:
				cout<<endl<<"Introduza o Codigo da Loja que pretende apagar: ";
				cod=intinput();
				try
				{
					l = procuraLoja(cod);
					removeLoja(l->getCodLoja());
				}
				catch (Excepcao &e)
				{
					cout<<e.getMessage();
				}
				system("pause");
				menuLoja();
				break;
			case 4:
				cout<<endl<<"Introduza o Codigo da Loja que pretende gerir os Produtos: ";
				cod=intinput();
				try
				{
					l = procuraLoja(cod);
				}
				catch (Excepcao &e)
				{
					cout<<e.getMessage();
				}
				menuProduto(l);
				menuLoja();
				break;
			case 0:
				break;
			default:
				cout<<"Opcao invalida! Insira uma das opcoes disponiveis"<<endl;
				system("pause");
				menuZona();
			}
		}
		else
		{
			switch(op)
			{
			case 1:
				try
				{
					addLoja();
				}
				catch (Excepcao &e)
				{
					cout<<e.getMessage();
				}
				menuLoja();
				break;
			case 0:
				break;
			default:
				cout<<"Opcao invalida! Insira uma das opcoes disponiveis"<<endl;
				system("pause");
				menuZona();
			}
		}
	}
	catch(Excepcao &e){
		cout<<"Opcao invalida, tenta novamente!\n";
		system("pause");
	}
}

void LojaElectronica::menuProduto(Loja *l)
{
	unsigned int op, cod;
	string filename;
	vector<string> opcoes;
	opcoes.push_back("Escolha uma das seguintes opcoes:");
	opcoes.push_back("");
	opcoes.push_back("1 - Adicionar um Produto");
	if(l->getProdutos().size()>0)
	{
		opcoes.push_back("2 - Editar um Protudo");
		opcoes.push_back("3 - Remover um Produto");
	}
	opcoes.push_back("");
	opcoes.push_back("0 - Voltar atras");

	showMenu("Menu Produto", opcoes);
	cout<<"    Opcao: ";
	op=intinput();
	system("cls");

	if(l->getProdutos().size()>0)
	{
		switch(op)
		{
		case 1:
			l->addProduto();
			menuProduto(l);
			break;
		case 2:
			l->editProduto();
			menuProduto(l);
			break;
		case 3:
			l->listaProduto();
			cout<<endl<<"Introduza o Codigo do Produto que pretende apagar: ";
			cod=intinput();
			try
			{
				l = NULL;
				for(unsigned int i=0; i<l->getProdutos().size(); i++)
				{
					if(cod == l->getProdutos()[i]->getCodProduto())
					{
						l->removeProduto(cod);
						break;
					}
				}
				if(l == NULL)
					throw Excepcao("Produto nao encontrado!\n");
			}
			catch (Excepcao &e)
			{
				cout<<e.getMessage();
			}
			system("pause");
			menuProduto(l);
			break;
		case 0:
			break;
		default:
			cout<<"Opcao invalida! Insira uma das opcoes disponiveis"<<endl;
			system("pause");
			menuProduto(l);
		}
	}
	else
	{
		switch(op)
		{
		case 1:
			l->addProduto();
			menuProduto(l);
			break;
		case 0:
			break;
		default:
			cout<<"Opcao invalida! Insira uma das opcoes disponiveis"<<endl;
			system("pause");
			menuProduto(l);
		}
	}
}

void LojaElectronica::addCliente()
{
	int nif;
	string nome,morada,contacto,email,zona;

	cout << "Nome: ";
	getline(cin,nome);
	cout << "Morada: ";
	getline(cin,morada);
	cout << "Telefone: ";
	getline(cin, contacto);
	cout << "Email: ";
	getline(cin,email);
	do{
		cout << "NIF: ";
		nif = intinput();
	}while(nif<100000000 || nif>999999999);

	cout<<endl<<"Lista das Zonas:"<<endl<<endl;
	listaZonas();

	cout << "Defina a designacao da Zona do Cliente: ";
	fflush(stdin);
	getline(cin,zona);

	Zona *zonaCliente=procuraZona(zona);

	Cliente *c=new Cliente(nome,morada,contacto,email,nif,zonaCliente);

	clientes.push_back(c);
}

void LojaElectronica::editCliente(Cliente *c)
{
	string morada, contacto, email, zona;
	int op;
	Zona *z = NULL;
	vector<string> opcoes;
	opcoes = c->editCliente();
	opcoes.push_back("");
	opcoes.push_back("0 - Voltar atras");

	showMenu("Editar Cliente", opcoes);
	cout<<"    Opcao: ";
	op=intinput();
	system("cls");

	switch(op)
	{
	case 1: //editar morada
		cout<<"Nova morada do Cliente: ";
		getline(cin, morada);
		c->setMorada(morada);
		break;
	case 2: //editar contacto
		cout<<"Novo contacto do Cliente: ";
		getline(cin, contacto);
		c->setContacto(contacto);
		break;
	case 3: //editar email
		cout<<"Novo email do Cliente: ";
		getline(cin, email);
		c->setEmail(email);
		break;
	case 4:
		cout<<"Nova Zona do Cliente: ";
		getline(cin, zona);
		z=procuraZona(zona);
		c->setZona(z);
		break;
	case 0: //voltar atras
		return;
	default:
		editCliente(c);
	}
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
}

Zona* LojaElectronica::procuraZona(string designacao) {
	vector<Vertex<Zona*> *> vs = myGraph.getVertexSet();
	vector<Vertex<Zona*> *>::iterator it = vs.begin();

	for(;it != vs.end();it++) {
		if((*it)->getInfo()->getDesignacao()==designacao)
			return (*it)->getInfo();
	}
	throw Excepcao("Zona nao encontrada!");
}
Zona* LojaElectronica::procuraZona(unsigned int id) {
	vector<Vertex<Zona*> *> vs = myGraph.getVertexSet();
	vector<Vertex<Zona*> *>::iterator it = vs.begin();

	for(;it != vs.end();it++) {
		if((*it)->getInfo()->getCodZona()==id)
			return (*it)->getInfo();
	}
	throw Excepcao("Zona nao encontrada!");
}

Loja* LojaElectronica::procuraLoja(unsigned int id) {
	vector<Vertex<Zona*> *> vs = myGraph.getVertexSet();
	vector<Vertex<Zona*> *>::iterator it = vs.begin();

	for(;it != vs.end();it++) {
		if((*it)->getInfo()->getLoja()->getCodLoja()==id)
			return (*it)->getInfo()->getLoja();
	}
	throw Excepcao("Loja nao encontrada!\n");
}

void LojaElectronica::addZona()
{
	string designacao;

	cout << "Designacao da Zona: " << endl;
	fflush(stdin);
	getline(cin,designacao);
	//verifica se ja existe alguma zona c mesma designacao

	vector<Vertex<Zona*> *> vs = myGraph.getVertexSet();
	vector<Vertex<Zona*> *>::iterator it = vs.begin();
	for(;it != vs.end();it++) {
		if((*it)->getInfo()->getDesignacao()==designacao)
			throw Excepcao("Zona ja existe!\n");
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
		Zona *z2 = NULL;
		bool b=false;
		do
		{
			cout << "Insira a designacao de uma Zona a qual ligar: ";
			fflush(stdin);
			getline(cin,desig);

			try{
				z2 = procuraZona(desig);
				b = true;
			}
			catch(Excepcao &e)
			{
				cout<<e.getMessage()<<endl;
			}
		}while(b == false);

		cout << "Distancia: ";
		fflush(stdin);
		cin >> dist;

		addArestaBidireccional(z1,z2,dist);

		cout << "Deseja inserir mais alguma distancia a outra zona? (S/N): ";
		fflush(stdin);
		cin >> resp;

	} while(resp!='n' || resp != 'N');
}

void LojaElectronica::addAresta(Zona *z) {
	cout << "Adicionar Ligacao" << endl << endl;
	listaZonas();
	string desig;
	int dist;
	Zona *z2 = NULL;
	bool b=false;
	do{
		cout << "Insira a designacao de uma Zona a qual ligar: ";
		fflush(stdin);
		getline(cin,desig);
		try
		{
			z2 = procuraZona(desig);
			b=true;
		}
		catch(Excepcao &e)
		{
			cout<<e.getMessage()<<endl;
		}
	}while(b == false);

	cout << "Distancia: ";
	fflush(stdin);
	cin >> dist;
	addArestaBidireccional(z,z2,dist);

}

void LojaElectronica::listaArestasDesde(Zona *z) {
	Vertex<Zona*>* v = devolveVertex(z);
	if(v->getAdj().size()==0)
		cout << "Nao existem ligacoes a partir desta Zona!" << endl;
	for(unsigned int i=0; i<v->getAdj().size();i++) {
		cout << v->getAdj()[i].getDest()->getInfo()->getDesignacao() << " | Distancia: " << v->getAdj()[i].getWeight()<<endl;
	}
}

void LojaElectronica::removeAresta(Zona *z) {
	cout << "Remover Ligacao" << endl << endl;
	listaArestasDesde(z);
	string desig;
	Zona *z2 = NULL;
	bool b=false;
	do{
		cout << "Insira a designacao da Zona destino da ligacao a remover: ";
		fflush(stdin);
		getline(cin,desig);

		try{
			z2 = procuraZona(desig);
			b=true;
		}
		catch(Excepcao &e)
		{
			cout<<e.getMessage()<<endl;
		}
	}while(b==false);

	removeArestaBidireccional(z,z2);
	cout << "Ligacao Eliminada!"<< endl;

}

void LojaElectronica::editPesoAresta(Zona *z) {
	cout << "Editar Distancia de Ligacao entre Zonas" << endl << endl;
	listaArestasDesde(z);
	string desig;
	int dist;
	Zona *z2 = NULL;
	bool b=false;
	do{
		cout << "Insira a designacao da Zona destino da ligacao a editar: ";
		fflush(stdin);
		getline(cin,desig);

		try{
			z2 = procuraZona(desig);
			b=true;
		}
		catch(Excepcao &e)
		{
			cout<<e.getMessage()<<endl;
		}
	}while(b==false);

	cout << "Insira o nova distancia: ";
	fflush(stdin);
	cin >> dist;
	removeArestaBidireccional(z,z2);
	addArestaBidireccional(z,z2,dist);
	cout << "Aresta Editada!"<< endl;

}

void LojaElectronica::addArestaBidireccional(Zona* z1, Zona* z2, int dist) {
	myGraph.addEdge(z1,z2,dist);
	myGraph.addEdge(z2,z1,dist);
	cout << "Aresta adicionada!" << endl<< endl;
}

void LojaElectronica::removeArestaBidireccional(Zona* z1, Zona* z2) {
	Vertex<Zona*>* v1 = devolveVertex(z1);
	Vertex<Zona*>* v2 = devolveVertex(z2);
	v1->removeEdgeTo(v2);
	v2->removeEdgeTo(v1);
}

Vertex<Zona*>* LojaElectronica::devolveVertex(Zona* z) {

	for(unsigned int i=0;i<myGraph.getVertexSet().size();i++) {
		if(myGraph.getVertexSet()[i]->getInfo()==z) {
			return myGraph.getVertexSet()[i];
		}
	}
	return NULL;
}
void LojaElectronica::removeZona(string desig)
{
	bool encontrou=false;

	for(unsigned int i=0;i<myGraph.getVertexSet().size();i++) {
		if(myGraph.getVertexSet()[i]->getInfo()->getDesignacao()==desig) {
			encontrou=true;
			Zona *z = myGraph.getVertexSet()[i]->getInfo();
			for(unsigned int i=0; i<myGraph.getVertexSet()[i]->getAdj().size();i++) {
				removeArestaBidireccional(z,myGraph.getVertexSet()[i]->getAdj()[i].getDest()->getInfo());
			}
			myGraph.removeVertex(z);
			break;
		}
	}
	if(encontrou==false)
		throw Excepcao("\n Nao existe nenhuma zona com esse ID \n");
	else
		cout<<"Zona Eliminada com sucesso"<<endl;
}

void LojaElectronica::listaZonas()
{
	if(myGraph.getVertexSet().size()==0 ) throw Excepcao("\n Nao existem zonas no sistema \n");
	cout << endl;
	for (unsigned int i=0; i < myGraph.getVertexSet().size(); i++)
	{
		cout << myGraph.getVertexSet()[i]->getInfo()->toString() << endl;
	}
	cout << endl;

}

void LojaElectronica::addLoja()
{
	string nome, morada, zona;

	cout << "Nome: ";
	getline(cin,nome);
	cout << "Morada: ";
	getline(cin,morada);

	listaZonas();
	cout << "Indique o nome da Zona onde pertence a loja: ";
	getline(cin,zona);

	Loja *l1=new Loja(nome,morada);
	Zona *zonaLoja=procuraZona(zona);

	zonaLoja->setLoja(l1);
	cout << "Loja adicionada com sucesso!" << endl;
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
		cout<<"Loja Eliminada com sucesso"<<endl;
	} else throw Excepcao("\n Nao existe nenhuma loja com esse ID \n");
}

void LojaElectronica::addEncomenda()
{
	system("cls");
	string nome, produto;
	Produto *p;
	Loja *l;
	string data = dataActual();
	bool enc=false;

	cout << "ENCOMENDA" << endl << endl;

	listaClientes();
	cout << "Insira o nome do cliente: ";
	fflush(stdin);
	getline(cin,nome);
	Cliente *c = ProcuraCliente_nome(nome);
	if(c==NULL)
		throw Excepcao("Cliente nao existente");

	Zona *noOrigem = c->getZona();
	Zona *noDest;

	cout << endl<< endl<< "Seleccionar Produto" << endl << endl;
	listaProdutos();

	cout << "Nome do produto desejado: ";
	fflush(stdin);
	getline(cin,produto);

	if(algoritmo==1) {
		//Caminhos mais curtos a partir de noOrigem --> Grafos Pesados - Djikstra
		myGraph.dijkstraShortestPath(noOrigem);
	}
	else {
		//Caminhos mais curtos a partir de noOrigem --> Grafos Nao Pesados
		myGraph.unweightedShortestPath(noOrigem);
	}

	vector<Vertex<Zona*>* > vDist = myGraph.getVertexSet();
	myGraph.insertionSort(vDist);

	//Procurar Produtos nas Lojas TOdas
	vector<int> codigoZonascomProduto;
	vector<Vertex<Zona*>* >::iterator it = vDist.begin();
	for(;it!=vDist.end();it++) {
		for(unsigned int i=0; i< (*it)->getInfo()->getLoja()->getProdutos().size();i++) {
			if((*it)->getInfo()->getLoja()->getProdutos()[i]->getDesignacao()==produto  && (*it)->getInfo()->getLoja()->getProdutos()[i]->getStock()>0 ) {
				codigoZonascomProduto.push_back((*it)->getInfo()->getCodZona());
			}
		}
	}

	it = vDist.begin();
	for(;it!=vDist.end();it++) {
		for(unsigned int i=0; i< (*it)->getInfo()->getLoja()->getProdutos().size();i++) {
			if((*it)->getInfo()->getLoja()->getProdutos()[i]->getDesignacao()==produto  && (*it)->getInfo()->getLoja()->getProdutos()[i]->getStock()>0 ) {
				p=(*it)->getInfo()->getLoja()->getProdutos()[i];
				l=(*it)->getInfo()->getLoja();
				(*it)->getInfo()->getLoja()->getProdutos()[i]->decStock();
				noDest=(*it)->getInfo();
				enc=true;
				break;
			}
		}
		if(enc==true) break;
	}
	if(enc==true) {
		cout << endl << "Produto Disponivel na Loja: " << l->getNome() << ", Zona: "<< noDest->getDesignacao() << endl << endl;
		Encomenda *e = new Encomenda(data,l,c,p);
		e->imprimeEncomendas();
		encomendas.push_back(e);
		cout << endl <<"Encomenda Registada com sucesso! A abrir Mapa..."<< endl << endl;
		vector<Zona*> vPath = myGraph.getPath(noOrigem,noDest);
		Caminho(vPath, codigoZonascomProduto);
	}
	else {
		cout << "O produto pretendido nao se encontra disponivel em nenhuma loja." << endl<<endl;
	}
}


void LojaElectronica::removeEncomenda(unsigned int codEncomenda)
{
	unsigned int idenc;
	listaEncomendas();
	cout << "Id da encomenda a eliminar: ";
	fflush(stdin);
	cin >> idenc;

	for(unsigned int i=0; i<encomendas.size();i++) {
		if(encomendas[i]->getcodEncomenda()==idenc) {
			encomendas.erase(encomendas.begin()+i);
			cout << "Encomenda removida com sucesso!"<< endl;
			return;
		}
	}
	cout << "Encomenda nao encontrada!"<< endl;
}

Encomenda * LojaElectronica::procuraEncomenda(unsigned int id) {
	for(unsigned int i=0; i<encomendas.size();i++) {
		if(encomendas[i]->getcodEncomenda()==id) {
			return encomendas[i];
		}
	}
	throw Excepcao("Encomenda nao encontrada!\n");
}

void LojaElectronica::listaClientes()
{
	if(clientes.size()==0 ) throw Excepcao("\n Nao existem clientes no sistema \n");
	cout << endl;
	for (unsigned int i=0; i < clientes.size(); i++) {
		clientes[i]->resumo();
	}
	cout << endl;
}

void LojaElectronica::listaProdutos()
{
	vector<string> vp = nomesProdutos();
	cout << "Produtos existentes:" << endl << endl;
	for(unsigned int i=0; i< vp.size(); i++) {
		cout << vp[i];
		if(i!=(vp.size()-1))cout << " | ";
	}
	cout << endl << endl;
}

vector<string> LojaElectronica::nomesProdutos(){

	string prod;
	vector<string> res;
	vector<Vertex<Zona*> *> vec = myGraph.getVertexSet();
	for (unsigned int i=0; i < vec.size(); i++)
	{
		for(unsigned int j=0;j<vec[i]->getInfo()->getLoja()->getProdutos().size();j++) {
			prod=vec[i]->getInfo()->getLoja()->getProdutos()[j]->getDesignacao();
			if(pesquisaSequencial(res,prod)==-1)
				res.push_back(prod);
		}
	}
	return res;
}

int LojaElectronica::listaLojas()
{
	if(myGraph.getVertexSet().size()==0) throw Excepcao("\n Nao existem lojas no sistema \n");
	int nLojas = 0;
	for (unsigned int i=0; i < myGraph.getVertexSet().size(); i++)
		if(myGraph.getVertexSet()[i]->getInfo()->getLoja() != NULL)
		{
			cout << myGraph.getVertexSet()[i]->getInfo()->getLoja()->toString() << endl;
			nLojas++;
		}
	return nLojas;
}

void LojaElectronica::listaEncomendas()
{
	for(unsigned int i=0;i<encomendas.size();i++) {
		encomendas[i]->resumo();
	}
	cout<< endl;
}

void LojaElectronica::loadClientes(string filename)
{
	// |Cod|Nome|NIF|Morada|Contacto|Email|CodZona|  fica este formato
	ifstream file;
	string line;
	string nome,morada,contacto,email,NIB;
	unsigned int NIF, codCliente, codZona;
	vector<string> v;

	file.open(filename.c_str());

	if (file.is_open())
	{
		getline(file, line);
		Cliente::setCount(atoi(line.c_str()));
		while(!file.eof() ){
			getline(file, line);
			if(line == "") break;
			v = split('|', line);
			codCliente = atoi(v[0].c_str());
			nome = v[1].c_str();
			NIF = atoi(v[2].c_str());
			morada = v[3].c_str();
			contacto = v[4].c_str();
			email = v[5].c_str();
			codZona = atoi(v[6].c_str());

			Zona *z = procuraZona(codZona);
			Cliente *c1 = new Cliente(nome,morada,contacto,email,NIF, codCliente, z);
			clientes.push_back(c1);
		}
		file.close();
		cout<<endl<<"Edges importadas com sucesso!"<<endl<<endl;
	}
	else
	{
		cout<<"Nao foi possivel abrir o ficheiro "<<filename<<"!"<<endl<<endl;
	}
}
void LojaElectronica::saveClientes(string filename)
{
	ofstream myfile(filename.c_str());
	if (myfile.is_open()) {
		myfile << Cliente::getCount() << endl;
		for(unsigned int i=0; i<clientes.size(); i++)
		{
			myfile<<"|"<<clientes[i]->getCodCliente()<<"|"<<clientes[i]->getNome()<<"|"<<clientes[i]->getNIF()<<"|"<<clientes[i]->getMorada()<<"|"<<clientes[i]->getContacto()<<"|"<<clientes[i]->getEmail()<<"|"<<clientes[i]->getZona()->getCodZona()<<"|"<<endl;
		}
		myfile.close();
		cout<<endl<<"Clientes exportadas com sucesso!"<<endl;
	}
	else
	{
		cout<<"Nao foi possivel abrir o ficheiro!"<<endl<<endl;
		system("pause");
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

		while(!file.eof() ) {

			getline(file, line);
			if(line=="") break;
			v=split('|', line);

			idloja = atoi(v[0].c_str());
			desig = v[1];
			preco= atof(v[2].c_str());
			stock=atoi(v[3].c_str());

			Produto *p = new Produto(desig,stock,preco);
			Loja *l1 = procuraLoja(idloja);
			l1->insertProd(p);
		}
		cout<<endl<<"Produtos importadas com sucesso!"<<endl<<endl;
		file.close();
	}
	else
	{
		cout<<"Nao foi possivel abrir o ficheiro "<<filename<<"!"<<endl<<endl;
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
				myfile << "|" << (*it)->getInfo()->getLoja()->getCodLoja();
				myfile << (*it)->getInfo()->getLoja()->getProdutos()[i]->toString() << endl;
			}
		}
		cout<<endl<<"Produtos exportadas com sucesso!"<<endl;
		myfile.close();
	}
	else
	{
		cout<<"Nao foi possivel abrir o ficheiro!"<<endl<<endl;
		system("pause");
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
		cout<<endl<<"Lojas importadas com sucesso!"<<endl<<endl;
		file.close();
	}
	else
	{
		cout<<"Nao foi possivel abrir o ficheiro "<<filename<<"!"<<endl<<endl;
	}
}
void LojaElectronica::saveLojas(string filename) {
	vector<Vertex<Zona*> *> vs = myGraph.getVertexSet();
	vector<Vertex<Zona*> *>::iterator it = vs.begin();

	ofstream myfile(filename.c_str());
	if(myfile.is_open())
	{
		myfile << Loja::getCount() << endl;

		for(; it!=vs.end(); it++)
			myfile << "|" << (*it)->getInfo()->getCodZona()<< (*it)->getInfo()->getLoja()->toString() << endl;

		cout<<endl<<"Lojas exportadas com sucesso!"<<endl;
		myfile.close();
	}
	else
	{
		cout<<"Nao foi possivel abrir o ficheiro!"<<endl<<endl;
		system("pause");
	}
}
/*
void LojaElectronica::loadEncomendas(string filename)
{
	ifstream file;
	string line;

	string data, clnome;
	unsigned int idenc, idloja, idprod;

	file.open(filename.c_str());

	if (file.is_open()) {

		getline(file, line);
		Cliente::setCount(atoi(line.c_str()));
		while(!file.eof() ){

			getline(file, line);
			if(line == "") break;
			idenc = atoi(line.c_str());

			getline(file, data);
			getline(file, clnome);
			getline(file, line);
			idloja = atoi(line.c_str());
			getline(file, line);
			idprod = atoi(line.c_str());

			Produto *p = NULL;
			Cliente *c = ProcuraCliente_nome(clnome);
			Loja *l = procuraLoja(idloja);
			for(unsigned int i=0;i<l->getProdutos().size();i++){
				if(l->getProdutos()[i]->getCodProduto()==idprod) {
					p = l->getProdutos()[i];
					break;
				}
			}
			Encomenda *e = new Encomenda(data,l,c,p,idenc);
			encomendas.push_back(e);
		}
		cout<<endl<<"Encomendas importadas com sucesso!"<<endl<<endl;
		file.close();
	}else
	{
		cout<<"Nao foi possivel abrir o ficheiro "<<filename<<"!"<<endl<<endl;
	}
}
*/
void LojaElectronica::loadEncomendas(string filename)
{
	ifstream file;
	string line;
	vector<string> v;
	string data, clnome;
	unsigned int idenc, idloja, idprod;

	file.open(filename.c_str());

	if (file.is_open()) {

		getline(file, line);
		Cliente::setCount(atoi(line.c_str()));
		while(!file.eof() ){

			getline(file, line);
			if(line == "") break;
			v=split('|', line);
			idenc = atoi(v[0].c_str());
			data = v[1].c_str();
			clnome = v[2].c_str();
			idloja = atoi(v[3].c_str());
			idprod = atoi(v[4].c_str());

			Produto *p = NULL;
			Cliente *c = ProcuraCliente_nome(clnome);
			Loja *l = procuraLoja(idloja);
			for(unsigned int i=0;i<l->getProdutos().size();i++){
				if(l->getProdutos()[i]->getCodProduto()==idprod) {
					p = l->getProdutos()[i];
					break;
				}
			}
			Encomenda *e = new Encomenda(data,l,c,p,idenc);
			encomendas.push_back(e);
		}
		cout<<endl<<"Encomendas importadas com sucesso!"<<endl<<endl;
		file.close();
	}else
	{
		cout<<"Nao foi possivel abrir o ficheiro "<<filename<<"!"<<endl<<endl;
	}
}
/*
void LojaElectronica::saveEncomendas(string filename)
{
	int i = 0;
	int tam = encomendas.size();
	ofstream myfile(filename.c_str());
	if (myfile.is_open()) {
		myfile << Encomenda::getCount() << endl;
		while (i < tam) {
			if(encomendas[i] != NULL){
				myfile << encomendas[i]->getcodEncomenda() << endl;
				myfile << encomendas[i]->getData();
				myfile << encomendas[i]->getCliente()->getNome() << endl;
				myfile << encomendas[i]->getLoja()->getCodLoja() << endl;
				myfile << encomendas[i]->getProduto()->getCodProduto() << endl;
			}
			i++;
		}
		cout<<endl<<"Encomendas exportadas com sucesso!"<<endl;
		myfile.close();
	}
	else
	{
		cout<<"Nao foi possivel abrir o ficheiro!"<<endl<<endl;
		system("pause");
	}
}

*/
void LojaElectronica::saveEncomendas(string filename)
{
	int i = 0;
	int tam = encomendas.size();
	ofstream myfile(filename.c_str());
	if (myfile.is_open()) {
		myfile << Encomenda::getCount() << endl;
		for(unsigned int i=0; i<encomendas.size(); i++)
		{
			if(encomendas[i] != NULL){
				string data = encomendas[i]->getData();
				data[data.size()-1]='\0';
				myfile<<"|"<<encomendas[i]->getcodEncomenda()<<"|"<<data<<"|"<<encomendas[i]->getCliente()->getNome()<<"|"<<encomendas[i]->getLoja()->getCodLoja()<<"|"<<encomendas[i]->getProduto()->getCodProduto()<<"|"<<endl;
			}
		}
		cout<<endl<<"Encomendas exportadas com sucesso!"<<endl;
		myfile.close();
	}
	else
	{
		cout<<"Nao foi possivel abrir o ficheiro!"<<endl<<endl;
		system("pause");
	}
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
		cout<<endl<<"Vertices importadas com sucesso!"<<endl<<endl;
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
		myfile << Zona::getCount()<<endl;

		for(it=vs.begin(); it!=vs.end(); it++)
			myfile<<(*it)->getInfo()->toString()<<endl;

		myfile.close();
		cout<<endl<<"Vertices exportadas com sucesso!"<<endl;
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
			if(z1==NULL) cout << "Z1 NULL!" << endl;
			Zona *z2 = procuraZona(atoi(v[1].c_str()));
			if(z1==NULL) cout << "Z2 NULL!" << endl;
			double peso = atof(v[2].c_str());

			myGraph.addEdge(z1, z2, peso, 0);
		}
		myfile.close();
		cout<<endl<<"Edges importadas com sucesso!"<<endl<<endl;
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
				myfile<<"|"<<(*it)->getInfo()->getCodZona()<<"|"<<ited->getDest()->getInfo()->getCodZona()<<"|"<<ited->getWeight()<<"|"<<endl;
		}
		myfile.close();
		cout<<endl<<"Edges exportadas com sucesso!"<<endl;
	}
	else
	{
		cout<<"Nao foi possivel abrir o ficheiro!"<<endl<<endl;
		system("pause");
	}
}


bool LojaElectronica::exists(vector<int>arestas, int a, int b){

	bool ok=false;

	for(unsigned int i=0; i<arestas.size()-1; i=i+2)
		if(arestas[i]==b && arestas[i+1]==a){
			ok=true;
		}
	return ok;
}

int LojaElectronica::SearchIdAresta(vector<int> v, int a, int b) {
	for(unsigned int i=0; i<v.size()-2; i=i+3) {
		if( (v[i]==a && v[i+1]==b) || (v[i]==b && v[i+1]==a) ){
			return v[i+2];
		}
	}
	return -1;
}


void LojaElectronica::Mapa(){

	GraphViewer *gv = new GraphViewer(1200, 700, true);
	//gv->setBackground("");
	gv->createWindow(1200, 700);

	//configurar a cor dos nos e arestas
	gv->defineVertexColor("black");
	gv->defineEdgeColor("black");

	//criar os nos partir do vector vertexSet
	for(unsigned int i=0;i<myGraph.getVertexSet().size();i++) {
		gv->addNode(myGraph.getVertexSet()[i]->getInfo()->getCodZona());
		gv->setVertexLabel(myGraph.getVertexSet()[i]->getInfo()->getCodZona(), myGraph.getVertexSet()[i]->getInfo()->getDesignacao()+"--Loja: "+myGraph.getVertexSet()[i]->getInfo()->getLoja()->getNome());
		gv->rearrange();
	}

	int idEdge=0;
	vector<int> arestas;
	vector<int> vIdsArestas;

	vector<Vertex<Zona*> *> vs = myGraph.getVertexSet();
	vector<Vertex<Zona*> *>::iterator it;


	for(it=vs.begin(); it!=vs.end(); it++)
	{
		vector<Edge<Zona*> > vedges = (*it)->getAdj();  //Arestas de cada no
		vector<Edge<Zona*> >::iterator ited;

		for(ited=vedges.begin(); ited!=vedges.end(); ited++) {

			int a=(*it)->getInfo()->getCodZona();
			int b=ited->getDest()->getInfo()->getCodZona();

			arestas.push_back(a);
			arestas.push_back(b);

			if(exists(arestas,a,b)==false){
				gv->addEdge(idEdge, (*it)->getInfo()->getCodZona(), ited->getDest()->getInfo()->getCodZona(), EdgeType::UNDIRECTED);
				string s = doubleToString((*ited).getWeight());
				gv->setEdgeLabel(idEdge,s);

				//push codZona1.CodZona2,IdEdge
				vIdsArestas.push_back((*it)->getInfo()->getCodZona());
				vIdsArestas.push_back(ited->getDest()->getInfo()->getCodZona());
				vIdsArestas.push_back(idEdge);

				idEdge++;
			}
		}
	}
	gv->rearrange();
	gv->closeWindow();
}


void LojaElectronica::Caminho(vector<Zona*> vPath, vector<int> vZonasComProduto) {

	//disable stdout
	streambuf* cout_sbuf = std::cout.rdbuf(); // save original sbuf
	ofstream   fout("/dev/null");
	cout.rdbuf(fout.rdbuf()); // redirect 'cout' to a 'fout'

	GraphViewer *gv = new GraphViewer(1200, 700, true);
	//gv->setBackground("");
	gv->createWindow(1200, 700);

	//configurar a cor dos nos
	gv->defineVertexColor("black");

	//configurar a cor das arestas
	gv->defineEdgeColor("black");

	//criar os nos partir do vector vertexSet
	for(unsigned int i=0;i<myGraph.getVertexSet().size();i++) {

		gv->addNode(myGraph.getVertexSet()[i]->getInfo()->getCodZona());
		gv->setVertexLabel(myGraph.getVertexSet()[i]->getInfo()->getCodZona(), myGraph.getVertexSet()[i]->getInfo()->getDesignacao()+"--Loja: "+myGraph.getVertexSet()[i]->getInfo()->getLoja()->getNome());
		gv->rearrange();
	}

	int idEdge=0;

	vector<Vertex<Zona*> *> vs = myGraph.getVertexSet();
	vector<Vertex<Zona*> *>::iterator it;

	vector<int> arestas;
	vector<int> vIdsArestas;

	for(it=vs.begin(); it!=vs.end(); it++)
	{
		vector<Edge<Zona*> > vedges = (*it)->getAdj();  //Arestas de cada no
		vector<Edge<Zona*> >::iterator ited;

		for(ited=vedges.begin(); ited!=vedges.end(); ited++) {

			int a=(*it)->getInfo()->getCodZona();
			int b=ited->getDest()->getInfo()->getCodZona();

			arestas.push_back(a);
			arestas.push_back(b);

			if(exists(arestas,a,b)==false){
				gv->addEdge(idEdge, (*it)->getInfo()->getCodZona(), ited->getDest()->getInfo()->getCodZona(), EdgeType::UNDIRECTED);
				string s = doubleToString((*ited).getWeight());
				gv->setEdgeLabel(idEdge,s);

				//push codZona1.CodZona2,IdEdge
				vIdsArestas.push_back((*it)->getInfo()->getCodZona());
				vIdsArestas.push_back(ited->getDest()->getInfo()->getCodZona());
				vIdsArestas.push_back(idEdge);

				idEdge++;
			}
		}
	}
	gv->rearrange();
	Sleep(2000);
	gv->setVertexColor(vPath[0]->getCodZona(),"blue");
	gv->rearrange();
	Sleep(2000);

	for(it=vs.begin(); it!=vs.end(); it++)
		gv->setVertexColor((*it)->getInfo()->getCodZona(),"red");

	for(unsigned int i=0; i<vZonasComProduto.size(); i++) {
		gv->setVertexColor(vZonasComProduto[i],"green");
	}

	gv->rearrange();

	Sleep(2000);
	unsigned int j=0;
	for(;j<vPath.size();j++) {
		gv->setVertexColor(vPath[j]->getCodZona(),"yellow");
		gv->rearrange();
		Sleep(2000);
		if(j+1!=vPath.size()) {
			int idAresta = SearchIdAresta(vIdsArestas, vPath[j]->getCodZona(), vPath[j+1]->getCodZona());
			gv->setEdgeThickness(idAresta,3);
			gv->setEdgeColor(idAresta,"yellow");
			gv->rearrange();
			Sleep(2000);
		}
	}
	gv->setVertexColor(vPath[j-1]->getCodZona(),"orange");
	gv->rearrange();

	cout.rdbuf(cout_sbuf); // restore the original stream buffer

	system("PAUSE");
	gv->closeWindow();
}


void LojaElectronica::startLojaElectronica()
{
	loadVertices("nos.txt");
	loadEdges("arestas.txt");
	loadClientes("clientes.txt");
	loadLojas("lojas.txt");
	loadProdutos("produtos.txt");
	loadEncomendas("encomendas.txt");
	welcome();
	menuPrincipal();

	system("PAUSE");
}
