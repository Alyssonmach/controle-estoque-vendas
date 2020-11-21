#include <iostream>
#include <string>
#include <locale>
#include <vector>
#include <fstream>
#include <cstdlib>

using namespace std;

#include "../implementations/Produto.cpp"
#include "../implementations/ProdutoPerecivel.cpp"
#include "../implementations/Remedio.cpp"
#include "../implementations/Estoque.cpp"
#include "../implementations/Vendas.cpp"

int main(void)
{
	setlocale(LC_ALL, "Portuguese");
	Produto registro_produto;
	ProdutoPerecivel registro_perecivel;
	Remedio registro_remedio;
	Vendas processo_vendas;
	
	int escolha;
	long int codigo;
	
	cout << "=== Análise da Classe de Vendas ===" << endl << endl;
	
	cout << "1 - Registrar Compras;" << endl;
	cout << "2 - Análise de Notas Fiscais;" << endl;
	cout << "3 - Visualizar a parte financeira da farmácia;" << endl; 
	cout << "0 - Sair do Programa;" << endl << endl; 
	
	cout << "Insira uma opção: ";
	cin >> escolha;
	
	cout << endl;
	system("pause");
	system("cls");
	
	switch(escolha)
	{
	case 0:
	{
		cout << "Programa encerrado. Volte Sempre!" << endl;
		break;
	}
	case 1:
	{
		cout << "=== Escolha o tipo de produto a ser registrado ===" << endl << endl;
		cout << "1 - Produto não perecível" << endl;
		cout << "2 - Produto perecível" << endl;
		cout << "3 - Remédio" << endl << endl;
		
		cout << "insira sua opção: ";
		cin >> escolha;
		
		cout << endl;
		system("pause");
		system("cls");
		
		switch(escolha)
		{
		case 1:
		{
			cout << "Insira o código de barras do produto não perecível: ";
			cin >> codigo;
			
			if(processo_vendas.pesquisarProduto(codigo))
			{
				cout << "Produto encontrado. Tem certeza que deseja registrar na nota?" << endl;
				cout << "1 - sim;" << endl;
				cout << "2 - não;" << endl << endl;
				cout << "Insira sua opção: ";
				cin >> escolha;
				
				cout << endl;
				system("pause");
				system("cls");
				
				if(escolha == 1)
				{
					registro_produto = processo_vendas.getProduto(processo_vendas.getIndiceProduto(codigo));
					processo_vendas.inserir_nota_produto(registro_produto);
					processo_vendas.set_saida_estoque_produto(codigo, 1);
					cout << endl;
					cout << "Produto não perecível Registrado com sucesso." << endl;
				}
				else if(escolha == 2)
				{
					cout << "Produto descartado." << endl;
				}
				else
				{
					cout << "Opção inválida. Tente novamente." << endl;
				}
				
			}
			else
			{
				cout << "Produto não encontrado." << endl;
			}
			break;
		}
		case 2:
		{
			cout << "Insira o código de barras do produto perecível: ";
			cin >> codigo;
			
			if(processo_vendas.pesquisarProdutoPerecivel(codigo))
			{
				cout << "Produto encontrado. Tem certeza que deseja registrar na nota?" << endl;
				cout << "1 - sim;" << endl;
				cout << "2 - não;" << endl << endl;
				cout << "Insira sua opção: ";
				cin >> escolha;
				
				cout << endl;
				system("pause");
				system("cls");
				
				if(escolha == 1)
				{
					registro_perecivel = processo_vendas.getProdutoPerecivel(processo_vendas.getIndiceProdutoPerecivel(codigo));
					processo_vendas.inserir_nota_perecivel(registro_perecivel);
					processo_vendas.set_saida_estoque_perecivel(codigo, 1);
					cout << endl;
					cout << "Produto perecível Registrado com sucesso." << endl;
				}
				else if(escolha == 2)
				{
					cout << "Produto descartado." << endl;
				}
				else
				{
					cout << "Opção inválida. Tente novamente." << endl;
				}
			}
			else
			{
				cout << "Produto não encontrado." << endl;
			}
			break;
		}
		case 3:
		{
			cout << "Insira o código de barras do remédio: ";
			cin >> codigo;
			
			if(processo_vendas.pesquisarRemedio(codigo))
			{
				cout << "Remédio encontrado. Tem certeza que deseja registrar na nota?" << endl;
				cout << "1 - sim;" << endl;
				cout << "2 - não;" << endl << endl;
				cout << "Insira sua opção: ";
				cin >> escolha;
				
				cout << endl;
				system("pause");
				system("cls");
				
				if(escolha == 1)
				{
					registro_remedio = processo_vendas.getRemedio(processo_vendas.getIndiceRemedio(codigo));
					processo_vendas.inserir_nota_remedio(registro_remedio);
					processo_vendas.set_saida_estoque_remedio(codigo, 1);
					cout << endl;
					cout << "Produto não perecível Registrado com sucesso." << endl;
				}
				else if(escolha == 2)
				{
					cout << "Remédio descartado." << endl;
				}
				else
				{
					cout << "Opção inválida. Tente novamente." << endl;
				}
			}
			else
			{
				cout << "Remédio não encontrado." << endl;
			}
			break;
		}
		default:
			cout << "Opção inválida. Tente novamente." << endl;
			break;
		}
		break;
	}
	default:
		cout << "Opção inválida. Tente novamente." << endl;
	}
	
	cout << endl;
	system("pause");
	system("cls");
	
	return 0;
}