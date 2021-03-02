#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int result_arr[201] = { 0 }; // 합계가 존재하는지 넣어줄 배열
    for(int i=0;i<numbers.size()-1;i++){
        for(int j=i+1;j<numbers.size();j++){
            if(result_arr[numbers[i]+numbers[j]]==0){ // 두수의 합인 곳이 지금 없다고 표시되어있을 경우에는
                result_arr[numbers[i]+numbers[j]]++; // 1로 표시
            }
        }
    }
    for(int i=0;i<201;i++){
        if(result_arr[i]!=0){ //합이 존재하지 않는 곳만 0이기때문에 0이 아니면 정답에 push해줌
            answer.push_back(i);
        }
    }
    return answer;
}
