class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> answer;
        for(int i=1; i <= n; i++){
            string imsi = "";
            if(i%3!=0 && i%5!=0){
                imsi+=to_string(i);
            }
            else{
                if(i%3==0){
                    imsi+="Fizz";
                }
                if(i%5==0){
                    imsi+="Buzz";
                }
            }
            answer.push_back(imsi);
        }
        return answer;
    }
};

// https://leetcode.com/problems/fizz-buzz/submissions/
