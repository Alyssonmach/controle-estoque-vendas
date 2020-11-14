#include <iostream>
#include <string>
#include <locale>
#include <vector>
#include <fstream>

using namespace std;

#include "../implementations/Produto.cpp"
#include "../implementations/ProdutoPerecivel.cpp"
#include "../implementations/Remedio.cpp"
#include "../implementations/Estoque.cpp"

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
	
	prodprop.preco_loja  = 12.39;
	prodprop.preco_consumidor = 20.50;
	prodprop.nome = "Absorvente Masculino";
	prodprop.categoria = "Higiene";
	prodprop.fabricante = "Pampers";
	prodprop.quantidade = 24;
	prodprop.codigo = 123456;
	
	produto.set_objeto_produto(prodprop);
	
	vencimento.dia = 10;
	vencimento.mes = 12;
	vencimento.ano = 2021;
	
	perecivel.set_objeto_perecivel(prodprop, vencimento);
	
	drogas.medida = "14 Unidades";
	drogas.info_adicional = "Contenção sanguinaria masculina";
	
	remedio.set_objeto_remedio(prodprop, vencimento, drogas);
	
	estoque.inserirProduto(produto);
	estoque.inserirProdutoPerecivel(perecivel);
	estoque.inserirRemedio(remedio);
	
	return 0;
}
