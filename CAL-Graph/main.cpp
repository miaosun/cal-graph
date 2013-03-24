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
			
				cout<<"Menu De Gestão de CLiente";
			}
			
			else if (choice == 0) {
				exit_console=true;
		 }
	 }

return 0;
}
