#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

// definindo uma estrutura com os atributos do funcionario
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
		// atributo que contem a estrutura de informacoes associadas aos funcionarios
		Funcionario_Prototipo objeto_funcionario;
		// atributos constantes para definir o login e a senha do administrador
		static const string key_login;
		static const string key_senha;
    public:
    	Funcionario(string = " ", string = " ", long int = 0, string = " ", string = " ", string = " ");
        // metodo de verificacao da validacao do administrador
		bool valida_key(Funcionario_Prototipo);
		// metodo de verificacao da validacao do administrador
        bool valida_funcionario(Funcionario_Prototipo);
        // metodoq que configura um objeto a partir da estrutura de um funcionario
        void set_objeto(Funcionario_Prototipo);
        // metodo que configura o nome do funcionario
        void set_nome(string);
        // metodo que configura o cpf do funcionario
        void set_cpf(string);
        // metodo que configura a identificacao do funcionario
        void set_id(long int);
        // metodo que configura o cargo desempenhado do funcionario
        void set_cargo(string);
        // metodo que configura o login do funcionario
        void set_login(string);
        // metodo que configura a senha do funcionario
        void set_senha(string);
        // metodo que retorna uma estrutura com os dados do funcionario
        Funcionario_Prototipo get_objeto_funcionario(void) const;
        // metodo que imprime os dados vinculados ao funcionario
        void imprime_dados(void) const;
};

// configurando o login e a senha do administrador 
const string Funcionario::key_login = "admin";
const string Funcionario::key_senha = "admin";

#endif