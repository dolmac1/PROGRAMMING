#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> arr;
	for (int i = 0;i < n;i++) {
		vector<int> arr_imsi;
		for (int j = 0;j < n;j++) {
			int k;
			cin >> k;
			
			if (i == 0) {
				if (j == 0) {
					arr_imsi.push_back(k);
				}
				else {
					arr_imsi.push_back(k + arr_imsi[j - 1]);
				}
			}
			else {
				if (j == 0) {
					arr_imsi.push_back(k + arr[i - 1][0]);
				}
				else {
					arr_imsi.push_back(k + arr[i - 1][j] + arr_imsi[j - 1] - arr[i - 1][j - 1]);
				}
			}
		}
		arr.push_back(arr_imsi);
	}
	for (int i = 0;i < m;i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int result = arr[c-1][d-1];
		if (a == 1) {
			if (b == 1) {
				
			}
			else {
				result -= arr[c - 1][b - 2];
			}
		}
		else {
			if (b == 1) {
				result -= arr[a - 2][d - 1];
			}
			else {
				result = result - arr[c - 1][b - 2] - arr[a - 2][d - 1] + arr[a - 2][b - 2];
			}
		}
		cout << result << "\n";
	}
	return 0;
}
