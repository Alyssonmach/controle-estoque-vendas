#include <iostream>
#include <locale>

using namespace std; 

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
    float a;  
    
    cin >> a;
    
    while(cin.fail())
	{
	        cout << "Entrada inválida. Tente novamente." << endl;
	        cin.clear();
	        cin.ignore(256,'\n');  
	        cin >> a;
	}

    cout << "a = " << a; 
 
    return 0;
}