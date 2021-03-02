#include <string>
#include <vector>
using namespace std;

string solution(int a, int b) {
    string answer = "";
    int month[12]={31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //월별 날짜수
    string week[7]={"SUN","MON","TUE","WED","THU","FRI","SAT"}; //각 숫자에 해당하는 요일
    int day=5;//1월 1일 금요일은 5
    for(int i=0;i<a-1;i++){ //월별로 날짜를 이전 달까지 더함
        day=day+month[i];
    }
    day=(day+b-1)%7;//날짜 더하고 7로 나눠서 요일인 날짜를 구함(나머지)
    answer = week[day];
    return answer;
}
