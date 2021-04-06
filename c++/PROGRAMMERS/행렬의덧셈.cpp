#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    for(int i=0;i<arr1.size();i++){
        vector<int> imsi_answer;
        for(int j=0;j<arr1[i].size();j++){
            int k = arr1[i][j] + arr2[i][j];
            imsi_answer.push_back(k);
        }
        answer.push_back(imsi_answer);
        
    }
    return answer;
}
