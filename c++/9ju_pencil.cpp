#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	int tcase;
	cin >> tcase;
	for (int a = 0;a < tcase;a++) {
		int result;
		int mongdanglength[10000] = { 0 };
		int mongdanglocate[10000] = { 0 };
		int dp[3][10000] = { 0 };//[0][x]=¿ÞÂÊ¾²·¯Áü,[1][x]=°¡¸¸È÷,[2][x]=¿À¸¥ÂÊ¾²·¯Áü
		int pencils;
		cin >> pencils;
		for (int b = 0;b < pencils;b++) {
			cin >> mongdanglocate[b] >> mongdanglength[b];
		}
		if (mongdanglength[0] < mongdanglocate[0]) {
			dp[0][0] = mongdanglength[0];
		}
		else {
			dp[0][0] = 0;
		}
		dp[1][0] = 0;
		if (mongdanglength[0] < mongdanglocate[1] - mongdanglocate[0]) {
			dp[2][0] = mongdanglength[0];
		}
		else {
			dp[2][0] = 0;
		}
		for (int c = 1;c < pencils;c++) {
			if (mongdanglength[c - 1] + mongdanglength[c] < mongdanglocate[c] - mongdanglocate[c - 1]) {
				dp[0][c] = max(dp[0][c - 1] + mongdanglength[c], dp[1][c - 1] + mongdanglength[c]);
				dp[0][c] = max(dp[0][c], dp[2][c - 1] + mongdanglength[c]);
			}
			else if (mongdanglength[c - 1] + mongdanglength[c] >= mongdanglocate[c] - mongdanglocate[c - 1]) {
				if (mongdanglength[c] >= mongdanglocate[c] - mongdanglocate[c - 1]) {
					dp[0][c] = max(dp[0][c - 1], dp[1][c - 1]);
					dp[0][c] = max(dp[0][c], dp[2][c - 1]);
				}
				else {
					dp[0][c] = max(dp[0][c - 1] + mongdanglength[c], dp[1][c - 1] + mongdanglength[c]);
				}//[0][x]
			}
			dp[1][c] = max(dp[0][c - 1], dp[1][c - 1]);
			dp[1][c] = max(dp[1][c], dp[2][c - 1]);//[1][x]
			if (mongdanglocate[c + 1] == 0) {
				dp[2][c] = max(dp[0][c - 1] + mongdanglength[c], dp[1][c - 1] + mongdanglength[c]);
				dp[2][c] = max(dp[2][c], dp[2][c - 1] + mongdanglength[c]);
			}
			else {
				if (mongdanglength[c] >= mongdanglocate[c + 1] - mongdanglocate[c]) {
					dp[2][c] = dp[1][c];
				}
				else {
					dp[2][c] = max(dp[0][c - 1] + mongdanglength[c], dp[1][c - 1] + mongdanglength[c]);
					dp[2][c] = max(dp[2][c], dp[2][c - 1] + mongdanglength[c]);
				}//[2][x]
			}


		}
		result = max(dp[0][pencils - 1], dp[1][pencils - 1]);
		result = max(result, dp[2][pencils - 1]);
		cout << result << endl;
		//		for (int k = 0;k < pencils - 1;k++) {
		//			cout << dp[0][k]<<" " << dp[1][k]<<" " << dp[2][k] << endl;
		//		}
	}

	return 0;
}