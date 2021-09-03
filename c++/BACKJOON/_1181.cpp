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
	set<string> result_vec[51];
	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		string m;
		cin >> m;
		result_vec[m.length()].insert(m);
	}
	for (int i = 0;i < 51;i++) {
		set<string>::iterator it;
		for (it = result_vec[i].begin();it != result_vec[i].end();it++) {
			cout << *it << endl;
		}
	}

	return 0;
}
