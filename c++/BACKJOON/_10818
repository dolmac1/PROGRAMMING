#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int *k=new int[1000000];
	int n;
	cin >> n;
	int minval, maxval;
	minval = 1000000;
	maxval = -1000000;
	for (int i = 0;i < n;i++) {
		int j;
		cin >> j;
		k[i] = j;
		if (k[i] < minval) {
			minval = k[i];
		}
		if (k[i] > maxval) {
			maxval = k[i];
		}
	}
	cout << minval << " " << maxval;
	return 0;
}
