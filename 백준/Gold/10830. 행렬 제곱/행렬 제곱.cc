#include <iostream>
#define mod 1000
typedef long long int lld;
using namespace std;
typedef struct {
    int msize;
    int arr[5][5];
} mat;
mat pow(mat m, lld b);
mat mul(mat m1, mat m2);
int main(){
    int n;
    lld b;
    cin >> n >> b;
    mat m;
    m.msize = n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> m.arr[i][j];
    m = pow(m, b);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << m.arr[i][j] << " ";
        cout << endl;
    }
    return 0;
}
mat pow(mat m, lld b){
    if(b == 1){
        for(int i = 0; i < m.msize; i++)
            for(int j = 0; j < m.msize; j++)
                m.arr[i][j] %= mod;
        return m;
    }
    mat ret = pow(m, b / 2);
    ret = mul(ret, ret);
    if(b & 1) ret = mul(ret, m);
    return ret;
}
mat mul(mat m1, mat m2){
    mat ret;
    ret.msize = m1.msize;
    for(int i = 0; i < m1.msize; i++){
        for(int j = 0; j < m1.msize; j++){
            ret.arr[i][j] = 0;
            for(int k = 0; k < m1.msize; k++)
                ret.arr[i][j] += (m1.arr[i][k] * m2.arr[k][j]) % mod;
            ret.arr[i][j] %= mod;
        }
    }
    return ret;
}
