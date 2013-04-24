/**
 * \mainpage LOJA DE COMERCIO ELECTRONICO (T3)
 * \section Informações
 * Turma: 2MIEIC2\n
 * Tema: 3\n
 * \authors
 * - Jorge Miguel Marques dos Reis - ei08053@fe.up.pt\n
 *  - Miao Sun - ei08162@fe.up.pt\n
 *  - Vitor Castro - ei09131@fe.up.pt\n
 *
 * \date 24/03/2013
 * \section Funcionalidade
 *      Este sistema reliza a gestão de uma Loja Electrónica de Electrodomesticos, com base no uso
 *      de grafos.
 */

#include "LojaElectronica.h"

#include <iostream>

int main()
{
	LojaElectronica lj;
	//lj.startLojaElectronica();

	using namespace std;

	cout	<< "-------------------------GESTAO DE UMA LOJA DE COMERCIO ELETRONICO-- ------------------------"
			<< endl << endl;

	bool exit_console = false;

	while (exit_console == false) {

		cout << "-----------MENU INICIAL-----------" << endl;
		cout << "1-Gestão de Clientes" << endl;
		cout << "2-Gestão de Encomendas" << endl;
		cout << "3-Gestão de Zonas" << endl;
		cout << "4-Gestão de Grafo" << endl;
		cout << "5-Importar Ficheiro" << endl;
		cout << "0-Sair" << endl << endl;

		cout << "Insira o numero da sua escolha :";

		int choice;
		cin >> choice;

		while ((choice < 0 || choice > 6) && (isdigit(choice)!=true))
		{
			cout << "Opcao invalida!! Introduza um numero entre 0 e 4." << endl;
			cin >> choice;
		}

		if (choice == 1) {

			int choice;
			bool exit_menu1 = false;

			while (exit_menu1 == false) {

				cout << "-------GESTÃO DE CLIENTES------" << endl;
				cout << "1-Adicionar Cliente" << endl;
				cout << "2-Eliminar Cliente" << endl;
				cout << "3-Editar Cliente" << endl;
				cout << "4-Procurar Cliente :"<< endl;
				cout << "5-Listar Cliente :"<< endl;
				cout <<" 6- MENU INICIAL"<< endl;
				cout << "Insira o numero da sua escolha :";
				cin >> choice;

				while ((choice < 1 || choice > 6) && (isdigit(choice) != true)) {
					cout << "Opcao invalida!! Introduza um numero entre 1 e 5."
							<< endl;
					cin >> choice;
				}

				if(choice==1){
					lj.addCliente();
				}

				else if(choice==2){
					//NAO ESTA A ATUALIZAR O NUMERO DE CLIENTES DEPOIS DE ELIMINACAO
					string nome;
					cout <<" Qual é o cliente que quer remover?";
					cin>>nome;
					try {
						lj.removeCliente(nome);
					} catch (Excepcao &ex) {
						cout << ex.getMessage();
					}


				}/*else if(choice==3){
							string nome;
							cout<<" Qual é o cliente que quer alterar? ";
							cin>> nome;
							//agencia.ProcuraCliente_nome(nome)->setPessoa();
							try {
								agencia.ProcuraCliente_nome(nome)->setPessoa();
							} catch (Excepccao &ex)
							{
								cout << ex.getMessage();
							}

					}*/
				else if(choice==4){
					string nome;
					cout<<" Qual é o cliente que quer Procurar? ";
					cin>> nome;
					try {
						lj.ProcuraCliente_nome(nome)->imprimeCliente();
					} catch (Excepcao &ex) {
						cout << ex.getMessage();
					}

				}else if(choice==5){
					try {
						lj.listaClientes();
					} catch (Excepcao &ex) {
						cout << ex.getMessage();
					}


				}
				else if (choice == 6) {
					exit_menu1=true;
				}
			}

		}else if(choice==2){

			int choice;
			bool exit_menu1 = false;

			while (exit_menu1 == false) {

				cout << "\n-------GESTÃO DE ENCOMENDAS------\n" << endl;
				cout << "1-Criar Encomenda" << endl;
				cout <<" 6- MENU INICIAL"<< endl;
				cout << "Insira o numero da sua escolha :";
				cin >> choice;

				while ((choice < 1 || choice > 6) && (isdigit(choice) != true)) {
					cout << "Opcao invalida!! Introduza um numero entre 1 e 5."
							<< endl;
					cin >> choice;
				}

				if(choice==1){

					lj.addEncomenda();
				}

				else if (choice == 6) {
					exit_menu1=true;
				}
			}
		}else if(choice==3){

			int choice;
			bool exit_menu1 = false;

			while (exit_menu1 == false) {

				cout << "\n-------GESTÃO DE ZONAS------\n" << endl;
				cout << "1-Criar Zona" << endl;
				cout << "2-Eliminar Zona" << endl;
				cout << "3-Listar Zonas" << endl;
				cout <<" 0- MENU INICIAL"<< endl;
				cout << "Insira o numero da sua escolha :";
				cin >> choice;

				while ((choice < 0 || choice > 3) && (isdigit(choice) != true)) {
					cout << "Opcao invalida!! Introduza um numero entre 1 e 5."
							<< endl;
					cin >> choice;
				}

				if(choice==1){

					lj.addZona();

				}else if(choice==2){
					//NAO ESTA A ATUALIZAR O NUMERO DE ZONAS DEPOIS DE ELIMINACAO
					string desig;
					cout <<" Qual é a zona que quer remover?";
					getline(cin,desig);
					try {
						//TODO lj.removeZona(desig);
					} catch (Excepcao &ex) {
						cout << ex.getMessage();
					}

				}else if(choice==3){
					try {
						lj.listaZonas();
					} catch (Excepcao &ex) {
						cout << ex.getMessage();
					}
				}

				else if (choice == 0) {
					exit_menu1=true;
				}
			}
		}else if(choice==4){
			int choice;
			bool exit_menu1 = false;

			while (exit_menu1 == false) {

				cout << "\n-------GESTÃO DE GRAFOS------\n" << endl;
				cout << "1-Acrescentar Zona" << endl;
				cout << "2-Eliminar Zona" << endl;
				cout << "3-Acrescentar Aresta" << endl;
				cout << "3-Eliminar Aresta" << endl;
				cout <<" 0- MENU INICIAL"<< endl;
				cout << "Insira o numero da sua escolha :";
				cin >> choice;

				while ((choice < 0 || choice > 3) && (isdigit(choice) != true)) {
					cout << "Opcao invalida!! Introduza um numero entre 1 e 5."
							<< endl;
					cin >> choice;
				}

				if(choice==1){

					//lj.addZonaGrafo();

				}
			}


		}else if(choice==5){

			lj.loadVertices("nos.txt");


		}

	}




	return 0;
}
