function solution(s) {
    var answer = '';
    var arr = s.split(' ');
    let max = -99999;
    let min = 99999;
    for (var i = 0; i< arr.length; i++){
        if(arr[i]*1>max){
            max = arr[i]*1;
        }
        if(arr[i]*1<min){
            min = arr[i]*1;
        }
    }
    answer = `${min} ${max}`;
    return answer;
}

// 플그 level 2
