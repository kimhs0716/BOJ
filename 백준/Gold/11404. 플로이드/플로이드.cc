#include<iostream>
#include<climits>

using namespace std;

static long D[101][101];
static int n, m;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int INF;
	cin >> n >> m;

	INF = INT_MAX;

	// 초기화 작업...
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) {
				D[i][j] = 0;
			}
			else
				D[i][j] = INF;
		}
	}

	// 가중치 입력
	for (int i = 0; i < m; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		if (D[s][e] > w)
			D[s][e] = w;

	}

	// 플로이드-워셜 작업

	for (int k = 1; k <= n; k++) {
		for (int s = 1; s <= n; s++) {
			for (int e = 1; e <= n; e++) {
				if (D[s][e] > D[s][k] + D[k][e])
					D[s][e] = D[s][k] + D[k][e];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (D[i][j] == INF) {
				cout << 0 << " ";

			}
			else {
				cout << D[i][j] << " ";
			}

		}
		cout << "\n";
	}
}


