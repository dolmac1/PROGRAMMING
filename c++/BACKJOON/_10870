#include <iostream>
#include <string>
using namespace std;
int pibonacci(int a) {
	if (a == 0) {
		return 0;
	}
	else if (a <= 2) {
		return 1;
	}
	else {
		return pibonacci(a - 1) + pibonacci(a - 2);
	}
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int result = pibonacci(n);
	cout << result << endl;
	return 0;
}
