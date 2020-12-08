#include<iostream>
#include<queue>
using namespace std;

int fruit[8];
int cake;
int cnt = 0;
int qCnt = 0;
queue<int> qArr[256];

void setCake() {
	cake = 0;
	for (int i = 0; i < 8; i++) {
		if (fruit[i] >= 1)
			cake |= (1 << i);
	}
}

void getCake(int t) {

	int minIndex = 256;
	int min = 0;

	for (int i = 0; i < 256; i++) {
		if ((i & (1 << t)) == 0)
			continue;
		else {
			if ((i & cake) == i && !qArr[i].empty()) {
				if (min == 0) {
					min = qArr[i].front();
					minIndex = i;
					continue;
				}
				else if (min > qArr[i].front()) {
					minIndex = i;
					min = qArr[i].front();
				}
			}
		}
	}
	if (minIndex != 256) {
		qCnt--;
		int tmp = qArr[minIndex].front();
		qArr[minIndex].pop();
		cout << tmp << endl;
		for (int i = 0; i < 8; i++)
			if (minIndex & (1 << i))
				fruit[i]--;
	}
}


int main() {
	ios::sync_with_stdio(false);

	int N, tmp, order;

	char op;
	cin >> N;

	while (N--) {
		cin >> op;

		if (op == 'D') {
			cin >> tmp;
			fruit[tmp]++;
			setCake();
			if (qCnt) {
				getCake(tmp);
			}
			setCake();
		}
		else if (op == 'O') {
			cin >> tmp;
			order = 0;
			for (int i = 0; i < tmp; i++) {
				int orderTmp;
				cin >> orderTmp;
				order |= (1 << orderTmp);
			}

			if ((cake & order) == order) {
				cout << cnt << endl;
				for (int i = 0; i < 8; i++)
					if (order & (1 << i))
						fruit[i]--;
				setCake();
				cnt++;
			}
			else {
				qArr[order].push(cnt);
				cnt++;
				qCnt++;
			}
		}
	}

}
