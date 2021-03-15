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
	int money[10001];
	int min_money = 999999;
	for (int i = 0;i <= m;i++) {
		money[i] = 999999;
	}
	vector<int> hwapae;
	for (int i = 0;i < n;i++) {
		int k;
		cin >> k;
		hwapae.push_back(k);
		money[k] = 1;
	}
	for (int i = 1;i <= m;i++) {
		for (int j = 0;j < n;j++) {
			if (i - hwapae[j] > 0) {
				money[i] = min(money[i], money[i - hwapae[j]] + 1);
			}
		}
	}
	if (money[m] != 999999) {
		cout << money[m] << endl;
	}
	else {
		cout << -1 << endl;
	}


	return 0;
}
