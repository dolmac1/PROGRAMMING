#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
int miro[200][200];
int n, m;
int locx[4] = { 0,0,1,-1 };
int locy[4] = { 1,-1,0,0 };
int bfs(int a, int b) {
	queue<pair<int, int>> loc;
	loc.push({ a, b });
	while (!loc.empty()) {
		int x = loc.front().first;
		int y = loc.front().second;
		loc.pop();

		for (int i = 0;i < 4;i++) {
			int next_x = x + locx[i];
			int next_y = y + locy[i];
			if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= m) {
				continue;
			}
			if (miro[next_x][next_y] == 1) {
				miro[next_x][next_y] = miro[x][y] + 1;
				loc.push({ next_x,next_y });
			}
		}
	}
	return miro[n][m];
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cin >> miro[i][j];
		}
	}
	bfs(0, 0);
	cout << miro[n - 1][m - 1] << endl;;
	return 0;
}
