#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> result_imsi;
    for(int i=0; i<moves.size();i++){//크레인이 지정된 칸에 인형이 있을 경우에는 그 값을 vector에 넣어주고 0으로 만들어서 빈칸으로 만들어줌
        for(int j=0;j<board.size();j++){
            if(board[j][moves[i]-1] == 0){
                continue;
            }
            else{
                result_imsi.push_back(board[j][moves[i]-1]);
                board[j][moves[i]-1] = 0;
                break;
            }
        }
    }
    for(int i=0;i<result_imsi.size()-1;i++){//i와 i+1번째를 비교해서 같을 경우에는 pop해주는데
        if(result_imsi[i]==result_imsi[i+1]){//같을경우에는 결과에+2를하고 두개의 값을 pop해준다.
            answer+=2;
            result_imsi.erase(result_imsi.begin()+i);
            result_imsi.erase(result_imsi.begin()+i);
            if(i==0&&result_imsi.size()>0){//이때 i가 0인경우에는 맨앞에서 터진것이기 때문에 그자리부터 다시 비교하면 된다. 단 vector가 size가 0이면 segmentation 에러 발생(i+1번째가 존재안하므로)하므로 예외해주고
                i--; //-1로 만들어줘서 다음 경우에는 바로 0번째부터 다시 비교하도록함
            }
            else{//나머지 경우에는 -2를 해서 바로 앞칸과 +1칸을 비교하도록 해줌
                i=i-2;
            }
        }
    }
    return answer;
}
