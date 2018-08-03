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
	Nation nation0("��Ż����", "�θ�");
	v.push_back(nation0);
	Nation nation1("�̱�", "�ͽ���");
	v.push_back(nation1);
	Nation nation2("������", "���帮��");
	v.push_back(nation2);
	Nation nation3("����", "������");
	v.push_back(nation3);
	cout << "********* ���� ���� ���߱� ������ �����մϴ�. *********" << endl;
	while (1) {
		int menu;
		cout << "���� �Է� : 1, ���� : 2, ���� : 3 >> ";
		cin >> menu;
		switch (menu) {
		case 1: {
			cout << "���� " << v.size() << "���� ���� �ԷµǾ� �ֽ��ϴ�." << endl;
			cout << "����� ������ �Է��ϼ���. (no no�� �Է� ��)" << endl;
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
				cout << v[random].getNation() << "�� ������? >> ";
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
			cout << "���� �޴��Դϴ�. " << endl;
			break;
		}
	}
	return 0;
}