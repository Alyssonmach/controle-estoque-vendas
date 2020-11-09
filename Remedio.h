#ifndef REMEDIO_H
#define REMEDIO_H

#include "ProdutoPerecivel.h"

// definindo a classe Remedio (configura e retorna os atributos do remedio)
// classe deriva de Produto
class Remedio : public ProdutoPerecivel
{
	// especificador de acesso private
	private:
		// membros de dados da classe
		string medida;
		string info_adicional;
		string contraindicacao;
    // especificador de acesso public
    public:
    	// construtor da classe 
    	Remedio(float = 0.0, float = 0.0, string = " ", string = " ", 
				string = " ", int = 0, long int = 0, int = 0, int = 0,
				int = 0, int = 0, int = 0, int = 0, string = " ", string = " ",
				string = " ", string = " ");
        // membros de funções da classe
    	void set_medida(string);
    	void set_info_adicional(string);
    	void set_contraindicacao(string);
    	string get_medida(void) const;
    	string get_info_adicional(void) const;
    	string get_contraindicacao(void) const;
};

#endif