#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	int n, m;
	cin >> n >> m;
	int road[101][101];
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			if (i == j) {
				road[i][j] = 0;
			}
			else {
				road[i][j] = 999999;
			}
		}
	}
	for (int i = 0;i < m;i++) {
		int a, b;
		cin >> a >> b;
		road[a][b] = 1;
		road[b][a] = 1;
	}
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			for (int k = 1;k <= n;k++) {
				road[j][k] = min(road[j][k], road[j][i] + road[i][k]);
			}
		}
	}
	int x, k;
	cin >> x >> k;
	int result = road[1][k] + road[k][x];
	if (result < 999999) {
		cout << result << endl;
	}
	else {
		cout << -1 << endl;
	}
	
	return 0;
}
