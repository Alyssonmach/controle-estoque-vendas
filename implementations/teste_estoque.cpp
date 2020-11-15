#include <iostream>
#include <string>
#include <locale>
#include <vector>
#include <fstream>

using namespace std;

#include "Produto.cpp"
#include "ProdutoPerecivel.cpp"
#include "Remedio.cpp"
#include "Estoque.cpp"

int main(void)
{
	setlocale(LC_ALL, "Portuguese");
	
	
	Estoque estoque;
	Produto produto;
	Remedio remedio;
	ProdutoPerecivel perecivel;
	
	Produto_prototipo prodprop;
	Data vencimento;
	Drogaria drogas;
	
	prodprop.preco_loja  = 11.00;
	prodprop.preco_consumidor = 13.00;
	prodprop.nome = "Fraldas Geriatricas";
	prodprop.categoria = "Cuidados Pessoais";
	prodprop.fabricante = "Fraldario Souza e Souza";
	prodprop.quantidade = 100;
	prodprop.codigo = 1237896;
	
	produto.set_objeto_produto(prodprop);
	
	vencimento.dia = 16;
	vencimento.mes = 11;
	vencimento.ano = 2022;
	
	perecivel.set_objeto_perecivel(prodprop, vencimento);
	
	drogas.medida = "14 Unidades";
	drogas.info_adicional = "Fraldas para cuidados de idosos";
	
	remedio.set_objeto_remedio(prodprop, vencimento, drogas); 
	
	//estoque.inserirProduto(produto);
	//estoque.inserirProdutoPerecivel(perecivel);
	//estoque.inserirRemedio(remedio);
	
	//estoque.removerProdutosPereciveisVencidos();
	//estoque.removerRemediosVencidos();
	estoque.imprimirProduto();
	estoque.imprimirProdutoPerecivel();
	estoque.imprimirRemedio();
	string nome;
	
	
	
	return 0;
}
