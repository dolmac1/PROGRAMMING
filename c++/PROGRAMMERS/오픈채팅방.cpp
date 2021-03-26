#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;
vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
 
    return answer;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> nickname;
    vector<string> record_el;
    vector<string> record_id;
    for(int i=0;i<record.size();i++){
        vector<string> imsi_record = split(record[i],' ');
        if(imsi_record[0] == "Enter"){
            if(nickname.find(imsi_record[1]) == nickname.end()){
                nickname.insert(pair<string,string>(imsi_record[1],imsi_record[2]));
            }
            else{
                nickname[imsi_record[1]]=imsi_record[2];
            }           
        }
        else if(imsi_record[0] == "Change"){
            nickname[imsi_record[1]]=imsi_record[2];
        }
        record_el.push_back(imsi_record[0]);
        record_id.push_back(imsi_record[1]);
    }
    for(int i=0;i<record_el.size();i++){
        string answer_push="";
        if(record_el[i]=="Enter"){
            answer_push = nickname[record_id[i]]+"님이 들어왔습니다.";
        }
        else if(record_el[i]=="Leave"){
            answer_push = nickname[record_id[i]]+"님이 나갔습니다.";
        }
        else{
            continue;
        }
        answer.push_back(answer_push);
    }
    return answer;
}
