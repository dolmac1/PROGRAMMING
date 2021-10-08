#include <string>
#include <vector>
#include <iostream>
using namespace std;
string level_one(string new_id){
    for(int i=0;i<new_id.length();i++){
        if(new_id[i]>='A' && new_id[i]<='Z'){
            new_id[i]=new_id[i]-'A'+'a';
        }
    }
    return new_id;
}
string level_two(string new_id){
    string answer="";
    for(int i=0;i<new_id.length();i++){
        if((new_id[i]>='a'&&new_id[i]<='z') 
           || (new_id[i]>='0' && new_id[i]<='9') 
           || new_id[i]=='-'
           || new_id[i]=='_'
           || new_id[i]=='.'){
            answer+=new_id[i];
        }
    }
    return answer;
}
string level_three(string new_id){
    string answer="";
    answer+=new_id[0];
    for(int i=1;i<new_id.length();i++){
        int add_val = 1;
        if(new_id[i]=='.'&&new_id[i-1]=='.'){
            add_val=0;
        }
        if(add_val == 1){
            answer+=new_id[i];
        }
    }
    return answer;
}
string level_four(string new_id){
    string answer ="";
    for(int i=0;i<new_id.length();i++){
        int add_val = 1;
        if(i==0 || i==new_id.length()-1){
            if(new_id[i]=='.'){
                add_val = 0;
            }
        }
        if(add_val == 1){
            answer+=new_id[i];
        }
    }
    return answer;
}
string level_five(string new_id){
    if(new_id.length()==0){
        return "a";
    }
    else{
        return new_id;
    }
}
string level_six(string new_id){
    string answer="";
    if(new_id.length()>=16){
        for(int i=0;i<15;i++){
            if(i!=14){
                answer+=new_id[i]; 
            }
            else{
                if(new_id[i]!='.'){
                    answer+=new_id[i];
                }
            }
        }
        return answer;
    }
    else{
        return new_id;
    }
}
string level_seven(string new_id){
    string answer="";
    if(new_id.length()==1){
        for(int i=0;i<3;i++){
            answer+=new_id[0];
        }
    }
    else if(new_id.length()==2){
        answer+=new_id[0];
        answer+=new_id[1];
        answer+=new_id[1];
        
    }
    else{
        answer = new_id;
    }
    return answer;
}
string solution(string new_id) {
    string answer = "";
    new_id = level_one(new_id);
    new_id = level_two(new_id);
    new_id = level_three(new_id);
    new_id = level_four(new_id);
    new_id = level_five(new_id);
    new_id = level_six(new_id);
    answer=level_seven(new_id);
    return answer;
}
