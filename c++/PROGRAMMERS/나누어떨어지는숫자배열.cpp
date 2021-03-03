#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    for(int i=0;i<arr.size();i++){//5로 나누어떨어지면 vector에 넣어줌
        if(arr[i]%divisor == 0){
            answer.push_back(arr[i]);
        }
    }
    if(answer.size()==0){//비어있으면 -1넣어주고
        answer.push_back(-1);
    }
    else{//아닌경우에는 
        sort(answer.begin(),answer.end());    
    }
    
    return answer;
}
