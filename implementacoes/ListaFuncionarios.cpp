#include "../cabecalhos/Funcionario.h"
#include "../cabecalhos/ListaFuncionarios.h"

ListaFuncionarios::ListaFuncionarios(void)
{
	leitura_funcionarios();
}

ListaFuncionarios::~ListaFuncionarios(void)
{
	gravacao_funcionarios();
}

void ListaFuncionarios::leitura_funcionarios(void)
{
	Funcionario func;
	ifstream arquivo4; 
	arquivo4.open("../funcionarios/lista_de_funcionarios.txt"); 
	
	if(arquivo4.is_open()) 
	{
		while(!arquivo4.eof()) 
		{
			arquivo4 >> func; 
			lista_funcionarios.push_back(func);
		}
	}
	arquivo4.close(); 
	
	return;
}

void ListaFuncionarios::gravacao_funcionarios(void)
{
	ofstream arquivo4; 
	
	arquivo4.open("../funcionarios/lista_de_funcionarios.txt", std::ios::trunc);
	
	if(arquivo4.is_open())
	{
		for(unsigned i(0); i < lista_funcionarios.size(); i++)
		{
			arquivo4 << lista_funcionarios[i]; 
		}	
	}	
	
	arquivo4.close();
	
	return;
}

bool ListaFuncionarios::inserir_funcionario(Funcionario func)
{
	for(unsigned i(0); i < lista_funcionarios.size(); i++)
	{
		if(lista_funcionarios[i].get_objeto_funcionario().cpf == func.get_objeto_funcionario().cpf)
		{
			return false;
		}
	}
	
	lista_funcionarios.push_back(func);
	
	return true;
}

void ListaFuncionarios::imprimir_funcionarios(void) const
{
	for(unsigned i(0); i < lista_funcionarios.size(); i++)
	{
		cout << "===== "<< i+1 << "° Funcionário =====" << endl;
		lista_funcionarios[i].imprime_dados();
		cout << endl;
	}
	
	return;
}

bool ListaFuncionarios::remover_funcionario_cpf(string cpf)
{
	unsigned contador(0);
	for(unsigned i(0); i < lista_funcionarios.size(); i++)
	{
		if(lista_funcionarios[i].get_objeto_funcionario().cpf == cpf)
		{
			lista_funcionarios.erase(lista_funcionarios.begin() + i);
			return true;
		}
		else
			contador++;
	}
	if(contador == lista_funcionarios.size())
		return false;
	
	return false;
}

bool ListaFuncionarios::pesquisar_funcionario_cpf(string cpf)
{
	unsigned contador(0);
	for(unsigned i(0); i < lista_funcionarios.size(); i++)
	{
		if(lista_funcionarios[i].get_objeto_funcionario().cpf == cpf)
		{
			lista_funcionarios[i].imprime_dados();
			return true;
		}
		else
			contador++;
	}
	if(contador == lista_funcionarios.size())
		return false;
	
	return false;
}

bool ListaFuncionarios::valida_funcionarios_estoque(Funcionario func_aux)
{
	for(unsigned i(0); i < lista_funcionarios.size(); i++)
	{
		if(lista_funcionarios[i].get_objeto_funcionario().cargo == "Controle de Estoque")
		{
			if(lista_funcionarios[i].valida_funcionario(func_aux.get_objeto_funcionario()))
				return true;
		}
	}
	
	return false;
}

bool ListaFuncionarios::valida_funcionarios_vendas(Funcionario func_aux)
{
	for(unsigned i(0); i < lista_funcionarios.size(); i++)
	{
		if(lista_funcionarios[i].get_objeto_funcionario().cargo == "Controle de Vendas")
		{
			if(lista_funcionarios[i].valida_funcionario(func_aux.get_objeto_funcionario()))
				return true;
		}
	}
	
	return false;
}

void ListaFuncionarios::ordena_funcionario_nome(void)
{
	int smallest;

    for(unsigned i = 0; i < lista_funcionarios.size() - 1; i++)
    {
        smallest = i; 

        for(unsigned index = i + 1; index < lista_funcionarios.size(); index++)
        {
            if(lista_funcionarios[index].get_objeto_funcionario().nome.compare(lista_funcionarios[smallest].get_objeto_funcionario().nome) < 0)
            {
                smallest = index;
            }
        }
		Funcionario func_aux;
		func_aux = lista_funcionarios[i];
    	lista_funcionarios[i] = lista_funcionarios[smallest];
    	lista_funcionarios[smallest] = func_aux;
    } 
    
    return;			
}

void ListaFuncionarios::ordena_funcionario_cpf(void)
{
	int smallest;

    for(unsigned i = 0; i < lista_funcionarios.size() - 1; i++)
    {
        smallest = i; 

        for(unsigned index = i + 1; index < lista_funcionarios.size(); index++)
        {
            if(lista_funcionarios[index].get_objeto_funcionario().cpf.compare(lista_funcionarios[smallest].get_objeto_funcionario().cpf) < 0)
            {
                smallest = index;
            }
        }
		Funcionario func_aux;
		func_aux = lista_funcionarios[i];
    	lista_funcionarios[i] = lista_funcionarios[smallest];
    	lista_funcionarios[smallest] = func_aux;
    } 
    
    return;			
}

void ListaFuncionarios::ordena_funcionario_cargo(void)
{
	int smallest;

    for(unsigned i = 0; i < lista_funcionarios.size() - 1; i++)
    {
        smallest = i; 

        for(unsigned index = i + 1; index < lista_funcionarios.size(); index++)
        {
            if(lista_funcionarios[index].get_objeto_funcionario().cargo.compare(lista_funcionarios[smallest].get_objeto_funcionario().cargo) < 0)
            {
                smallest = index;
            }
        }
		Funcionario func_aux;
		func_aux = lista_funcionarios[i];
    	lista_funcionarios[i] = lista_funcionarios[smallest];
    	lista_funcionarios[smallest] = func_aux;
    } 
    
    return;			
}

void ListaFuncionarios::ordena_funcionario_id(void)
{
	int smallest;

    for(unsigned i = 0; i < lista_funcionarios.size() - 1; i++)
    {
        smallest = i; 

        for(unsigned index = i + 1; index < lista_funcionarios.size(); index++)
        {
            if(lista_funcionarios[index].get_objeto_funcionario().id < lista_funcionarios[smallest].get_objeto_funcionario().id)
            {
                smallest = index;
            }
        }
		Funcionario func_aux;
		func_aux = lista_funcionarios[i];
    	lista_funcionarios[i] = lista_funcionarios[smallest];
    	lista_funcionarios[smallest] = func_aux;
    } 
    
    return;			
}

void ListaFuncionarios::ordena_funcionario_login(void)
{
	int smallest;

    for(unsigned i = 0; i < lista_funcionarios.size() - 1; i++)
    {
        smallest = i; 

        for(unsigned index = i + 1; index < lista_funcionarios.size(); index++)
        {
            if(lista_funcionarios[index].get_objeto_funcionario().login.compare(lista_funcionarios[smallest].get_objeto_funcionario().login) < 0)
            {
                smallest = index;
            }
        }
		Funcionario func_aux;
		func_aux = lista_funcionarios[i];
    	lista_funcionarios[i] = lista_funcionarios[smallest];
    	lista_funcionarios[smallest] = func_aux;
    } 
    
    return;			
}

void ListaFuncionarios::ordena_funcionario_senha(void)
{
	int smallest;

    for(unsigned i = 0; i < lista_funcionarios.size() - 1; i++)
    {
        smallest = i; 

        for(unsigned index = i + 1; index < lista_funcionarios.size(); index++)
        {
            if(lista_funcionarios[index].get_objeto_funcionario().senha.compare(lista_funcionarios[smallest].get_objeto_funcionario().senha) < 0)
            {
                smallest = index;
            }
        }
		Funcionario func_aux;
		func_aux = lista_funcionarios[i];
    	lista_funcionarios[i] = lista_funcionarios[smallest];
    	lista_funcionarios[smallest] = func_aux;
    } 
    
    return;			
}
