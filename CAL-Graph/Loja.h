/*
 *     FICHEIRO: Loja.h
 *    PROJECTO: Projecto CAL - Loja de Comercio Electronico (T3)
 *    DESCRICAO: Definicao da classe Loja
 *  TURMA / GRUPO: Turma 2MIEIC2 / Grupo D
 *  AUTORES:
 *  - Jorge Miguel Reis
 *  - Miao Sun
 *  - Vitor Castro
 */

#ifndef LOJA_H_
#define LOJA_H_

#include <iostream>
#include <string>

class Zona;

using namespace std;
class Loja
{
    const unsigned int codLoja;
    static unsigned int countLojas;
    string designacao;
    string morada;
    Zona * zona;
	//FAZER VECTOR PRODUTOS

public:
    //! Construtor que inicializa todos os membros-dado
    /**
     * \param designacao  uma string que vai atribuir valor ao membro-dado designacao.
     * \param morada  uma string que vai atribuir valor ao membro-dado morada.
     * \param zona  um apontador para a zona da loja
     */
    Loja(string desig, string mor, Zona *zon);

    //! Membro-funo para retornar o valor do membro-dado codLoja
    /**  um membro-funo const para garantir a no modificao de nenhum membro-dado.
     * \return um unsgined int com valor do membro-dado codLoja. */
    unsigned int getCodLoja() const;

    //! Membro-funo para retornar o valor do membro-dado designacao
    /**  um membro-funo const para garantir a no modificao de nenhum membro-dado.
     * \return uma string com valor do membro-dado designacao. */
    string getDesignacao() const;

    //! Membro-funo para retornar o valor do membro-dado morada
    /**  um membro-funo const para garantir a no modificao de nenhum membro-dado.
     * \return uma string com valor do membro-dado morada. */
    string getMorada() const;

    //! Membro-funo para retornar o valor do membro-dado zona
    /**  um membro-funo const para garantir a no modificao de nenhum membro-dado.
     * \return um apontador para a zona */
    Zona* getZona() const;

    //! Membro-funo para setar o membro-dado nome de um objeto tipo Loja j instanciado
    /** \param designacao  o contedo da string a ser atribuida ao membro-dado designacao. */
    void setDesignacao(string desig);

    //! Membro-funo para setar o membro-dado morada de um objeto tipo Loja j instanciado
    /** \param morada  o contedo da string a ser atribuida ao membro-dado morada. */
    void setMorada(string morada);

    //! Membro-funo para setar o membro-dado zona de um objeto tipo Loja j instanciado
    /** \param zona  um apontador para a zona da loja */
    void setZona(Zona* zon);

    //! Overloading do operador de comparao == para objetos do tipo Loja
    /**
     * Uma loja  igual a outra se seus codLojas forem iguais
     * \return um booleano que  true se uma loja for igual a outra e false caso contrrio.
     */
    bool operator==(const Loja & x) const;

    //! Membro-funo estatico para setar o membro-dado estatico countLojas
    /** \param n e um inteiro com contedo a ser atribuido ao membro-dado estatico countLojas. */
    static void setCount(unsigned int n) {countLojas = n;}
    //! Membro-funo estatico para retornar o valor do membro-dado estatico countClientes
    /**
     * \return um inteiro com contedo do membro-dado estatico countLojas. */
    static unsigned int getCount() {return countLojas;}

    //! Membro-funo que imprime no ecr os membros-dado de um objeto tipo Loja
    /**
     * Membro-funo para imprimir no ecr o contedo dos membros-dado de um objeto tipo Loja no formato,
     * \n Loja nmero: \n Designacao: \n Morada: \n Zona: \n
     */
    void imprimeLoja() const;

};


#endif /* LOJA_H_ */
