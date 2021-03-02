#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    answer.push_back(arr[0]);//첫번째 숫자를 벡터에 넣음
    for(int i=1;i<arr.size();i++){//벡터의 2번째숫자부터 return 벡터의 마지막 단어와 비교하여 같으면 넘어가고 다르면 넣어줌
        if(arr[i]==answer.back()){
            continue;
        }
        else{
            answer.push_back(arr[i]);
        }
    }
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}
