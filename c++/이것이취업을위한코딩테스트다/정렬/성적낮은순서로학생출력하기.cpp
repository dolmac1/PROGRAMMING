#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	map<int, string> result;
	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		string name;
		int exam;
		cin >> name >> exam;
		result.insert(pair<int,string>(exam, name));
	}
	while (!result.empty()) {
		cout << result.begin()->second << " ";
		result.erase(result.begin()->first);
	}
	return 0;
}
