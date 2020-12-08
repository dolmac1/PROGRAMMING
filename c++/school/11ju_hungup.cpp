#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int tcase;
	cin >> tcase;
	for (int a = 0;a < tcase;a++) {
		int hang;
		int yeul;
		int hunggup2[51][51] = { 0 };
		cin >> hang >> yeul;
		int eorf;
		char eorf2;
		int maxsize = 0;
		for (int b = 0;b < hang;b++) {
			int yeulwich = 0;
			for (int c = 0;c <= yeul;c++) {
				cin >> eorf >> eorf2;
				if (eorf2 == 'f') {
					maxsize = max(maxsize, eorf);
					int eorfa = eorf;
					for (int d = yeulwich;d < yeulwich + eorf;d++) {
						hunggup2[b][d] = eorfa;
						eorfa--;
					}
					int yeulwich1 = yeulwich;
					for (int kk = 0;kk < 1;) {
						if (yeulwich1 != 0 && hunggup2[b][yeulwich1 - 1] != 0) {
							hunggup2[b][yeulwich1 - 1] = hunggup2[b][yeulwich1] + 1;
							yeulwich1--;
						}
						else {
							kk = 1;
						}
					}
				}
				yeulwich = yeulwich + eorf;
				c = yeulwich;
			}
		}
		for (int e = 0;e < yeul;e++) {
			for (int f = 0;f < hang;f++) {
				int finduplarge = 0;
				int finddownlarge = 0;
				if (hunggup2[f][e] != 0) {
					if (f == 0) {
						for (int g = 1;g < hang;g++) {
							if (hunggup2[g][e] >= hunggup2[f][e]) {
								finddownlarge++;
							}
							else {
								g = hang;
							}
						}
						maxsize = max(maxsize, (finddownlarge + 1)*hunggup2[f][e]);
					}
					else if (f == hang - 1) {
						for (int g = hang - 2;g > -1;g--) {
							if (hunggup2[g][e] >= hunggup2[f][e]) {
								finduplarge++;
							}
							else {
								g = -1;
							}
						}
						maxsize = max(maxsize, (finduplarge + 1)*hunggup2[f][e]);
					}
					else if (f > 0 && f < hang - 1) {
						for (int g = f + 1;g < hang;g++) {
							if (hunggup2[g][e] >= hunggup2[f][e]) {
								finddownlarge++;
							}
							else {
								g = hang;
							}
						}
						for (int g = f - 1;g > -1;g--) {
							if (hunggup2[g][e] >= hunggup2[f][e]) {
								finduplarge++;
							}
							else {
								g = -1;
							}
						}
						maxsize = max(maxsize, (finduplarge + finddownlarge + 1)*hunggup2[f][e]);

					}

				}
			}
		}
		cout << maxsize << endl;

	}
	return 0;
}
