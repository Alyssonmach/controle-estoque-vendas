#include <iostream>
#include <locale>
#include <iomanip>

using namespace std;

#include "../implementacoes/Produto.cpp"
#include "../implementacoes/ProdutoPerecivel.cpp"

int main(void)
{
	setlocale(LC_ALL, "Portuguese");
	
	Produto_prototipo produto_cadastro;
	ProdutoPerecivel produto_perecivel;
	Data vencimento;
	
	cout << "=== Teste da classe Produto Perecível ===" << endl;
	
	produto_cadastro.preco_loja = 13.49;
	produto_cadastro.preco_consumidor = 20.99;
	produto_cadastro.nome = "Pastilha Anti-inflamação";
	produto_cadastro.categoria = "Produto Perecível";
	produto_cadastro.fabricante = "Souza e Zousa";
	produto_cadastro.quantidade = 345;
	produto_cadastro.codigo = 123458;
	vencimento.dia = 14;
	vencimento.mes = 11;
	vencimento.ano = 2022;
	
	produto_perecivel.set_objeto_perecivel(produto_cadastro, vencimento);
	
	cout << "Produto Cadastrado: " << endl;
	cout << produto_perecivel.get_objeto_produto().preco_loja << endl;
	cout << produto_perecivel.get_objeto_produto().preco_consumidor << endl;
	cout << produto_perecivel.get_objeto_produto().nome << endl;
	cout << produto_perecivel.get_objeto_produto().categoria << endl;
	cout << produto_perecivel.get_objeto_produto().fabricante << endl;
	cout << produto_perecivel.get_objeto_produto().quantidade << endl;
	cout << "Data Vencimento: " << endl;
	cout << setw(2);
	cout << setfill('0') << produto_perecivel.get_data_validade().dia << "/";
	cout << setfill('0') << produto_perecivel.get_data_validade().mes << "/";
	cout << setfill('0') << produto_perecivel.get_data_validade().ano << endl;
	
	cout << "Data Atual: " << endl;
	cout << setw(2);
	cout << setfill('0') << produto_perecivel.get_data_atual().dia << "/";
	cout << setfill('0') << produto_perecivel.get_data_atual().mes << "/";
	cout << setfill('0') << produto_perecivel.get_data_atual().ano << endl;
	
	return 0;
}
