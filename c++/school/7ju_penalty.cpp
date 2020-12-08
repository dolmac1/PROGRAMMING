#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int tcase;
	cin >> tcase;
	for (int a = 0;a < tcase;a++) {
		int round;
		cin >> round;
		int tcase2;
		cin >> tcase2;
		for (int b = 0;b < tcase2;b++) {
			int ascore;
			int bscore;
			int cor = 0;
			cin >> ascore >> bscore;
			if (ascore > bscore&&ascore - bscore > round - ascore + 2) 
			{
				cor = 1;
			}
			else if (bscore > ascore&&bscore - ascore > round - bscore + 1) {
				cor = 1;
			}
			if (cor == 1) {
				cout << 0 << endl;
			}
			else {
				cout << 1 << endl;
			}
		}
	}
	return 0;
}
