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
1. 표현식과 연산자
 - 표현식은 어떤 값으로 평가되는 것. 가장 간단한 표현식은 숫자, 문자열, 논리값 등의 원시값
 - 변수, 프로퍼티, 배열 요소, 함수 호출, 메서드 호출도 표현식이라고 할 수 있음
 - 연산자를 활용하여 더 복잡한 표현식을 만들어 낼 수 있다.
 - 연산자에도 우선순위 존재
   > |우선순위|연산자|결합법칙|
   > |-------|------|-------|
   > |1|()(그룹 연산자)|없음|
   > |2|., []|왼쪽 -> 오른쪽|
   > |2|new(인수 있음)|오른쪽 -> 왼쪽|
   > |3|()(함수 호출)|왼쪽 -> 오른쪽|
   > |3|new(인수 없음)|오른쪽 -> 왼쪽|
   > |4|++(후위), --(후위)|없음|
   > |5|!, ~, +(단항), -(부호반전), typeof, void, delete, ++(전위), --(전위)|오른쪽 -> 왼쪽|
   > |6|*, /, %| 왼쪽 -> 오른쪽|
   > |7|+, -, +(문자열 결합)|왼쪽 -> 오른쪽|
   > |8|<<,>>,>>>|왼쪽 -> 오른쪽|
   > |9|<,<=,>,>=,in,instanceof|왼쪽 -> 오른쪽|
   > |10|==,!=,===,!==|왼쪽 -> 오른쪽|
   > |11|&|왼쪽 -> 오른쪽|
   > |12|^|왼쪽 -> 오른쪽|
   > |13|\||왼쪽 -> 오른쪽|
   > |14|&&|왼쪽 -> 오른쪽|
   > |15|\|\||왼쪽 -> 오른쪽|
   > |16|?:|오른쪽 -> 왼쪽|
   > |17|yield, yield*|오른쪽 -> 왼쪽|
   > |18|=.+=.-=,*=,/=,%=,<<=,>>=,>>>=,&=,^=,\|=|오른쪽 -> 왼쪽|
   > |19|...|없음|
   > |20|,|왼쪽 -> 오른쪽|
 - 변수 값을 바꾸는 연산자를 부수 연산자(대입연산자, 증가연산자, 감소연산자, delete)
2. 산술 연산
 - 산술연산자는 피연산자가 숫자인 연산자
 - 산술 이항 연산자 : +,-,*,/,%
 - 산술 이항 연산자 특징
   > 정수끼리 나눠도 부동소수점이됨<br>
   > 나머지 연산자 %의 피연산자는 부동소수점이다.<br>
   > +연산자는 피연산자 하나라도 문자열이면 문자열 더하기로 바뀜<br>
   > 계산할 수 없는 경우 NaN으로 표시 (ex. 0/0 = NaN)
 - 산술 단항 연산자는 ++,--,+,-있다.
 - 산술 대입 연산자는 계산해서 대입하는 연산자 +=,-= 같은것
 - 복잡한 수학 연산자는 Math 객체가 지원하며, Math.sin 같은 방식으로 사용
 - 부동 소수점은 64비트로 사용, 자리수 문제로 오차가 있을 수 있음
 - 부호 1비트, 지수부 11비트, 가수부 52비트
 - 가수부는 2^53 = 약 16자리
3. 문자열 제어
 - 문자열은 + 연산자로 연결
 - 한쪽이라도 문자열이면 문자열 연결로 처리됨
 - var str = new String("asdfasdf");로 string 타입으로 선언하여 문자열 처리
 - 문자열이 프로퍼티를 사용하려고 하면 자동으로 string 객체로 변환
 - 문자열은 배열처럼 호출해 쓸 수 있으나 대입은 할 수 없음.
4. 논리연산자와 관계 연산자
 - 관계 연산자는 두 개의 피연산자 비교해서 true, false
 - ==는 값이 같다 ===는 값과 타입이 같다, != 값이다르다 !==는 값과 타입이 모두 다르다.
 - 좌우 피연산자의 타입이 같을 때, ==값이 같음을 비교하는데 원시 타입은 데이터 그 자체를 비교하지만 객체 타입은 객체의 참조를 비교
   > var a = [1,2,3];<br>
   > var b = [1,2,3];<br>
   > var c = a;<br>
   > //a==b -> false;<br>
   > //a==c -> true;
 - 배열에는 같은 데이터값이 들어있지만 메모리에서 차지하고 있는 위치가 달라서 false 가 나오는 것
 - 좌우 피연산자의 타입이 다를 때는
   - undifined와 null은 같은것
   - 한쪽이 숫자고 다른쪽이 문자열이면 문자열을 숫자로 변환하여 비교
   - 둘 중 한쪽이 논리값이라면 true = 1 false = 0으로 변환하여 비교
   - 한쪽이 객체고 다른 한쪽이 숫자 또는 문자열이면 toString 이나 valueOf를 사용하여 원시타입으로 변환하여 비교
   - 앞의 규칙을 벗어나면 모두 같지 않음으로 판정
 - 일치연산자는 연산자의 타입을 변환하지 않고 엄격하게 비교
   - NaN은 x !== x를 만족하는 유일한 식
 - 논리 연산자
   - &&은 양쪽 다 true 여야 true
   - ||는 한쪽 이상 true 면 true
   - !는 부정
   - !가 우선순위가 &&와 ||보다 높음
   - 논리 연산자의 피연산자값은 꼭 논리 값이 아니어도 됨
   - 논리 연산자는 단락평가를 함(앞의 연산이 표현식의 결과를 결정 지으면 뒤의 값의 결과를 구하지 않음) ex. ||연산자에서 앞의 연산이 true이면 무조건 true 이므로 뒤는 계산 x
5. 비트 연산
 - 비트 연산은 2진수 연산
   > & and 연산 <br>
   > | or 연산 <br>
   > ^ xor 연산 <br>
   > ~ not 연산
 - 비트 시프트 연산도 존재
   > \<\< 왼쪽 쉬프트 (시프트 후 나머지는 0으로 채운다)<br>
   > \>\> 오른쪽 쉬프트 (시프트 후 나머지는 부호값으로 채운다)<br>
   > \>\>\> 부호 없는 오른쪽 쉬프트 (시프트 후 나머지는 0으로 채운다)
 - 비트 연산의 대입 연산도 가능 ( &=, |=, ^=, <<=, >>=, >>>=)
6. 기타 연산
 - typeof : 데이터 타입 조사
 - ?: : 조건 연산자
 - void : 정의되지않은 값 반환
 - , : 왼쪽에서 오른쪽으로 피연산자 계속 수행
 - delete : 객체의 프로퍼티 삭제
 - new : 새로운 객체를 생성
 - in : 객체의 포함여부
 - instanceof : 객체의 종류 확인
 - eval : 인수로 받은 문자열을 자바스크립트 코드로 실행
7. 명시적 타입 변환
 - 숫자를 문자열로 변환
   - 숫자를 문자열과 연결하면 문자열이 됨 
     > 10 + "a", 10 + "", ("0000" + 12).slice(-4)
   - Number 객체의 메서드 활용
     > toString, toLocaleString, toFixed, toExponential, toPrecision
     > <br> var a = 1; a.toString, a.toLocaleString 이런식으로 사용
   - String 함수 사용
     > String(26) -> "26"
 - 문자열을 숫자로 변환
   - 묵시적인 방법
     > var a = "2"; <br> a - 0 <br> +a
   - parseInt, parseFloat 사용
   - Number 함수 사용
 - 논리값으로 변환
   - !!x , Boolean(x) 방법으로 사용
   
## 6장
1. 대화 상자
 - alert(경고창), prompt(입력창), confirm(확인, 취소창) 3개의 다화상자 존재
 - alert("안녕하세요"); 이런식으로 사용, 확인 클릭 시 호출한 부분으로 코드 제어권 돌아감
 - var name = prompt("이름을 입력해주세요"); 이런식으로 사용하며 내용 입력 누르고 확인 클릭 시 var로 값 들어감
 - prompt는 두번째 인수로 초기값 설정 가능 ( var name = prompt("이름을 입력하세요","김용수");)
 - parseInt, parseFloat 로 형변환도 가능 ( var age = parseInt(prompt("나이를 입력하세요"));)
 - var yesOrNo = comfirm("링크를 표시하겠습니까?"); 확인버튼은 true, 취소 버튼은 false 값 넘겨줌
2. console
 - console 창에 출력할 때 사용하며 console 객체는 보통 디버깅할때 사용
 - 콘솔에 텍스트를 출력하기 위해서는 (console.log(로그), console.info(정보), console.warn(경고), cosole.error(에러)) 메서드 사용
 - 객체의 프로퍼티를 나열하기 위해서 console.dir 사용
   > var a = {x:1, y:2};<br> console.dir(a);
 - 콘솔에 타이머 출력 가능(console.time("answer_time") ~ console.timeEnd("answer_time")) 인수가 같은 것을 찾을 때까지
   > console.time("answer_time"); <br> alert("눌렁"); <br> console.timeEnd("answer_time");
3. 이벤트 처리기 등록하기와 타이머 알아보기
 - 웹 브라우저는 이벤트 주도형 프로그램임(이벤트 발생 시, 응답을 주는 것)
 - 이벤트 처리기란 이벤트가 발생했을 때 실행하는 함수
 - HTML 요소의 속성에 이벤트 처리기 등록
   - 예제)콘솔에 시각 표시하기
   - 이벤트 처리기는 onclick, ondblclick, onmousedown 등등 있음
 - DOM에서 가져온 HTML 요소에 이벤트 처리기 지정하기
   - DOM 은 Document Object Model 의 약자로 html 요소를 조작할 수 있게 하는 인터페이스
   - DOM 에는 주요 객체가 아래와 같이 있음
     - window 는 웹브라우저 원도우 하나 또는 탭하나를 의미
     - document는 html 문서 전체를 가리킴, html 요소 객체를 가져오거나 새로 만드는 등의 기능을 제공
     - 요소 객체는 html 문서의 요소를 가리키는 객체
   - DOM을 사용하여 이벤트 처리기를 등록하는 전형적인 방법
     1. window.onload 를 사용하여 HTML 문서를 다 읽어들인 후 2,3번 수행
     2. document.getElementById를 사용하여 특정 id를 가진 html 요소를 가져옴
     3. 요소 객체의 이벤트 처리기 프로퍼티에 이벤트 처리길로 동작할 함수 등록
   - DOM을 사용한 이벤트 처리 예시는 6-2.html
   - 원래 javascript 부분은 html 불러오기 전에 먼저 읽어들이기 때문에 실행을 못하는데 window.onload를 사용하여 다 불러온 후에 실행하는 것
   - 이벤트 처리기 프로퍼티에 등록한 이벤트는 null 값을 대입하여 없앨 수 있음 ex) button.onclick = null;
 - 타이머
  - window 객체에는 setTimeout 과 setInterval 메서드 존재
  - setTimeout 함수를 쓰면 일정 시간 후에 호출되는 함수 생성 가능
    >setTimeout(function(){<br>
    >  console.log(Date());<br>
    >},2000);
    - 2000ms 후에 함수 실행
    - 첫번째 인자는 실행할 메서드, 두번째 인자는 기다릴 시간(ms 단위)
    - 단 clearTimeout() 사용 시 초기화되어 함수 실행 x
      > var a = setTimeout(console.log("a"),2000); <br> clearTimeout(a);
    - 지연시간을 0ms 로 설정하면 바로 수행할 것 같지만 이미 진행중인 메서드가 끝난 후에 실행됨
  - setInterval은 지정된 시간마다 반복하는 것
    >setInterval(function(){...}, 1000);
    - 이런식으로 사용 시, 1000ms 마다(1초) 1번씩 수행
    - setTimeout 과 마찬가지고 clearInterval을 통해서 중단 가능
    - 내용물에 문자열을 넣으면 eval()로 평가후 실행
4. html 요소를 동적으로 읽고 쓰기
 - 
