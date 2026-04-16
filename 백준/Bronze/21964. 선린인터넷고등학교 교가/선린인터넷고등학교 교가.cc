#include <iostream>
#include <string>

#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    cout << s.substr(n - 5, 5) << endl;
    return 0;
}