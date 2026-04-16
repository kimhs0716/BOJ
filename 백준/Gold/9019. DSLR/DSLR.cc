#include <iostream>
#include <queue>
#include <string>
#define endl '\n'
using namespace std;
int L(int a){
    return (a % 1000) * 10 + a / 1000;
}
int R(int a){
    return (a % 10) * 1000 + a / 10;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        bool visited[10000] = {0, };
        queue<pair<int, string>> q;
        int a, b;
        cin >> a >> b;
        pair<int, string> f;
        q.push({a, ""});
        visited[a] = 1;
        do{
            //cout << "qsize: " << q.size() << endl;
            f = q.front();
            q.pop();
            int A = (f.first * 2) % 10000;
            int B = (f.first == 0) ? 9999 : (f.first - 1);
            int C = R(f.first);
            int D = L(f.first);
            //printf("%d %d %d %d\n", A, B, C, D);
            if(visited[A] == 0) { q.push({A, f.second + "D"}); visited[A] = 1; }
            if(visited[B] == 0) { q.push({B, f.second + "S"}); visited[B] = 1; }
            if(visited[C] == 0) { q.push({C, f.second + "R"}); visited[C] = 1; }
            if(visited[D] == 0) { q.push({D, f.second + "L"}); visited[D] = 1; }
        }while(f.first != b);
        cout << f.second << endl;
    }
    return 0;
}
