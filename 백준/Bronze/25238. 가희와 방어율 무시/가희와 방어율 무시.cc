#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <string>
#include <map>
#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long int lld;
int main(){
    FASTIO;
    int a, b;
    cin >> a >> b;
    if(a - a * b / 100.0 >= 100) cout << 0;
    else cout << 1;
    cout << endl;
    return 0;
}
