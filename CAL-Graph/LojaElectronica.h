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
#include "Graph.h"

#include <stdlib.h>
#include <vector>
#include <sstream>
#include <fstream>

class LojaElectronica
{
	vector <Cliente *> clientes;
	vector <Loja *> lojas;
	vector <Encomenda *> encomendas;
	//vector <Produto *> produtos;  passa para classe Loja

public:
	//! Construtor que inicializa membros-dado
	LojaElectronica();

	//! Destrutor que liberta o recurso de memoria foi alocado
	~LojaElectronica();

	//! Membro-fucao que mostra a mensagem inicial do programa ao utilizador
	void welcome();
	//! Membro-fucao que auxilia a mostracao dos menu
	/** recebe um string como um atribuito, titulo dum menu
	 *  um vector de string, as opcoes disponiveis dum menu */
	void showMenu(string titulo, vector <string> opcoes);
	//! Membro-fucao que mostra o menu principal ao utilizador
	void menuPrincipal();
	//! Membro-fucao que mostra o menu encomenda ao utilizador
	void menuEncomenda();
	//! Membro-fucao que mostra o menu cliente ao utilizador
	void menuCliente();
	//! Membro-fucao que mostra o menu produto ao utilizador
	void menuProduto();

	//! Membro-fucao que permite a adicao de clientes novos
	void addCliente();
	//! Membro-fucao que permite a remocao de clientes existentes
	/** dado o nome do cliente que pretende remover */
	void removeCliente(string nome);
	//! Membro-fucao que permite a remocao de clientes existentes
		/** dado o nome do cliente que pretende remover */
	Cliente *ProcuraCandidato_nome(string nome);
	//! Membro-fucao que permite a remocao de clientes existentes
		/** dado o codigo do cliente que pretende remover */
	void removeCliente(unsigned int codCliente);
	//! Membro-fucao que permite a adicao de produtos novos
	void addProduto();
	//! Membro-fucao que permite a remocao de produtos novos
	/** dado o codigo do produto que pretende remover */
	void removeProduto(unsigned int codProduto);
	//! Membro-fucao que permite a adicao de zonas novas
	void addZona();
	//! Membro-fucao que permite a remocao de zonas novos
	/** dado o codigo da zona que pretende remover */
	void removeZona(unsigned int codZona);
	//! Membro-fucao que permite a adicao de lojas novas
	void addLoja();
	//! Membro-fucao que permite a remocao de lojas novos
	/** dado o codigo da loja que pretende remover */
	void removeLoja(unsigned int codLoja);
	//! Membro-fucao que permite a adicao de encomendas novas
	void addEncomenda();
	//! Membro-fucao que permite a remocao de encomendas novos
	/** dado o codigo da encomenda que pretende remover */
	void removeEncomenda(unsigned int codEncomenda);
	//! Membro-fucao que lista os clientes existentes no base de dados
	void listaClientes();
	//! Membro-fucao que lista os produtos existentes na determinada loja no base de dados
	void listaProdutos();
	//! Membro-fucao que lista as lojas existentes no base de dados
	void listaLojas();
	//! Membro-fucao que lista as encomendas existentes no base de dados
	void listaEncomendas();
	//! Membro-fucao que le os clientes partir dum ficheiro
	void loadClientes(string filename);
	//! Membro-fucao que grava os clientes a um ficheiro
	void saveClientes(string filename);
	//! Membro-fucao que le os produtos partir dum ficheiro
	void loadProdutos(string filename);
	//! Membro-fucao que grava os produtos a um ficheiro
	void saveProdutos(string filename);
	//! Membro-fucao que le as zonas partir dum ficheiro
	void loadZonas(string filename);
	//! Membro-fucao que grava os zonas a um ficheiro
	void saveZonas(string filename);
	//! Membro-fucao que le as encomendas partir dum ficheiro
	void loadEncomendas(string filename);
	//! Membro-fucao que grava as encomendas a um ficheiro
	void saveEncomendas(string filename);

	void startLojaElectronica();

};

//Classe Excepcao utilizada para excepções. Retorna uma mensagem para o utilizador com a excepção
class Excepcao{
private:
	string message;
public:
Excepcao( string mens ){message=mens;};
 string getMessage() { return message; };



};

#endif /* LOJAELECTRONICA_H_ */
