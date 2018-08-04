#include <iostream>
#include <string>
#include <cstdlib> // 난수 생성 위한 헤더파일
#include <ctime> // 난수 생성 위한 헤더파일
#include <Windows.h> // 딜레이를 주기 위한 헤더파일(Sleep)
using namespace std;

class Player { // 클래스 Player 선언
	string name;
public: 
	void setName(string name); // 이름 설정하는 함수
	string getName(); // 이름을 반환하는 함수
};
void Player::setName(string name)
{
	this->name = name;
}

string Player::getName()
{
	return name; 
}
class GamblingGame { // GamblingGame 클래스 선언
	Player *p; 

public: 
	GamblingGame(string name, string name2); // 사용자로부터 플레이어 이름 두개를 입력받는 생성자
	~GamblingGame(); // 소멸자
	void run(); // 게임을 실행하는 함수
};
GamblingGame::GamblingGame(string name, string name2) // 사용자로부터 플레이어 이름을 두개 입력받는 생성자
{
	p = new Player[2]; // 플레이어 2명 동적 생성
	p[0].setName(name); // p[0]에 매개변수 name을 설정
	p[1].setName(name2); // p[1]에 매개변수 name2를 설정
}
GamblingGame::~GamblingGame()
{
	delete[] p;
}
void GamblingGame::run() { // 게임을 실행하는 함수 구현
	int check = 2; // 플레이어 1 차례인지 2 차례인지 체크하기 위한 변수
	cin.ignore(); // 위에서 쳐진 공백을 무시함
	while (1) // 반복문 실행
	{
		string enter;
		if (check == 2) { // 만약 플레이어 1의 차례라면 check = 2
			cout << p[0].getName() << ": <Enter>";
			getline(cin, enter, '\n'); // 엔터 입력받기

			int rand_num0, rand_num1, rand_num2; // 난수 변수 3개 생성
			srand((unsigned int)time(0)); // 시드를 현재 시간으로 초기화
			rand_num0 = rand() % 3; // 난수 1개 생성
			rand_num1 = rand() % 3; // 난수 1개 생성
			rand_num2 = rand() % 3; // 난수 1개 생성
			Sleep(1000); // 다음 난수 생성때 겹치지 않게 하기 위해 딜레이 1초 주기

			if (rand_num0 == rand_num1 && rand_num1 == rand_num2) { // 만약 난수 1, 2, 3이 모두 같은 수라면
				cout << rand_num0 << "\t" << rand_num1 << "\t" << rand_num2 << "\t"; // 난수 출력 후에
				cout << p[0].getName() << "님 승리!!" << endl; // 플레이어 1의 승리라고 출력
				break; // 승리했으니 반복문 멈추기
			}
			else { // 모두 같은 수가 아니라면
				cout << rand_num0 << "\t" << rand_num1 << "\t" << rand_num2 << "\t"; // 난수 출력 후에
				cout << "아쉽군요!" << endl;
				check = 3; // 플레이어 2의 순서로 넘기기
			}
		}
		if (check == 3) // 만약 플레이어 2의 순서라면
		{
			cout << p[1].getName() << ": <Enter>";
			getline(cin, enter, '\n'); // 엔터 입력받기

			int rand_num0, rand_num1, rand_num2; // 난수 변수 3개 생성
			srand((unsigned int)time(0)); // 시드를 현재 시간으로 초기화
			rand_num0 = rand() % 3; // 난수 1개 생성
			rand_num1 =	rand() % 3; // 난수 1개 생성
			rand_num2 = rand() % 3; // 난수 1개 생성
			Sleep(1000);// 다음 난수 생성때 겹치지 않게 하기 위해 딜레이 1초 주기

			if (rand_num0 == rand_num1 && rand_num1 == rand_num2) { // 만약 난수 1, 2, 3이 모두 같은 수라면
				cout << rand_num0 << "\t" << rand_num1 << "\t" << rand_num2 << "\t"; // 난수 출력 후에
				cout << p[1].getName() << "님 승리!!" << endl; // 플레이어 2의 승리라고 출력
				break; // 승리했으니 반복문 멈추기
			}
			else { // 모두 같은 수가 아니라면
				cout << rand_num0 << "\t" << rand_num1 << "\t" << rand_num2 << "\t";
				cout << "아쉽군요!" << endl; 
 				check = 2; // check를 2로 바꾸어서 플레이어 1의 순서로 넘기기
			}
		}
	}
}

int main() 
{
	cout << "***** 갬블링 게임을 시작합니다. *****" << endl; // 갬블링 게임 시작을 알리는 메세지 출력
	string first_name, second_name; // 플레이어 1, 2의 이름을 입력받기 위한 변수 선언
	cout << "첫번째 선수 이름 : ";
	cin >> first_name; // 플레이어 1 이름 입력 받기
	cout << "두번째 선수 이름 : "; 
	cin >> second_name; // 플레이어 2 이름 입력 받기
	GamblingGame Game(first_name, second_name); // 생성자로 플레이어 1, 2의 이름 생성
	Game.run(); // 게임 실행
	return 0;
}