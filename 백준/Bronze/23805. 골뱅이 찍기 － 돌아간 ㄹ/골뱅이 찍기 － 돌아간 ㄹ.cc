#include <iostream>
using namespace std;
void print(char c, int n){
    for(int i = 0; i < n; i++) printf("%c", c);
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        print('@', 3 * n);
        print(' ', n);
        print('@', n);
        printf("\n");
    }
    for(int i = 0; i < 3 * n; i++){
        print('@', n);
        print(' ', n);
        print('@', n);
        print(' ', n);
        print('@', n);
        printf("\n");
    }
    for(int i = 0; i < n; i++){
        print('@', n);
        print(' ', n);
        print('@', 3 * n);
        printf("\n");
    }
    return 0;
}
