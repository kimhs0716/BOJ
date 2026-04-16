#include <iostream>
using namespace std;
int main(){
    char str[256];
    int cnt;
    while(1){
        scanf("%[^\n]s", str);
        scanf("%*c");
        if(str[0] == '#' && str[1] == '\0') break;
        cnt = 0;
        int idx = 0;
        while(str[idx]){
            char ch = str[idx++];
            if(ch == 'A' || ch == 'a' || ch == 'E' || ch == 'e' || ch == 'I' ||\
                ch == 'i' || ch == 'O' || ch == 'o' || ch == 'U' || ch == 'u') cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}
