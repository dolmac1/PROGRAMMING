#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int max_1 = 0;
    int max_2 = 0;
    for(int i=0;i<sizes.size();i++){
        if(sizes[i][0]>=sizes[i][1]){
            max_1 = max(max_1,sizes[i][0]);
            max_2 = max(max_2,sizes[i][1]);
        }
        else{
            max_1 = max(max_1,sizes[i][1]);
            max_2 = max(max_2,sizes[i][0]);
        }
    }
    answer = max_1*max_2;
    return answer;
}
