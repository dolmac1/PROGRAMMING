// 직각삼각형 b3
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <stack>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (1) {
		vector<int> a;
		int n;
		for (int i = 0;i < 3;i++) {
			cin >> n;
			a.push_back(n);
		}
		sort(a.begin(), a.end());

		if (a[0] == 0 && a[1] == 0 && a[2] == 0) {
			break;
		}
		if (a[0] * a[0] + a[1] * a[1] == a[2] * a[2]) {
			cout << "right" << endl;
		}
		else {
			cout << "wrong" << endl;
		}
	}

	return 0;
}
