//b2 hashing
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <stack>
using namespace std;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	long long result = 0;
	long long mul_val = 1;
	for (int i = 0;i < n;i++) {
		char input_val;
		cin >> input_val;
		int real_val = input_val - 96;
		result = (result + (real_val * mul_val)) % 1234567891;
		mul_val = (mul_val * 31) % 1234567891;
	}
	cout << result << endl;
	return 0;
}
