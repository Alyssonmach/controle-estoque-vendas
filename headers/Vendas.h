#ifndef VENDAS_H
#define VENDAS_H

#include "Estoque.h"
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <dirent.h>
#include <string>

using namespace std;

// definindo a classe Vendas que herda de Estoque
class Vendas : public Estoque
{
	// Especificado de acesso private
	private:
		// membros de dados da classe
		float apurado;
		float saldo;
		void adiciona_apurado(float);
    	void adiciona_saldo(float);
    	int quantidade_notas_fiscais(void);
    	string diretorio_nota(int);
    	vector <Produto> produto_nota;
    	vector <ProdutoPerecivel> perecivel_nota;
    	vector <Remedio> remedio_nota;
    // especificador de acesso public
    public:
    	// construtor da classe
    	Vendas(void);
    	// membros de funções da classe
    	bool inserir_nota_produto(Produto);
    	bool inserir_nota_perecivel(ProdutoPerecivel);
    	bool inserir_nota_remedio(Remedio);
    	bool pesquisar_nota_produto(long int);
    	bool pesquisar_nota_perecivel(long int);
    	bool pesquisar_nota_remedio(long int);
    	bool apaga_da_nota_produto(long int);
    	bool apaga_da_nota_perecivel(long int);
    	bool apaga_da_nota_remedio(long int);
 		void imprime_historico_fiscal(void) const;
    	void limpa_historico_notas(void);
    	void restaura_historico_notas(void);
    	void imprime_ultimas_notas(int);
    	Data retornaDataAtual(void) const;
    	void monta_nota_fiscal(void);
    	float get_apurado(void) const;
    	float get_saldo(void) const;
    	float get_despezas(void) const;
};

#endif