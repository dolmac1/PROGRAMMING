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
 - let 과 const 는 블록범위({})안에서만 유효
 - let은 블록 유효 범위를 갖는 지역변수(var문과 사용법 같음) ex. let x;
 - const 는 선언할 때 초기화 해줘야함 const x = 2;
 - const가 상수면 변경할 수 없지만 객체이거나 배열이면 프로퍼티를 변경 가능 (ex. const orig = {x:1, y:2}; orig.x = 2;)
 - 함수 리터럴로 함수 선언 가능 ( ex. var square = function(x) {return x*x;}; )
 - 함수 리터럴에서 무명함수도 되고 이름 선언해줄 수 있음. 단, 함수 리터럴은 위로 끌어올려주지 않음
 - 객체의 메서드도 생성 가능하다
   > var circle = {<br>
   >  center: {x:1.0, y:2.0},<br>
   >  readius: 2.5,<br>
   >  area: function(){ //객체의 메서드<br>
   >  return Math.PI * this.radius * this.radius;<br>
   >  }<br>
   > };
 - 객체의 메서드는 circle.area(); 이런식으로 실행
 - 메서드도 프로퍼티의 일종이므로 추후에 추가 가능
   > circle.translate = function(a, b){<br>
   >  this.center.x = this.center.x + a;<br>
   >  this.center.y = this.center.y + b;<br>
   > };
 - 추후에 추가한 프로퍼티도 circle.translate(1,2); 이런식으로 실행 가능
3. 생성자
 - js에는 class가 없다. 생성자라고 하는 함수로 객체를 생성할 수 있다.
   > function Card(suit, rank){<br>
   >  this.suit = suit;<br>
   >  this.rank = rank;<br>
   > }
 - var card = new Card("하트","A");로 사용
 - new 연산자로 객체를 생성할 것으로 기대하고 만든 함수를 생성자라고 보면됨. 생성자는 파스칼 표기법(첫자만 대문자)으로 작명함.
 - 생성자와 new 연산자로 생성한 것을 인스턴스라고 부름, 인스턴스는 여러개 생성 가능
   > var card1 = new Card("하트","A");<br>
   > var card2 = new Card("다이아몬드", "2");<br>
   > var card3 = new Card("클로버","3");
 - 생성자는 함수이므로 프로퍼티에 대입도 가능
   > function exam(a,b){<br>
   >  this.a = a;<br>
   >  this.b = b;<br>
   >  this.c = a+b;<br>
   > }
4. 내장 객체
 - 자바스크립트는 내장 생성자가 있음.
 - Date 생성자는 날짜, 시간을 표현하는 내장 생성자. var now = new Date();로 사용 현재 시간을 넣어둠
 - var then = new Date(2020, 1, 5); 이런식으로 선언 가능
   > var start = new Date();<br>
   > var end = new Date();<br>
   > var time = end - start; //이렇게해서 걸린시간 밀리초 단위로 구할 수 있음
 - Function 생성자는 함수를 생성하는 생성자 var make_func = new Function("인수1","인수2",...., "동작");으로 사용 //ex. var make_func = new Function("x","return x*x");
5. 배열
 - 배열 리터럴은 []사이에 값을 넣어 선언 //var array = [2,4,6,8];
 - 배열 내에는 모든 타입의 값이 올 수 있음 //var array2 = [2,"a",true,{x:1, y:2},[1,2,3,4]];
 - 배열의 길이는 length 를 사용 (다른 언어들과 같음) //console.log(array.length); -> 4
 - Array 생성자로 배열을 생성 가능 //var a = new Array(1,2,3);
 - 단, 생성자로 생성할 때 인수가 1개에 양의 정수면 그 숫자의 길이만큼의 배열 생성, 음수는 불가능함
 - 배열에 삽입을 할 때, var array = [1,2,3]; 일 때 array[4] = 4;로 삽입하거나 array.push(4);로 삽입 가능
 - 삭제는 delete array[4]; 이 때 배열의 length는 줄어들지 않음.
 - 희소배열은 중간에 비어있는 배열 ex. a 배열이 [1,2,3,undifined,5]
 - property가 있는지 확인하는법 a.hasOwnProperty("4"); -> false, a.hasOwnProperty("3"); -> true
 
## 5장
