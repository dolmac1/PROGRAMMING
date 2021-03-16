#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	int n;
	cin >> n;
	vector<int> home;
	for (int i = 0;i < n;i++) {
		int k;
		cin >> k;
		home.push_back(k);
	}
	sort(home.begin(), home.end());
	cout << home[(n - 1) / 2] << endl;
	return 0;
}
