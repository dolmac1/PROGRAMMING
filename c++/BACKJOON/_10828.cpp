//스택 s4
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <stack>
#include <set>
using namespace std;

bool cmp(pair<int, string> a, pair<int, string> b) {
		return a.first < b.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> stack_vec;
	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		string stack_job;
		cin >> stack_job;
		if (stack_job == "push") {
			int num;
			cin >> num;
			stack_vec.push_back(num);
		}
		else if (stack_job == "pop") {
			if (stack_vec.size() != 0) {
				cout << stack_vec[stack_vec.size() - 1] << '\n';
				stack_vec.pop_back();
			}
			else {
				cout << -1 << '\n';
			}
		}
		else if (stack_job == "size") {
			cout << stack_vec.size() << '\n';
		}
		else if (stack_job == "empty") {
			if (stack_vec.size() == 0) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else if (stack_job == "top") {
			if (stack_vec.size() != 0) {
				cout << stack_vec[stack_vec.size() - 1] << '\n';
			}
			else {
				cout << -1 << '\n';
			}
		}
		else {

		}
	}

	return 0;
}
