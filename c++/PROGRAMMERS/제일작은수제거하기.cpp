#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    if(arr.size()==1){
        answer.push_back(-1);
    }
    else{
        int min_val = 99999;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<min_val){
                min_val = arr[i];
            }
        }
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=min_val){
                answer.push_back(arr[i]);
            }
        }
    }
    return answer;
}
