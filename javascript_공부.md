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
   > var dot = { x:1, y:2 };<br>
   > var circle = {<br>
        center: {x:1,y:2};<br>
        radius: 2.5;<br>
     };  //circle.center.x는 결과값 1<br>
   > var person ={ name:"김용수", age:27, gender:"남"};
 - 프로퍼티에 저장된 값의 타입이 함수면 메서드라고 부름 //c++ 클래스 내의 함수라고 보면 될듯?
 - 객체는 참조 타입이라서 var a = card; 로 하면 a = {"suit":"하트", "rank":"A" };로 된다.
2. 함수
 - y = f(x)
 - function 키워드를 사용해서 선언
   > function sqare(x) { return x*x; } 
 - 함수는 캐멀표기법이나 밑줄 표기법으로 이름 지정, 이름만으로도 기능을 이해하기 쉽게 만들어야함
 - sqare(3) 이런식으로 호출함. 다른 언어들이랑 똑같다.
 - 함수도 변수랑 마찬가지로 프로그램의 아무 위치에나 선언할 수 있음
   > console.log(square(5));<br>
   > function square(x) { return x*x; }
 - 자바스크립트에선 함수가 객체임. 함수 선언문으로 함수를 선언하여 사용가능
   > var sq = square;<br>
   > console.log(sq(5));
 - 함수의 인수가 많아지면 고칠때 힘듬. 따라서 함수에 인수를 넘길 때 객체 프로퍼티를 이용해서 넘기면됨(변수의 순서가 바뀌어도 상관없다)
 - 전역변수랑 똑같은 이름을 가진 함수내 지역변수가 있으면 지역변수 우선
 - 함수 내에서 변수를 선언하지 않은 상태에서 대입하면 전역변수로 설정
   > funtion f(){<br>
   > a="local";<br>
   > console.log(a);  //local <br>
   > return a;<br>
   > }<br>
   > console.log(a); // local
 - 
