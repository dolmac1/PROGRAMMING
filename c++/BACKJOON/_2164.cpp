//카드2 s4
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <stack>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	queue<int> result;
	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		result.push(i + 1);
	}
	while (result.size() != 1) {
		result.pop();
		result.push(result.front());
		result.pop();
	}
	cout << result.front();

	return 0;
}
