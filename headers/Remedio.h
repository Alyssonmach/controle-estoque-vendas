#ifndef REMEDIO_H
#define REMEDIO_H

#include "ProdutoPerecivel.h"

struct Drogaria
{
	string medida;
	string info_adicional;
};

// definindo a classe Remedio (configura e retorna os atributos do remedio)
// classe deriva de Produto
class Remedio : public ProdutoPerecivel
{
	// especificador de acesso private
	private:
		// membros de dados da classe
		Drogaria objeto_remedio;
    // especificador de acesso public
    public:
    	// construtor da classe 
    	Remedio(float = 0.0, float = 0.0, string = " ", string = " ", 
				string = " ", int = 0, long int = 0, int = 0, int = 0,
				int = 0, string = " ", string = " ");
        // membros de funções da classe
        void set_objeto_remedio(Produto_prototipo, Data, Drogaria);
    	void set_medida(string);
    	void set_info_adicional(string);
    	Drogaria get_objeto_remedio(void) const;
};

#endif