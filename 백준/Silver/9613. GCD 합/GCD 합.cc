#include <iostream>
using namespace std;
int gcd(int a, int b);
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        long long int sum = 0;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                sum += gcd(arr[i], arr[j]);
        cout << sum << endl;
    }
    return 0;
}
int gcd(int a, int b){
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
