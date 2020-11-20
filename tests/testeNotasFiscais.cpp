// writing on a text file
#include <iostream>
#include <fstream>
#include <locale>
using namespace std;

int main (void) {
	
  setlocale(LC_ALL, "Portuguese");
  
  std::ofstream myfile;
  myfile.open ("../NotasFiscais/historico_notas_fiscais.txt", std::ofstream::out | std::ofstream::app);

  if (myfile.is_open())
  {
	  	myfile << "=== Teste === Data: 12/12/1111" << endl;
	  	myfile << "Nome do lojista" << endl;
    	myfile << "Nome do Produto - Preço" << endl;
    	myfile << "info info" << endl << endl;
    	myfile.close();
  }
  else cout << "Não foi possível abrir o arquivo." << cout;

  string line;
  ifstream myfile2 ("../NotasFiscais/historico_notas_fiscais.txt");
  if (myfile2.is_open())
  {
    while ( getline (myfile2,line) )
    {
      cout << line << '\n';
    }
    myfile2.close();
  }
  else cout << "Não foi possível abrir o arquivo." << cout;
  
  return 0;
}