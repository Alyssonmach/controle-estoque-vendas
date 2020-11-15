#ifndef ESTOQUE_H
#define ESTOQUE_H

#include <vector>
#include "Produto.h"
#include "ProdutoPerecivel.h"
#include "Remedio.h"

// definindo a classe estoque
class Estoque 
{
	// especificador de acesso private
	private:
		// membros de dados da classe
		vector <Produto> produtos;
		vector <ProdutoPerecivel> pereciveis;
		vector <Remedio> remedios;
		bool checaVencimentoPerecivel(int, int);
    	bool checaVencimentoRemedio(int, int);
    // especificador de acesso public
    public:
    	// construtor e destrutor da classe (trabalhar manipulação de arquivo)
    	Estoque();
    	~Estoque();
    	// membros de funções da classe
    	void lerProduto(void);
    	void lerProdutoPerecivel(void);
    	void lerRemedio(void);
    	void salvarProduto(void);
    	void salvarProdutoPerecivel(void);
    	void salvarRemedio(void);
    	bool inserirProduto(Produto);
    	bool inserirRemedio(Remedio);
    	bool inserirProdutoPerecivel(ProdutoPerecivel);
    	void imprimirProduto(void) const;
    	void imprimirProdutoPerecivel(void) const;
    	void imprimirRemedio(void) const;
    	bool removerProduto(long int);
    	bool removerProdutoPerecivel(long int);
    	bool removerRemedio(long int);
    	bool pesquisarProduto(string) const;
    	bool pesquisarProdutoPerecivel(string) const;
    	bool pesquisarRemedio(string) const;
    	bool pesquisaPerecivelVencido(int);
    	bool pesquisaRemedioVencido(int);
    	//Produto getProduto(int) const;
    	//ProdutoPerecivel getProdutoPerecivel(int) const;
    	//Remedio getRemedio(int) const;
    	//vector <Produto> lista_produtos(void) const;
    	//vector <ProdutoPerecivel> lista_pereciveis(void) const;
    	//vector <Remedio> lista_remedios(void) const;
};

#endif