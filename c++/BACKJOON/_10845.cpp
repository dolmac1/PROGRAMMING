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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	queue<int> queue_vec;
	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		string queue_job;
		cin >> queue_job;
		if (queue_job == "push") {
			int num;
			cin >> num;
			queue_vec.push(num);
		}
		else if (queue_job == "pop") {
			if (queue_vec.size() != 0) {
				cout << queue_vec.front() << '\n';
				queue_vec.pop();
			}
			else {
				cout << -1 << '\n';
			}
		}
		else if (queue_job == "size") {
			cout << queue_vec.size() << '\n';
		}
		else if (queue_job == "empty") {
			if (queue_vec.size() == 0) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else if (queue_job == "front") {
			if (queue_vec.size() != 0) {
				cout << queue_vec.front() << '\n';
			}
			else {
				cout << -1 << '\n';
			}
		}
		else if (queue_job == "back") {
			if (queue_vec.size() != 0) {
				cout << queue_vec.back() << '\n';
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
