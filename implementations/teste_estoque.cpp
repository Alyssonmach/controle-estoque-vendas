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
	//Remedio remedio;
	ProdutoPerecivel perecivel;
	
	Produto_prototipo prodprop;
	Data vencimento;
	//Drogaria drogas;
	
	estoque.imprimirLista();
	
	prodprop.preco_loja  = 12.39;
	prodprop.preco_consumidor = 20.50;
	prodprop.nome = "Termometro";
	prodprop.categoria = "Cuidados Pessoais";
	prodprop.fabricante = "Aviante";
	prodprop.quantidade = 44;
	prodprop.codigo = 1234583;
	
	//produto.set_objeto_produto(prodprop);
	
	
	vencimento.dia = 10;
	vencimento.mes = 12;
	vencimento.ano = 2021;
	
	perecivel.set_objeto_perecivel(prodprop, vencimento);
	
	//drogas.medida = "14 Unidades";
	//drogas.info_adicional = "Contenção sanguinaria masculina";
	
	//remedio.set_objeto_remedio(prodprop, vencimento, drogas); 
	
	//cout << estoque.inserirProduto(produto);
	cout << estoque.inserirProdutoPerecivel(perecivel);
	//cout << estoque.inserirRemedio(remedio);
	
	//estoque.imprimirLista();
	
	return 0;
}
