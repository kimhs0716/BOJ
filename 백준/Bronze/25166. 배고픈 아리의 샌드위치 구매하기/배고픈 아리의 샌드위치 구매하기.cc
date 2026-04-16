#include <iostream>

using namespace std;
int main()
{
	int s, m;
	cin >> s >> m;
	if(s <= 1023) cout << "No thanks" << endl;
	else{
		s -= 1023;
		//cout << s << " " << m << " " << (s & m) << endl;
		if((s & m) == s) cout << "Thanks" << endl ;
		else cout << "Impossible" << endl;
	}
	return 0;
}