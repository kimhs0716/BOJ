#include <iostream>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int i, j;
    i = j = 0;
    int sum = 0, c = 0;
    while(i < n){
        if(sum == m){
            c++;
        }
        if(sum < m){
            j++;
            sum += arr[j - 1];
        }
        else{
            i++;
            sum -= arr[i - 1];
        }
    }
    cout << c;
    return 0;
}
