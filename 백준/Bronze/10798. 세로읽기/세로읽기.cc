#include <iostream>
#include <cstring>
using namespace std;
int main(){
    char arr[5][16] = {0, };
    for(int i = 0; i < 5; i++) {
        scanf("%s", arr[i]);
    }
    for(int i = 0; i < 15; i++) {
        for(int j = 0; j < 5; j++) {
            if(arr[j][i] == 0) continue;
            cout << arr[j][i];
        }
    }
    return 0;
}
