#ifndef PRODUTOPERECIVEL_H
#define PRODUTOPERECIVEL_H

#include "Produto.h"

// definindo uma struct com os atributos de data
struct Data
{
	int dia;
	int mes;
	int ano;
};

// definindo a classe ProdutoPerecivel (configura e retorna os atributos do produto perec�vel)
// classe herdade de Produto
class ProdutoPerecivel : public Produto 
{
	// especificador de acesso private
	private:
	// membros de dados da classe
		Data data_atual;
		Data data_validade;
    public:
    	// construtor da clase
    	ProdutoPerecivel(float = 0.0, float = 0.0, string = " ", string = " ", 
				string = " ", int = 0, long int = 0, int = 0, int = 0,
				int = 0, int = 0, int = 0, int = 0)
    	// membros de fun��es da classe
    	void set_data_validade(Data);
    	void set_data_atual(Data);
    	Data get_data_validade(void) const;
    	Data get_data_atual(void) const;
};

#endif