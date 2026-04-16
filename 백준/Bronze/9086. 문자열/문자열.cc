#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#define endl '\n'

using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        cout << s[0] << s[s.length() - 1] << endl;
    }

    return 0;
}
