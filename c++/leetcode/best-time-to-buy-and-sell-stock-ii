class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        for(int i=0; i<prices.size()-1; i++){
            if(prices[i+1]>prices[i]){
                result += (prices[i+1]-prices[i]);
            }
        }
        return result;
    }
};

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii
