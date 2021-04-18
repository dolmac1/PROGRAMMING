#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	int n;
	cin >> n;
	int number[9] = { 0 };
	int max_val = 0;
	if (n == 0) {
		max_val = 1;
	}
	else {
		while (n) {
			if (n % 10 == 9) {
				number[6]++;
			}
			else {
				number[n % 10]++;
			}
			n /= 10;
		}
		number[6] = (number[6] + 1) / 2;

		for (int i = 0;i < 9;i++) {
			max_val = max(max_val, number[i]);
		}
	}
	cout << max_val << endl;
	return 0;
}
