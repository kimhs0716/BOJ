#include <iostream>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    long long int s = 0;
    long long int M = 0;
    int i = 0;
    for(int i = 0; i < m; i++)
        s += arr[i];
    while(i < n - m){
        M = max(M, s);
        s -= arr[i];
        s += arr[i + m];
        i++;
    }\
    cout << M << endl;
    return 0;
}
