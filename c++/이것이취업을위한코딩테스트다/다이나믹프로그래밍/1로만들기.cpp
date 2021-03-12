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
	int result[30001];
	result[1] = 0;
	for (int i = 2;i <= n;i++) {
		result[i] = result[i - 1] + 1;
		if (i % 2 == 0) {
			result[i] = min(result[i], result[i / 2] + 1);
		}
		if (i % 5 == 0) {
			result[i] = min(result[i], result[i / 5] + 1);
		}
	}
	cout << result[n] << endl;

	return 0;
}
