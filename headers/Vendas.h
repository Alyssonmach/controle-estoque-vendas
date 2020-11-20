#ifndef VENDAS_H
#define VENDAS_H

#include "Estoque.h"

// definindo a classe Vendas que herda de Estoque
class Vendas : public Estoque
{
	// Especificado de acesso private
	private:
		// membros de dados da classe
		float apurado;
		float saldo;
		void calcula_apurado(float);
    	void calcula_saldo(float);
    	int conta_notas(void);
    	string diretorio_nota(void);
    	vector <Produto> produto_nota;
    	vector <ProdutoPerecivel> perecivel_nota;
    	vector <Remedio> remedio_nota;
    // especificador de acesso public
    public:
    	// construtor da classe
    	Vendas();
    	// membros de funções da classe
    	
    	void monta_nota_fiscal(void);
    	float get_apurado(void) const;
    	float get_saldo(void) const;
    	float get_despezas(void) const;
    	void apaga_da_nota_produto(long int);
    	void apaga_da_nota_perecivel(long int);
    	void apaga_da_nota_remedio(long int);
    	void limpa_historico_notas(void);
    	void restaura_historico_notas(void);
    	void imprime_nota_fiscal(void);
};

#endif