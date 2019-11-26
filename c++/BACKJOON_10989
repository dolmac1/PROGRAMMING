//#include <iostream> //C++로 짜면 CIN,COUT때매 시간 초과 나서 C로 짬
//#include <string>
//#include <algorithm>
#include <stdio.h>
using namespace std;

int main(void)
{
//	cin.tie(NULL);
//	ios::sync_with_stdio(false);
	int N;
	//cin >> N;
	scanf("%d", &N);
	int max_num = 0;
	int num[10001] = { 0 };
	for (int i = 0;i < N;i++) {
		int number;
		//cin >> number;
		scanf("%d", &number);
		if (number > max_num) {
			max_num = number;
		}
		num[number]++;
	}
	for (int i = 0;i < max_num+1;i++) {
		if (num[i] > 0) {
			for (int j = 0;j < num[i];j++) {
				//cout << i << endl;
				printf("%d\n", i);
			}
		}
	}
	return 0;
}
