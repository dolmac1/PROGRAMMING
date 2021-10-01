using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    long long price_count = 0;
    for(int i=1;i<=count;i++){
        price_count += i;
    }
    answer = (price_count*price) - money;
    if(answer < 0){
        answer = 0;
    }
    return answer;
}
