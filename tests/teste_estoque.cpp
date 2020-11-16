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
		cout << "=== Teste de implementa��o do estoque ===" << endl << endl;
		
		cout << "Escolha uma op��o para testar a classe estoque: " << endl << endl;
		cout << "1 - Inserir um novo produto ao estoque;" << endl;
		cout << "2 - Visualizar estoque;" << endl;
		cout << "3 - Remover produto por c�digo de barra." << endl;
		cout << "4 - Fazer a gest�o da validade dos produtos;" << endl;
		cout << "5 - Pesquisar sobre o produto;" << endl;
		cout << "0 - Encerrar o programa;" << endl << endl;
		cout << "Digite sua op��o: ";
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
			cout << "1 - Departamento de produtos n�o perec�veis;" << endl;
			cout << "2 - Departamento de produtos perec�veis;" << endl;
			cout << "3 - Departamento de rem�dios;" << endl << endl;
			cout << "Op��o: ";
			cin >> escolha;
			
			cout << endl;
			system("pause");
			system("cls");
			
			switch(escolha)
			{
			case 1:
			{
				cout << "Informe o pre�o de aquisi��o do produto: ";
				cin >> auxiliar_produto.preco_loja;
				cout << "Informe o pre�o de venda do produto: ";;
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
				cout << "Informe o c�digo de barras do produto: ";
				cin >> auxiliar_produto.codigo;
				
				produto.set_objeto_produto(auxiliar_produto);
				estoque.inserirProduto(produto);
				break;
			}
			case 2:
			{
				cout << "Informe o pre�o de aquisi��o do produto perec�vel: ";
				cin >> auxiliar_produto.preco_loja;
				cout << "Informe o pre�o de venda do produto perec�vel: ";;
				cin >> auxiliar_produto.preco_consumidor;
				cin.ignore();
				cout << "Informe o nome do produto perec�vel: ";
				getline(cin, auxiliar_produto.nome);
				cout << "Informe a categoria do produto perec�vel: ";
				getline(cin, auxiliar_produto.categoria);
				cout << "Informe o fabricante do produto perec�vel: ";
				getline(cin, auxiliar_produto.fabricante);
				cout << "Informe a quantidade em estoque do produto perec�vel: ";
				cin >> auxiliar_produto.quantidade;
				cout << "Informe o c�digo de barras do produto perec�vel: ";
				cin >> auxiliar_produto.codigo;
				cout << "Informe o dia que o produto perec�vel se vence: ";
				cin >> vencimento.dia;
				cout << "Informe o m�s que o produto perec�vel se vence: ";
				cin >> vencimento.mes;
				cout << "Informe o ano que o produto perec�vel se vence: ";
				cin >> vencimento.ano;
				
				perecivel.set_objeto_perecivel(auxiliar_produto, vencimento);
				estoque.inserirProdutoPerecivel(perecivel);
				break;
			}
			case 3:
			{
				cout << "Informe o pre�o de aquisi��o do rem�dio: ";
				cin >> auxiliar_produto.preco_loja;
				cout << "Informe o pre�o de venda do rem�dio: ";;
				cin >> auxiliar_produto.preco_consumidor;
				cin.ignore();
				cout << "Informe o nome do rem�dio: ";
				getline(cin, auxiliar_produto.nome);
				cout << "Informe a tarja do rem�dio: ";
				getline(cin, auxiliar_produto.categoria);
				cout << "Informe o fabricante do rem�dio: ";
				getline(cin, auxiliar_produto.fabricante);
				cout << "Informe a quantidade em estoque do rem�dio: ";
				cin >> auxiliar_produto.quantidade;
				cout << "Informe o c�digo de barras do rem�dio: ";
				cin >> auxiliar_produto.codigo;
				cout << "Informe o dia que o rem�dio se vence: ";
				cin >> vencimento.dia;
				cout << "Informe o m�s que o rem�dio se vence: ";
				cin >> vencimento.mes;
				cout << "Informe o ano que o rem�dio se vence: ";
				cin >> vencimento.ano;
				cin.ignore();
				cout << "Informe a medida do rem�dio: ";
				getline(cin, informacoes_remedio.medida);
				cout << "Informe a descri��o do rem�dio: ";
				getline(cin, informacoes_remedio.info_adicional);
				
				remedio.set_objeto_remedio(auxiliar_produto, vencimento, informacoes_remedio);
				estoque.inserirRemedio(remedio);
				break;
			}
			default:
				cout << "Op��o Inv�lida. Tente novamente." << endl;
			}
			
			break;
		}
		case 2:
		{
			int escolha;
			
			cout << "=== Escolha o departamento de estoque === :" << endl << endl;
			cout << "1 - Departamento de produtos n�o perec�veis;" << endl;
			cout << "2 - Departamento de produtos perec�veis;" << endl;
			cout << "3 - Departamento de rem�dios;" << endl << endl;
			cout << "Op��o: ";
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
				cout << "Op��o Inv�lida. Tente novamente." << endl;
			}
			
			break;
		}
		case 3:
		{
			int escolha;
			long int codigo;
			
			cout << "=== Escolha o departamento a ter o produto subtraido === :" << endl << endl;
			cout << "1 - Departamento de produtos n�o perec�veis;" << endl;
			cout << "2 - Departamento de produtos perec�veis;" << endl;
			cout << "3 - Departamento de rem�dios;" << endl << endl;
			cout << "Op��o: ";
			cin >> escolha;
			
			cout << endl;
			system("pause");
			system("cls");
			
			switch(escolha)
			{
			case 1:
			{
				cout << "Informe o c�digo de barras do produto a ser removido: ";
				cin >> codigo;
				if(estoque.removerProduto(codigo))
				{
					cout << "Produto removido com sucesso." << endl;
				}
				else
				{
					cout << "Opera��o n�o realizada. Tente Novamete." << endl;
				}
				break;
			}
			case 2:
			{
				cout << "Informe o c�digo de barras do produto perec�vel a ser removido: ";
				cin >> codigo;
				if(estoque.removerProdutoPerecivel(codigo))
				{
					cout << "Produto removido com sucesso." << endl;
				}
				else
				{
					cout << "Opera��o n�o realizada. Tente Novamete." << endl;
				}
				break;
			}
			case 3:
			{
				cout << "Informe o c�digo de barras do produto a ser removido: ";
				cin >> codigo;
				if(estoque.removerRemedio(codigo))
				{
					cout << "Produto removido com sucesso." << endl;
				}
				else
				{
					cout << "Opera��o n�o realizada. Tente Novamete." << endl;
				}
				break;
			}
			default:
				cout << "Op��o Inv�lida. Tente novamente." << endl;
			}
			break;
		}
		default:
			cout << "Op��o Inv�lida. Tente novamente." << endl;
		}
		
		cout << endl;
		system("pause");
		system("cls");
	}
	
	
	return 0;
}
