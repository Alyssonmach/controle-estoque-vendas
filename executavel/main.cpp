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
#include "../implementacoes/Funcionario.cpp"
#include "../implementacoes/ListaFuncionarios.cpp"
#include "../implementacoes/Estoque.cpp"
#include "../implementacoes/Vendas.cpp"

void controle_estoque(void);
void controle_vendas(void);

int main(void)
{
	setlocale(LC_ALL, "Portuguese");
	int escolha(1);
	
	ListaFuncionarios lista;
	Funcionario_Prototipo funcionario;
	Funcionario analisa_admin;
	
	while(escolha)
	{
		cout << "=== Gerencimento de Estoque e Vendas da Farmácia PharmaBem ===" << endl << endl;
	
		cout << "Escolha um ambiente de acesso: " << endl << endl;
		cout << "1 - Acessar Controle de Estoque;" << endl;
		cout << "2 - Acessar Controle de Vendas;" << endl;
		cout << "3 - Gerenciar Funcionários da Farmácia;" << endl;
		cout << "0 - Sair do Programa;" << endl << endl;
		
		cout << "Insira sua opção: ";
		cin >> escolha;
		
		cout << endl;
		system("pause");
		system("cls");
	
		switch(escolha)
		{
		case 0:
		{
			cout << "Programa encerrado com sucesso. Todos os processos foram salvos." << endl;
			break;
		}
		case 1:
		{
			cin.ignore();
			cout << "Login do funcionario: ";
			getline(cin, funcionario.login);
			cout << "Senha do funcionário: ";
			getline(cin, funcionario.senha);
					
			analisa_admin.set_login(funcionario.login);
			analisa_admin.set_senha(funcionario.senha);
					
			if(lista.valida_funcionarios_estoque(analisa_admin))
			{
				cout << endl;
				cout << "Funcionário registrado. Acesso Permitido" << endl;
				
				cout << endl;
				system("pause");
				system("cls");
				
				controle_estoque();
			}
			else
			{
				cout << endl;
				cout << "Funcionário não registrado. Acesso negado." << endl;
			}
			break;
		}
		case 2:
		{
			cin.ignore();
			cout << "Login do funcionario: ";
			getline(cin, funcionario.login);
			cout << "Senha do funcionário: ";
			getline(cin, funcionario.senha);
					
			analisa_admin.set_login(funcionario.login);
			analisa_admin.set_senha(funcionario.senha);
					
			if(lista.valida_funcionarios_vendas(analisa_admin))
			{
				cout << endl;
				cout << "Funcionário registrado. Acesso Permitido" << endl;
				
				cout << endl;
				system("pause");
				system("cls");
				
				controle_vendas();
			}
			else
			{
				cout << endl;
				cout << "Funcionário não registrado. Acesso negado." << endl;
			}
			break;
		}
		case 3:
		{
			cin.ignore();
			cout << "Para acessar essa página, entre com o cadastro do administrador." << endl << endl;
			cout << "Login do administrador: ";
			getline(cin, funcionario.login);
			cout << "Senha do administrador: ";
			getline(cin, funcionario.senha);
			
			if(analisa_admin.valida_key(funcionario))
			{
				cout << endl;
				cout << "Acesso permitido." << endl;
				
				cout << endl;
				system("pause");
				system("cls");
				
				while(escolha)
				{
					cout << "=== Gestão dos Funcionários da Farmácia ===" << endl << endl;
					cout << "1 - Inserir um novo funcionário;" << endl;
					cout << "2 - Imprimir lista de funcionarios;" << endl;
					cout << "3 - Pesquisar funcionários;" << endl;
					cout << "4 - Ordenar lista de funcionarios;" << endl;
					cout << "5 - Remover Funcionário por CPF;" << endl;
					cout << "6 - Testar Validação das senhas dos funcionarios;" << endl;
					cout << "0 - Sair da Gestão de Funcionários;" << endl << endl;
					cout << "Insira uma opção: ";
					cin >> escolha;
					
					cout << endl;
					system("pause");
					system("cls");
					
					switch(escolha)
					{
					case 0:
					{
						cout << "Voltando para o menu principal." << endl;
						break;
					}
					case 1:
					{
						cout << "Nome do Funcionário: ";
						cin.ignore();
						getline(cin, funcionario.nome);
						cout << "CPF do Funcionário: ";
						getline(cin, funcionario.cpf);
						cout << "ID do Funcionário: ";
						cin >> funcionario.id;
						cin.ignore();
						cout << "Cargo do Funcionário: ";
						getline(cin, funcionario.cargo);
						cout << "Defina um login para o Funcionário: ";
						getline(cin, funcionario.login);
						cout << "Defina uma senha para Funcionário: ";
						getline(cin, funcionario.senha);
						
						cout << endl;
						if(lista.pesquisar_funcionario_cpf(funcionario.cpf))
						{
							cout << endl;
							cout << "Funcionário já cadastrado. Tente novamente." << endl;
						}
						else
						{
							analisa_admin.set_objeto(funcionario);
							lista.inserir_funcionario(analisa_admin);
							cout << "Funcionário cadatrado com sucesso." << endl;
						}
						break;
					}
					case 2:
					{
						cout << "=== Lista de Funcionários ===" << endl << endl;
						lista.imprimir_funcionarios();
						break;
					}
					case 3:
					{
						cout << "Informe o CPF do funcionário: ";
						cin.ignore();
						getline(cin, funcionario.cpf);
						cout << endl << endl;
						cout << "Busca por: " << funcionario.cpf << ":" << endl << endl;
						if(lista.pesquisar_funcionario_cpf(funcionario.cpf))
						{
							cout << endl;
							cout << "Funcionário encontrado." << endl;
						}
						else
						{
							cout << "Funcionário não encontrado." << endl;
						}
						break;
					}
					case 4:
					{
						cout << "=== Escolha o tipo de ordenação ===" << endl << endl;
						cout << "1 - Ordenar por nome;" << endl;
						cout << "2 - Ordenar por CPF;" << endl;
						cout << "3 - Ordenar por ID;" << endl;
						cout << "4 - Ordenar por Cargo;" << endl;
						cout << "5 - Ordenar por Login;" << endl;
						cout << "6 - Ordenar por Senha;" << endl << endl;
						
						cout << "Insira sua opção: ";
						cin >> escolha;
						
						cout << endl;
						system("pause");
						system("cls");
						
						switch(escolha)
						{
						case 1:
						{
							lista.ordena_funcionario_nome();
							lista.imprimir_funcionarios();
							break;
						}
						case 2:
						{
							lista.ordena_funcionario_cpf();
							lista.imprimir_funcionarios();
							break;
						}
						case 3:
						{
							lista.ordena_funcionario_id();
							lista.imprimir_funcionarios();
							break;
						}
						case 4:
						{
							lista.ordena_funcionario_cargo();
							lista.imprimir_funcionarios();
							break;
						}
						case 5:
						{
							lista.ordena_funcionario_login();
							lista.imprimir_funcionarios();
							break;
						}
						case 6:
						{
							lista.ordena_funcionario_senha();
							lista.imprimir_funcionarios();
							break;
						}
						default:
							cout << "Tentativa incorreta. Tente novamente." << endl;
							break;
						}
						break;
					}
					case 5:
					{
						cout << "Informe o CPF do usuário: ";
						cin.ignore();
						getline(cin, funcionario.cpf);
						
						cout << endl;
						if(lista.pesquisar_funcionario_cpf(funcionario.cpf))
						{
							lista.remover_funcionario_cpf(funcionario.cpf);
							cout << endl;
							cout << "Funcionário Demitido." << endl;
						}
						else
						{
							cout << endl;
							cout << "Funcionário não encontrado. Tente novamente." << endl;
						}
						break;
					}
					case 6:
					{
						cout << " === Escolha o tipo de cadastro para análise ===" << endl << endl;
						cout << "1 - Cadastro de Estoque;" << endl;
						cout << "2 - Cadastro de Vendas;" << endl << endl;
						cout << "Insira sua opção: ";
						cin >> escolha;
						
						cout << endl;
						system("pause");
						system("cls");
						
						switch(escolha)
						{
						case 1:
						{
							cin.ignore();
							cout << "Login: ";
							getline(cin, funcionario.login);
							cout << "Senha: ";
							getline(cin, funcionario.senha);
							
							analisa_admin.set_login(funcionario.login);
							analisa_admin.set_senha(funcionario.senha);
							
							if(lista.valida_funcionarios_estoque(analisa_admin))
							{
								cout << endl;
								cout << "Funcionário registrado." << endl;
							}
							else
							{
								cout << endl;
								cout << "Funcionário não registrado." << endl;
							}
							break;
						}
						case 2:
						{
							cin.ignore();
							cout << "Login: ";
							getline(cin, funcionario.login);
							cout << "Senha: ";
							getline(cin, funcionario.senha);
							
							analisa_admin.set_login(funcionario.login);
							analisa_admin.set_senha(funcionario.senha);
							
							if(lista.valida_funcionarios_vendas(analisa_admin))
		                    {
								cout << endl;
								cout << "Funcionário registrado." << endl;
							}
							else
							{
								cout << endl;
								cout << "Funcionário não registrado." << endl;
							}
							break;
						}
						default:
							cout << "Tentativa incorreta. Tente novamente." << endl;
							break;
						}
						
						break;
					}
					default:
						cout << "Tentativa incorreta. Tente novamente." << endl;
						break;
					}
					
					if(escolha)
					{
						cout << endl;
						system("pause");
						system("cls");
					}
						
				}
			}
			else 
			{
				cout << endl;
				cout << "Login ou senha incorretos. Tente novamente." << endl;
			}
			
			escolha = 1;
			break;
		}
		default:
		{
			cout << "Entrada inválida. Por Favor tente novamente." << endl;
		}
		}
		
		cout << endl;
		system("pause");
		system("cls");
	}
	
	return 0;
}

void controle_estoque(void)
{
	Estoque estoque;
	Produto produto;
	ProdutoPerecivel perecivel;
	Remedio remedio;
	Produto_prototipo auxiliar_produto;
	Data vencimento;
	Drogaria informacoes_remedio;
	
	int escolha(1);
	
	while(escolha)
	{
		cout << "=== Controle de Estoque ===" << endl << endl;
		
		cout << "Escolha uma das ações a serem realizadas no estoque: " << endl << endl;
		cout << "1 - Inserir um novo produto ao estoque;" << endl;
		cout << "2 - Gerir quantidades de produto em estoque;" << endl;
		cout << "3 - Visualizar estoque;" << endl;
		cout << "4 - Remover produtos por código de barra;" << endl;
		cout << "5 - Fazer a gestão da validade dos produtos;" << endl;
		cout << "6 - Pesquisar sobre o produto;" << endl;
		cout << "7 - Ordenação de Estoque;" << endl;
		cout << "8 - Visualizar as depezas atuais;" << endl;
		cout << "0 - Voltar para o menu principal;" << endl << endl;
		cout << "Digite sua opção: ";
		cin >> escolha;
		
		cout << endl;
		system("pause");
		system("cls");
		
		switch(escolha)
		{
		case 0:
		{
			cout << "Voltando para o menu principal." << endl;
			break;
		}
		case 1:
		{
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
				cout << endl;
				if(estoque.pesquisarProduto(produto.get_objeto_produto().codigo))
				{
					cout << endl;
					cout << "Código já vinculado. Tente novamente." << endl;
				}
				else
				{
					estoque.inserirProduto(produto);
					cout << "Produto Cadastrado com sucesso." << endl;	
				}
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
				
				cout << endl;
				if(estoque.pesquisarProdutoPerecivel(perecivel.get_objeto_produto().codigo))
				{
					cout << endl;
					cout << "Código já vinculado. Tente novamente." << endl;
				}
				else
				{
					estoque.inserirProdutoPerecivel(perecivel);
					cout << "Produto Perecível Cadastrado com sucesso." << endl;
				}
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
				
				cout << endl;
				if(estoque.pesquisarRemedio(remedio.get_objeto_produto().codigo))
				{
					cout << endl;
					cout << "Código já vinculado. Tente novamente." << endl;		
				}
				else
				{
					estoque.inserirRemedio(remedio);
					cout << "Remédio Cadastrado com sucesso." << endl;
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
			int quantidade;
			long int codigo;
				
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
					int aux;
					
					cout << "Foi encontrado produtos perecíveis perto do vencimento com limite de " << limite << " dias." << endl;
					
					cout << endl;
					system("pause");
					system("cls");
					
					cout << "Deseja Remover os produtos perecíveis já vencidos da lista?" << endl;
					cout << "1 - sim;" << endl;
					cout << "2 - não" << endl;
					cout << "Digite sua opção: ";
					cin >> aux;
					
					if(aux == 1)
					{
						estoque.removerProdutosPereciveisVencidos();
					} 
					else if(aux == 2)
					{
						cout << "Produtos vencidos mantidos." << endl;
					}
					else
					{
						cout << "Entrada inválidade. Tente novamente." << endl;
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
					else if(aux == 2)
					{
						cout << "Remédios vencidos mantidos." << endl;	
					}
					else
					{
						cout << "Entrada inválidade. Tente novamente." << endl;
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
		
		if(escolha)
		{
			cout << endl;
			system("pause");
			system("cls");
		}
		
	}
	
	return;
}

void controle_vendas(void)
{
	Produto registro_produto;
	ProdutoPerecivel registro_perecivel;
	Remedio registro_remedio;
	Vendas processo_vendas;
	
	int escolha(1), quantidade;
	long int codigo;
	
	while(escolha)
	{
		
		cout << "=== Controle de Vendas da Farmácia ===" << endl << endl;
	
		cout << "1 - Registrar Compras;" << endl;
		cout << "2 - Análise de Notas Fiscais;" << endl;
		cout << "3 - Visualizar a parte financeira da farmácia;" << endl; 
		cout << "0 - Voltar para o Menu Principal;" << endl << endl; 
		
		cout << "Insira uma opção: ";
		cin >> escolha;
		
		cout << endl;
		system("pause");
		system("cls");
	
		switch(escolha)
		{
			case 0:
			{
				cout << "Voltando para o menu principal." << endl;
				break;
			}
			case 1:
			{	
				while(escolha)
				{
					cout << "=== Escolha o tipo de produto a ser registrado ===" << endl << endl;
					cout << "1 - Departamento de Produtos Perecíveis;" << endl;
					cout << "2 - Departamento de Produtos Perecíveis;" << endl;
					cout << "3 - Departamento de Remédios;" << endl;
					cout << "4 - Remover itens da compra;" << endl;
					cout << "0 - Montar nota fiscal;" << endl << endl;
					
					cout << "insira sua opção: ";
					cin >> escolha;
					
					cout << endl;
					system("pause");
					system("cls");
					
					switch(escolha)
					{
						case 0:
						{
							cout << "Nota Fiscal montada com sucesso!" << endl;
							processo_vendas.monta_nota_fiscal();
							break;
						}
						case 1:
						{
							cout << "Insira o código de barras do produto não perecível: ";
							cin >> codigo;
							cout << endl;
							
							if(processo_vendas.pesquisarProduto(codigo))
							{
								cout << endl;
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
							cout << endl;
							
							if(processo_vendas.pesquisarProdutoPerecivel(codigo))
							{
								cout << endl;
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
							cout << endl;
							
							if(processo_vendas.pesquisarRemedio(codigo))
							{
								cout << endl;
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
						case 4:
						{
							cout << "=== De qual departamento você deseja remover o produto? ===" << endl << endl;
							cout << "1 - Departamento de produtos não perecíveis;" << endl;
							cout << "2 - Departamento de produtos perecíveis;" << endl;
							cout << "3 - Departamento de remédios;" << endl;
							cout << "0 - Cancelar operação;" << endl << endl;
							
							cout << "Digite sua opção: ";
							cin >> escolha;
							
							cout << endl;
							system("pause");
							system("cls");
							
							switch(escolha)
							{
                            case 0:
							{
								cout << "Operação cancelada." << endl;
								break;
							}
							case 1:
							{
								cout << "Informe o código do produto não perecível a ser removido da nota: ";
								cin >> codigo;
								cout << endl;
								
								if(processo_vendas.pesquisar_nota_produto(codigo))
								{
									cout << endl;
									cout << "Produto encontrado." << endl;
									
									cout << endl;
									system("pause");
									system("cls");
									
									processo_vendas.apaga_da_nota_produto(codigo);
									processo_vendas.set_entrada_estoque_produto(codigo, 1);
									cout << endl;
									cout << "Produto removido da nota fiscal." << endl;
								}
								else
								{
									cout << "Produto não encontrado." << endl;
								}
								break;
							}
							case 2:
							{
								cout << "Informe o código do produto perecível a ser removido da nota: ";
								cin >> codigo;
								
								if(processo_vendas.pesquisar_nota_perecivel(codigo))
								{
									cout << endl;
									cout << "Produto perecível encontrado." << endl;
									
									cout << endl;
									system("pause");
									system("cls");
									
									processo_vendas.apaga_da_nota_perecivel(codigo);
									processo_vendas.set_entrada_estoque_perecivel(codigo, 1);
									cout << endl;
									cout << "Produto perecível removido da nota fiscal." << endl;
								}
								else
								{
									cout << "Produto perecível não encontrado." << endl;
								}
								
								break;
							}
							case 3:
							{
								cout << "Informe o código do remédio a ser removido da nota: ";
								cin >> codigo;
								
								if(processo_vendas.pesquisar_nota_remedio(codigo))
								{
									cout << endl;
									cout << "Remédio encontrado." << endl;
									
									cout << endl;
									system("pause");
									system("cls");
									
									processo_vendas.apaga_da_nota_remedio(codigo);
									processo_vendas.set_entrada_estoque_remedio(codigo, 1);
									cout << endl;
									cout << "Remédio removido da nota fiscal." << endl;
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
							break;
						}
						
					cout << endl;
					system("pause");
					system("cls");
				}
				escolha = 1;
				break;
			}
			case 2:
			{
				cout << "=== Escolha uma opçõa de visualização das notas fiscais ===" << endl << endl;
				cout << "1 - Visualizar histórico de notas fiscais;" << endl;
				cout << "2 - Limpar histório de notas fiscais;" << endl;
				cout << "3 - Restaurar histórico de notas fiscais;" << endl;
				cout << "4 - Visualizar últimais notas fiscais;" << endl << endl;
				
				cout << "Insira sua opção: ";
				cin >> escolha;
				
				cout << endl;
				system("pause");
				system("cls");
				
				switch(escolha)
				{
				case 1:
				{
					cout << "=== Registro de notas fiscais ===" << endl << endl;
					processo_vendas.imprime_historico_fiscal();
					break;
				}
				case 2:
				{
					processo_vendas.limpa_historico_notas();
					cout << "Histórico de notas fiscais apagados." << endl;
					break;
				}
				case 3:
				{
					processo_vendas.restaura_historico_notas();
					cout << "Histórico de notas fiscais restaurada." << endl;
					break;
				}
				case 4:
				{
					cout << "Informe a quantidade de notas a serem pesquisadas: ";
					cin >> quantidade;
					
					cout << endl;
					system("pause");
					system("cls");
					
					cout << "=== Registro de notas fiscais ===" << endl << endl;
					processo_vendas.imprime_ultimas_notas(quantidade);
					break;
				}
				default:
					cout << "Opção inválida. Tente novamente" << endl;
					break;
				}
				
					cout << endl;
					system("pause");
					system("cls");
					
				break;
			}
			case 3:
			{
				cout << "=== Análise Fiscal da Empresa ===" << endl;
				cout << "1 - Visualizar o saldo mensal da empresa;" << endl;
				cout << "2 - Visualizar o apurado mensal da empresa;" << endl;
				cout << "3 - Visualizar a despeza mensal da empresa;" << endl;
				cout << "4 - Finalizar as contas do mês;" << endl << endl;
				cout << "Escolha uma opção: ";
				cin >> escolha;
				
				cout << endl;
				system("pause");
				system("cls");
				
				switch(escolha)
				{
				case 1:
				{
					cout << "Saldo mensal: " << processo_vendas.get_saldo() << " R$" << endl;
					break;
				}
				case 2:
				{
					cout << "Apurado mensal: " << processo_vendas.get_apurado() << " R$" << endl;
					break;
				}
				case 3:
				{
					cout << "Despeza mensal: " << processo_vendas.get_despezas() << " R$" << endl;
					break;
				}
				case 4:
				{
					processo_vendas.fecha_conta_mes();
					cout << "As contas do mês foram encerrados. Reiniciando uma nova análise." << endl;
					break;
				}
				default:
					cout << "Opção inválida. Tente novamente." << endl;
					break;
				}
				
				cout << endl;
				system("pause");
				system("cls");
				
				break;
			}
			default:
				cout << "Opção inválida. Tente novamente." << endl;
		}
	}
	
	return;
}