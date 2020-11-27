#ifndef ESTOQUE_H
#define ESTOQUE_H

#include <vector>
#include <string>
#include <stdexcept>
#include "Produto.h"
#include "ProdutoPerecivel.h"
#include "Remedio.h"

using std::string;
using std::out_of_range;

class Estoque 
{
	private:
		// definindo vectors para armazenar diversos produtos usando alocacao dinamica de memoria
		vector <Produto> produtos;
		vector <ProdutoPerecivel> pereciveis;
		vector <Remedio> remedios;
		// metodos que checam a data de vencimento de um determinado produto i atraves de um limite de n dias
		bool checaVencimentoPerecivel(int, int);
    	bool checaVencimentoRemedio(int, int);
    	// metodos para ler de um arquivo objetos salvos
    	void lerProduto(void);
    	void lerProdutoPerecivel(void);
    	void lerRemedio(void);
    public:
    	// metodos para gravar em um arquivo objetos definidos
    	void salvarProduto(void);
    	void salvarProdutoPerecivel(void);
    	void salvarRemedio(void);
    	// construtor carrega os objetos salvos em um arquivo
    	Estoque();
    	// destrutor salva os objetos definidos em um arquivo
    	~Estoque();
    	// metodos para inserir produtos nas listas de vector
    	bool inserirProduto(Produto);
    	bool inserirRemedio(Remedio);
    	bool inserirProdutoPerecivel(ProdutoPerecivel);
    	// metodos para imprimir na tela do usuario as listas de vector definidas
    	void imprimirProduto(void) const;
    	void imprimirProdutoPerecivel(void) const;
    	void imprimirRemedio(void) const;
    	// metodos para remover produtos da lista de vector
    	bool removerProduto(long int);
    	bool removerProdutoPerecivel(long int);
    	bool removerRemedio(long int);
    	// metodos para remover produtos vencidos da lista de vector
    	void removerProdutosPereciveisVencidos(void);
    	void removerRemediosVencidos(void);
    	// metodos para pesquisar produtos pelo nome ou codigo de barras
    	bool pesquisarProduto(string) const;
    	bool pesquisarProdutoPerecivel(string) const;
    	bool pesquisarRemedio(string) const;
 		bool pesquisarProduto(long int) const;
    	bool pesquisarProdutoPerecivel(long int) const;
    	bool pesquisarRemedio(long int) const;
    	// metodos para pesquisar produtos vencidos com n dias de tolerancia
    	bool pesquisaPerecivelVencido(int);
    	bool pesquisaRemedioVencido(int);
    	// metodos de ordenacao dos produtos atraves dos seus atributos
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
    	// metodos para definir a entrada/saida de produtos do estoque
    	bool set_entrada_estoque_produto(long int, int);
    	bool set_entrada_estoque_perecivel(long int, int);
    	bool set_entrada_estoque_remedio(long int, int);
    	bool set_saida_estoque_produto(long int, int);
    	bool set_saida_estoque_perecivel(long int, int);
    	bool set_saida_estoque_remedio(long int, int);
    	// metodo que retorna as despezas atuais com base nos produtos que ainda estao no estoque
    	float get_despezas(void) const;
    	// meotodos que retornam o indice dos produtos atraves de pesquisa por nome ou codigo de barras
    	int getIndiceProduto(long int) const;
    	int getIndiceProduto(string) const;
    	int getIndiceProdutoPerecivel(long int) const;
    	int getIndiceProdutoPerecivel(string) const;
    	int getIndiceRemedio(long int) const;
    	int getIndiceRemedio(string) const;
    	// metodos que retornam determinados objetos da lista de vector
    	Produto getProduto(int) const;
    	ProdutoPerecivel getProdutoPerecivel(int) const;
    	Remedio getRemedio(int) const;
    	// metodos que retornam uma copia da lista de vector em um estado atua
    	vector <Produto> getListaProdutos(void) const;
    	vector <ProdutoPerecivel> getListaProdutosPereciveis(void) const;
    	vector <Remedio> getListaRemedios(void) const;
};

#endif