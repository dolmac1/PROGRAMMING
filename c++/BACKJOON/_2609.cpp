#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int gcd(int a, int b) {
	int c;
	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	int a, b;
	cin >> a >> b;
	int gcd_val = gcd(a, b);
	cout << gcd_val <<" "<< (a*b)/gcd_val;
	return 0;
}

//유클리드 호제법
