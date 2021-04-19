#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	int arr[1001];
	arr[1] = 1;
	arr[2] = 2;
	int n;
	cin >> n;
	for (int i = 3;i <= n;i++) {
		arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
	}
	cout << arr[n] << endl;
	return 0;
}
