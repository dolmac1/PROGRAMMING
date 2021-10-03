#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    string answer = "";
    int max_answer = 0;
    for(int i=0;i<table.size();i++){
        vector<string> table_vec;
        map<string, int> table_div;
        string imsi="";
        int push_num = 0;
        for(int j=0;j<table[i].length();j++){
            if(table[i][j] != ' '){
                imsi+=table[i][j];
            }
            else{
                table_vec.push_back(imsi);
                table_div.insert({imsi,push_num});
                push_num++;
                imsi="";
            }
        }
                table_vec.push_back(imsi);
                table_div.insert({imsi,push_num});        
        int total_num = 0;
        for(int j=0;j<languages.size();j++){
            if(table_div[languages[j]] != 0){
                total_num+=(preference[j]*(table_vec.size()-table_div[languages[j]]));
            }
        }
        if(total_num>max_answer){
            max_answer=total_num;
            answer = table_vec[0];
        }
        else if(total_num == max_answer){
            if(answer[0]>table_vec[0][0]){
                answer = table_vec[0];
            }
        }
    }
    return answer;
}
