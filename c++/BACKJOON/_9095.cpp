#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	int number[12];
	number[1] = 1;
	number[2] = 2;
	number[3] = 4;
	for (int i = 4;i < 12;i++) {
		number[i] = number[i - 3] + number[i - 2] + number[i - 1];
	}
	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		int num;
		cin >> num;
		cout << number[num] << endl;
	}
	return 0;
}
