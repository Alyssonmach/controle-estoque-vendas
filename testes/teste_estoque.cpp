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
		cout << "2 - Gerir quantidades de produto em estoque;" << endl;
		cout << "3 - Visualizar estoque;" << endl;
		cout << "4 - Remover produtos por código de barra." << endl;
		cout << "5 - Fazer a gestão da validade dos produtos;" << endl;
		cout << "6 - Pesquisar sobre o produto;" << endl;
		cout << "7 - Ordenação de Estoque;" << endl;
		cout << "8 - Visualizar as depezas atuais;" << endl;
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
			
			cout << "=== Escolha o tipo de procedimento a ser realizado === :" << endl << endl;
			cout << "1 - Adicionar Produtos;" << endl;
			cout << "2 - Remover Produtos;" << endl << endl;
			cout << "Opção: ";
			cin >> escolha;
			
			cout << endl;
			system("pause");
			system("cls");
			
			switch(escolha)
			{
			case 1:
			{
				int escolha, quantidade;
				long int codigo;
				
				cout << "=== Escolha o departamento a ter itens adicionados === :" << endl << endl;
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
					cout << "Informe o código de barras do produto a ser aumentado no estoque: ";
					cin >> codigo;
					cout << "Informe a quantidade de aumento:";
					cin >> quantidade;
					
					cout << "Pesquisando..." << endl << endl;
					if(estoque.set_entrada_estoque_produto(codigo, quantidade))
					{
						cout << endl;
						cout << "Produtos adicionados com sucesso." << endl;
					}
					else
					{
						cout << "Operação não realizada. Tente Novamete." << endl;
					}
					break;
				}
				case 2:
				{
					cout << "Informe o código de barras do produto perecível a ser aumentado no estoque: ";
					cin >> codigo;
					cout << "Informe a quantidade de aumento:";
					cin >> quantidade;
					
					cout << "Pesquisando..." << endl << endl;
					if(estoque.set_entrada_estoque_perecivel(codigo, quantidade))
					{
						cout << endl;
						cout << "Produtos perecíveis adicionados com sucesso." << endl;
					}
					else
					{
						cout << "Operação não realizada. Tente Novamete." << endl;
					}
					break;
				}
				case 3:
				{
					cout << "Informe o código de barras do remédio a ser aumentado no estoque: ";
					cin >> codigo;
					cout << "Informe a quantidade de aumento:";
					cin >> quantidade;
					
					cout << "Pesquisando..." << endl << endl;
					if(estoque.set_entrada_estoque_remedio(codigo, quantidade))
					{
						cout << endl;
						cout << "Remédios adicionados com sucesso." << endl;
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
			case 2:
			{
				int escolha, quantidade;
				long int codigo;
				
				cout << "=== Escolha o departamento a ter itens adicionados === :" << endl << endl;
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
					cout << "Informe o código de barras do produto a ser diminuido no estoque: ";
					cin >> codigo;
					cout << "Informe a quantidade de diminuição: ";
					cin >> quantidade;
					
					cout << "Pesquisando..." << endl << endl;
					if(estoque.set_saida_estoque_produto(codigo, quantidade))
					{
						cout << endl;
						cout << "Produtos removidos com sucesso." << endl;
					}
					else
					{
						cout << "Operação não realizada. Tente Novamete." << endl;
					}
					break;
				}
				case 2:
				{
					cout << "Informe o código de barras do produto perecível a ser diminuido no estoque: ";
					cin >> codigo;
					cout << "Informe a quantidade de diminuição: ";
					cin >> quantidade;
					
					cout << "Pesquisando..." << endl << endl;
					if(estoque.set_saida_estoque_perecivel(codigo, quantidade))
					{
						cout << endl;
						cout << "Produtos perecíveis removidos com sucesso." << endl;
					}
					else
					{
						cout << "Operação não realizada. Tente Novamete." << endl;
					}
					break;
				}
				case 3:
				{
					cout << "Informe o código de barras do remédio a ser aumentado no diminuido: ";
					cin >> codigo;
					cout << "Informe a quantidade de diminuição:";
					cin >> quantidade;
					
					cout << "Pesquisando..." << endl << endl;
					if(estoque.set_saida_estoque_remedio(codigo, quantidade))
					{
						cout << endl;
						cout << "Remédios removidos com sucesso." << endl;
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
			
			break;
		}
		case 3:
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
		case 4:
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
				
				cout << "Produtos Encontrados: " << endl << endl;
				if(estoque.pesquisarProduto(codigo))
				{
					cout << endl;
					cout << "Processando remoção..." << endl;
				}
				
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
				
				cout << "Produtos Encontrados: " << endl << endl;
				if(estoque.pesquisarProdutoPerecivel(codigo))
				{
					cout << endl;
					cout << "Processando remoção..." << endl;
				}
				
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
				cout << "Informe o código de barras do remédio a ser removido: ";
				cin >> codigo;
				
				cout << "Produtos Encontrados: " << endl << endl;
				if(estoque.pesquisarProduto(codigo))
				{
					cout << endl;
					cout << "Processando remoção..." << endl;
				}
				
				if(estoque.removerRemedio(codigo))
				{
					cout << "Remédio removido com sucesso." << endl;
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
		case 5:
		{
			int escolha;
			int limite;
			
			cout << "=== Escolha o departamento para analisar validade dos produtos === :" << endl << endl;
			cout << "1 - Departamento de produtos perecíveis;" << endl;
			cout << "2 - Departamento de remédios;" << endl << endl;
			cout << "Opção: ";
			cin >> escolha;
			
			cout << endl;
			system("pause");
			system("cls");
			
			switch(escolha)
			{
			case 1:
			{
				cout << "Informe o limite de validade em dias a ser pesquisado: ";
				cin >> limite;
				if(estoque.pesquisaPerecivelVencido(limite))
				{
					cout << "Foi encontrado produtos perecíveis perto do vencimento com limite de " << limite << " dias." << endl;
					int aux;
					
					cout << "Deseja Remover os produtos perecíveis já vencidos da lista?" << endl;
					cout << "1 - sim;" << endl;
					cout << "2 - não" << endl;
					cout << "Digite sua opção: ";
					cin >> aux;
					
					if(aux == 1)
					{
						estoque.removerProdutosPereciveisVencidos();
					} 
					else if(aux != 1 || aux != 2)
					{
						cout << "Entrada inválidade. Tente novamente." << endl;
					}
					else
					{
						cout << "Produtos vencidos mantidos." << endl;
					}
				}
				else
				{
					cout << "Todos os produtos estão com a validade em dia." << endl;
				}
				break;
			}
			case 2:
			{
				cout << "Informe o limite de validade em dias a ser pesquisado: ";
				cin >> limite;
				if(estoque.pesquisaRemedioVencido(limite))
				{
					cout << "Foi encontrado remédios perto do vencimento com limite de " << limite << " dias." << endl;
					int aux;
					
					cout << "Deseja Remover os remédios já vencidos da lista?" << endl;
					cout << "1 - sim;" << endl;
					cout << "2 - não" << endl;
					cout << "Digite sua opção: ";
					cin >> aux;
					
					if(aux == 1)
					{
						estoque.removerRemediosVencidos();
					} 
					else if(aux != 1 || aux != 2)
					{
						cout << "Entrada inválidade. Tente novamente." << endl;
					}
					else
					{
						cout << "Remédios vencidos mantidos." << endl;
					}
				}
				else
				{
					cout << "Todos os Remédios estão com a validade em dia." << endl;
				}
				break;
			}
			default:
				cout << "Opção Inválida. Tente novamente." << endl;
			}
			break;
		}
		case 6:
		{
			int escolha;
			
			
			cout << "=== Escolha o tipo de pesquisa a ser realizada === :" << endl << endl;
			cout << "1 - Pesquisa por código de barras;" << endl;
			cout << "2 - Pesquisa por nome do produto;" << endl;
			cout << "Opção: ";
			cin >> escolha;
			
			cout << endl;
			system("pause");
			system("cls");
			
			switch(escolha)
			{
			case 1:
			{
				int escolha;
				long int codigo;
			
				cout << "=== Escolha o departamento a ter o produto pesquisado === :" << endl << endl;
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
					cout << "Informe o código de barras do produto a ser pesquisado: ";
					cin >> codigo;
					
					if(estoque.pesquisarProduto(codigo))
					{
						cout << endl;
						cout << "Produtos acima pertencem ao estoque." << endl;
					}
					else
					{
						cout << endl;
						cout << "Sem ocorrências de produtos com esse código no estoque." << endl;
					}
					break;
				}
				case 2:
				{
					cout << "Informe o código de barras do produto perecível a ser pesquisado: ";
					cin >> codigo;
					
					if(estoque.pesquisarProdutoPerecivel(codigo))
					{
						cout << endl;
						cout << "Produtos perecíveis acima pertencem ao estoque." << endl;
					}
					else
					{
						cout << endl;
						cout << "Sem ocorrências de produtos perecíveis com esse código no estoque." << endl;
					}
					break;
				}
				case 3:
				{
					cout << "Informe o código de barras do remédio a ser pesquisado: ";
					cin >> codigo;
					
					if(estoque.pesquisarRemedio(codigo))
					{
						cout << endl;
						cout << "Remédios acima pertencem ao estoque." << endl;
					}
					else
					{
						cout << endl;
						cout << "Sem ocorrências de remédios com esse código no estoque." << endl;
					}
					break;
				}
				default:
				{
					cout << "Opção Inválida. Tente novamente." << endl;
				}
				}
				break;
			}
			case 2:
			{
				int escolha;
				string nome;
			
				cout << "=== Escolha o departamento a ter o produto pesquisado === :" << endl << endl;
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
					cout << "Informe o nome do produto a ser pesquisado: ";
					cin.ignore();
					getline(cin, nome);
					
					if(estoque.pesquisarProduto(nome))
					{
						cout << endl;
						cout << "Produtos acima pertencem ao estoque." << endl;
					}
					else
					{
						cout << endl;
						cout << "Sem ocorrências de produtos com esse código no estoque." << endl;
					}
					break;
				}
				case 2:
				{
					cout << "Informe o nome do produto perecível a ser pesquisado: ";
					cin.ignore();
					getline(cin, nome);
					
					if(estoque.pesquisarProdutoPerecivel(nome))
					{
						cout << endl;
						cout << "Produtos perecíveis acima pertencem ao estoque." << endl;
					}
					else
					{
						cout << endl;
						cout << "Sem ocorrências de produtos perecíveis com esse código no estoque." << endl;
					}
					break;
				}
				case 3:
				{
					cout << "Informe o nome do remédio a ser pesquisado: ";
					cin.ignore();
					getline(cin, nome);
					
					if(estoque.pesquisarRemedio(nome))
					{
						cout << endl;
						cout << "Remédios acima pertencem ao estoque." << endl;
					}
					else
					{
						cout << endl;
						cout << "Sem ocorrências de remédios com esse código no estoque." << endl;
					}
					break;
				}
				default:
				{
					cout << "Opção Inválida. Tente novamente." << endl;
				}
				}
				break;
			}
			default:
				{
					cout << "Opção Inválida. Tente novamente." << endl;
				}
			}
			break;
		}
		case 7:
		{
				int escolha;
			
				cout << "=== Escolha o departamento para ter seus dados ordenados === :" << endl << endl;
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
					cout << "=== Escolha o tipo de ordenação === :" << endl << endl;
					cout << "1 - Ordenar por preço de venda do produto;" << endl;
					cout << "2 - Ordenar por nome do produto;" << endl;
					cout << "3 - Ordenar por fabricante;" << endl;
					cout << "4 - Ordenar por quantidade em estoque;" << endl << endl;
					cout << "Opção: ";
					cin >> escolha;
					
					cout << endl;
					system("pause");
					system("cls");
					
					switch(escolha)
					{
					case 1:
					{
						estoque.ordenaProdutoPrecoVenda();
						estoque.imprimirProduto();
						break;
					}
					case 2:
					{
						estoque.ordenaProdutoNome();
						estoque.imprimirProduto();
						break;
					}
					case 3:
					{
						estoque.ordenaProdutoFabricante();
						estoque.imprimirProduto();
						break;
					}
					case 4:
					{
						estoque.ordenaProdutoEstoque();
						estoque.imprimirProduto();
						break;
					}
					default:
						cout << "Opção Inválida. Tente novamente." << endl;
					}
					break;
				}
				case 2:
				{
					cout << "=== Escolha o tipo de ordenação === :" << endl << endl;
					cout << "1 - Ordenar por preço de venda do produto;" << endl;
					cout << "2 - Ordenar por nome do produto;" << endl;
					cout << "3 - Ordenar por fabricante;" << endl;
					cout << "4 - Ordenar por quantidade em estoque;" << endl << endl;
					cout << "Opção: ";
					cin >> escolha;
					
					cout << endl;
					system("pause");
					system("cls");
					
					switch(escolha)
					{
					case 1:
					{
						estoque.ordenaPerecivelPrecoVenda();
						estoque.imprimirProdutoPerecivel();
						break;
					}
					case 2:
					{
						estoque.ordenaPerecivelNome();
						estoque.imprimirProdutoPerecivel();
						break;
					}
					case 3:
					{
						estoque.ordenaPerecivelFabricante();
						estoque.imprimirProdutoPerecivel();
						break;
					}
					case 4:
					{
						estoque.ordenaPerecivelEstoque();
						estoque.imprimirProdutoPerecivel();
						break;
					}
					default:
						cout << "Opção Inválida. Tente novamente." << endl;
					}
					break;
				}
				case 3:
				{
					cout << "=== Escolha o tipo de ordenação === :" << endl << endl;
					cout << "1 - Ordenar por preço de venda do produto;" << endl;
					cout << "2 - Ordenar por nome do produto;" << endl;
					cout << "3 - Ordenar por fabricante;" << endl;
					cout << "4 - Ordenar por quantidade em estoque;" << endl;
					cout << "5 - Ordenar por tarja;" << endl << endl;
					cout << "Opção: ";
					cin >> escolha;
					
					cout << endl;
					system("pause");
					system("cls");
					
					switch(escolha)
					{
					case 1:
					{
						estoque.ordenaRemedioPrecoVenda();
						estoque.imprimirRemedio();
						break;
					}
					case 2:
					{
						estoque.ordenaRemedioNome();
						estoque.imprimirRemedio();
						break;
					}
					case 3:
					{
						estoque.ordenaRemedioFabricante();
						estoque.imprimirRemedio();
						break;
					}
					case 4:
					{
						estoque.ordenaRemedioEstoque();
						estoque.imprimirRemedio();
						break;
					}
					case 5:
					{
						estoque.ordenaRemedioTarja();
						estoque.imprimirRemedio();
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
				break;
		}
		case 8:
		{
			cout << "Despezas atuais: " << estoque.get_despezas() << " R$" <<  endl;
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
