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
	int weight[11] = { 0 };


	for (int i = 0;i < n;i++) {
		int k;
		cin >> k;
		weight[k]++;
	}
	int answer = 0;
	for (int i = 1;i <= m;i++) {
		if (weight[i] != 0) {
			answer = answer + (( n - weight[i])*weight[i]);
		}
	}
	answer /= 2;
	cout << answer << endl;

	return 0;
}
