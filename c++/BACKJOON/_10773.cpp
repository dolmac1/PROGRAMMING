//제로 s3
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <stack>
using namespace std;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;

	int answer = 0;
	stack<int> input_val;
	for (int i = 0;i < n;i++) {
		int k;
		cin >> k;
		if (k != 0) {
			answer += k;
			input_val.push(k);
		}
		else {
			answer -= input_val.top();
			input_val.pop();
		}

	}
	cout << answer << '\n';

	return 0;
}
