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

#include <stdlib.h>
#include <vector>
#include <sstream>
#include <fstream>

class LojaElectronica
{
	vector <Cliente *> clientes;
	vector <Loja *> lojas;
	vector <Encomenda *> encomendas;
	vector <Produto *> produtos;

public:
	LojaElectronica();
	~LojaElectronica();

	void welcome();
	void showMenu(string titulo, vector <string> opcoes);
	void menuPrincipal();
	void menuEncomenda();
	void menuCliente();
	void menuProduto();

	void addCliente();
	void removeCliente(unsigned int codCliente);
	void addProduto();
	void removeProduto(unsigned int codProduto);
	void addZona();
	void removeZona();
	void addLoja();
	void removeLoja();
	void addEncomenda();
	void removeEncomenda();

	void listaClientes();
	void listaProdutos();
	void listaLojas();
	void listaEncomendas();

	void loadClientes(string filename);
	void saveClientes(string filename);
	void loadProdutos(string filename);
	void saveProdutos(string filename);
	void loadZonas(string filename);
	void saveZonas(string filename);
	void loadEncomendas(string filename);
	void saveEncomendas(string filename);

	void startLojaElectronica();

};


#endif /* LOJAELECTRONICA_H_ */
