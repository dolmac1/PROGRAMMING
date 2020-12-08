#include <iostream>
#include <math.h>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int tcase;
	cin >> tcase;
	for (int a = 0;a < tcase;a++) {
		int N;
		cin >> N;
		int *whatisin = new int[937501];
		for (int b = 0;b < 937501;b++) {
			whatisin[b] = 0;
		}
		int anumber;
		int bnumber;
		for (int c = 0;c < N;c++) {
			cin >> anumber;
			int mook1;
			int namuji1;
			mook1 = anumber / 32;
			namuji1 = anumber % 32;
			int kk = pow(2.0, (double)namuji1);
			whatisin[mook1] = whatisin[mook1] | kk;
		}
		int blanks = 0;
		for (int d = 0;d < N;d++) {
			cin >> bnumber;
			int mook2 = bnumber / 32;
			int namuji2 = bnumber % 32;
			int kk2 = pow(2.0, (double)namuji2);
			int samething = whatisin[mook2] & kk2;
			if (samething != kk2) {
				blanks = 1;
				cout << bnumber << " ";
			}

		}
		if (blanks == 0) {
			cout << "0";
		}
		cout << endl;
		delete whatisin;
	}
	return 0;
}
