#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(vector<vector<int>> scores) {
    string answer = "";
    vector<double> average_score;
    for(int i=0;i<scores.size();i++){
        int except_num = 1;
        int max_num = 0;
        int max_count = 0;
        int min_num = 100;
        int min_count = 0;
        int sum_val = 0;
        for(int j=0;j<scores[i].size();j++){
            sum_val += scores[j][i];
            if(scores[j][i]>max_num){
                max_num = scores[j][i];
                max_count = 1;
            }
            else if(scores[j][i] == max_num){
                max_count++;
            }
            if(scores[j][i]<min_num){
                min_num = scores[j][i];
                min_count=1;
            }
            else if(scores[j][i] == min_num){
                min_count++;
            }
        }
        if(max_num == scores[i][i] && max_count == 1){
            except_num = 0;
        }
        if(min_num == scores[i][i] && min_count == 1){
            except_num = 0;
        }
        if(except_num == 0){
            sum_val-=scores[i][i];
            double imsi = sum_val/(scores[i].size()-1);
            average_score.push_back(imsi);
        }
        else{
            double imsi = sum_val/scores[i].size();
            average_score.push_back(imsi);
        }
    }
    for(int i=0;i<average_score.size();i++){
        cout<<average_score[i]<<" ";
        if(average_score[i]>=90){
            answer+="A";
        }
        else if(average_score[i]>=80){
            answer+="B";
        }
        else if(average_score[i]>=70){
            answer+="C";
        }
        else if(average_score[i]>=50){
            answer+="D";
        }
        else{
            answer+="F";
        }
    }
    return answer;
}
