#ifndef VENDAS_H
#define VENDAS_H

#include "Estoque.h"

// definindo a classe Vendas que herda de Estoque
class Vendas : public Estoque
{
	// Especificado de acesso private
	private:
		// membros de dados da classe
		int entrada_estoque;
		int saida_estoque;
		float apurado;
		float saldo;
    // especificador de acesso public
    public:
    	// construtor da classe
    	Vendas();
    	// membros de funções da classe
    	void monta_nota_fiscal();
    	void set_entrada_estoque(int);
    	void set_saida_estoque(int);
    	void calcula_apurado(float);
    	void calcula_saldo(float);
    	int get_estoque_atual(void) const;
    	int get_saida_de_estoque(void) const;
    	float get_apurado(void) const;
    	float get_saldo(void) const;
    	float get_despezas(void) const;
    	float get_lucro(void) const;
    	void imprime_nota_fiscal(void);
};

#endif