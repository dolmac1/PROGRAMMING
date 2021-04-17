#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		int x1,x2,y1,y2,r1,r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		int result = 9999;
		int a_far_b = pow(x2 - x1, 2) + pow(y2 - y1, 2);
		if (a_far_b == 0) {
			if (r1 - r2 == 0) {
				result = -1;
			}
			else {
				result = 0;
			}
		}
		else {
			if (pow(r1 + r2, 2) == a_far_b || pow(r1-r2,2) == a_far_b) {
				result = 1;
			}
			else if (pow(r1 - r2, 2) < a_far_b && a_far_b < pow(r1 + r2, 2)) {
				result = 2;
			}
			else {
				result = 0;
			}
		}
		
		cout << result << endl;
	}
	return 0;
}
