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
	int div_val = 64;
	int result = 0;
	while (n) {
		if (n >= div_val) {
			n = n - div_val;
			result++;
		}
		div_val /= 2;
	}
	cout << result << endl;
	return 0;
}
