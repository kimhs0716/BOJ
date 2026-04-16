#include <iostream>
#include <string>
using namespace std;
int main(){
    char S[20] = {0, };
    int m;
    cin >> m;
    while(m--){
        char str[20];
        scanf("%s", str);
        string cmd = str;
        if(cmd == "add"){
            int x;
            scanf("%d", &x);
            S[x - 1] = 1;
        }
        else if(cmd == "remove"){
            int x;
            scanf("%d", &x);
            S[x - 1] = 0;
        }
        else if(cmd == "check"){
            int x;
            scanf("%d", &x);
            printf("%d\n", S[x - 1]);
        }
        else if(cmd == "toggle"){
            int x;
            scanf("%d", &x);
            S[x - 1] = !S[x - 1];
        }
        else if(cmd == "all"){
            for(int i = 0; i < 20; i++)
                S[i] = 1;
        }
        else
            for(int i = 0; i < 20; i++)
                S[i] = 0;
    }
    return 0;
}
