#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    for(int i=0;i<arr1.size();i++){
        vector<int> imsi;
        for(int j=0;j<arr2[0].size();j++){
            int num = 0;
            for(int k=0;k<arr1[i].size();k++){
                num+=arr1[i][k]*arr2[k][j];
            }
            imsi.push_back(num);
        }
        answer.push_back(imsi);
    }
    return answer;
}
