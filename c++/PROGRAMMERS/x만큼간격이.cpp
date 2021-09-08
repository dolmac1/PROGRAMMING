#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    int imsi = x-x;
    for(int i=0;i<n;i++){
        imsi+=x;
        answer.push_back(imsi);
    }
    return answer;
}
