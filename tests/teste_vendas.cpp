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
	
	int escolha(1), quantidade;
	long int codigo;
	
	while(escolha)
	{
		
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
									
									processo_vendas.apaga_da_nota_perecivel(codigo);
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
			default:
				cout << "Op��o inv�lida. Tente novamente." << endl;
		}
	}
	
	
	
	
	return 0;
}