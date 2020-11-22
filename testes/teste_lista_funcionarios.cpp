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
	
	cout << "Para acessar essa p�gina, entre com o cadastro do administrador." << endl << endl;
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
			cout << "1 - Inserir um novo funcion�rio;" << endl;
			cout << "2 - Imprimir lista de funcionarios;" << endl;
			cout << "3 - Pesquisar funcion�rios;" << endl;
			cout << "4 - Ordenar lista de funcionarios;" << endl;
			cout << "5 - Remover Funcion�rio por CPF;" << endl;
			cout << "6 - Testar Valida��o das senhas dos funcionarios;" << endl;
			cout << "0 - Sair do programa;" << endl << endl;
			cout << "Insira uma op��o: ";
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
					cout << endl;
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