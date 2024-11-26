#include<cstring>
#include<iostream>
using namespace std;

int arr[100001][4];

int main(){
ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    arr[1][1] = 1;
    arr[2][2] = 1;
    arr[3][1] = 1;
    arr[3][2] = 1;
    arr[3][3] = 1;
    
    for(int i=4;i<=100000;i++){
        if(i-1>0)
            arr[i][1] = (arr[i-1][2] + arr[i-1][3])%1000000009;
        if(i-2>0)
            arr[i][2] = (arr[i-2][1] + arr[i-2][3])%1000000009;
        if(i-3>0)
            arr[i][3] = (arr[i-3][1] + arr[i-3][2])%1000000009;
    }
    while(n--){
        int m;
        cin>>m;
        cout<<((arr[m][1] + arr[m][2]) % 1000000009 + arr[m][3])%1000000009<<"\n";
    }
}