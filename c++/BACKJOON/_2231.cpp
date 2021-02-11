#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int result = 9999999;
	for (int i = 0; i < n;i++) {
		int a, b, c, d, e, f, g;
		int n2 = i;
		a = n2 % 10;
		n2 = n2 / 10;
		b = n2 % 10;
		n2 = n2 / 10;
		c = n2 % 10;
		n2 = n2 / 10;
		d = n2 % 10;
		n2 = n2 / 10;
		e = n2 % 10;
		n2 = n2 / 10;
		f = n2 % 10;
		n2 = n2 / 10;
		g = n2 % 10;
		n2 = n2 / 10;
		if (a + b + c + d + e + f + g + i == n) {
			result = i;
			break;
		}
	}
	if (result == 9999999) {
		cout << 0 << endl;
	}
	else {
		cout << result << endl;

	}
	
	return 0;
}
