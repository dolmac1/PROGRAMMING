#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int result[10] = { 0 };
	int num[3];
	int mul_result;
	for (int i = 0;i < 3;i++) {
		cin >> num[i];
	}
	mul_result = num[0] * num[1] * num[2];
	while (mul_result != 0) {
		int k = mul_result % 10;
		result[k]++;
		mul_result = mul_result / 10;
	}
	for (int i = 0; i < 10; i++) {
		cout << result[i] << endl;
	}
	return 0;
}
