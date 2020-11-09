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
		string tarja;
		string medida;
		string info_adicional;
    // especificador de acesso public
    public:
    	// construtor da classe 
    	Remedio(float = 0.0, float = 0.0, string = " ", string = " ", 
				string = " ", int = 0, long int = 0, int = 0, int = 0,
				int = 0, int = 0, int = 0, int = 0, string = " ", string = " ",
				string = " ");
        // membros de funções da classe
    	void set_tarja(string);
    	void set_medida(string);
    	void set_info_adicional(string);
    	string get_tarja(void) const;
    	string get_medida(void) const;
    	string get_info_adicional(void) const;
};

#endif