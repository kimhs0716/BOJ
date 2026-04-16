#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    map<string, string> dict;
    string site, pw;
    int n, m;

    cin >> n >> m;

    while(n--){
        cin >> site >> pw;
        dict[site] = pw;
    }

    while(m--){
        cin >> site;
        cout << dict[site] << "\n";
    }

    return 0;
}
