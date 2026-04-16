#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
vector<ll> k;
vector<vector<pair<int,int>>> adj;

// 주어진 T로 M개 알고리즘을 배울 수 있는지 검사
bool feasible(ll T) {
    vector<ll> red(N, 0);        // 각 알고리즘에 누적된 할인량
    vector<char> inq(N, 0), used(N, 0);
    queue<int> q;
    // 초기: 기본 비용 k[i] <= T인 알고리즘들을 후보에 넣는다
    for (int i = 0; i < N; i++) {
        if (k[i] <= T) {
            q.push(i);
            inq[i] = 1;
        }
    }

    int cnt = 0;
    while (!q.empty() && cnt < M) {
        int u = q.front(); q.pop();
        if (used[u]) continue;
        used[u] = 1;
        cnt++;
        // u를 배우면 u->v 간선의 할인 D를 v에 적용
        for (auto &e : adj[u]) {
            int v = e.first;
            int d = e.second;
            red[v] += d;
            // 아직 배우지 않았고, 큐에도 없는 v가 이제 k[v]-red[v] <= T라면 큐에 추가
            if (!used[v] && !inq[v] && k[v] - red[v] <= T) {
                inq[v] = 1;
                q.push(v);
            }
        }
    }
    return cnt >= M;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력
    cin >> N >> M;
    k.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> k[i];
    }
    int R;
    cin >> R;
    adj.assign(N, {});
    for (int i = 0; i < R; i++) {
        int A, B;
        int D;
        cin >> A >> B >> D;
        --A; --B;
        adj[A].emplace_back(B, D);
    }

    // 이분 탐색: T의 범위는 [0, max(k_i)]
    ll lo = 0, hi = *max_element(k.begin(), k.end());
    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        if (feasible(mid)) hi = mid;
        else lo = mid + 1;
    }

    cout << lo << "\n";
    return 0;
}
