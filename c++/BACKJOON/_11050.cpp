//이항계수1 b1
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <stack>
using namespace std;

int factorial(int a) {
	int result = 1;
	for (int i = 1;i <= a;i++) {
		result = result * i;
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	
	cout << factorial(n)/(factorial(m)*factorial(n-m));

	return 0;
}
