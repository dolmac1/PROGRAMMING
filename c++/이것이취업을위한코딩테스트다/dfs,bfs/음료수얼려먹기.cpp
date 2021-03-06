#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, m;
int ice[1000][1000];
int dfs(int a, int b) {
	if (a <= -1 || a>=n || b<=-1 || b>=m ) {
		return 0;
	}
	if (ice[a][b] == 0) {
		ice[a][b] = 1;
		dfs(a - 1, b);
		dfs(a + 1, b);
		dfs(a, b + 1);
		dfs(a, b - 1);
		return 1;
	}
	return 0;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	int result = 0;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cin >> ice[i][j];
		}
	}
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			if (dfs(i, j)) {
				result += 1;
			}
			
		}
	}
	cout << result << endl;
	return 0;
}
