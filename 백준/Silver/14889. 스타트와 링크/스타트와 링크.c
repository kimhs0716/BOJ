#include <stdio.h>
#include <limits.h>

int dup(int *arr, int len){
    for(int i = 0; i < len; i++)
        for(int j = i + 1; j < len; j++)
            if(arr[i] == arr[j]) return 1;
    return 0;
}

int include(int *arr, int n, int size){
    for(int i = 0; i < size; i++){
        if(arr[i] == n) return 1;
    }
    return 0;
}

int score(int arr[], int team[], int len, int team2[]){
    int score1 = 0, score2 = 0;
    for(int i = 0; i < len / 2; i++){
        for(int j = i + 1; j < len / 2; j++){
            score1 += arr[team[i] * len + team[j]] + arr[team[j] * len + team[i]];
            score2 += arr[team2[i] * len + team2[j]] + arr[team2[j] * len + team2[i]];
        }
    }
    return (score1 > score2) ? (score1 - score2) : (score2 - score1);
}

void dfs(int arr[], int *min, int level, int lim, int *team){
    if(level == lim / 2){
        int team2[lim / 2], idx = 0;
        for(int i = 0; i < lim; i++){
            if(include(team, i, lim / 2) == 0){
                team2[idx++] = i;
            }
            if(idx == lim / 2) break;
        }
        /*
        for(int i = 0; i < level; i++)
            printf("%d ", team[i]);
        for(int i = 0; i < level; i++)
            printf("%d ", team2[i]);
        printf("\n");
        */
        int s = score(arr, team, lim, team2);
        //printf("%d\n", s);
        *min = (*min > s) ? s : *min;
        return;
    }
    for(int i = team[level - 1] + 1; i < lim; i++){
        team[level] = i;
        if(dup(team, level + 1)) continue;
        dfs(arr, min, level + 1, lim, team);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int arr[n * n], min = INT_MAX, team[n / 2];
    for(int i = 0; i < n * n; i++)
        scanf("%d", &arr[i]);
    team[0] = 0;
    dfs(arr, &min, 1, n, team);
    printf("%d", min);
}
