#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int binary_search(long long x, long long y) {
	int begin = 0;
	int end = 1000000000;
	int result = -1;
	if (y * 100 / x  >= 99) {
		return -1;
	}
	while (begin<=end) {
		int mid = (begin + end) / 2;
		long long rate = y * 100 / x;
		long long mid_rate = ((y + mid) * 100) / (x + mid);
		if (rate < mid_rate) {
			end = mid - 1;
			result = mid;
		}
		else {
			begin = mid + 1;
		}
	}
	return result;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long x, y;
	cin >> x >> y;
	int a = binary_search(x, y);
	cout << a << endl;
	return 0;
}
