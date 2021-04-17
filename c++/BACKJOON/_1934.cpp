#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
int gcd(int a, int b) {
	while (b!=0) {
		int temp = a%b;
		a = b;
		b = temp;
	}
	return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		int a, b;
		cin >> a >> b;
		int gcd_val = gcd(a, b);
		cout << a * b / gcd_val << endl;
	}
	return 0;
}
// 백준 최소공배수
