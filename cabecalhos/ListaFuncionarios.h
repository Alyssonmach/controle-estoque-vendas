#ifndef LISTAFUNCIONARIOS_H
#define LISTAFUNCIONARIOS_H

#include <vector>
#include <string>
#include "Funcionario.h"
#include "Sobrecarga2.h"

using std::string;

class ListaFuncionarios
{
	private:
		// lista de vector que armazena diversos funcionarios
	   vector <Funcionario> lista_funcionarios;	
	   // metodos para leitura e gravacao de objetos na lista de vector
	   void leitura_funcionarios(void);
	   void gravacao_funcionarios(void);
    public:
    	// construtor inicia a leitura dos arquivos para a lista de vector
    	ListaFuncionarios(void);
    	// destrutor salva os objetos da lista de vector no arquivo
    	~ListaFuncionarios(void);
    	// metodo para inserir funcionario na lista de vector
    	bool inserir_funcionario(Funcionario);
    	// metodo para imprimir funcionarios da lista de vector
    	void imprimir_funcionarios(void) const;
    	// metodo para remover funcionarios da lista de vector pelo cpf
    	bool remover_funcionario_cpf(string);
    	// metodo para pesquisar funcionarios da lista de vector pelo cpf
    	bool pesquisar_funcionario_cpf(string);
    	// metodos para validar o acesso de funcionarios pelo login e senha 
    	bool valida_funcionarios_estoque(Funcionario);
    	bool valida_funcionarios_vendas(Funcionario);
    	// metodos para ordenar a lista de vector a partir dos atributos do objeto
    	void ordena_funcionario_nome(void);
    	void ordena_funcionario_cpf(void);
    	void ordena_funcionario_id(void);
    	void ordena_funcionario_cargo(void);
    	void ordena_funcionario_login(void);
    	void ordena_funcionario_senha(void);
};

#endif