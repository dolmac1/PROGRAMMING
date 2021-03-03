#include <vector>
#include <bitset>
using namespace std;

int solution(vector<int> nums)
{
    bitset<200001> a;//200000종류의 폰켓몬이 1~200000까지의 이름을 달고있으니 그만큼의 bitset 선언(이미 만난 포켓몬은 1로) 
    a.reset();
    int answer = 0;
    for(int i=0; i<nums.size();i++){
        if(!a.test(nums[i])){//아직까지 한번도 못본 폰켓몬이면 종류수에 1더하고 bitset을 1로 set
            answer++;
            a.set(nums[i]);
        }
    }
    if(answer > nums.size()/2){//절반보다 많은 종류의 폰켓몬이 있으면 절반가져갈 수 있으므로 바꿔줌
        answer = nums.size()/2;
    }
    
    return answer;
}
