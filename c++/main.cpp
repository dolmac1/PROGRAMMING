#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main() {
	int N; //process ��
	int a_t[10];//arrival time
	int priority[10];//priority
	int processnumber[10];
	int bursttime[10][40] = { 0 };//cpu burst, io burst Ȧ����° cpu ¦����° io(�� ��ġ�����δ� �ݴ�)
	int bursttime2[10][40] = { 0 };//burst time �����
	int times[10] = { 0 };//terminate �� ������ �� �ɸ��� �ð�
	int waiting[4][10];//waiting time
	int turnaround[4][10];//turnaround time
	int firstrunning[10] = { 0 };
	cout << "scheduling programing" << endl;
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> a_t[i] >> priority[i]; // �����ð��̶� �켱����
		processnumber[i]=i;
		int timenumber = 0;
		for (int j = 0;j == 0;) {
			if (cin.get() == '\n') {//���ͳ����� �̹� ���μ����� burst time�Է� �� 
				j = 1;
			}
			else {//enter�� ������ ������ �̹� ���μ����� bursttime
				cin >> bursttime[i][timenumber];
				bursttime2[i][timenumber]= bursttime[i][timenumber];
				times[i] = times[i] + bursttime[i][timenumber];
				timenumber = timenumber + 1;
			}
		}
	}
	//������ʹ� fifo���
	cout << "(FIFO)" << endl;
	queue<int> readyqueue;
	queue<int> ioqueue;
	int running = 11;
	int ioing = 11;
	for (int j = 0;j < 1000000;j++) {
		for (int k = 0;k < 10;k++) {
			if (a_t[k] == j) {
				readyqueue.push(processnumber[k]);
			}
		}//ó�� �����ϸ� ����ť�� �ֱ�
		if (running == 11 && !readyqueue.empty()) {//running�� ������ ť�� �Ǿ� ����
			running = readyqueue.front();
			cout << j << " " << readyqueue.front() << endl;
			readyqueue.pop();
			if (firstrunning[running] == 0) {
				waiting[0][running] = j - a_t[running];
				firstrunning[running] = 1;
			}
		}//running ���� ���ٸ� �ֱ�
		if (bursttime[running][0] == 0) {
			if (bursttime[running][1] == 0) {
				turnaround[0][running] = j - a_t[running];//�������μ����� turnaround time
				running = 11;
				if (running == 11 && !readyqueue.empty()) {//running�� ������ ť�� �Ǿ� ����
					running = readyqueue.front();
					cout << j << " " << readyqueue.front() << endl;
					readyqueue.pop();
					if (firstrunning[running] == 0) {
						waiting[0][running] = j - a_t[running];
						firstrunning[running] = 1;
					}

				}//������ �������� ������ ������ �ֱ�
			}
			else {//���� ������ ���� ���μ���
				ioqueue.push(running);
				for (int k = 0;k < 39;k++) {
					bursttime[running][k] = bursttime[running][k + 1];//�Ϸ������ ��ĭ�� �����
				}
				bursttime[running][39] = 0;
				running = 11;
				if (running == 11 && !readyqueue.empty()) {//running�� ������ ť�� �Ǿ� ����
					running = readyqueue.front();
					cout << j << " " << readyqueue.front() << endl;
					readyqueue.pop();
					if (firstrunning[running] == 0) {
						waiting[0][running] = j - a_t[running];
						firstrunning[running] = 1;
					}

				}//������ �������� ������
			}
		}
		if (ioing == 11&&!ioqueue.empty()) {//io���� ������ ť�� �Ǿ� ����
			ioing = ioqueue.front();
			ioqueue.pop();
		}
		else if(ioing!=11){//io ó������ ���� ���� ��
			if (bursttime[ioing][0] == 0) {
				readyqueue.push(ioing);
				for (int k = 0;k < 39;k++) {
					bursttime[ioing][k] = bursttime[ioing][k + 1];//�Ϸ������ ��ĭ�� �����
				}
				bursttime[ioing][39] = 0;
				ioing = 11;
			}
			if (ioing == 11 && !ioqueue.empty()) {//io���� ������ ť�� �Ǿ� ����
				ioing = ioqueue.front();
				ioqueue.pop();
			}
		}

		if (ioing == 11 && running == 11 && !ioqueue.empty() && !readyqueue.empty() && bursttime[0][0] == 0 && bursttime[1][0] == 0 && bursttime[2][0] == 0 && bursttime[3][0] == 0 && bursttime[4][0] == 0 && bursttime[5][0] == 0 && bursttime[6][0] == 0 && bursttime[7][0] == 0 && bursttime[8][0] == 0 && bursttime[9][0] == 0) {
			j = 1000000;
		}//�ٳ����� �����ϱ����� 
		if (running != 11) {
			bursttime[running][0]--;
		}
		if (ioing != 11) {
			bursttime[ioing][0]--;
		}
		//�������� �ð� 1�� ���ҽ�������
	}
	for (int h = 0;h < N;h++) {
		cout << "process " << h << " waiting time : " << waiting[0][h] << ", turn around time : " << turnaround[0][h] << endl;
	}
	for (int aa = 0;aa < 10;aa++) {
		for (int bb = 0;bb < 40;bb++) {
			bursttime[aa][bb] = bursttime2[aa][bb];
		}
	}
	for (int dd = 0;dd < 10;dd++) {
		firstrunning[dd] = 0;
	}
//-------------------------------------------------------------------------------------------------
	//���⼭���ʹ� SJF
	cout << "(SJF)" << endl;
	running = 11;
	ioing = 11;
	int testing[10] = { 0 };
	for (int j = 0;j < 1000000;j++) {
		for (int k = 0;k < 10;k++) {
			if (a_t[k] == j) {
				if (readyqueue.empty()) {
					readyqueue.push(processnumber[k]);
				}
				else {
					testing[processnumber[k]] = 1;
					while (!readyqueue.empty()) {
						testing[readyqueue.front()] = 1;
						readyqueue.pop();
					}
					for (int ss = 0;ss < 10;ss++) {
						int min = 1000000;
						int locate = 11;
						for (int tt = 0;tt < 10;tt++) {
							if (testing[tt] == 1 && bursttime[testing[tt]][0] < min) {
								min = bursttime[testing[tt]][0];
								locate = tt;
							}
						}
						if (min != 1000000) {
							readyqueue.push(locate);
							testing[locate] = 1000000;
						}
					}
				}
			}
		}//ó�� �����ϸ� ����ť�� �ֱ�
		if (running == 11 && !readyqueue.empty()) {//running�� ������ ť�� �Ǿ� ����
			running = readyqueue.front();
			cout << j << " " << readyqueue.front() << endl;
			readyqueue.pop();
			if (firstrunning[running] == 0) {
				waiting[1][running] = j - a_t[running];
				firstrunning[running] = 1;
			}
		}//running ���� ���ٸ� �ֱ�
		if (bursttime[running][0] == 0) {
			if (bursttime[running][1] == 0) {
				turnaround[1][running] = j - a_t[running];//�������μ����� turnaround time
				running = 11;
				if (running == 11 && !readyqueue.empty()) {//running�� ������ ť�� �Ǿ� ����
					running = readyqueue.front();
					cout << j << " " << readyqueue.front() << endl;
					readyqueue.pop();
					if (firstrunning[running] == 0) {
						waiting[1][running] = j - a_t[running];
						firstrunning[running] = 1;
					}

				}//������ �������� ������ ������ �ֱ�
			}
			else {//���� ������ ���� ���μ���
				  //ioqueue.push(running);
				if (ioqueue.empty()) {
					ioqueue.push(running);
				}
				else {
					testing[running] = 1;
					while (!ioqueue.empty()) {
						testing[ioqueue.front()] = 1;
						ioqueue.pop();
					}
					for (int ss = 0;ss < 10;ss++) {
						int min = 1000000;
						int locate = 11;
						for (int tt = 0;tt < 10;tt++) {
							if (testing[tt] == 1 && bursttime[testing[tt]][0] < min) {
								min = bursttime[testing[tt]][0];
								locate = tt;
							}
						}
						if (min != 1000000) {
							ioqueue.push(locate);
							testing[locate] = 1000000;
						}
					}
				}
				for (int k = 0;k < 39;k++) {
					bursttime[running][k] = bursttime[running][k + 1];//�Ϸ������ ��ĭ�� �����
				}
				bursttime[running][39] = 0;
				running = 11;
				if (running == 11 && !readyqueue.empty()) {//running�� ������ ť�� �Ǿ� ����
					running = readyqueue.front();
					cout << j << " " << readyqueue.front() << endl;
					readyqueue.pop();
					if (firstrunning[running] == 0) {
						waiting[1][running] = j - a_t[running];
						firstrunning[running] = 1;
					}

				}//������ �������� ������
			}
		}
		if (ioing == 11 && !ioqueue.empty()) {//io���� ������ ť�� �Ǿ� ����
			ioing = ioqueue.front();
			ioqueue.pop();
		}
		else if (ioing != 11) {//io ó������ ���� ���� ��
			if (bursttime[ioing][0] == 0) {
				//readyqueue.push(ioing);
				if (readyqueue.empty()) {
					readyqueue.push(ioing);
				}
				else {
					testing[ioing] = 1;
					while (!readyqueue.empty()) {
						testing[readyqueue.front()] = 1;
						readyqueue.pop();
					}
					for (int ss = 0;ss < 10;ss++) {
						int min = 1000000;
						int locate = 11;
						for (int tt = 0;tt < 10;tt++) {
							if (testing[tt] == 1 && bursttime[testing[tt]][0] < min) {
								min = bursttime[testing[tt]][0];
								locate = tt;
							}
						}
						if (min != 1000000) {
							readyqueue.push(locate);
							testing[locate] = 1000000;
						}
					}
				}
				for (int k = 0;k < 39;k++) {
					bursttime[ioing][k] = bursttime[ioing][k + 1];//�Ϸ������ ��ĭ�� �����
				}
				bursttime[ioing][39] = 0;
				ioing = 11;
			}
			if (ioing == 11 && !ioqueue.empty()) {//io���� ������ ť�� �Ǿ� ����
				ioing = ioqueue.front();
				ioqueue.pop();
			}
		}

		if (ioing == 11 && running == 11 && !ioqueue.empty() && !readyqueue.empty() && bursttime[0][0] == 0 && bursttime[1][0] == 0 && bursttime[2][0] == 0 && bursttime[3][0] == 0 && bursttime[4][0] == 0 && bursttime[5][0] == 0 && bursttime[6][0] == 0 && bursttime[7][0] == 0 && bursttime[8][0] == 0 && bursttime[9][0] == 0) {
			j = 1000000;
		}//�ٳ����� �����ϱ����� 
		if (running != 11) {
			bursttime[running][0]--;
		}
		if (ioing != 11) {
			bursttime[ioing][0]--;
		}
		//�������� �ð� 1�� ���ҽ�������
	}


	for (int h = 0;h < N;h++) {
		cout << "process " << h << " waiting time : " << waiting[1][h] << ", turn around time : " << turnaround[1][h] << endl;
	}
	for (int aa = 0;aa < 10;aa++) {
		for (int bb = 0;bb < 40;bb++) {
			bursttime[aa][bb] = bursttime2[aa][bb];
		}
	}
	for (int dd = 0;dd < 10;dd++) {
		firstrunning[dd] = 0;
	}
//-------------------------------------------------------------------------------------------------
	//���⼭���ʹ� PQ
	cout << "(priority)" << endl;
	running = 11;
	ioing = 11;
	int testing2[10] = { 0 };
	for (int j = 0;j < 1000000;j++) {
		for (int k = 0;k < 10;k++) {
			if (a_t[k] == j) {
				if (readyqueue.empty()) {
					readyqueue.push(processnumber[k]);
				}
				else {
					testing2[processnumber[k]] = 1;
					while (!readyqueue.empty()) {
						testing2[readyqueue.front()] = 1;
						readyqueue.pop();
					}
					for (int ss = 0;ss < 10;ss++) {
						int min = 1000000;
						int locate = 11;
						for (int tt = 0;tt < 10;tt++) {
							if (testing2[tt]==1&&priority[testing2[tt]] < min) {
								min = priority[testing2[tt]];
								locate = tt;
							}
						}
						if (min != 1000000) {
							readyqueue.push(locate);
							testing2[locate] = 1000000;
						}
					}
				}
			}
		}//ó�� �����ϸ� ����ť�� �ֱ�
		if (running == 11 && !readyqueue.empty()) {//running�� ������ ť�� �Ǿ� ����
			running = readyqueue.front();
			cout << j << " " << readyqueue.front() << endl;
			readyqueue.pop();
			if (firstrunning[running] == 0) {
				waiting[2][running] = j - a_t[running];
				firstrunning[running] = 1;
			}
		}//running ���� ���ٸ� �ֱ�
		if (bursttime[running][0] == 0) {
			if (bursttime[running][1] == 0) {
				turnaround[2][running] = j - a_t[running];//�������μ����� turnaround time
				running = 11;
				if (running == 11 && !readyqueue.empty()) {//running�� ������ ť�� �Ǿ� ����
					running = readyqueue.front();
					cout << j << " " << readyqueue.front() << endl;
					readyqueue.pop();
					if (firstrunning[running] == 0) {
						waiting[2][running] = j - a_t[running];
						firstrunning[running] = 1;
					}

				}//������ �������� ������ ������ �ֱ�
			}
			else {//���� ������ ���� ���μ���
				//ioqueue.push(running);
				if (ioqueue.empty()) {
					ioqueue.push(running);
				}
				else {
					testing2[running] = 1;
					while (!ioqueue.empty()) {
						testing2[ioqueue.front()] = 1;
						ioqueue.pop();
					}
					for (int ss = 0;ss < 10;ss++) {
						int min = 1000000;
						int locate = 11;
						for (int tt = 0;tt < 10;tt++) {
							if (testing2[tt] == 1 && priority[testing2[tt]] < min) {
								min = priority[testing2[tt]];
								locate = tt;
							}
						}
						if (min != 1000000) {
							ioqueue.push(locate);
							testing2[locate] = 1000000;
						}
					}
				}
				for (int k = 0;k < 39;k++) {
					bursttime[running][k] = bursttime[running][k + 1];//�Ϸ������ ��ĭ�� �����
				}
				bursttime[running][39] = 0;
				running = 11;
				if (running == 11 && !readyqueue.empty()) {//running�� ������ ť�� �Ǿ� ����
					running = readyqueue.front();
					cout << j << " " << readyqueue.front() << endl;
					readyqueue.pop();
					if (firstrunning[running] == 0) {
						waiting[2][running] = j - a_t[running];
						firstrunning[running] = 1;
					}

				}//������ �������� ������
			}
		}
		if (ioing == 11 && !ioqueue.empty()) {//io���� ������ ť�� �Ǿ� ����
			ioing = ioqueue.front();
			ioqueue.pop();
		}
		else if (ioing != 11) {//io ó������ ���� ���� ��
			if (bursttime[ioing][0] == 0) {
				//readyqueue.push(ioing);
				if (readyqueue.empty()) {
					readyqueue.push(ioing);
				}
				else {
					testing2[ioing] = 1;
					while (!readyqueue.empty()) {
						testing2[readyqueue.front()] = 1;
						readyqueue.pop();
					}
					for (int ss = 0;ss < 10;ss++) {
						int min = 1000000;
						int locate = 11;
						for (int tt = 0;tt < 10;tt++) {
							if (testing2[tt] == 1 && priority[testing2[tt]] < min) {
								min = priority[testing2[tt]];
								locate = tt;
							}
						}
						if (min != 1000000) {
							readyqueue.push(locate);
							testing2[locate] = 1000000;
						}
					}
				}
				for (int k = 0;k < 39;k++) {
					bursttime[ioing][k] = bursttime[ioing][k + 1];//�Ϸ������ ��ĭ�� �����
				}
				bursttime[ioing][39] = 0;
				ioing = 11;
			}
			if (ioing == 11 && !ioqueue.empty()) {//io���� ������ ť�� �Ǿ� ����
				ioing = ioqueue.front();
				ioqueue.pop();
			}
		}

		if (ioing == 11 && running == 11 && !ioqueue.empty() && !readyqueue.empty() && bursttime[0][0] == 0 && bursttime[1][0] == 0 && bursttime[2][0] == 0 && bursttime[3][0] == 0 && bursttime[4][0] == 0 && bursttime[5][0] == 0 && bursttime[6][0] == 0 && bursttime[7][0] == 0 && bursttime[8][0] == 0 && bursttime[9][0] == 0) {
			j = 1000000;
		}//�ٳ����� �����ϱ����� 
		if (running != 11) {
			bursttime[running][0]--;
		}
		if (ioing != 11) {
			bursttime[ioing][0]--;
		}
		//�������� �ð� 1�� ���ҽ�������
	}

	for (int h = 0;h < N;h++) {
		cout << "process " << h << " waiting time : " << waiting[2][h] << ", turn around time : " << turnaround[2][h] << endl;
	}
	for (int aa = 0;aa < 10;aa++) {
		for (int bb = 0;bb < 40;bb++) {
			bursttime[aa][bb] = bursttime2[aa][bb];
		}
	}
	for (int dd = 0;dd < 10;dd++) {
		firstrunning[dd] = 0;
	}
//-----------------------------------------------------------------------------
	//���⼭���ʹ� ����κ�
	cout << "(round robin)" << endl;
	running = 11;
	ioing = 11;
	int readytimeout = 1111110;
	int iotimeout = 1111110;

	for (int j = 0;j < 1000000;j++) {

		for (int k = 0;k < 10;k++) {
			if (a_t[k] == j) {
				readyqueue.push(processnumber[k]);
			}
		}//ó�� �����ϸ� ����ť�� �ֱ�
		if (running != 11 && readytimeout == j&&bursttime[running][0] != 0) {
			readyqueue.push(running);
			running = 11;
		}
		if (running == 11 && !readyqueue.empty()) {//running�� ������ ť�� �Ǿ� ����
			running = readyqueue.front();
			cout << j << " " << readyqueue.front() << endl;
			readyqueue.pop();
			if (firstrunning[running] == 0) {
				waiting[3][running] = j - a_t[running];
				firstrunning[running] = 1;
			}
		}//running ���� ���ٸ� �ֱ�

		if (bursttime[running][0] == 0) {
			if (bursttime[running][1] == 0) {
				turnaround[3][running] = j - a_t[running];//�������μ����� turnaround time
				running = 11;
				if (running == 11 && !readyqueue.empty()) {//running�� ������ ť�� �Ǿ� ����
					running = readyqueue.front();
					readytimeout = j + 10;
					cout << j << " " << readyqueue.front() << endl;
					readyqueue.pop();
					if (firstrunning[running] == 0) {
						waiting[3][running] = j - a_t[running];
						firstrunning[running] = 1;
					}

				}//������ �������� ������ ������ �ֱ�
			}
			else {//���� ������ ���� ���μ���
				ioqueue.push(running);
				for (int k = 0;k < 39;k++) {
					bursttime[running][k] = bursttime[running][k + 1];//�Ϸ������ ��ĭ�� �����
				}
				bursttime[running][39] = 0;
				running = 11;
				if (running == 11 && !readyqueue.empty()) {//running�� ������ ť�� �Ǿ� ����
					running = readyqueue.front();
					readytimeout = j + 10;
					cout << j << " " << readyqueue.front() << endl;
					readyqueue.pop();
					if (firstrunning[running] == 0) {
						waiting[3][running] = j - a_t[running];
						firstrunning[running] = 1;
					}

				}//������ �������� ������
			}
		}
		if (bursttime[ioing][0]!=0&&ioing != 11 && iotimeout == j) {
			ioqueue.push(ioing);
			ioing = 11;
		}
		if (ioing == 11 && !ioqueue.empty()) {//io���� ������ ť�� �Ǿ� ����
			ioing = ioqueue.front();
			iotimeout = j + 10;
			ioqueue.pop();
		}
		else if (ioing != 11) {//io ó������ ���� ���� ��
			if (bursttime[ioing][0] == 0) {
				readyqueue.push(ioing);
				for (int k = 0;k < 39;k++) {
					bursttime[ioing][k] = bursttime[ioing][k + 1];//�Ϸ������ ��ĭ�� �����
				}
				bursttime[ioing][39] = 0;
				ioing = 11;
			}
			if (ioing == 11 && !ioqueue.empty()) {//io���� ������ ť�� �Ǿ� ����
				ioing = ioqueue.front();
				iotimeout = j + 10;
				ioqueue.pop();
			}
		}


		if (ioing == 11 && running == 11 && !ioqueue.empty() && !readyqueue.empty() && bursttime[0][0] == 0 && bursttime[1][0] == 0 && bursttime[2][0] == 0 && bursttime[3][0] == 0 && bursttime[4][0] == 0 && bursttime[5][0] == 0 && bursttime[6][0] == 0 && bursttime[7][0] == 0 && bursttime[8][0] == 0 && bursttime[9][0] == 0) {
			j = 1000000;
		}//�ٳ����� �����ϱ����� 
		if (running != 11) {
			bursttime[running][0]--;
		}
		if (ioing != 11) {
			bursttime[ioing][0]--;
		}
		//�������� �ð� 1�� ���ҽ�������
	}
	for (int h = 0;h < N;h++) {
		cout << "process " << h << " waiting time : " << waiting[3][h] << ", turn around time : " << turnaround[3][h] << endl;
	}
	return 0;
}