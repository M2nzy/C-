#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
class Nation {
	string nation;
	string capital;
public:
	Nation(string a, string b) { nation = a; capital = b; }
	string getNation() { return nation; }
	string getCapital() { return capital; }
};
int main()
{
	srand(time(0));
	vector <Nation> v;
	Nation nation0("이탈리아", "로마");
	v.push_back(nation0);
	Nation nation1("미국", "와싱턴");
	v.push_back(nation1);
	Nation nation2("스페인", "마드리드");
	v.push_back(nation2);
	Nation nation3("독일", "베를린");
	v.push_back(nation3);
	cout << "********* 나라 수도 맞추기 게임을 시작합니다. *********" << endl;
	while (1) {
		int menu;
		cout << "정보 입력 : 1, 퀴즈 : 2, 종료 : 3 >> ";
		cin >> menu;
		switch (menu) {
		case 1: {
			cout << "현재 " << v.size() << "개의 나라가 입력되어 있습니다." << endl;
			cout << "나라와 수도를 입력하세요. (no no면 입력 끝)" << endl;
			int exit = 1;
			while (exit) {
				string a, b;
				int size = v.size();
				int i;
				cout << size + 1 << " >> ";
				cin >> a >> b;
				if (a == "no" && b == "no") {
					exit = 0;
					break;
				}
				else {
					for (i = 0; i < size; i++) {
						if (v[i].getNation() == a) {
							cout << "already exists !!" << endl;
							break;
						}
					}
					if (i == size) {
						Nation temp(a, b);
						v.push_back(temp);
					}
				}
			}
			break;
		}
		case 2:
			while (1) {
				int random = rand() % v.size();
				string answer;
				cout << v[random].getNation() << "의 수도는? >> ";
				cin >> answer;
				if (answer == "exit") break;
				else if (answer == v[random].getCapital()) cout << "Correct !!" << endl;
				else cout << "NO !!" << endl;
			}
			break;
		case 3:
			return 0;
			break;
		default:
			cout << "없는 메뉴입니다. " << endl;
			break;
		}
	}
	return 0;
}