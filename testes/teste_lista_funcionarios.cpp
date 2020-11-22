#include <iostream>
#include <locale>
#include <cstdlib>
#include <fstream>
#include <vector>

using namespace std;

#include "../implementations/Funcionario.cpp"
#include "../implementations/ListaFuncionarios.cpp"

int main(void)
{
	setlocale(LC_ALL, "Portuguese");
	
	int escolha(1);
	ListaFuncionarios lista;
	Funcionario_Prototipo funcionario;
	Funcionario analisa_admin;
	
	cout << "Para acessar essa página, entre com o cadastro do administrador." << endl << endl;
	cout << "Login: ";
	getline(cin, funcionario.login);
	cout << "Senha: ";
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
			cout << "=== Teste da Classe ListaFuncionarios ===" << endl << endl;
			cout << "1 - Inserir um novo funcionário;" << endl;
			cout << "2 - Imprimir lista de funcionarios;" << endl;
			cout << "3 - Pesquisar funcionários;" << endl;
			cout << "4 - Ordenar lista de funcionarios;" << endl;
			cout << "5 - Remover Funcionário por CPF;" << endl;
			cout << "6 - Testar Validação das senhas dos funcionarios;" << endl;
			cout << "0 - Sair do programa;" << endl << endl;
			cout << "Insira uma opção: ";
			cin >> escolha;
			
			cout << endl;
			system("pause");
			system("cls");
			
			switch(escolha)
			{
			case 0:
			{
				cout << "Programa encerrado." << endl;
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
					cout << endl;
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
			
			cout << endl;
			system("pause");
			system("cls");
				
		}
	}
	else 
	{
		cout << endl;
		cout << "Login ou senha incorretos. Tente novamente." << endl;
	}
	
	cin.ignore();
	return 0;
}