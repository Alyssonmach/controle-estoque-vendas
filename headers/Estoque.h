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
    	void lerProduto(void);
    	void lerProdutoPerecivel(void);
    	void lerRemedio(void);
    	void salvarProduto(void);
    	void salvarProdutoPerecivel(void);
    	void salvarRemedio(void);
    // especificador de acesso public
    public:
    	// construtor e destrutor da classe (trabalhar manipulação de arquivo)
    	Estoque();
    	~Estoque();
    	// membros de funções da classe
    	bool inserirProduto(Produto);
    	bool inserirRemedio(Remedio);
    	bool inserirProdutoPerecivel(ProdutoPerecivel);
    	void imprimirProduto(void) const;
    	void imprimirProdutoPerecivel(void) const;
    	void imprimirRemedio(void) const;
    	bool removerProduto(long int);
    	bool removerProdutoPerecivel(long int);
    	bool removerRemedio(long int);
    	void removerProdutosPereciveisVencidos(void);
    	void removerRemediosVencidos(void);
    	bool pesquisarProduto(string) const;
    	bool pesquisarProdutoPerecivel(string) const;
    	bool pesquisarRemedio(string) const;
 		bool pesquisarProduto(long int) const;
    	bool pesquisarProdutoPerecivel(long int) const;
    	bool pesquisarRemedio(long int) const;
    	bool pesquisaPerecivelVencido(int);
    	bool pesquisaRemedioVencido(int);
    	void ordenaProdutoPrecoVenda(void);
    	void ordenaProdutoNome(void);
    	void ordenaProdutoFabricante(void);
    	void ordenaProdutoEstoque(void);
    	void ordenaPerecivelPrecoVenda(void);
    	void ordenaPerecivelNome(void);
    	void ordenaPerecivelFabricante(void);
    	void ordenaPerecivelEstoque(void);
    	void ordenaRemedioPrecoVenda(void);
    	void ordenaRemedioNome(void);
    	void ordenaRemedioFabricante(void);
    	void ordenaRemedioTarja(void);
    	void ordenaRemedioEstoque(void);
    	int getIndiceProduto(long int) const;
    	int getIndiceProduto(string) const;
    	int getIndiceProdutoPerecivel(long int) const;
    	int getIndiceProdutoPerecivel(string) const;
    	int getIndiceRemedio(long int) const;
    	int getIndiceRemedio(string) const;
    	Produto getProduto(int) const;
    	ProdutoPerecivel getProdutoPerecivel(int) const;
    	Remedio getRemedio(int) const;
    	vector <Produto> getListaProdutos(void) const;
    	vector <ProdutoPerecivel> getListaProdutosPereciveis(void) const;
    	vector <Remedio> getListaRemedios(void) const;
};

#endif