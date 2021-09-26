#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int dp[2][4] ={0};
    for(int i=0;i<land.size();i++){
        for(int j=0;j<4;j++){
            dp[0][j] = dp[1][j];
        }
        dp[1][0] = max(dp[0][1]+land[i][0],max(dp[0][2]+land[i][0],dp[0][3]+land[i][0]));
        dp[1][1] = max(dp[0][0]+land[i][1],max(dp[0][2]+land[i][1],dp[0][3]+land[i][1]));
        dp[1][2] = max(dp[0][1]+land[i][2],max(dp[0][0]+land[i][2],dp[0][3]+land[i][2]));
        dp[1][3] = max(dp[0][1]+land[i][3],max(dp[0][2]+land[i][3],dp[0][0]+land[i][3]));
    }
    for(int i=0;i<4;i++){
        cout<<dp[1][i]<<endl;
    }
    answer = max(max(dp[1][0],dp[1][1]),max(dp[1][2],dp[1][3]));
    return answer;
}
