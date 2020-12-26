class Solution {
public:
    bool isHappy(int n) {
        vector<int> nums;
        while(1){ 
            int temp = 0;
            while(n){
                temp = temp + pow((n%10),2);
                n = n/10;
            }
            if(temp == 1){
                return true;
            }
            if(find(nums.begin(), nums.end(), temp)!= nums.end()){
                return false;
            }
            else{
                nums.push_back(temp);
                n=temp;
            }
        }
    }
};

// https://leetcode.com/problems/
