#ifndef ORDENA_H
#define ORDENA_H

#include "Estoque.h"
#include <vector>

// definindo a classe Ordena (ordena as listas de diferentes modos)
class Ordena 
{
	// especificador de acesso public
	public:
		vector <Produto> ordena_produto_preco(vector <Produto>);
		vector <ProdutoPerecivel> ordena_produto_perecivel_preco(vector <ProdutoPerecivel>);
		vector <Remedio> ordena_remedio_preco(vector <Remedio>);
		vector <Produto> ordena_produto_nome(vector <Produto>);
		vector <ProdutoPerecivel> ordena_produto_perecivel_nome(vector <ProdutoPerecivel>);
		vector <Remedio> ordena_remedio_nome(vector <Remedio>);
		vector <Produto> ordena_produto_categoria(vector <Produto>);
		vector <ProdutoPerecivel> ordena_produto_perecivel_categoria(vector <ProdutoPerecivel>);
		vector <Remedio> ordena_remedio_categoria(vector <Remedio>);
		vector <Remedio> ordena_remedio_tarja(vector <Remedio>);
};

#endif