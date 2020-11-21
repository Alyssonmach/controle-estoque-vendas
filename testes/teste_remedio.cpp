#include <iostream>
#include <locale>
#include <iomanip>

using namespace std;

#include "../implementations/Produto.cpp"
#include "../implementations/ProdutoPerecivel.cpp"
#include "../implementations/Remedio.cpp"

int main(void)
{
	setlocale(LC_ALL, "Portuguese");
	
	Produto_prototipo produto_cadastro;
	ProdutoPerecivel produto_perecivel;
	Remedio meu_remedio;
	Data vencimento;
	Drogaria remedio;
	
	cout << "=== Teste da classe Produto Perecível ===" << endl;
	
	cout << "Data Atual: " << endl;
	cout << setw(2);
	cout << setfill('0') << produto_perecivel.get_data_atual().dia << "/";
	cout << setfill('0') << produto_perecivel.get_data_atual().mes << "/";
	cout << setfill('0') << produto_perecivel.get_data_atual().ano << endl;
	
	produto_cadastro.preco_loja = 50.00;
	produto_cadastro.preco_consumidor = 100.00;
	produto_cadastro.nome = "BCAA";
	produto_cadastro.categoria = "Sem Tarja";
	produto_cadastro.fabricante = "BLC medicals";
	produto_cadastro.quantidade = 30;
	produto_cadastro.codigo = 123459;
	vencimento.dia = 10;
	vencimento.mes = 10;
	vencimento.ano = 2021;
	remedio.medida = "120 capsulas";
	remedio.info_adicional = "Suplemento ideal para atletas";
	
	meu_remedio.set_objeto_remedio(produto_cadastro, vencimento, remedio);
	
	cout << "Produto Cadastrado: " << endl;
	cout << meu_remedio.get_objeto_produto().preco_loja << endl;
	cout << meu_remedio.get_objeto_produto().preco_consumidor << endl;
	cout << meu_remedio.get_objeto_produto().nome << endl;
	cout << meu_remedio.get_objeto_produto().categoria << endl;
	cout << meu_remedio.get_objeto_produto().fabricante << endl;
	cout << meu_remedio.get_objeto_produto().quantidade << endl;
	cout << "Data Vencimento: " << endl;
	cout << setw(2);
	cout << setfill('0') << meu_remedio.get_data_validade().dia << "/";
	cout << setfill('0') << meu_remedio.get_data_validade().mes << "/";
	cout << setfill('0') << meu_remedio.get_data_validade().ano << endl;
	cout << meu_remedio.get_objeto_remedio().medida << endl;
	cout << meu_remedio.get_objeto_remedio().info_adicional << endl;
	
	
	
	
	return 0;
}
