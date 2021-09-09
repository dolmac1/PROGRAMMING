//s4 팩토리얼 0갯수
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
	int result = 0;
	int five = 0;
	int two = 0;
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		int fact_val = i;
		while (1) {
			if (fact_val % 5 == 0 || fact_val % 2 == 0) {
				if (fact_val % 5 == 0) {
					five++;
					fact_val /= 5;
				}
				if (fact_val % 2 == 0) {
					two++;
					fact_val /= 2;
				}
			}
			else {
				break;
			}

		}
	}
	cout << min(two, five) << '\n';
	return 0;
}
