#include <iostream>
#include <locale>
#include <string>

using namespace std;

#include "../implementations/Produto.cpp"

int main(void)
{
	setlocale(LC_ALL, "Portuguese");
	
	cout << "=== Testando a classe Produto ===" << endl << endl;
	
	Produto_prototipo produto_auxiliar;
	Produto produto_teste;
	
	float preco_loja = 12.99;
	float preco_consumidor =  15.99;
	string nome = "Fraldas de Pano";
	string categoria = "Produtos não perecíveis";
	string fabricante = "Confortmax Brasil";
	int quantidade = 200;
	long int codigo = 123456;
	
	produto_teste.set_preco_loja(preco_loja);
	produto_teste.set_preco_consumidor(preco_consumidor);
	produto_teste.set_nome(nome);
	produto_teste.set_categoria(categoria);
	produto_teste.set_fabricante(fabricante);
	produto_teste.set_quantidade(quantidade);
	produto_teste.set_codigo(codigo);
	
	cout << "Produto armazenado:" << endl;
	cout << produto_teste.get_objeto_produto().preco_loja << endl;
	cout << produto_teste.get_objeto_produto().preco_consumidor << endl;
	cout << produto_teste.get_objeto_produto().nome << endl;
	cout << produto_teste.get_objeto_produto().categoria << endl;
	cout << produto_teste.get_objeto_produto().fabricante << endl;
	cout << produto_teste.get_objeto_produto().quantidade << endl;
	cout << produto_teste.get_objeto_produto().codigo << endl;
	
	produto_auxiliar.preco_loja = -2;
	produto_auxiliar.preco_consumidor = 2;
	produto_auxiliar.nome = "a";
	produto_auxiliar.fabricante = "b";
	produto_auxiliar.categoria = "c";
	produto_auxiliar.quantidade = -3;
	produto_auxiliar.codigo = 10;
	
	produto_teste.valida_objeto_produto(produto_auxiliar);
	produto_teste.set_objeto_produto(produto_auxiliar);
	
	produto_auxiliar.preco_loja = 14.50;
	produto_auxiliar.preco_consumidor = 20.10;
	produto_auxiliar.nome = "Desodorante Rolivon";
	produto_auxiliar.fabricante = "Rolivon e Família";
	produto_auxiliar.categoria = "Produto Perecível";
	produto_auxiliar.quantidade = 100;
	produto_auxiliar.codigo = 123457;
	
	produto_teste.valida_objeto_produto(produto_auxiliar);
	produto_teste.set_objeto_produto(produto_auxiliar);
	
	cout << "Produto armazenado:" << endl;
	cout << produto_teste.get_objeto_produto().preco_loja << endl;
	cout << produto_teste.get_objeto_produto().preco_consumidor << endl;
	cout << produto_teste.get_objeto_produto().nome << endl;
	cout << produto_teste.get_objeto_produto().categoria << endl;
	cout << produto_teste.get_objeto_produto().fabricante << endl;
	cout << produto_teste.get_objeto_produto().quantidade << endl;
	cout << produto_teste.get_objeto_produto().codigo << endl;
	
	return 0;
}
