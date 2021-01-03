# 모던 자바스크립트 입문

## 3장

1. 자바스크립트는 변수를 뒤에 선언해줘도 앞으로 당겨와서 출력해줌
 - colsole.log(a);
   var a; 로 해도 된다는 뜻
   (단, var a=5;와 같이 아래에 선언해두면 var a;는 위로 당겨서 수행하지만 a=5는 colsole.log보다 뒤에서 수행)
2. 심벌 = 자기 자신을 제외한 그 어떤 값과도 다른 유일무이한 값
 - var sym1 = Symbol();로 선언
 - sym1 == sym2 //false
 - var A = Symbol("A");로 선언 가능 //colsole.log(A.toString());  해보면 Symbol(A)로 나옴
 - 심벌과 문자열 연결 가능 //Symbol.for("문자열"); 이건 sym1 == sym2 하면 true 
3. 출력할 때 console.log("i = " + i); 대신 console.log(`i = ${i}`);로 출력하면 동일한 결과 출력할 수 있음 (템플릿 리터럴)

## 4장

1. 객체 리터럴
 - var card = { "suit":"하트", "rank":"A" }; 이런식으로 선언
 - card.suit 또는 card["rank"] 이런식으로 호출
 - 객체에 없는 것 호출 시 undifined(ex. card.color)
 - 빈 객체도 생성 가능(var obj = {})
 - card.value = 1; 로 추가가능
 - delete card.value;로 삭제 가능
 - in 연산자 사용해서 객체 안에 프로퍼티가 있는지 확인 가능 ex. if("suit" in card) 이런 식으로 쓰면 true
 - 객체 리터럴 사용 예시
   > var dot = { x:1, y:2 };\n
   > var circle = {
        center: {x:1,y:2};
        radius: 2.5;
     };  //circle.center.x는 결과값 1
   > var person ={ name:"김용수", age:27, gender:"남"};
   
2. 
