#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for(int i=1;i<=n;i++){
        int num=0;
        int plus_num=i;
        while(1){
            num+=plus_num;
            if(num>n){
                break;
            }
            else if(num==n){
                answer++;
                break;
            }
            else{
                plus_num++;
            }
        }
        
    }
    return answer;
}
