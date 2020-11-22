#ifndef LISTAFUNCIONARIOS_H
#define LISTAFUNCIONARIOS_H

#include <vector>
#include "Funcionario.h"
#include "Sobrecarga2.h"

class ListaFuncionarios
{
	private:
	   vector <Funcionario> lista_funcionarios;	
	   void leitura_funcionarios(void);
	   void gravacao_funcionarios(void);
    public:
    	ListaFuncionarios(void);
    	~ListaFuncionarios(void);
    	bool inserir_funcionario(Funcionario);
    	void imprimir_funcionarios(void) const;
    	bool remover_funcionario_cpf(string);
    	bool pesquisar_funcionario_cpf(string);
    	bool valida_funcionarios_estoque(Funcionario);
    	bool valida_funcionarios_vendas(Funcionario);
    	void ordena_funcionario_nome(void);
    	void ordena_funcionario_cpf(void);
    	void ordena_funcionario_id(void);
    	void ordena_funcionario_cargo(void);
    	void ordena_funcionario_login(void);
    	void ordena_funcionario_senha(void);
};

#endif