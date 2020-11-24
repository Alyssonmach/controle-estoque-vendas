#include "../cabecalhos/Funcionario.h"

Funcionario::Funcionario(string nome, string cpf, long int id, string cargo, string login, string senha)
{
	set_nome(nome);
	set_cpf(cpf);
	set_id(id);
	set_cargo(cargo);
	set_login(login);
	set_senha(senha);
}

bool Funcionario::valida_key(Funcionario_Prototipo aux)
{
	if(aux.login == key_login)
	{
		if(aux.senha == key_senha)
		{
			return true;
		}
	}
	
	return false;
}

bool Funcionario::valida_funcionario(Funcionario_Prototipo aux)
{
	if(aux.login == objeto_funcionario.login)
	{
		if(aux.senha == objeto_funcionario.senha)
		{
			return true;
		}
	}
	
	return false;
}

void Funcionario::set_objeto(Funcionario_Prototipo func)
{
	set_nome(func.nome);
	set_cpf(func.cpf);
	set_id(func.id);
	set_cargo(func.cargo);
	set_login(func.login);
	set_senha(func.senha);
	
	return;
}

void Funcionario::set_nome(string nome)
{
	this -> objeto_funcionario.nome = nome;
	
	return;
}

void Funcionario::set_cpf(string cpf)
{
	this -> objeto_funcionario.cpf = cpf;
	
	return;
}

void Funcionario::set_id(long int id)
{
	this -> objeto_funcionario.id = id;
	
	return;
}
void Funcionario::set_cargo(string cargo)
{
	this -> objeto_funcionario.cargo = cargo;
	
	return;
}

void Funcionario::set_login(string login)
{
	this -> objeto_funcionario.login = login;
	
	return;
}

void Funcionario::set_senha(string senha)
{
	this -> objeto_funcionario.senha = senha;
	
	return;
}

Funcionario_Prototipo Funcionario::get_objeto_funcionario(void) const
{
	return objeto_funcionario;
}

void Funcionario::imprime_dados(void) const
{
	cout << "Nome do Funcionário: " << get_objeto_funcionario().nome << endl;
	cout << "CPF do Funcionário: " << get_objeto_funcionario().cpf << endl;
	cout << "ID do Funcionário: " << get_objeto_funcionario().id << endl;
	cout << "Cargo do Funcionário: " << get_objeto_funcionario().cargo << endl;
	cout << "Login do Funcionário: " << get_objeto_funcionario().login << endl;
	cout << "Senha do Funcionário: " << get_objeto_funcionario().senha << endl;
	
	return;
}