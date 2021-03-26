#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int x_val = x;
    int x_sum = 0;
    while(x_val){
        x_sum= x_sum + (x_val%10);
        x_val/=10;
    }
    if(x%x_sum != 0){
        answer = false;
    }
    return answer;
}
