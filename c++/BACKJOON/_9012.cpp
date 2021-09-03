//괄호 
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
	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		string vps;
		cin >> vps;
		stack<char> vps_stack;
		int isvps = 1;
		for (int j = 0;j < vps.length();j++) {
			if (vps[j] == '(') {
				vps_stack.push('(');
			}
			else {
				if (!vps_stack.empty()) {
					vps_stack.pop();
				}
				else {
					isvps = 0;
					break;
				}
			}
		}
		if (!vps_stack.empty()) {
			isvps = 0;
		}
		if (isvps == 1) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

	return 0;
}
