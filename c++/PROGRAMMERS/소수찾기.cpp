#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> num;
    for(int i=0;i<=n;i++){
        num.push_back(1);
    }
    for(int i=2;i<=n;i++){
        if(num[i]==1){
            answer++;
            int mul_val=2;
            while(1){
                if(i*mul_val<=n){
                    num[i*mul_val]=0;
                    mul_val++;
                }
                else{break;}
            }
        }
    }
    return answer;
}
