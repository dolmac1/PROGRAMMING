#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	double score[1000];
	double max = 0;
	double total = 0;
	double average;
	for (int i = 0;i < n;i++) {
		cin >> score[i];
		if (score[i] > max) {
			max = score[i];
		}
	}
	for (int i = 0;i < n;i++) {
		score[i] = score[i] / max * 100;
		total = total + score[i];
	}
	average = total / n;
	cout.precision(4);
	cout << average;
	return 0;
}
