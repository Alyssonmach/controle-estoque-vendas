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
		cout << "=== Gerencimento de Estoque e Vendas da Farm�cia PharmaBem ===" << endl << endl;
	
		cout << "Escolha um ambiente de acesso: " << endl << endl;
		cout << "1 - Acessar Controle de Estoque;" << endl;
		cout << "2 - Acessar Controle de Vendas;" << endl;
		cout << "3 - Gerenciar Funcion�rios da Farm�cia;" << endl;
		cout << "0 - Sair do Programa;" << endl << endl;
		
		cout << "Insira sua op��o: ";
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
			cout << "Senha do funcion�rio: ";
			getline(cin, funcionario.senha);
					
			analisa_admin.set_login(funcionario.login);
			analisa_admin.set_senha(funcionario.senha);
					
			if(lista.valida_funcionarios_estoque(analisa_admin))
			{
				cout << endl;
				cout << "Funcion�rio registrado. Acesso Permitido" << endl;
				
				cout << endl;
				system("pause");
				system("cls");
				
				controle_estoque();
			}
			else
			{
				cout << endl;
				cout << "Funcion�rio n�o registrado. Acesso negado." << endl;
			}
			break;
		}
		case 2:
		{
			cin.ignore();
			cout << "Login do funcionario: ";
			getline(cin, funcionario.login);
			cout << "Senha do funcion�rio: ";
			getline(cin, funcionario.senha);
					
			analisa_admin.set_login(funcionario.login);
			analisa_admin.set_senha(funcionario.senha);
					
			if(lista.valida_funcionarios_vendas(analisa_admin))
			{
				cout << endl;
				cout << "Funcion�rio registrado. Acesso Permitido" << endl;
				
				cout << endl;
				system("pause");
				system("cls");
				
				controle_vendas();
			}
			else
			{
				cout << endl;
				cout << "Funcion�rio n�o registrado. Acesso negado." << endl;
			}
			break;
		}
		case 3:
		{
			cin.ignore();
			cout << "Para acessar essa p�gina, entre com o cadastro do administrador." << endl << endl;
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
					cout << "=== Gest�o dos Funcion�rios da Farm�cia ===" << endl << endl;
					cout << "1 - Inserir um novo funcion�rio;" << endl;
					cout << "2 - Imprimir lista de funcionarios;" << endl;
					cout << "3 - Pesquisar funcion�rios;" << endl;
					cout << "4 - Ordenar lista de funcionarios;" << endl;
					cout << "5 - Remover Funcion�rio por CPF;" << endl;
					cout << "6 - Testar Valida��o das senhas dos funcionarios;" << endl;
					cout << "0 - Sair da Gest�o de Funcion�rios;" << endl << endl;
					cout << "Insira uma op��o: ";
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
						cout << "Nome do Funcion�rio: ";
						cin.ignore();
						getline(cin, funcionario.nome);
						cout << "CPF do Funcion�rio: ";
						getline(cin, funcionario.cpf);
						cout << "ID do Funcion�rio: ";
						cin >> funcionario.id;
						cin.ignore();
						cout << "Cargo do Funcion�rio: ";
						getline(cin, funcionario.cargo);
						cout << "Defina um login para o Funcion�rio: ";
						getline(cin, funcionario.login);
						cout << "Defina uma senha para Funcion�rio: ";
						getline(cin, funcionario.senha);
						
						cout << endl;
						if(lista.pesquisar_funcionario_cpf(funcionario.cpf))
						{
							cout << endl;
							cout << "Funcion�rio j� cadastrado. Tente novamente." << endl;
						}
						else
						{
							analisa_admin.set_objeto(funcionario);
							lista.inserir_funcionario(analisa_admin);
							cout << "Funcion�rio cadatrado com sucesso." << endl;
						}
						break;
					}
					case 2:
					{
						cout << "=== Lista de Funcion�rios ===" << endl << endl;
						lista.imprimir_funcionarios();
						break;
					}
					case 3:
					{
						cout << "Informe o CPF do funcion�rio: ";
						cin.ignore();
						getline(cin, funcionario.cpf);
						cout << endl << endl;
						cout << "Busca por: " << funcionario.cpf << ":" << endl << endl;
						if(lista.pesquisar_funcionario_cpf(funcionario.cpf))
						{
							cout << endl;
							cout << "Funcion�rio encontrado." << endl;
						}
						else
						{
							cout << "Funcion�rio n�o encontrado." << endl;
						}
						break;
					}
					case 4:
					{
						cout << "=== Escolha o tipo de ordena��o ===" << endl << endl;
						cout << "1 - Ordenar por nome;" << endl;
						cout << "2 - Ordenar por CPF;" << endl;
						cout << "3 - Ordenar por ID;" << endl;
						cout << "4 - Ordenar por Cargo;" << endl;
						cout << "5 - Ordenar por Login;" << endl;
						cout << "6 - Ordenar por Senha;" << endl << endl;
						
						cout << "Insira sua op��o: ";
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
						cout << "Informe o CPF do usu�rio: ";
						cin.ignore();
						getline(cin, funcionario.cpf);
						
						cout << endl;
						if(lista.pesquisar_funcionario_cpf(funcionario.cpf))
						{
							lista.remover_funcionario_cpf(funcionario.cpf);
							cout << endl;
							cout << "Funcion�rio Demitido." << endl;
						}
						else
						{
							cout << endl;
							cout << "Funcion�rio n�o encontrado. Tente novamente." << endl;
						}
						break;
					}
					case 6:
					{
						cout << " === Escolha o tipo de cadastro para an�lise ===" << endl << endl;
						cout << "1 - Cadastro de Estoque;" << endl;
						cout << "2 - Cadastro de Vendas;" << endl << endl;
						cout << "Insira sua op��o: ";
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
								cout << "Funcion�rio registrado." << endl;
							}
							else
							{
								cout << endl;
								cout << "Funcion�rio n�o registrado." << endl;
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
								cout << "Funcion�rio registrado." << endl;
							}
							else
							{
								cout << endl;
								cout << "Funcion�rio n�o registrado." << endl;
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
			cout << "Entrada inv�lida. Por Favor tente novamente." << endl;
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
		
		cout << "Escolha uma das a��es a serem realizadas no estoque: " << endl << endl;
		cout << "1 - Inserir um novo produto ao estoque;" << endl;
		cout << "2 - Gerir quantidades de produto em estoque;" << endl;
		cout << "3 - Visualizar estoque;" << endl;
		cout << "4 - Remover produtos por c�digo de barra;" << endl;
		cout << "5 - Fazer a gest�o da validade dos produtos;" << endl;
		cout << "6 - Pesquisar sobre o produto;" << endl;
		cout << "7 - Ordena��o de Estoque;" << endl;
		cout << "8 - Visualizar as depezas atuais;" << endl;
		cout << "0 - Voltar para o menu principal;" << endl << endl;
		cout << "Digite sua op��o: ";
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
				cout << endl;
				if(estoque.pesquisarProduto(produto.get_objeto_produto().codigo))
				{
					cout << endl;
					cout << "C�digo j� vinculado. Tente novamente." << endl;
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
				
				cout << endl;
				if(estoque.pesquisarProdutoPerecivel(perecivel.get_objeto_produto().codigo))
				{
					cout << endl;
					cout << "C�digo j� vinculado. Tente novamente." << endl;
				}
				else
				{
					estoque.inserirProdutoPerecivel(perecivel);
					cout << "Produto Perec�vel Cadastrado com sucesso." << endl;
				}
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
				
				cout << endl;
				if(estoque.pesquisarRemedio(remedio.get_objeto_produto().codigo))
				{
					cout << endl;
					cout << "C�digo j� vinculado. Tente novamente." << endl;		
				}
				else
				{
					estoque.inserirRemedio(remedio);
					cout << "Rem�dio Cadastrado com sucesso." << endl;
				}
				break;
			}
			default:
				cout << "Op��o Inv�lida. Tente novamente." << endl;
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
			cout << "Op��o: ";
			cin >> escolha;
			
			cout << endl;
			system("pause");
			system("cls");
			
			switch(escolha)
			{
			case 1:
			{	
				cout << "=== Escolha o departamento a ter itens adicionados === :" << endl << endl;
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
					cout << "Informe o c�digo de barras do produto a ser aumentado no estoque: ";
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
						cout << "Opera��o n�o realizada. Tente Novamete." << endl;
					}
					break;
				}
				case 2:
				{
					cout << "Informe o c�digo de barras do produto perec�vel a ser aumentado no estoque: ";
					cin >> codigo;
					cout << "Informe a quantidade de aumento:";
					cin >> quantidade;
					
					cout << "Pesquisando..." << endl << endl;
					if(estoque.set_entrada_estoque_perecivel(codigo, quantidade))
					{
						cout << endl;
						cout << "Produtos perec�veis adicionados com sucesso." << endl;
					}
					else
					{
						cout << "Opera��o n�o realizada. Tente Novamete." << endl;
					}
					break;
				}
				case 3:
				{
					cout << "Informe o c�digo de barras do rem�dio a ser aumentado no estoque: ";
					cin >> codigo;
					cout << "Informe a quantidade de aumento:";
					cin >> quantidade;
					
					cout << "Pesquisando..." << endl << endl;
					if(estoque.set_entrada_estoque_remedio(codigo, quantidade))
					{
						cout << endl;
						cout << "Rem�dios adicionados com sucesso." << endl;
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
			case 2:
			{
				cout << "=== Escolha o departamento a ter itens adicionados === :" << endl << endl;
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
					cout << "Informe o c�digo de barras do produto a ser diminuido no estoque: ";
					cin >> codigo;
					cout << "Informe a quantidade de diminui��o: ";
					cin >> quantidade;
					
					cout << "Pesquisando..." << endl << endl;
					if(estoque.set_saida_estoque_produto(codigo, quantidade))
					{
						cout << endl;
						cout << "Produtos removidos com sucesso." << endl;
					}
					else
					{
						cout << "Opera��o n�o realizada. Tente Novamete." << endl;
					}
					break;
				}
				case 2:
				{
					cout << "Informe o c�digo de barras do produto perec�vel a ser diminuido no estoque: ";
					cin >> codigo;
					cout << "Informe a quantidade de diminui��o: ";
					cin >> quantidade;
					
					cout << "Pesquisando..." << endl << endl;
					if(estoque.set_saida_estoque_perecivel(codigo, quantidade))
					{
						cout << endl;
						cout << "Produtos perec�veis removidos com sucesso." << endl;
					}
					else
					{
						cout << "Opera��o n�o realizada. Tente Novamete." << endl;
					}
					break;
				}
				case 3:
				{
					cout << "Informe o c�digo de barras do rem�dio a ser aumentado no diminuido: ";
					cin >> codigo;
					cout << "Informe a quantidade de diminui��o:";
					cin >> quantidade;
					
					cout << "Pesquisando..." << endl << endl;
					if(estoque.set_saida_estoque_remedio(codigo, quantidade))
					{
						cout << endl;
						cout << "Rem�dios removidos com sucesso." << endl;
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
			
			break;
		}
		case 3:
		{
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
		case 4:
		{
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
				
				cout << "Produtos Encontrados: " << endl << endl;
				if(estoque.pesquisarProduto(codigo))
				{
					cout << endl;
					cout << "Processando remo��o..." << endl;
				}
				
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
				
				cout << "Produtos Encontrados: " << endl << endl;
				if(estoque.pesquisarProdutoPerecivel(codigo))
				{
					cout << endl;
					cout << "Processando remo��o..." << endl;
				}
				
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
				cout << "Informe o c�digo de barras do rem�dio a ser removido: ";
				cin >> codigo;
				
				cout << "Produtos Encontrados: " << endl << endl;
				if(estoque.pesquisarProduto(codigo))
				{
					cout << endl;
					cout << "Processando remo��o..." << endl;
				}
				
				if(estoque.removerRemedio(codigo))
				{
					cout << "Rem�dio removido com sucesso." << endl;
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
		case 5:
		{
			int limite;
			
			cout << "=== Escolha o departamento para analisar validade dos produtos === :" << endl << endl;
			cout << "1 - Departamento de produtos perec�veis;" << endl;
			cout << "2 - Departamento de rem�dios;" << endl << endl;
			cout << "Op��o: ";
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
					
					cout << "Foi encontrado produtos perec�veis perto do vencimento com limite de " << limite << " dias." << endl;
					
					cout << endl;
					system("pause");
					system("cls");
					
					cout << "Deseja Remover os produtos perec�veis j� vencidos da lista?" << endl;
					cout << "1 - sim;" << endl;
					cout << "2 - n�o" << endl;
					cout << "Digite sua op��o: ";
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
						cout << "Entrada inv�lidade. Tente novamente." << endl;
					}
				}
				else
				{
					cout << "Todos os produtos est�o com a validade em dia." << endl;
				}
				break;
			}
			case 2:
			{
				cout << "Informe o limite de validade em dias a ser pesquisado: ";
				cin >> limite;
				if(estoque.pesquisaRemedioVencido(limite))
				{
					cout << "Foi encontrado rem�dios perto do vencimento com limite de " << limite << " dias." << endl;
					int aux;
					
					cout << "Deseja Remover os rem�dios j� vencidos da lista?" << endl;
					cout << "1 - sim;" << endl;
					cout << "2 - n�o" << endl;
					cout << "Digite sua op��o: ";
					cin >> aux;
					
					if(aux == 1)
					{
						estoque.removerRemediosVencidos();
					} 
					else if(aux == 2)
					{
						cout << "Rem�dios vencidos mantidos." << endl;	
					}
					else
					{
						cout << "Entrada inv�lidade. Tente novamente." << endl;
					}
				}
				else
				{
					cout << "Todos os Rem�dios est�o com a validade em dia." << endl;
				}
				break;
			}
			default:
				cout << "Op��o Inv�lida. Tente novamente." << endl;
			}
			break;
		}
		case 6:
		{
			cout << "=== Escolha o tipo de pesquisa a ser realizada === :" << endl << endl;
			cout << "1 - Pesquisa por c�digo de barras;" << endl;
			cout << "2 - Pesquisa por nome do produto;" << endl;
			cout << "Op��o: ";
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
					cout << "Informe o c�digo de barras do produto a ser pesquisado: ";
					cin >> codigo;
					
					if(estoque.pesquisarProduto(codigo))
					{
						cout << endl;
						cout << "Produtos acima pertencem ao estoque." << endl;
					}
					else
					{
						cout << endl;
						cout << "Sem ocorr�ncias de produtos com esse c�digo no estoque." << endl;
					}
					break;
				}
				case 2:
				{
					cout << "Informe o c�digo de barras do produto perec�vel a ser pesquisado: ";
					cin >> codigo;
					
					if(estoque.pesquisarProdutoPerecivel(codigo))
					{
						cout << endl;
						cout << "Produtos perec�veis acima pertencem ao estoque." << endl;
					}
					else
					{
						cout << endl;
						cout << "Sem ocorr�ncias de produtos perec�veis com esse c�digo no estoque." << endl;
					}
					break;
				}
				case 3:
				{
					cout << "Informe o c�digo de barras do rem�dio a ser pesquisado: ";
					cin >> codigo;
					
					if(estoque.pesquisarRemedio(codigo))
					{
						cout << endl;
						cout << "Rem�dios acima pertencem ao estoque." << endl;
					}
					else
					{
						cout << endl;
						cout << "Sem ocorr�ncias de rem�dios com esse c�digo no estoque." << endl;
					}
					break;
				}
				default:
				{
					cout << "Op��o Inv�lida. Tente novamente." << endl;
				}
				}
				break;
			}
			case 2:
			{
				string nome;
			
				cout << "=== Escolha o departamento a ter o produto pesquisado === :" << endl << endl;
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
						cout << "Sem ocorr�ncias de produtos com esse c�digo no estoque." << endl;
					}
					break;
				}
				case 2:
				{
					cout << "Informe o nome do produto perec�vel a ser pesquisado: ";
					cin.ignore();
					getline(cin, nome);
					
					if(estoque.pesquisarProdutoPerecivel(nome))
					{
						cout << endl;
						cout << "Produtos perec�veis acima pertencem ao estoque." << endl;
					}
					else
					{
						cout << endl;
						cout << "Sem ocorr�ncias de produtos perec�veis com esse c�digo no estoque." << endl;
					}
					break;
				}
				case 3:
				{
					cout << "Informe o nome do rem�dio a ser pesquisado: ";
					cin.ignore();
					getline(cin, nome);
					
					if(estoque.pesquisarRemedio(nome))
					{
						cout << endl;
						cout << "Rem�dios acima pertencem ao estoque." << endl;
					}
					else
					{
						cout << endl;
						cout << "Sem ocorr�ncias de rem�dios com esse c�digo no estoque." << endl;
					}
					break;
				}
				default:
				{
					cout << "Op��o Inv�lida. Tente novamente." << endl;
				}
				}
				break;
			}
			default:
				{
					cout << "Op��o Inv�lida. Tente novamente." << endl;
				}
			}
			break;
		}
		case 7:
		{
				cout << "=== Escolha o departamento para ter seus dados ordenados === :" << endl << endl;
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
					cout << "=== Escolha o tipo de ordena��o === :" << endl << endl;
					cout << "1 - Ordenar por pre�o de venda do produto;" << endl;
					cout << "2 - Ordenar por nome do produto;" << endl;
					cout << "3 - Ordenar por fabricante;" << endl;
					cout << "4 - Ordenar por quantidade em estoque;" << endl << endl;
					cout << "Op��o: ";
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
						cout << "Op��o Inv�lida. Tente novamente." << endl;
					}
					break;
				}
				case 2:
				{
					cout << "=== Escolha o tipo de ordena��o === :" << endl << endl;
					cout << "1 - Ordenar por pre�o de venda do produto;" << endl;
					cout << "2 - Ordenar por nome do produto;" << endl;
					cout << "3 - Ordenar por fabricante;" << endl;
					cout << "4 - Ordenar por quantidade em estoque;" << endl << endl;
					cout << "Op��o: ";
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
						cout << "Op��o Inv�lida. Tente novamente." << endl;
					}
					break;
				}
				case 3:
				{
					cout << "=== Escolha o tipo de ordena��o === :" << endl << endl;
					cout << "1 - Ordenar por pre�o de venda do produto;" << endl;
					cout << "2 - Ordenar por nome do produto;" << endl;
					cout << "3 - Ordenar por fabricante;" << endl;
					cout << "4 - Ordenar por quantidade em estoque;" << endl;
					cout << "5 - Ordenar por tarja;" << endl << endl;
					cout << "Op��o: ";
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
						cout << "Op��o Inv�lida. Tente novamente." << endl;
					}
					break;
				}
				default:
					cout << "Op��o Inv�lida. Tente novamente." << endl;
				}
				break;
		}
		case 8:
		{
			cout << "Despezas atuais: " << estoque.get_despezas() << " R$" <<  endl;
			break;
		}
		default:
			cout << "Op��o Inv�lida. Tente novamente." << endl;
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
		
		cout << "=== Controle de Vendas da Farm�cia ===" << endl << endl;
	
		cout << "1 - Registrar Compras;" << endl;
		cout << "2 - An�lise de Notas Fiscais;" << endl;
		cout << "3 - Visualizar a parte financeira da farm�cia;" << endl; 
		cout << "0 - Voltar para o Menu Principal;" << endl << endl; 
		
		cout << "Insira uma op��o: ";
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
					cout << "1 - Departamento de Produtos Perec�veis;" << endl;
					cout << "2 - Departamento de Produtos Perec�veis;" << endl;
					cout << "3 - Departamento de Rem�dios;" << endl;
					cout << "4 - Remover itens da compra;" << endl;
					cout << "0 - Montar nota fiscal;" << endl << endl;
					
					cout << "insira sua op��o: ";
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
							cout << "Insira o c�digo de barras do produto n�o perec�vel: ";
							cin >> codigo;
							cout << endl;
							
							if(processo_vendas.pesquisarProduto(codigo))
							{
								cout << endl;
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
							cout << endl;
							
							if(processo_vendas.pesquisarProdutoPerecivel(codigo))
							{
								cout << endl;
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
							cout << endl;
							
							if(processo_vendas.pesquisarRemedio(codigo))
							{
								cout << endl;
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
						case 4:
						{
							cout << "=== De qual departamento voc� deseja remover o produto? ===" << endl << endl;
							cout << "1 - Departamento de produtos n�o perec�veis;" << endl;
							cout << "2 - Departamento de produtos perec�veis;" << endl;
							cout << "3 - Departamento de rem�dios;" << endl;
							cout << "0 - Cancelar opera��o;" << endl << endl;
							
							cout << "Digite sua op��o: ";
							cin >> escolha;
							
							cout << endl;
							system("pause");
							system("cls");
							
							switch(escolha)
							{
                            case 0:
							{
								cout << "Opera��o cancelada." << endl;
								break;
							}
							case 1:
							{
								cout << "Informe o c�digo do produto n�o perec�vel a ser removido da nota: ";
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
									cout << "Produto n�o encontrado." << endl;
								}
								break;
							}
							case 2:
							{
								cout << "Informe o c�digo do produto perec�vel a ser removido da nota: ";
								cin >> codigo;
								
								if(processo_vendas.pesquisar_nota_perecivel(codigo))
								{
									cout << endl;
									cout << "Produto perec�vel encontrado." << endl;
									
									cout << endl;
									system("pause");
									system("cls");
									
									processo_vendas.apaga_da_nota_perecivel(codigo);
									processo_vendas.set_entrada_estoque_perecivel(codigo, 1);
									cout << endl;
									cout << "Produto perec�vel removido da nota fiscal." << endl;
								}
								else
								{
									cout << "Produto perec�vel n�o encontrado." << endl;
								}
								
								break;
							}
							case 3:
							{
								cout << "Informe o c�digo do rem�dio a ser removido da nota: ";
								cin >> codigo;
								
								if(processo_vendas.pesquisar_nota_remedio(codigo))
								{
									cout << endl;
									cout << "Rem�dio encontrado." << endl;
									
									cout << endl;
									system("pause");
									system("cls");
									
									processo_vendas.apaga_da_nota_remedio(codigo);
									processo_vendas.set_entrada_estoque_remedio(codigo, 1);
									cout << endl;
									cout << "Rem�dio removido da nota fiscal." << endl;
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
				cout << "=== Escolha uma op��a de visualiza��o das notas fiscais ===" << endl << endl;
				cout << "1 - Visualizar hist�rico de notas fiscais;" << endl;
				cout << "2 - Limpar hist�rio de notas fiscais;" << endl;
				cout << "3 - Restaurar hist�rico de notas fiscais;" << endl;
				cout << "4 - Visualizar �ltimais notas fiscais;" << endl << endl;
				
				cout << "Insira sua op��o: ";
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
					cout << "Hist�rico de notas fiscais apagados." << endl;
					break;
				}
				case 3:
				{
					processo_vendas.restaura_historico_notas();
					cout << "Hist�rico de notas fiscais restaurada." << endl;
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
					cout << "Op��o inv�lida. Tente novamente" << endl;
					break;
				}
				
					cout << endl;
					system("pause");
					system("cls");
					
				break;
			}
			case 3:
			{
				cout << "=== An�lise Fiscal da Empresa ===" << endl;
				cout << "1 - Visualizar o saldo mensal da empresa;" << endl;
				cout << "2 - Visualizar o apurado mensal da empresa;" << endl;
				cout << "3 - Visualizar a despeza mensal da empresa;" << endl;
				cout << "4 - Finalizar as contas do m�s;" << endl << endl;
				cout << "Escolha uma op��o: ";
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
					cout << "As contas do m�s foram encerrados. Reiniciando uma nova an�lise." << endl;
					break;
				}
				default:
					cout << "Op��o inv�lida. Tente novamente." << endl;
					break;
				}
				
				cout << endl;
				system("pause");
				system("cls");
				
				break;
			}
			default:
				cout << "Op��o inv�lida. Tente novamente." << endl;
		}
	}
	
	return;
}