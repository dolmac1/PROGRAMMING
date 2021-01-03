class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        else{
            string number = "1";
            for(int loop_ct = 0;loop_ct < n-1;loop_ct++){
                char num = number[0];
                int count = 1;
                string result = "";
                for(int i=1;i<number.size();i++){
                    if(num == number[i]){
                        count++;
                    }
                    else{
                        result = result+to_string(count)+num;
                        num = number[i];
                        count = 1;
                    }
                }
                result = result+to_string(count)+num;
                number = result;
                cout << number <<endl;
            }
            return number;
        }
        return "0";
    }
};

// https://leetcode.com/problems/count-and-say
