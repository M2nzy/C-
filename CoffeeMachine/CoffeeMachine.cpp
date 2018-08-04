#include <iostream> // iostream 헤더파일 선언
#include <string> // string 헤더파일 선언
using namespace std; //std 네임스페이스 사용

class Circle // Circle 클래스 선언
{
	int radius; // 정수 반지름 변수 선언
	string name; // 문자열 이름 변수 선언
public: // 사용할 수 있도록 public으로
	void setCircle(string name, int radius); // 원의 이름과 반지름을 설정하는 함수
	double getArea(); // 원의 면적을 반환하는 함수
	string getName(); // 원의 이름을 반환하는 함수
};

void Circle::setCircle(string name, int radius) // 원의 이름과 반지름을 설정하는 함수 구현하기
{
	this->radius = radius; // 매개변수의 radius를 클래스의 private 멤버 radius에 넣기
	this->name = name; // 매개변수의 name을 클래스의 private 멤버 name에 넣기
}
double Circle::getArea(){ // 원의 면적을 반환하는 함수 구현하기
	return 3.14 * radius * radius; // 원의 면적을 구하여 반환
}
string Circle::getName() { // 원의 이름을 반환하는 함수 구현하기
	return name; // 원의 이름을 반환
}

class CircleManager { // 원을 배열로 관리하는 클래스
	Circle *p; // Circle 클래스의 포인터
	int size; // 배열의 크기
public: // 쓸 수 있도록 public으로
	CircleManager(int size); // size크기의 배열을 동적 생성
	~CircleManager(); // 소멸자
	void searchByName(); // 사용자로부터 원의 이름을 입력받아 면적 출력
	void searchByArea(); // 사용자로부터 면적을 입력받아 면적보다 큰 원의 이름과 면적을 출력
};
CircleManager::CircleManager(int size) { // size 크기의 배열을 동적 생성하는 생성자
	p = new Circle[size]; // 포인터 p에 size 크기의 배열을 동적 생성함
	this->size = size; // private 멤버 size에 매개변수 size를 넣음
	for (int i = 0; i < size; i++) // i=0부터 size 전까지 반복하며 증가
	{
		string cin_name; // 입력받을 이름
		int cin_radius; // 입력받을 반지름
		cout << "원 " << i+1 << "의 이름과 반지름 >> "; // 사용자에게 이름과 반지름을 입력하라고 명령
		cin >> cin_name; // 이름 입력받기
		cin >> cin_radius; // 반지름 입력받기
		p[i].setCircle(cin_name, cin_radius); // p의 i번째 배열에다가 입력받은 이름과 반지름을 설정함
	}
	searchByName(); // 사용자로부터 원의 이름을 입력받아 면적 출력하는 함수 실행
	searchByArea(); // 사용자로부터 면적을 입력받아 면적보다 큰 원의 이름과 면적을 출력하는 함수 실행
}
CircleManager::~CircleManager() { // 소멸자
	delete [] p; // 동적 생성된 것을 삭제함
}
void CircleManager::searchByName() { // 사용자로부터 원의 이름을 입력받아 면적 출력하는 함수
	string search_name; // 찾고자 하는 이름 선언
	cout << "검색하고자 하는 원의 이름 >> "; // 입력 명령
	cin >> search_name; // 찾고자 하는 이름을 입력받음
	for (int i = 0; i < size; i++) // i=0부터 size 전까지 i를 증가하면서 반복
	{
		if (search_name == p[i].getName()) // 만약 입력받은 이름과 p의 i번째 이름이 같다면
			cout << p[i].getName() << "의 면적은 " << p[i].getArea() << endl; // p의 i번째 이름과 면적을 출력
	}
}
void CircleManager::searchByArea() { // 사용자로부터 면적을 입력받아 면적보다 큰 원의 이름과 면적을 출력하는 함수
	int small_size; // 최소 면적 변수 선언
	cout << "최소 면적을 정수로 입력하세요 >> "; // 입력 명령
	cin >> small_size; // 최소 면적을 입력받음
	cout << small_size << "보다 큰 원을 검색합니다." <<endl; // 안내 메세지
	for (int i = 0; i < size; i++) // i=0부터 size 전까지 i를 증가하면서 반복
	{
		if (p[i].getArea() > small_size) // 만약 p의 i번째 면적이 최소 면적보다 크다면
		{
			cout << p[i].getName() << "의 면적은 " << p[i].getArea() << ", "; // p의 i번째 이름과 면적을 출력
		}
	}
	cout << endl; // 줄바꿈
}

int main() // 메인 함수
{
	cout << "원의 개수 >> "; // 입력 명령
	int circle_size; // 원의 개수 선언
	cin >> circle_size; // 원의 개수 입력받음
	CircleManager::CircleManager(circle_size); // CircleManager::CircleManager(int size) 생성자 실행함
	return 0; // 종료
}