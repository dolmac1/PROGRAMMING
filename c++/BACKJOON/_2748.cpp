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
	long long a = 0;
	long long b = 1;
	long long result=0;
	for (int i = 2;i <= n;i++) {
		result = a + b;
		a = b;
		b = result;
	}
	if (n == 0) {
		result = 0;
	}
	if (n == 1) {
		result = 1;
	}
	cout << result << endl;
	return 0;
}
