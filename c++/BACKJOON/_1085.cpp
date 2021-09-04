//직사각형에서 탈출하기 s4 
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
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	cout << min(min(x - 0, w - x), min(y - 0, h - y));
	return 0;
}
