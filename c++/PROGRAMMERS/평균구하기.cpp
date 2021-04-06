#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    for(int i=0;i<arr.size();i++){
        if(i<arr.size()-1){
            answer+=arr[i];
        }
        else{
            answer = (answer + arr[i])/arr.size();
        }
    }
    return answer;
}
