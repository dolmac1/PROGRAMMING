#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <stack>
using namespace std;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<vector<int>> trangle_val;
	int result = 0;
	for (int i = 0;i < n;i++) {
		vector<int> imsi;
		for (int j = 0;j <= i;j++) {
			int a;
			cin >> a;
			imsi.push_back(a);
		}
		trangle_val.push_back(imsi);
	}
	for (int i = 1;i < n;i++) {
		for (int j = 0;j <= i;j++) {
			if (j == 0) {
				trangle_val[i][j] = trangle_val[i - 1][j] + trangle_val[i][j];
			}
			else if (j == i) {
				trangle_val[i][j] = trangle_val[i - 1][j - 1] + trangle_val[i][j];
			}
			else {
				trangle_val[i][j] = max(trangle_val[i - 1][j - 1] + trangle_val[i][j], trangle_val[i - 1][j] + trangle_val[i][j]);
			}
		}
	}
	for (int i = 0;i < n;i++) {
		result = max(result, trangle_val[n - 1][i]);
	}
	cout << result << endl;
	return 0;
}
