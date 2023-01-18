/* const 멤버변수를 초기화하기 위해 멤버 이니셜라이저를 활용
    생성자() : a(_a)  이거 이름이 멤버 이니셜라이저라고 함.*/
/* 
   멤버 함수 상수화 
   함수명() const 
   참고로 책에는 안나왔지만 포인터로 해당 객체를 받을때 const 객체* 로 받아야
   사용가능한 함수 목록에 뜬다.
   public 이어도 const 함수는 객체가 const 일때 호출 가능.
   예시로 2-2 은행시스템 코드를 보면 SearchAccount 함수 리턴 값이 const Account* 인데
   이 포인터로 const 함수인 Get_Balance()에 접근 가능하다. 
*/

/* 아니네 설명 나와있네.
    "함수명 const 는 상수화된 함수라 상수화 되지 않음 함수의 호출을 허용하지 않는다.
	또 멤버 변수의 포인터를 리턴하는것도 허용하지 않는다."

	상수함수냐 아니냐에 따라서 오버로딩이 성립한다.(이건 안해봐서 몰랐음)
	둘다 호출 가능한 경우 상수아닌함수가 호출.
	우선순위 
	상수함수 < 상수X함수
	*/
/* explit= 명시적인것만 허용.
    mutable=const 함수에서도 변경 할수 있다. 예외를 주겠다.
	자세한 설명은 저번에 공부할때 블로그에 올려둔거 있음.*/

/*
class count
{
private:
	int val;
public:
	int& func()const { return val; } // 이런식으로 쓰면 안됨.
	void func2() const { func3(); } //이런식으로 쓰면 안됨.
	void func3() {};
};
int main()
{
	count c;
	c.func();
	c.func2();
}
*/

