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

#include "Cliente.h"
#include "Loja.h"
#include "Produto.h"
#include "Encomenda.h"
#include "Zona.h"
#include "Graph.h"

#include <stdlib.h>
#include <vector>
#include <sstream>
#include <fstream>

class LojaElectronica
{
	vector <Cliente *> clientes;
	vector <Loja *> lojas;
	vector <Zona *> zonas;
	vector <Encomenda *> encomendas;

	//vector <Produto *> produtos;  passa para classe Loja

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
	//! Membro-funcao que mostra o menu encomenda ao utilizador
	void menuEncomenda();
	//! Membro-funcao que mostra o menu cliente ao utilizador
	void menuCliente();
	//! Membro-funcao que mostra o menu produto ao utilizador
	void menuProduto();
	//! Membro-funcao que com base na morada do utilizador determina a sua zona
	Zona * determinaZona(string morada);
	//! Membro-funcao que permite a adicao de clientes novos
	void addCliente();
	//! Membro-funcao que permite a remocao de clientes existentes
	/** dado o nome do cliente que pretende remover */
	void removeCliente(string nome);
	//! Membro-funcao que permite a remocao de clientes existentes
	/** dado o nome do cliente que pretende remover */
	Cliente *ProcuraCliente_nome(string nome);
	//! Membro-funcao que permite a remocao de clientes existentes
	/** dado o codigo do cliente que pretende remover */
	void removeCliente(unsigned int codCliente);
	//! Membro-funcao que permite a adicao de produtos novos
	void addProduto();
	//! Membro-funcao que permite a remocao de produtos novos
	/** dado o codigo do produto que pretende remover */
	void removeProduto(unsigned int codProduto);
	//! Membro-funcao que permite a adicao de zonas novas
	void addZona();
	//! Membro-funcao que permite a adicao de zonas novas ao grafo
	void addZonaGrafo();
	//! Membro-funcao que permite a remocao de zonas novos
	/** dado o codigo da zona que pretende remover */
	void removeZona(unsigned int codZona);
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
	//! Membro-funcao que lista os clientes existentes no base de dados
	void listaClientes();
	//! Membro-funcao que lista os produtos existentes na determinada loja no base de dados
	void listaProdutos();
	//! Membro-funcao que lista as lojas existentes no base de dados
	void listaLojas();
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
	//! Membro-funcao que le as zonas a partir dum ficheiro
	void loadZonas(string filename);
	//! Membro-funcao que grava os zonas num ficheiro
	void saveZonas(string filename);
	//! Membro-funcao que le as encomendas a partir dum ficheiro
	void loadEncomendas(string filename);
	//! Membro-funcao que grava as encomendas num ficheiro
	void saveEncomendas(string filename);

	void startLojaElectronica();

};

//Classe Excepcao utilizada para excep��es. Retorna uma mensagem para o utilizador com a excep��o
class Excepcao{
private:
	string message;
public:
	Excepcao( string mens ){message=mens;};
	string getMessage() { return message; };



};

#endif /* LOJAELECTRONICA_H_ */
