#include <iostream>

using namespace std;
int main()
{
	int n, m, ac, d, sc, sr, ar = 1;
	cin >> n >> m >> ac >> d >> sr >> sc;
	while(ar != n || ac != m){
		//cout << ar << ac << endl;
		if(d == 0){
			if(ac != 1)ac--;
			else d = !d, ar++;
		}
		else
		{
			if(ac < m) ac++;
			else d = !d, ar++;
		}
		if(ar == sr && ac == sc){cout << "NO..." << endl; return 0;}
	}
	cout << "YES!" << endl;
	return 0;
}