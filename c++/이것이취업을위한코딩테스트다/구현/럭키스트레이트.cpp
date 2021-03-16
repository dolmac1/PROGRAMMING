#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	string score;
	cin >> score;
	int mid = score.length() / 2;
	int left_score = 0;
	int right_score = 0;
	for (int i = 0;i < mid;i++) {
		left_score += score[i];
		right_score += score[i + mid];
	}
	if (left_score == right_score) {
		cout << "LUCKY" << endl;
	}
	else {
		cout << "READY" << endl;
	}
	return 0;
}
