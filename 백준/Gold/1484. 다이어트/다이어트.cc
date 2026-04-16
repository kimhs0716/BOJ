#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <map>
#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long int lld;
int main(){
    FASTIO;
    int g; cin >> g;
    lld i = 1, j = 1;
    bool passed = 0;
    while(2 * i + 1 <= g){
        if(j * j - i * i == g) passed = 1, cout << j << endl;
        if(j * j - i * i > g) i++;
        else j++;
    }
    if(!passed) cout << "-1\n";
    return 0;
}
