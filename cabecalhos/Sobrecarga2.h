#include "Funcionario.h"
#include <string>

// Sobrecarregando o operador de saída << para que possa gravar um objeto inteiro em um arquivo.
ofstream& operator << (ofstream& arquivo4, Funcionario& func)
{
	arquivo4 << endl << func.get_objeto_funcionario().id << endl;
	arquivo4 << func.get_objeto_funcionario().cpf << endl;
	arquivo4 << func.get_objeto_funcionario().cargo << endl;
	arquivo4 << func.get_objeto_funcionario().login << endl;
	arquivo4 << func.get_objeto_funcionario().senha << endl;
	arquivo4 << func.get_objeto_funcionario().nome;
	
	return arquivo4;
}

// Sobrecarregando o operador de entrada >> para que possa ler um objeto inteiro de um arquivo.
ifstream& operator >> (ifstream& arquivo4, Funcionario& func)
{
	
	string nome, cpf, cargo, login, senha;
	long int id;
	
	//arquivo4.ignore();
	arquivo4 >> id;  arquivo4.ignore();
	func.set_id(id);
	getline(arquivo4, cpf); 
	func.set_cpf(cpf);
	getline(arquivo4, cargo); 
	func.set_cargo(cargo);
	getline(arquivo4, login); 
	func.set_login(login);
	getline(arquivo4, senha); 
	func.set_senha(senha); 
	getline(arquivo4, nome);
	func.set_nome(nome); 
	
	
	return arquivo4;
}