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
    	//unsigned int pesquisar_produto(long int) const;
    	//unsigned int pesquisar_produto_perecivel(long int) const;
    	//unsigned int pesquisar_remedio(long int) const;
    	//void checar_vencimento_produto_perecivel(int);
    	//void checar_vencimento_remedio(int);
    	//Produto get_produto(unsigned int) const;
    	//ProdutoPerecivel get_produto_perecivel(unsigned int) const;
    	//Remedio get_remedio(unsigned int) const;
    	//vector <Produto> lista_produtos(void) const;
    	//vector <ProdutoPerecivel> lista_pereciveis(void) const;
    	//vector <Remedio> lista_remedios(void) const;
};

#endif