#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    for(int i=1;i<land.size();i++){
        land[i][0] = land[i][0] + max(land[i-1][1],max(land[i-1][2],land[i-1][3]));
        land[i][1] = land[i][1] + max(land[i-1][0],max(land[i-1][2],land[i-1][3]));
        land[i][2] = land[i][2] + max(land[i-1][0],max(land[i-1][1],land[i-1][3]));
        land[i][3] = land[i][3] + max(land[i-1][0],max(land[i-1][1],land[i-1][2]));
        
    }
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;
    int k = land.size()-1;
    answer = max(land[k][0], max(land[k][1],max(land[k][2],land[k][3])));
    return answer;
}
//플그 레벨2
