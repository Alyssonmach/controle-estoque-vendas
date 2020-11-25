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

class Vendas : public Estoque
{
	private:
		// atributo responsavel por armazenar o apurado da farmacia
		float apurado;
		// atributo responsavel por armazenar o saldo da farmacia
		float saldo;
		// metodos responsaveis por computar apurado/saldo da farmacia
		void adiciona_apurado(float);
    	void adiciona_saldo(float);
    	// metodo que conta a quantidade de arquivos no diretorio
    	int quantidade_notas_fiscais(void);
    	// metodo que monta a pasta de destino e o nome do arquivo da nota fiscal a ser salva
    	string diretorio_nota(int);
    	// listas de vector que armazenam os produtos enquando o caixa estiver registrando as compras
    	vector <Produto> produto_nota;
    	vector <ProdutoPerecivel> perecivel_nota;
    	vector <Remedio> remedio_nota;
    public:
    	// construtor da classe carrega as informacoes financeiras da farmacia
    	Vendas(void);
    	// destrutor da classe salva as informacoes financeiras da farmacia
    	~Vendas(void);
    	// metodo responsaveis por organizar uma lista transitoria dos produtos de compra
    	void inserir_nota_produto(Produto);
    	void inserir_nota_perecivel(ProdutoPerecivel);
    	void inserir_nota_remedio(Remedio);
    	// metodos que permite a pesquisa de produtos em registro de compras pelo codigo de barras 
    	bool pesquisar_nota_produto(long int);
    	bool pesquisar_nota_perecivel(long int);
    	bool pesquisar_nota_remedio(long int);
    	// metodos que apagam os produtos ja registrados na lista transitoria para a nota fiscal
    	bool apaga_da_nota_produto(long int);
    	bool apaga_da_nota_perecivel(long int);
    	bool apaga_da_nota_remedio(long int);
    	// metodo que limpa os produtos adicionados ao carrinho de compras
    	void limpa_carrinho(void);
    	// metodo que imprime o historico total de notas fiscais feitas a cada compra
 		void imprime_historico_fiscal(void) const;
 		// metodo que zera o arquivo do historico das notas fiscais
    	void limpa_historico_notas(void);
    	// metodo que recupera o historico de notas fiscais atraves das notas fiscais armazenadas separadamente
    	void restaura_historico_notas(void);
    	// metodo que imprime as ultimas n notas fiscais feitas
    	void imprime_ultimas_notas(int);
    	// metodo que retorna a data atual formatada
    	Data retornaDataAtual(void) const;
    	// metodo que fecha a nota fiscal e limpa as listas de vector transitoria para uma nova compra
    	void monta_nota_fiscal(void);
    	// metodo que recomeca a contagem das fincancas da farmacia a partir do zero
    	void fecha_conta_mes(void);
    	// metodo que retorna o apurado atual da farmacia com base nas vendas
    	float get_apurado(void) const;
    	// metodo que retorna o saldo atual da farmacia com base nas vendas
    	float get_saldo(void) const;
};

#endif