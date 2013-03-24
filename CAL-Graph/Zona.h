/*
 * 	FICHEIRO: Zona.h
 *	PROJECTO: Projecto CAL - Loja de Comercio Electronico (T3)
 *	DESCRICAO: Definicao da classe Zona
 *  TURMA / GRUPO: Turma 2MIEIC2 / Grupo D
 *  AUTORES:
 *  - Jorge Miguel Reis
 *  - Miao Sun
 *  - Vitor Castro
 */

#ifndef ZONA_H_
#define ZONA_H_

#include "Loja.h"

#include <string>
using namespace std;

class Zona
{
	unsigned int codZona;
	string localizacao;
	Loja *loja;

public:
	//! Construtor que inicializa membros-dado
	/**
	 * \param codZona um inteiro que vai atribuir valor ao membro-dado codZona.
	 * \param licalizacao uma string que vai atribuir valor ao membro-dado localizacao.
	*/
	Zona(unsigned int codZona, string localizacao);

	//! Destrutor que liberta o recurso de memoria foi alocado
	~Zona();
	//! Membro-fucao para retornar o valor do membro-dado localizacao
	/** um membro-funcao const para garantir a nao modificacao de nenhum membro-dado.
	 * \return uma string com conteudo do membro-dado localizacao. */
	string getLocalizacao() const;

	//! Membro-funcao para setar o membro-dado localizacao de um objeto tipo Zona ja instanciado
	/** \param localizacao o conteudo da string a ser atribuida ao membro-dado localizacao. */
	void setLocalizacao(string localizacao);
	//! Membro-fucao para retornar o valor do membro-dado codZona
	/** um membro-funcao const para garantir a nao modificacao de nenhum membro-dado.
	 * \return uma inteiro com conteudo do membro-dado codZona. */
	unsigned int getCodZona() const;
	//! Membro-funcao para setar o membro-dado codZona de um objeto tipo Zona ja instanciado
	/** \param id o conteudo da inteiro a ser atribuida ao membro-dado codZona. */
	void setCodZona(unsigned int codZona);

};

#endif /* ZONA_H_ */
