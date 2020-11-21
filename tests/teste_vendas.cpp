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
	
	cout << "=== An�lise da Classe de Vendas ===" << endl << endl;
	
	cout << "1 - Registrar Compras;" << endl;
	cout << "2 - An�lise de Notas Fiscais;" << endl;
	cout << "3 - Visualizar a parte financeira da farm�cia;" << endl; 
	cout << "0 - Sair do Programa;" << endl << endl; 
	
	cout << "Insira uma op��o: ";
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
		cout << "1 - Produto n�o perec�vel" << endl;
		cout << "2 - Produto perec�vel" << endl;
		cout << "3 - Rem�dio" << endl << endl;
		
		cout << "insira sua op��o: ";
		cin >> escolha;
		
		cout << endl;
		system("pause");
		system("cls");
		
		switch(escolha)
		{
		case 1:
		{
			cout << "Insira o c�digo de barras do produto n�o perec�vel: ";
			cin >> codigo;
			
			if(processo_vendas.pesquisarProduto(codigo))
			{
				cout << "Produto encontrado. Tem certeza que deseja registrar na nota?" << endl;
				cout << "1 - sim;" << endl;
				cout << "2 - n�o;" << endl << endl;
				cout << "Insira sua op��o: ";
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
					cout << "Produto n�o perec�vel Registrado com sucesso." << endl;
				}
				else if(escolha == 2)
				{
					cout << "Produto descartado." << endl;
				}
				else
				{
					cout << "Op��o inv�lida. Tente novamente." << endl;
				}
				
			}
			else
			{
				cout << "Produto n�o encontrado." << endl;
			}
			break;
		}
		case 2:
		{
			cout << "Insira o c�digo de barras do produto perec�vel: ";
			cin >> codigo;
			
			if(processo_vendas.pesquisarProdutoPerecivel(codigo))
			{
				cout << "Produto encontrado. Tem certeza que deseja registrar na nota?" << endl;
				cout << "1 - sim;" << endl;
				cout << "2 - n�o;" << endl << endl;
				cout << "Insira sua op��o: ";
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
					cout << "Produto perec�vel Registrado com sucesso." << endl;
				}
				else if(escolha == 2)
				{
					cout << "Produto descartado." << endl;
				}
				else
				{
					cout << "Op��o inv�lida. Tente novamente." << endl;
				}
			}
			else
			{
				cout << "Produto n�o encontrado." << endl;
			}
			break;
		}
		case 3:
		{
			cout << "Insira o c�digo de barras do rem�dio: ";
			cin >> codigo;
			
			if(processo_vendas.pesquisarRemedio(codigo))
			{
				cout << "Rem�dio encontrado. Tem certeza que deseja registrar na nota?" << endl;
				cout << "1 - sim;" << endl;
				cout << "2 - n�o;" << endl << endl;
				cout << "Insira sua op��o: ";
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
					cout << "Produto n�o perec�vel Registrado com sucesso." << endl;
				}
				else if(escolha == 2)
				{
					cout << "Rem�dio descartado." << endl;
				}
				else
				{
					cout << "Op��o inv�lida. Tente novamente." << endl;
				}
			}
			else
			{
				cout << "Rem�dio n�o encontrado." << endl;
			}
			break;
		}
		default:
			cout << "Op��o inv�lida. Tente novamente." << endl;
			break;
		}
		break;
	}
	default:
		cout << "Op��o inv�lida. Tente novamente." << endl;
	}
	
	cout << endl;
	system("pause");
	system("cls");
	
	return 0;
}