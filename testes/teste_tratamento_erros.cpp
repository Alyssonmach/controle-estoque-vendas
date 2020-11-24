#include <iostream>
#include <string>
#include <locale>
#include <vector>
#include <fstream>
#include <cstdlib>

using namespace std;

#include "../implementacoes/Produto.cpp"
#include "../implementacoes/ProdutoPerecivel.cpp"
#include "../implementacoes/Remedio.cpp"
#include "../implementacoes/Estoque.cpp"

int main(void)
{
	setlocale(LC_ALL, "Portuguese");
	
	Estoque meu_estoque;
	ProdutoPerecivel perecivel;
	Produto produto;
	Remedio remedio;
	
	produto = meu_estoque.getProduto(30);
	cout << endl;
	perecivel = meu_estoque.getProdutoPerecivel(30);
	cout << endl;
	remedio = meu_estoque.getRemedio(30);
	cout << endl;
	
	produto.imprimeProduto();
	cout << endl;
	perecivel.imprimeProdutoPerecivel();
	cout << endl;
	remedio.imprimeRemedio();
	
	return 0;
}