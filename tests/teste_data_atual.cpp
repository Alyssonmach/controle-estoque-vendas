#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int main(void)
{
	time_t t;
	struct tm * infoTempo;
	
	time(&t);
	infoTempo = localtime(&t);
	
	cout << setw(2);
	cout << setfill('0') << infoTempo -> tm_mday << "/";
	cout << setfill('0') << infoTempo -> tm_mon << "/";
	cout << setfill('0') << 1900 + (infoTempo -> tm_year);
	
	return 0;
}
