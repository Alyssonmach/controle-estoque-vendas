#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <dirent.h>
#include <string>

using namespace std;

int main(void)
{
	DIR *dir;
	struct dirent *lsdir;
	char snum[1];
	
	int count = 0;
	string nome = "NotaFiscal", numero;
	
	dir = opendir("../NotasFiscais/notas_de_compras/");
	
	while((lsdir = readdir(dir)) != NULL)
	{
		cout << lsdir -> d_name << endl;
		count++;
	}
	
	cout << count - 2 << " Arquivos" << endl;
	
	nome = nome + itoa(count - 2, snum, 10);
	cout << nome << endl;
	closedir(dir);
	
	return 0;
}