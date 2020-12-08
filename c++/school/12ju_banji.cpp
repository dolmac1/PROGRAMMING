#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int tcase;
	cin >> tcase;
	for (int a = 0;a < tcase;a++) {
		int maeul[501];//°˘°˘ ¸śŔťľéŔÇ ĂÖ´Ü°Ĺ¸Ž
		int maeulgill[501][501];
		int maeulgill2[501][501];
		int maeulfar[500001];
		int visitthis[501];
		int locaa[500001];
		int locab[500001];
		int maxxx = 0;
		int howmanymaeul, maeulroad;
		cin >> howmanymaeul >> maeulroad;
		for (int aa = 0;aa <= howmanymaeul;aa++) {
			maeul[aa] = 10000000;
			visitthis[aa] = 0;
		}
		for (int b = 0;b <= howmanymaeul;b++) {
			for (int c = 0;c <= howmanymaeul;c++) {
				maeulgill[b][c] = 10000000;
				maeulgill2[b][c] = 10000000;
			}
		}
		for (int d = 0;d < maeulroad;d++) {
			int maeul1, maeul2, geri;
			cin >> maeul1 >> maeul2 >> geri;
			maeulgill[maeul1][maeul2] = geri;
			maeulgill[maeul2][maeul1] = geri;
			maeulgill2[maeul1][maeul2] = geri;
			maeulgill2[maeul2][maeul1] = geri;
			locaa[d] = maeul1;
			locab[d] = maeul2;
		}
		maeul[1] = 0;
		visitthis[1] = 1;
		int ttt = 0;
		for (int e = 1;e <= howmanymaeul;e++) {
			maeul[1] = 0;
			visitthis[1] = 1;
			if (e != 1) {
				int nextmins = 10000000;
				int nextminvals = 10000000;
				for (int hoho = 1;hoho <= howmanymaeul;hoho++) {
					if (visitthis[hoho] == 0 && maeul[hoho] < nextminvals) {
						nextmins = hoho;
						nextminvals = maeul[hoho];
					}
				}
				visitthis[nextmins] = 1;
				for (int f = 1;f <= howmanymaeul;f++) {
					if (maeulgill2[nextmins][f] != 10000000) {
						maeul[f] = min(maeul[f], maeul[nextmins] + maeulgill2[nextmins][f]);
					}
				}
			}
			else if (e == 1) {
				for (int f = 2;f <= howmanymaeul;f++) {
					if (maeulgill2[e][f] != 10000000) {
						maeul[f] = min(maeul[f], maeulgill2[e][f]);
					}
				}
			}
		}
		if (maeul[howmanymaeul] == 10000000) {
			goto a;
		}
		else {
			maeulfar[ttt] = maeul[howmanymaeul];
			ttt++;
			for (int g = 0;g < maeulroad; g++) {
				maeulgill2[locaa[g]][locab[g]] = 10000000;
				maeulgill2[locab[g]][locaa[g]] = 10000000;
				for (int bb = 2;bb <= howmanymaeul;bb++) {
					maeul[bb] = 10000000;
					visitthis[bb] = 0;
				}
				for (int e = 1;e <= howmanymaeul;e++) {
					if (e != 1) {
						int nextmins = 1;
						int nextminvals = 10000000;

						for (int hoho = 1;hoho <= howmanymaeul;hoho++) {
							if (visitthis[hoho] == 0 && maeul[hoho] < nextminvals) {
								if (nextmins != 1) {
									visitthis[nextmins] = 0;
								}
								nextminvals = maeul[hoho];
								nextmins = hoho;
								visitthis[nextmins] = 1;
							}
						}
						visitthis[nextmins] = 1;
						for (int f = 2;f <= howmanymaeul;f++) {
							if (maeulgill2[nextmins][f] != 10000000) {
								maeul[f] = min(maeul[f], maeul[nextmins] + maeulgill2[nextmins][f]);
							}
						}
					}
					else if (e == 1) {
						for (int f = 2;f <= howmanymaeul;f++) {
							if (maeulgill2[e][f] != 10000000) {
								maeul[f] = min(maeul[f], maeulgill2[e][f]);
							}
						}
					}
				}
				if (maeul[howmanymaeul] == 10000000) {
					goto a;
				}
				else {
					maeulfar[ttt] = maeul[howmanymaeul];
					ttt++;
				}
				maeulgill2[locaa[g]][locab[g]] = maeulgill[locaa[g]][locab[g]];
				maeulgill2[locab[g]][locaa[g]] = maeulgill[locab[g]][locaa[g]];
			}
			for (int h = 1;h <= maeulroad;h++) {
				maxxx = max(maxxx, maeulfar[h]);
			}
			cout << maxxx - maeulfar[0] << endl;
			goto b;
		}
	a: {}
		cout << "-1" << endl;
	b: {}
	}
	return 0;
}
