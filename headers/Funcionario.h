#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

struct Funcionario_Prototipo
{
	string nome;
	string cpf;
	long int id;
	string cargo;
	string login;
	string senha;
};

class Funcionario 
{
	private:
		Funcionario_Prototipo objeto_funcionario;
		static const key_login;
		static const key_senha;
    public:
    	Funcionario(string = " ", string = " ", long int = 0, string = " ",
		            string = " ", string = " ");
        bool valida_key(Funcionario_Prototipo);
        bool valida_funcionario(Funcionario_Prototipo);
        void set_nome(string);
        void set_cpf(string);
        void set_id(long int);
        void set_cargo(string);
        void set_login(string);
        void set_senha(string);
        Funcionario_Prototipo get_objeto_funcionario(void);
        void imprime_dados(void) const;
};

const static Funcionario::key_login = "admin";
const static Funcionario::key_senha = "admin";

#endif