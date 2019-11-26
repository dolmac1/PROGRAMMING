#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int tcase;
	cin >> tcase;
	for (int a = 0;a < tcase;a++) {
		int hobitnum;
		int breadnum;
		int hobitwant[10000] = { 0 };
		cin >> hobitnum >> breadnum;
		int totalwant = 0;
		int totalgive = 0;
		for (int b = 0;b < hobitnum;b++) {
			cin >> hobitwant[b];
			totalwant = totalwant + hobitwant[b];

		}
		int okays = 0;
		int locate = 0;
		int sumh = totalwant;
		if (totalwant <= breadnum) {
			okays = 1;
		}
		else if (totalwant > breadnum) {
			sort(hobitwant, hobitwant + hobitnum);
			for (int d = hobitnum - 2;d >= 0;d--) {//
				sumh = sumh - (hobitnum - d - 1)*(hobitwant[d + 1] - hobitwant[d]);
				if (sumh < breadnum) {
					locate = d;
					d = -1;

				}
			}
		}//
		int k = breadnum - sumh;
		k = k / (hobitnum - locate - 1);
		totalgive = sumh + (k*(hobitnum - locate - 1));
		if (okays == 1) {
			cout << totalwant << endl;
		}
		else {
			cout << totalgive << endl;
		}
	}
	return 0;
}