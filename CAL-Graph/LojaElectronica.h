/*
 * 	FICHEIRO: LojaElectronica.h
 *	PROJECTO: Projecto CAL - Loja de Comercio Electronico (T3)
 *	DESCRICAO: Definicao da classe LojaElectronica
 *  TURMA / GRUPO: Turma 2MIEIC2 / Grupo D
 *  AUTORES:
 *  - Jorge Miguel Reis
 *  - Miao Sun
 *  - Vitor Castro
 */

#ifndef LOJAELECTRONICA_H_
#define LOJAELECTRONICA_H_

#include "Encomenda.h"
#include "Excepcao.h"
#include "Graph.h"
#include "graphviewer.h"


class LojaElectronica
{
	vector <Cliente *> clientes;
	vector <Encomenda *> encomendas;
	Graph<Zona*> myGraph;

public:
	//! Construtor que inicializa membros-dado
	LojaElectronica();

	//! Destrutor que liberta o recurso de memoria foi alocado
	~LojaElectronica();

	//! Membro-funcao que mostra a mensagem inicial do programa ao utilizador
	void welcome();
	//! Membro-funcao que auxilia a mostracao dos menu
	/** recebe um string como um atribuito, titulo dum menu
	 *  um vector de string, as opcoes disponiveis dum menu */
	void showMenu(string titulo, vector <string> opcoes);

	//! Membro-funcao que mostra o menu principal ao utilizador
	void menuPrincipal();
	//! Membro-funcao que mostra o menu cliente ao utilizador
	void menuCliente();
	//! Membro-funcao que mostra o menu encomenda ao utilizador
	void menuEncomenda();
	//! Membro-funcao que mostra o menu zona ao utilizador
	void menuZona();
	//! Membro-funcao que mostra o menu loja ao utilizador
	void menuLoja();
	//! Membro-funcao que mostra o menu produto ao utilizador
	void menuProduto(Loja *l);

	//! Membro-funcao que permite a adicao de clientes novos
	void addCliente();
	//! Membro-funcao que permite a remocao de clientes existentes
	/** dado o nome do cliente que pretende remover */
	void removeCliente(string nome);
	//! Membro-funcao que procura clientes existentes
	/** dado o nome do cliente que pretende procurar */
	Cliente *ProcuraCliente_nome(string nome);

	vector<string> nomesProdutos();

	//! Membro-funcao que permite a adicao de zonas novas
	void addZona();
	//! Membro-funcao que permite a adicao de zonas novas ao grafo
	void addZonaGrafo(Zona* z);
	//! Membro-funcao que permite a adicao de arestas novas a zona
	void addAresta(Zona *z);
	//! Membro-funcao que permite a remocao de arestas duma zona
	void removeAresta(Zona *z);
	//! Membro-funcao que permite a edicao do peso das arestas duma zona
	void editPesoAresta(Zona *z);
	//! Membro-funcao que devolve o vertex duma zona
	Vertex<Zona*> * devolveVertex(Zona *z);
	//! Membro-funcao que lista todas as arestas existentes duma zona origin
	void listaArestasDesde(Zona *z);
	//! Membro-funcao que adiciona uma aresta bidirecional a 2 zonas com distancia
	void addArestaBidireccional(Zona* z1, Zona* z2, int dist);
	//! Membro-funcao que remove uma aresta bidirecional de 2 zonas
	void removeArestaBidireccional(Zona* z1, Zona *z2);
	//! Membro-funcao que edita uma aresta bidirecional de 2 zonas
	void editArestaBidireccional(Zona* z1, Zona *z2);

	//! Membro-funcao que procura zonas existentes
	/** dado a designacao da zona que pretende procurar */
	Zona* procuraZona(string designacao);
	//! Membro-funcao que procura zonas existentes
	/** dado o id da zona que pretende procurar */
	Zona* procuraZona(unsigned int id);
	//! Membro-funcao que procura lojas existentes
	/** dado o id da loja que pretende procurar */
	Loja* procuraLoja(unsigned int id);
	//! Membro-funcao que permite a remocao de zonas novos
	/** dado a designacao da zona que pretende remover */
	void removeZona(string designacao);
	//! Membro-funcao que lista as zonas existentes no base de dados
	void listaZonas();

	//! Membro-funcao que permite a adicao de lojas novas
	void addLoja();
	//! Membro-funcao que permite a remocao de lojas novos
	/** dado o codigo da loja que pretende remover */
	void removeLoja(unsigned int codLoja);
	//! Membro-funcao que permite a adicao de encomendas novas
	void addEncomenda();
	//! Membro-funcao que permite a remocao de encomendas novos
	/** dado o codigo da encomenda que pretende remover */
	void removeEncomenda(unsigned int codEncomenda);
	//! Membro-funcao que permite a procura de encomendas existentes
	/** dado o codigo da encomenda que pretende procurar */
	Encomenda * procuraEncomenda(unsigned int id);
	//! Membro-funcao que faz edicao dum dado cliente
	void editCliente(Cliente *c);
	//! Membro-funcao que faz edicao duma dada loja
	void editLoja(Loja *l);

	//! Membro-funcao que lista os clientes existentes no base de dados
	void listaClientes();
	//! Membro-funcao que lista os produtos existentes na determinada loja no base de dados
	void listaProdutos();
	//! Membro-funcao que lista as lojas existentes no base de dados
	int listaLojas();
	//! Membro-funcao que lista as encomendas existentes no base de dados
	void listaEncomendas();

	//! Membro-funcao que le os clientes a partir dum ficheiro
	void loadClientes(string filename);
	//! Membro-funcao que grava os clientes num ficheiro
	void saveClientes(string filename);
	//! Membro-funcao que le os produtos a partir dum ficheiro
	void loadProdutos(string filename);
	//! Membro-funcao que grava os produtos num ficheiro
	void saveProdutos(string filename);
	//! Membro-funcao que le as lojas a partir dum ficheiro
	void loadLojas(string filename);
	//! Membro-funcao que grava as lojas num ficheiro
	void saveLojas(string filename);
	//! Membro-funcao que le os zonas (vertices) a partir dum ficheiro
	void loadVertices(string filename);
	//! Membro-funcao que grava as zonas (vertices) num ficheiro
	void saveVertices(string filename);
	//! Membro-funcao que le as arestas entre zonas a partir dum ficheiro
	void loadEdges(string filename);
	//! Membro-funcao que grava as arestas entre zonas num ficheiro
	void saveEdges(string filename);
	//! Membro-funcao que le as encomendas a partir dum ficheiro
	void loadEncomendas(string filename);
	//! Membro-funcao que grava as encomendas num ficheiro
	void saveEncomendas(string filename);

	//! Membro-funcao que verifica se ja existe aresta entre 2 vertices
	bool exists(vector<int>arestas, int a, int b);
	//! Membro-funcao que devolve o id da aresta que existe entre 2 vertices
	int SearchIdAresta(vector<int> v, int a, int b);

	void escolhaAlgoritmo();
	void Mapa();
	void Caminho(vector<Zona*> vPath, vector<int> vZonasComProduto);

	//! Membro-funcao onde comeca o lanco do programa
	void startLojaElectronica();

};

#endif /* LOJAELECTRONICA_H_ */
