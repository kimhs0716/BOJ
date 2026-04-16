#include <iostream>
#include <cstring>
#define endl '\n'
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
bool alpha[26];
char names[26][6];
int len[26], cnt, cur[26];
typedef long long int lld;
void dfs(int depth){
    if(depth == 26) {
        cnt++;
        return;
    }
    for(int i = 0; i < len[depth]; i++){
        if(alpha[names[depth][i] - 'A']) continue;
        alpha[names[depth][i] - 'A'] = 1;
        dfs(depth + 1);
        alpha[names[depth][i] - 'A'] = 0;
    }
}
int main(){
    FASTIO;
    for(int i = 0; i < 26; i++){
        alpha[i] = 0;
        scanf(" %s", names[i]);
        int l = strlen(names[i]);
        char newName[6] = {0, };
        bool visited[26] = {0, };
        for(int j = 0; j < l; j++){
            if(visited[names[i][j] - 'A']) continue;
            visited[names[i][j] - 'A'] = 1;
            newName[len[i]++] = names[i][j];
        }
        strcpy(names[i], newName);
    }
    dfs(0);
    printf("%d\n", cnt);
    return 0;
}
