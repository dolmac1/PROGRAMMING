#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int tcase;
	cin >> tcase;
	int n, m;
	for (int a = 0;a < tcase;a++) {
		cin >> n >> m;
		int arry[51][51] = { 0 };
		for (int b = 0;b <= n;b++) {
			for (int c = 0;c <= n;c++) {
				arry[b][c] = 99999999;
			}
		}
		int smallvalue[51] = { 0 };
		int largevalue[51] = { 0 };

		for (int d = 0;d < m;d++) {
			int lar, sma;
			cin >> lar >> sma;
			arry[lar][sma] = 1;
		}
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) {
				for (int k = 1;k <= n;k++) {
					if (arry[j][k] > arry[i][k] + arry[j][i]) {
						arry[j][k] = arry[i][k] + arry[j][i];
					}
				}
			}
		}
		int loopcheck = 0;
		for (int e = 1;e <= n;e++) {
			for (int f = 1;f <= n;f++) {
				if (arry[e][f] != 99999999 && arry[f][e] != 99999999) {
					loopcheck = 1;
				}
				else if (arry[e][f] != 99999999) {
					smallvalue[e]++;
					largevalue[f]++;
				}
			}
		}
		if (loopcheck == 1) {
			cout << -1 << endl;
		}
		else {
			for (int g = 1;g <= n;g++) {
				cout << largevalue[g] << " " << smallvalue[g] << endl;
			}
		}
	}

	return 0;
}
