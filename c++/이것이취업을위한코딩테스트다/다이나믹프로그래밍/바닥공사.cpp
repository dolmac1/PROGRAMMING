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
	int result[1001];
	result[1] = 1;
	result[2] = 3;
	for (int i = 3;i <= n;i++) {
		result[i] = result[i - 1] + result[i - 2] * 2;
	}
	cout << result[n]%796796 << endl;
	return 0;
}
