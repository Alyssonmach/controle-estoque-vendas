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

int main(void)
{
	setlocale(LC_ALL, "Portuguese");

	Estoque estoque;
	Produto produto;
	ProdutoPerecivel perecivel;
	Remedio remedio;
	Produto_prototipo auxiliar_produto;
	Data vencimento;
	Drogaria informacoes_remedio;
	
	int opcao(1);
	
	while(opcao)
	{
		cout << "=== Teste de implementação do estoque ===" << endl << endl;
		
		cout << "Escolha uma opção para testar a classe estoque: " << endl << endl;
		cout << "1 - Inserir um novo produto ao estoque;" << endl;
		cout << "2 - Visualizar estoque;" << endl;
		cout << "3 - Remover produto por código de barra." << endl;
		cout << "4 - Fazer a gestão da validade dos produtos;" << endl;
		cout << "5 - Pesquisar sobre o produto;" << endl;
		cout << "0 - Encerrar o programa;" << endl << endl;
		cout << "Digite sua opção: ";
		cin >> opcao;
		
		cout << endl;
		system("pause");
		system("cls");
		
		switch(opcao)
		{
		case 0:
		{
			cout << "Encerrando programa. Todo o estoque foi salvo." << endl;
			break;
		}
		case 1:
		{
			int escolha;
			
			cout << "=== Escolha o tipo de produto a ser cadastrado === :" << endl << endl;
			cout << "1 - Departamento de produtos não perecíveis;" << endl;
			cout << "2 - Departamento de produtos perecíveis;" << endl;
			cout << "3 - Departamento de remédios;" << endl << endl;
			cout << "Opção: ";
			cin >> escolha;
			
			cout << endl;
			system("pause");
			system("cls");
			
			switch(escolha)
			{
			case 1:
			{
				cout << "Informe o preço de aquisição do produto: ";
				cin >> auxiliar_produto.preco_loja;
				cout << "Informe o preço de venda do produto: ";;
				cin >> auxiliar_produto.preco_consumidor;
				cin.ignore();
				cout << "Informe o nome do produto: ";
				getline(cin, auxiliar_produto.nome);
				cout << "Informe a categoria do produto: ";
				getline(cin, auxiliar_produto.categoria);
				cout << "Informe o fabricante do produto: ";
				getline(cin, auxiliar_produto.fabricante);
				cout << "Informe a quantidade em estoque do produto: ";
				cin >> auxiliar_produto.quantidade;
				cout << "Informe o código de barras do produto: ";
				cin >> auxiliar_produto.codigo;
				
				produto.set_objeto_produto(auxiliar_produto);
				estoque.inserirProduto(produto);
				break;
			}
			case 2:
			{
				cout << "Informe o preço de aquisição do produto perecível: ";
				cin >> auxiliar_produto.preco_loja;
				cout << "Informe o preço de venda do produto perecível: ";;
				cin >> auxiliar_produto.preco_consumidor;
				cin.ignore();
				cout << "Informe o nome do produto perecível: ";
				getline(cin, auxiliar_produto.nome);
				cout << "Informe a categoria do produto perecível: ";
				getline(cin, auxiliar_produto.categoria);
				cout << "Informe o fabricante do produto perecível: ";
				getline(cin, auxiliar_produto.fabricante);
				cout << "Informe a quantidade em estoque do produto perecível: ";
				cin >> auxiliar_produto.quantidade;
				cout << "Informe o código de barras do produto perecível: ";
				cin >> auxiliar_produto.codigo;
				cout << "Informe o dia que o produto perecível se vence: ";
				cin >> vencimento.dia;
				cout << "Informe o mês que o produto perecível se vence: ";
				cin >> vencimento.mes;
				cout << "Informe o ano que o produto perecível se vence: ";
				cin >> vencimento.ano;
				
				perecivel.set_objeto_perecivel(auxiliar_produto, vencimento);
				estoque.inserirProdutoPerecivel(perecivel);
				break;
			}
			case 3:
			{
				cout << "Informe o preço de aquisição do remédio: ";
				cin >> auxiliar_produto.preco_loja;
				cout << "Informe o preço de venda do remédio: ";;
				cin >> auxiliar_produto.preco_consumidor;
				cin.ignore();
				cout << "Informe o nome do remédio: ";
				getline(cin, auxiliar_produto.nome);
				cout << "Informe a tarja do remédio: ";
				getline(cin, auxiliar_produto.categoria);
				cout << "Informe o fabricante do remédio: ";
				getline(cin, auxiliar_produto.fabricante);
				cout << "Informe a quantidade em estoque do remédio: ";
				cin >> auxiliar_produto.quantidade;
				cout << "Informe o código de barras do remédio: ";
				cin >> auxiliar_produto.codigo;
				cout << "Informe o dia que o remédio se vence: ";
				cin >> vencimento.dia;
				cout << "Informe o mês que o remédio se vence: ";
				cin >> vencimento.mes;
				cout << "Informe o ano que o remédio se vence: ";
				cin >> vencimento.ano;
				cin.ignore();
				cout << "Informe a medida do remédio: ";
				getline(cin, informacoes_remedio.medida);
				cout << "Informe a descrição do remédio: ";
				getline(cin, informacoes_remedio.info_adicional);
				
				remedio.set_objeto_remedio(auxiliar_produto, vencimento, informacoes_remedio);
				estoque.inserirRemedio(remedio);
				break;
			}
			default:
				cout << "Opção Inválida. Tente novamente." << endl;
			}
			
			break;
		}
		case 2:
		{
			int escolha;
			
			cout << "=== Escolha o departamento de estoque === :" << endl << endl;
			cout << "1 - Departamento de produtos não perecíveis;" << endl;
			cout << "2 - Departamento de produtos perecíveis;" << endl;
			cout << "3 - Departamento de remédios;" << endl << endl;
			cout << "Opção: ";
			cin >> escolha;
			
			cout << endl;
			system("pause");
			system("cls");
			
			switch(escolha)
			{
			case 1:
			{
				estoque.imprimirProduto();
				break;
			}
			case 2:
			{
				estoque.imprimirProdutoPerecivel();
				break;
			}
            case 3:
			{
				estoque.imprimirRemedio();
            	break;
			}
			default:
				cout << "Opção Inválida. Tente novamente." << endl;
			}
			
			break;
		}
		case 3:
		{
			int escolha;
			long int codigo;
			
			cout << "=== Escolha o departamento a ter o produto subtraido === :" << endl << endl;
			cout << "1 - Departamento de produtos não perecíveis;" << endl;
			cout << "2 - Departamento de produtos perecíveis;" << endl;
			cout << "3 - Departamento de remédios;" << endl << endl;
			cout << "Opção: ";
			cin >> escolha;
			
			cout << endl;
			system("pause");
			system("cls");
			
			switch(escolha)
			{
			case 1:
			{
				cout << "Informe o código de barras do produto a ser removido: ";
				cin >> codigo;
				if(estoque.removerProduto(codigo))
				{
					cout << "Produto removido com sucesso." << endl;
				}
				else
				{
					cout << "Operação não realizada. Tente Novamete." << endl;
				}
				break;
			}
			case 2:
			{
				cout << "Informe o código de barras do produto perecível a ser removido: ";
				cin >> codigo;
				if(estoque.removerProdutoPerecivel(codigo))
				{
					cout << "Produto removido com sucesso." << endl;
				}
				else
				{
					cout << "Operação não realizada. Tente Novamete." << endl;
				}
				break;
			}
			case 3:
			{
				cout << "Informe o código de barras do produto a ser removido: ";
				cin >> codigo;
				if(estoque.removerRemedio(codigo))
				{
					cout << "Produto removido com sucesso." << endl;
				}
				else
				{
					cout << "Operação não realizada. Tente Novamete." << endl;
				}
				break;
			}
			default:
				cout << "Opção Inválida. Tente novamente." << endl;
			}
			break;
		}
		default:
			cout << "Opção Inválida. Tente novamente." << endl;
		}
		
		cout << endl;
		system("pause");
		system("cls");
	}
	
	
	return 0;
}
