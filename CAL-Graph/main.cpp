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
			cout << "0-Sair" << endl << endl;
			
			cout << "Insira o numero da sua escolha :";

			int choice;
			cin >> choice;

			while ((choice < 0 || choice > 4) && (isdigit(choice)!=true))
			{
				cout << "Opcao invalida!! Introduza um numero entre 0 e 4." << endl;
				cin >> choice;
			}

			if (choice == 1) {
			
				int choice;
				bool exit_menu1 = false;

				while (exit_menu1 == false) {

					cout << "-------GESTÃO DE CANDIDATOS------" << endl;
					cout << "1-Adicionar Candidato" << endl;
					cout << "2-Eliminar Candidato" << endl;
					cout << "3-Editar Candidato" << endl;
					cout << "4-Procurar Candidato :"<< endl;
					cout << "5-Listar Candidatos :"<< endl;
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
							cout <<" Qual é o candidato que quer remover?";
							cin>>nome;
							try {
								lj.removeCliente(nome);
							} catch (Excepcao &ex) {
								cout << ex.getMessage();
							}


					}/*else if(choice==3){
							string nome;
							cout<<" Qual é o candidato que quer alterar? ";
							cin>> nome;
							//agencia.ProcuraCandidato_nome1(nome)->setPessoa();
							try {
								agencia.ProcuraCandidato_nome1(nome)->setPessoa();
							} catch (Excepccao &ex)
							{
								cout << ex.getMessage();
							}

					}*/
					else if(choice==4){
							string nome;
							cout<<" Qual é o candidato que quer Procurar? ";
							cin>> nome;
							try {
								lj.ProcuraCandidato_nome(nome)->imprimeCliente();
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
			}

	}




return 0;
}
