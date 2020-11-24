#ifndef PRODUTOPERECIVEL_H
#define PRODUTOPERECIVEL_H

#include "Produto.h"

// estrutura com os atrbutos da data de vencimento de um produto ou a data atual
struct Data
{
	int dia;
	int mes;
	int ano;
};

class ProdutoPerecivel : public Produto 
{
	private:
		// definindo um atributo para fazer a coleta de data de vencimento do produto e data atual
		Data data_validade;
    public:
    	ProdutoPerecivel(float = 0.0, float = 0.0, string = " ", string = " ", string = " ", int = 0, long int = 0, int = 0, int = 0, int = 0);
    	// metodo que configura um objeto do tipo produto nao perecivel (tem data de validade associada)
		void set_objeto_perecivel(Produto_prototipo, Data);
		// metodo que configura a data de validade do produto nao perecivel
    	void set_data_validade(Data);
    	// metodo que retorna a data de validade do produto nao perecivel
    	Data get_data_validade(void) const;
    	// metodo que retorna a data atual 
    	Data get_data_atual(void) const;
    	// metodo que imprime a data atual formatada
    	void imprimeDataAtual(void) const;
    	// metodo que imprime a data de vencimento do produto formatada
    	void imprimeDataVencimento(void) const;
    	// metodo que imprime o objeto do tipo produto perecivel 
    	void imprimeProdutoPerecivel(void) const;
};

#endif