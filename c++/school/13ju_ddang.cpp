#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int tcase;
	cin >> tcase;
	for (int a = 0;a < tcase;a++) {
		int maxx = -99999;
		int maxy = -99999;
		int minx = 99999;
		int miny = 99999;
		int x, y;
		int num;
		cin >> num;
		for (int b = 0;b < num;b++) {
			cin >> x >> y;
			if (x > maxx) {
				maxx = x;
			}
			if (x < minx) {
				minx = x;
			}
			if (y > maxy) {
				maxy = y;
			}
			if (y < miny) {
				miny = y;
			}
		}
		int maxwidth = (maxx - minx)*(maxy - miny);
		cout << maxwidth << endl;
	}

	return 0;
}
