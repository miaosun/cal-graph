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

int algoritmoPesado=1;


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
	//opcoes.push_back("5 - Importar Ficheiro");
	opcoes.push_back("5 - GraphViewer");
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
		//case 5:
		//importar ficheiro  TODO
	case 5:
		windows();
		menuPrincipal();
		break;
	case 0:
		//sair e gravar nos ficheiros; TODO
		break;
	default:
		cout<<"Opcao invalida! Insira uma das opcoes disponiveis"<<endl;
		//menuPrincipal();
	}
}

void LojaElectronica::menuEncomenda()
{
	int op, cod;
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
		opcoes.push_back("4 - Importar Encomendas dum ficheiro");//opcao 5
		opcoes.push_back("5 - Exportar Encomendas para ficheiro");//opcao 6
	}
	else
		opcoes.push_back("2 - Importar Encomendas dum ficheiro");
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
			addEncomenda();
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
				for(unsigned int i=0; i<encomendas.size(); i++)
				{
					if(cod == encomendas[i]->getcodEncomenda())
					{
						e = encomendas[i];
						break;
					}
				}
				//showMenu("Detalhes da Encomenda", e->resumo());
				removeEncomenda(e->getcodEncomenda());
			}
			catch (NotFound)
			{
				cout<<endl<<"Encomenda nao encontrado!"<<endl;
				system("pause");
			}
			menuEncomenda();
			break;
		case 5://importar Encomenda
			system("cls");
			cout<<"   --Importar Encomenda--"<<endl<<endl;
			cout<<"Nome do ficheiro: ";
			getline(cin, filename);
			loadEncomendas(filename);
			system("pause");
			menuEncomenda();
			break;
		case 6://exportar Cliente
			system("cls");
			cout<<"   --Exportar Encomenda--"<<endl<<endl;
			cout<<"Nome do ficheiro para onde vai exportar: ";
			getline(cin, filename);
			saveEncomendas(filename);
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
		case 1://criar Encomenda
			addEncomenda();
			menuEncomenda();
			break;
		case 2://importar Encomenda
			system("cls");
			cout<<"   --Importar Pessoas--"<<endl<<endl;
			cout<<"Nome do ficheiro: ";
			getline(cin, filename);
			loadEncomendas(filename);
			system("pause");
			menuEncomenda();
			break;
		case 0://voltar ao menu anterior
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
	int op, cod;
	Cliente *c;
	vector<string> opcoes;
	string filename;
	opcoes.push_back("Escolha uma das seguintes opcoes:");
	opcoes.push_back("");
	opcoes.push_back("1 - Adicionar Cliente");//opcao 1
	if(clientes.size()>0)
	{
		opcoes.push_back("2 - Ver detalho dum Cliente");//opcao 2
		opcoes.push_back("3 - Editar um Cliente");//opcao 3
		opcoes.push_back("4 - Remover um Cliente");//opcao 4
		opcoes.push_back("5 - Importar Clientes dum ficheiro");//opcao 5
		opcoes.push_back("6 - Exportar Clientes para ficheiro");//opcao 6
	}
	else
		opcoes.push_back("2 - Importar Clientes dum ficheiro");
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
			addCliente();
			menuCliente();
			break;
		case 2:
			listaClientes();
			cout<<endl<<"Introduza o Codigo do Cliente que pretende ver os detalhes: ";
			cod=intinput();
			try
			{
				for(unsigned int i=0; i<clientes.size(); i++)
				{
					if(cod == clientes[i]->getCodCliente())
					{
						c = clientes[i];
						break;
					}
				}
				showMenu("Detalhes do Cliente", c->imprimeCliente());
			}
			catch (NotFound)
			{
				cout<<endl<<"Cliente nao encontrado!"<<endl;
			}
			system("pause");
			menuCliente();//volta ao menu Cliente
			break;
		case 3://editar Cliente
			listaClientes();
			cout<<endl<<"Introduza o Codigo do Cliente que pretende editar: ";
			cod=intinput();
			try
			{
				for(unsigned int i=0; i<clientes.size(); i++)
				{
					if(cod == clientes[i]->getCodCliente())
					{
						c = clientes[i];
						break;
					}
				}
				editCliente(c);
			}
			catch (NotFound)
			{
				cout<<endl<<"Cliente nao encontrado!"<<endl;
			}
			cout<<"\nAlteracao com sucesso!\n";
			system("pause");
			menuCliente();
			break;
		case 4://apagar Cliente
			listaClientes();
			cout<<endl<<"Introduza o Codigo do Cliente que pretende apagar: ";
			cod=intinput();

			try
			{
				for(unsigned int i=0; i<clientes.size(); i++)
				{
					if(cod == clientes[i]->getCodCliente())
					{
						c = clientes[i];
						break;
					}
				}
				showMenu("Detalhes do Cliente", c->imprimeCliente());
				removeCliente(c->getNome());
			}
			catch (NotFound)
			{
				cout<<endl<<"Cliente nao encontrado!"<<endl;
				system("pause");
			}
			menuCliente();
			break;
		case 5://importar Cliente
			system("cls");
			cout<<"   --Importar Cliente--"<<endl<<endl;
			cout<<"Nome do ficheiro: ";
			getline(cin, filename);
			loadClientes(filename);
			system("pause");
			menuCliente();
			break;
		case 6://exportar Cliente
			system("cls");
			cout<<"   --Exportar Pessoas--"<<endl<<endl;
			cout<<"Nome do ficheiro para onde vai exportar: ";
			getline(cin, filename);
			saveClientes(filename);
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
		case 1://criar Cliente
			addCliente();
			menuCliente();
			break;
		case 2://importar Cliente
			system("cls");
			cout<<"   --Importar Pessoas--"<<endl<<endl;
			cout<<"Nome do ficheiro: ";
			getline(cin, filename);
			loadClientes(filename);
			system("pause");
			menuCliente();
			break;
		case 0://voltar ao menu anterior
			break;
		default:
			cout<<"Opcao invalida! Insira uma das opcoes disponiveis"<<endl;
			system("pause");
			menuCliente();
		}
	}
}

void LojaElectronica::menuProduto()
{

}

void LojaElectronica::menuZona()
{
	int op, cod;
	Zona *z;
	vector<string> opcoes;
	opcoes.push_back("Escolha uma das seguintes opcoes:");
	opcoes.push_back("");

	opcoes.push_back("1 - Adicionar uma Zona");
	opcoes.push_back("2 - Editar uma Zona");
	opcoes.push_back("3 - Remover uma Zona");
	opcoes.push_back("4 - Addicionar Ligacao entre Zonas");
	opcoes.push_back("5 - Remover Ligacao entre Zonas");
	opcoes.push_back("");
	opcoes.push_back("0 - Voltar atras");

	showMenu("Menu Zona", opcoes);
	cout<<"    Opcao: ";
	op=intinput();

	switch(op)
	{
	case 1:
		addZona();
		menuZona();
		break;
	case 2:
		//editZona(); //TODO
		menuZona();
		break;
	case 3:
		listaZonas();
		cout<<endl<<"Introduza o Codigo da Zona que pretende apagar: ";
		cod=intinput();
		try
		{
			for(unsigned int i=0; i<myGraph.getVertexSet().size(); i++)
			{
				if(cod == myGraph.getVertexSet()[i]->getInfo()->getCodZona())
				{
					z = myGraph.getVertexSet()[i]->getInfo();
					break;
				}
			}
			//showMenu("Detalhes do Cliente", z->imprimeZona());
			removeZona(z->getDesignacao());
		}
		catch (NotFound)
		{
			cout<<endl<<"Zona nao encontrada!"<<endl;
		}
		system("pause");
		menuZona();
		break;
	case 4:
		//addLigacao(); TODO
		menuZona();
		break;
	case 5:
		//removeLigacao(); TODO
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
		getline(cin, morada);
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
	int op, cod;
	Loja *l;
	vector<string> opcoes;
	opcoes.push_back("Escolha uma das seguintes opcoes:");
	opcoes.push_back("");

	opcoes.push_back("1 - Adicionar uma Loja");
	opcoes.push_back("2 - Editar uma Loja");
	opcoes.push_back("3 - Remover uma Loja");
	opcoes.push_back("4 - Gerir Produtos duma Loja");
	opcoes.push_back("");
	opcoes.push_back("0 - Voltar atras");

	showMenu("Menu Loja", opcoes);
	cout<<"    Opcao: ";
	op=intinput();

	switch(op)
	{
	case 1:
		addLoja();
		menuLoja();
		break;
	case 2:
		listaLojas();
		cout<<endl<<"Introduza o Codigo da Loja que pretende editar: ";
		cod=intinput();
		try
		{
			for(unsigned int i=0; i<myGraph.getVertexSet().size(); i++)
			{
				if(cod == myGraph.getVertexSet()[i]->getInfo()->getLoja()->getCodLoja())
				{
					l = myGraph.getVertexSet()[i]->getInfo()->getLoja();
					editLoja(l);
					break;
				}
			}
		}
		catch (NotFound)
		{
			cout<<endl<<"Loja nao encontrada!"<<endl;
		}
		system("pause");
		menuLoja();
		break;
	case 3:
		listaLojas();
		cout<<endl<<"Introduza o Codigo da Loja que pretende apagar: ";
		cod=intinput();
		try
		{
			for(unsigned int i=0; i<myGraph.getVertexSet().size(); i++)
			{
				if(cod == myGraph.getVertexSet()[i]->getInfo()->getLoja()->getCodLoja())
				{
					l = myGraph.getVertexSet()[i]->getInfo()->getLoja();
					break;
				}
			}
			//showMenu("Detalhes do Lojas", l->imprimeLoja());
			removeLoja(l->getCodLoja());
		}
		catch (NotFound)
		{
			cout<<endl<<"Loja nao encontrada!"<<endl;
		}
		system("pause");
		menuLoja();
		break;
	case 4:
		listaLojas();
		cout<<endl<<"Introduza o Codigo da Loja que pretende gerir os Produtos: ";
		cod=intinput();
		try
		{
			for(unsigned int i=0; i<myGraph.getVertexSet().size(); i++)
			{
				if(cod == myGraph.getVertexSet()[i]->getInfo()->getLoja()->getCodLoja())
				{
					l = myGraph.getVertexSet()[i]->getInfo()->getLoja();
					break;
				}
			}
			//showMenu("Detalhes do Lojas", l->imprimeLoja());
		}
		catch (NotFound)
		{
			cout<<endl<<"Loja nao encontrada!"<<endl;
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

void LojaElectronica::menuProduto(Loja *l)
{
	int op, cod;
	string filename;
	vector<string> opcoes;
	opcoes.push_back("Escolha uma das seguintes opcoes:");
	opcoes.push_back("");
	opcoes.push_back("1 - Adicionar um Produto");
	if(l->getProdutos().size()>0)
	{
		opcoes.push_back("2 - Editar um Protudo");
		opcoes.push_back("3 - Remover um Produto");
		opcoes.push_back("4 - Importar Produtos dum ficheiro");
		opcoes.push_back("5 - Exportar Produtos para um ficheiro");
	}
	else
		opcoes.push_back("2 - Importar Produtos dum ficheiro");
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
				for(unsigned int i=0; i<l->getProdutos().size(); i++)
				{
					if(cod == l->getProdutos()[i]->getCodProduto())
					{
						l->removeProduto(cod);
						break;
					}
				}
			}
			catch (NotFound)
			{
				cout<<endl<<"Produto nao encontrada!"<<endl;
			}
			system("pause");
			menuProduto(l);
			break;
		case 4://importar Produto
			system("cls");
			cout<<"   --Importar Cliente--"<<endl<<endl;
			cout<<"Nome do ficheiro: ";
			getline(cin, filename);
			loadProdutos(filename);
			system("pause");
			menuProduto(l);
			break;
		case 5://exportar Produto
			system("cls");
			cout<<"   --Exportar Pessoas--"<<endl<<endl;
			cout<<"Nome do ficheiro para onde vai exportar: ";
			getline(cin, filename);
			saveProdutos(filename);
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
		case 2://importar Produto
			system("cls");
			cout<<"   --Importar Cliente--"<<endl<<endl;
			cout<<"Nome do ficheiro: ";
			getline(cin, filename);
			loadProdutos(filename);
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
	//TODO excepcao

	Cliente *c=new Cliente(nome,morada,contacto,email,nif,zonaCliente);

	clientes.push_back(c);
}

void LojaElectronica::editCliente(Cliente *c)
{
	//nao e permetido de alterar nome e NIF
	string morada, contacto, email;
	//Zona *zona;   editar zona do cliente
	// TODO
	int op;

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
	case 0: //voltar atras
		return;
		break;
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
			cout << "Zona nao existente!" << endl;
		}
		else
		{
			cout << "Distancia: ";
			fflush(stdin);
			cin >> dist;

			addArestaBidireccional(z1,z2,dist);

			cout << "Deseja inserir mais alguma distancia a outra zona? (S/N): ";
			fflush(stdin);
			cin >> resp;
		}
	} while(resp!='n' || resp != 'N');
}

void LojaElectronica::addAresta(Zona *z) {
	cout << "Adicionar Ligacao" << endl << endl;
	listaZonas();
	string desig;
	int dist;
	cout << "Insira a designacao de uma Zona a qual ligar: ";
	fflush(stdin);
	getline(cin,desig);

	Zona *z2 = procuraZona(desig);
	if(z2==NULL) {
		cout << "Zona nao existente!" << endl;
		//TODO excepcao! tratar (voltar a pedir)
	}
	else
	{
		cout << "Distancia: ";
		fflush(stdin);
		cin >> dist;
		addArestaBidireccional(z,z2,dist);
	}
}

void LojaElectronica::listaArestasDesde(Zona *z) {
	Vertex<Zona*>* v = devolveVertex(z);
	if(v->getAdj().size()==0)
		cout << "Nao existem ligacoes a partir desta Zona!" << endl;
	for(unsigned int i=0; i<v->getAdj().size();i++) {
		cout << v->getAdj()[i].getDest()->getInfo()->getDesignacao() << " | Distância: " << v->getAdj()[i].getWeight()<<endl;
	}
}

void LojaElectronica::removeAresta(Zona *z) {
	cout << "Remover Ligacao" << endl << endl;
	listaArestasDesde(z);
	string desig;
	int dist;
	cout << "Insira a designacao da Zona destino da ligacao a remover: ";
	fflush(stdin);
	getline(cin,desig);

	Zona *z2 = procuraZona(desig);
	if(z2==NULL) {
		cout << "Zona nao existente!" << endl;
		//TODO excepcao! tratar (voltar a pedir)
	}
	else
	{
		removeArestaBidireccional(z,z2);
		cout << "Ligacao Eliminada!"<< endl;
	}
}

void LojaElectronica::editPesoAresta(Zona *z) {
	cout << "Editar Distancia de Ligacao entre Zonas" << endl << endl;
	listaArestasDesde(z);
	string desig;
	int dist;
	cout << "Insira a designacao da Zona destino da ligacao a editar: ";
	fflush(stdin);
	getline(cin,desig);

	Zona *z2 = procuraZona(desig);
	if(z2==NULL) {
		cout << "Zona nao existente!" << endl;
		//TODO excepcao! tratar (voltar a pedir)
	}
	else
	{
		cout << "Insira o nova distancia: ";
		fflush(stdin);
		cin >> dist;
		removeArestaBidireccional(z,z2);
		addArestaBidireccional(z,z2,dist);
		cout << "Aresta Editada!"<< endl;
	}
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
		cout << myGraph.getVertexSet()[i]->getInfo()->toString() << endl << endl;
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
	if(zonaLoja==NULL) {
		cout << "Loja inserida nao existe!" << endl;
	}
	else {
		cout << "Loja adicionada com sucesso!" << endl;
		zonaLoja->setLoja(l1);
	}
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
		cout<<"Loja Eliminada com sucesso";
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

	cout << "	ENCOMENDA" << endl << endl;

	listaClientes();
	cout << "Insira o nome do cliente: ";
	fflush(stdin);
	getline(cin,nome);
	Cliente *c = ProcuraCliente_nome(nome); //TODO excepcao
	Zona *noOrigem = c->getZona();

	cout << "	Seleccionar Produto" << endl;
	listaProdutos();

	cout << "Nome do produto desejado: ";
	fflush(stdin);
	getline(cin,produto);

	if(algoritmoPesado==1) {
		//Caminhos mais curtos a partir de noOrigem --> Grafos Pesados - Djikstra
		myGraph.dijkstraShortestPath(noOrigem);
	}
	else {
		//Caminhos mais curtos a partir de noOrigem --> Grafos Nao Pesados
		myGraph.unweightedShortestPath(noOrigem);
	}

	vector<Vertex<Zona*>* > vDist = myGraph.getVertexSet();
	insertionSort(vDist);

	vector<Vertex<Zona*>* >::iterator it = vDist.begin();
	vector<Produto*>::iterator it2;
	for(;it!=vDist.end();it++) {
		for(it2==(*it)->getInfo()->getLoja()->getProdutos().begin();it2!=(*it)->getInfo()->getLoja()->getProdutos().end();it2++) {
			if(((*it2)->getDesignacao() == produto) && ((*it2)->getStock()>0)) {
				p=(*it2);
				l=(*it)->getInfo()->getLoja();
				(*it2)->decStock();
				enc=true;
				break;
			}
		}
	}
	if(enc==true) {
		Encomenda *e = new Encomenda(data,l,c,p);
		encomendas.push_back(e);
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
	cout << "Encomenda nï¿½o encontrada!"<< endl;
}

Encomenda * LojaElectronica::procuraEncomenda(unsigned int id) {
	for(unsigned int i=0; i<encomendas.size();i++) {
		if(encomendas[i]->getcodEncomenda()==id) {
			return encomendas[i];
		}
	}
	return NULL;
}

void LojaElectronica::listaClientes()
{
	if(clientes.size()==0 ) throw Excepcao("\n Nao existem clientes no sistema \n");

	for (unsigned int i=0; i < clientes.size(); i++)
	{
		clientes[i]->resumo();
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

void LojaElectronica::listaLojas()
{
	if(myGraph.getVertexSet().size()==0 ) throw Excepcao("\n Nao existem lojas no sistema \n");

	for (unsigned int i=0; i < myGraph.getVertexSet().size(); i++)
		if(myGraph.getVertexSet()[i]->getInfo()->getLoja() != NULL)
		{
			cout<<"listaLojas test : "<<endl;     //TODO    continua sem funcionar!!
			//cout << myGraph.getVertexSet()[i]->getInfo()->getLoja()->toString() << endl;
		}
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
		cout<<endl<<endl<<"Edges importadas com sucesso!"<<endl<<endl;
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
		cout<<endl<<endl<<"Clientes exportadas com sucesso!"<<endl;
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
		cout<<endl<<endl<<"Produtos importadas com sucesso!"<<endl<<endl;
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
				myfile << "|" << (*it)->getInfo()->getLoja()->getCodLoja()<<"|";
				myfile << (*it)->getInfo()->getLoja()->getProdutos()[i]->toString() << endl;
			}
		}
		cout<<endl<<endl<<"Produtos exportadas com sucesso!"<<endl;
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
		cout<<endl<<endl<<"Lojas importadas com sucesso!"<<endl<<endl;
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
		myfile << Loja::getCount();

		for(; it!=vs.end(); it++)
			myfile << "|" << (*it)->getInfo()->getCodZona()<<"|"<< (*it)->getInfo()->getLoja()->toString() << endl;

		cout<<endl<<endl<<"Lojas exportadas com sucesso!"<<endl;
		myfile.close();
	}
	else
	{
		cout<<"Nao foi possivel abrir o ficheiro!"<<endl<<endl;
		system("pause");
	}
}

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
		cout<<endl<<endl<<"Encomendas importadas com sucesso!"<<endl<<endl;
		file.close();
	}else
	{
		cout<<"Nao foi possivel abrir o ficheiro "<<filename<<"!"<<endl<<endl;
	}
}

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
				myfile << encomendas[i]->getData() << endl;
				myfile << encomendas[i]->getCliente()->getNome() << endl;
				myfile << encomendas[i]->getLoja()->getCodLoja() << endl;
				myfile << encomendas[i]->getProduto()->getCodProduto() << endl;
			}
			i++;
		}
		cout<<endl<<endl<<"Encomendas exportadas com sucesso!"<<endl;
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
		myfile << Zona::getCount()<<endl;

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
			if(z1==NULL) cout << "Z1 NULL!" << endl;
			Zona *z2 = procuraZona(atoi(v[1].c_str()));
			if(z1==NULL) cout << "Z2 NULL!" << endl;
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
				myfile<<"|"<<(*it)->getInfo()->getCodZona()<<"|"<<ited->getDest()->getInfo()->getCodZona()<<"|"<<ited->getWeight()<<"|"<<endl;
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


bool LojaElectronica::exists(vector<int>arestas, int a, int b){

	//cout<<"Aresta"<<a<<"-"<<b<<endl;

	bool ok=false;

	for(unsigned int i=0; i<arestas.size()-1; i=i+2)
		if(arestas[i]==b && arestas[i+1]==a){
			//	cout<<"Entrou no if"<<endl;
			ok=true;
		}


	//cout<<"ok"<<ok<<endl;
	return ok;
}





void LojaElectronica::windows(){
	//	vector<Vertex<Zona*> *> vs = myGraph.getVertexSet();
	//	vector<Vertex<Zona*> *>::iterator it=vs.begin();
	//	for(;it!=vs.end();it++) {
	//		cout << (*it)->getInfo()->getCodZona()<< endl;
	//	}
	//
	//	cout << myGraph.getVertexSet()[0]->getInfo()->getCodZona()<< endl;
	//	cout << myGraph.getVertexSet()[1]->getInfo()->getCodZona()<< endl;
	//	cout << myGraph.getVertexSet()[2]->getInfo()->getCodZona()<< endl;
	//	cout << myGraph.getVertexSet()[3]->getInfo()->getCodZona()<< endl;
	//	cout << myGraph.getVertexSet()[4]->getInfo()->getCodZona()<< endl;


	//configurar uma janela
	GraphViewer *gv = new GraphViewer(600, 600, true);
	//gv->setBackground("abc.jpg");
	gv->createWindow(600, 600);

	//configurar a cor dos nos
	gv->defineVertexColor("blue");

	//configurar a cor das arestas
	gv->defineEdgeColor("black");

	//criar os nos partir do vector vertexSet
	for(unsigned int i=0;i<myGraph.getVertexSet().size();i++){

		gv->addNode(myGraph.getVertexSet()[i]->getInfo()->getCodZona());
		gv->setVertexLabel(myGraph.getVertexSet()[i]->getInfo()->getCodZona(), myGraph.getVertexSet()[i]->getInfo()->getDesignacao());
		gv->rearrange();
	}


	int idEdge=0;

	vector<Vertex<Zona*> *> vs = myGraph.getVertexSet();
	vector<Vertex<Zona*> *>::iterator it;
	//cout<<"hello: "<<vs.size()<<endl; //Numero de Vertices

	vector<int> arestas;


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

				//cout<<"aaa"<<(*it)->getInfo()->getDesignacao()<<endl;
				//cout<<"bbb"<<(*it)->getInfo()->getCodZona()<<"-"<<ited->getDest()->getInfo()->getCodZona()<<endl;
				gv->addEdge(idEdge, (*it)->getInfo()->getCodZona(), ited->getDest()->getInfo()->getCodZona(), EdgeType::UNDIRECTED);
				idEdge++;

			}//else cout<<"Aresta Repetida"<<endl;

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
 *    fica para depois
 *
 */
void LojaElectronica::startLojaElectronica()
{
	loadVertices("nos.txt");
	loadEdges("arestas.txt");
	loadClientes("clientes.txt");
	welcome();
	menuPrincipal();
	saveEncomendas("encomendas.txt");
}
