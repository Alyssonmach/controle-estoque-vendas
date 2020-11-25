#ifndef REMEDIO_H
#define REMEDIO_H

#include "ProdutoPerecivel.h"

// estrutura que armazena informacoes adicionais associadas a um remedio
struct Drogaria
{
	string medida;
	string info_adicional;
};

class Remedio : public ProdutoPerecivel
{
	private:
		// atributo que contem uma estrutura com informacoes adicionais do remedio
		Drogaria objeto_remedio;
    public:
    	Remedio(float = 0.0, float = 0.0, string = " ", string = " ", string = " ", int = 0, long int = 0, int = 0, int = 0, int = 0, string = " ", string = " ");
        // metodo que verifica a configuracao de um remedio
		bool valida_objeto_remedio(Produto_prototipo, Data);
		// metodo que configura um objeto do tipo remedio
        void set_objeto_remedio(Produto_prototipo, Data, Drogaria);
        // metodo que configura a medida do remedio
    	void set_medida(string);
    	// metodo que configura informacoes adicionais do remedio
    	void set_info_adicional(string);
    	// metodo que retorna o objeto do tipo remedio
    	Drogaria get_objeto_remedio(void) const;
    	// metodo que imprime o objeto remedio
    	void imprimeRemedio(void) const;
};

#endif