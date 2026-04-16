#include <iostream>
#include <string>
#include <vector>
#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

typedef long long int lld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

int main() {
	FASTIO;
	
	char arr[] = "KOREA";
	int idx = 0, cnt = 0;
	string s; cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == arr[idx % 5]) cnt++, idx++;
	}
	cout << cnt << endl;

	return 0;
}