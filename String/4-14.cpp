#include <iostream>
#include <string>
#include <cstdlib> // ���� ���� ���� �������
#include <ctime> // ���� ���� ���� �������
#include <Windows.h> // �����̸� �ֱ� ���� �������(Sleep)
using namespace std;

class Player { // Ŭ���� Player ����
	string name;
public: 
	void setName(string name); // �̸� �����ϴ� �Լ�
	string getName(); // �̸��� ��ȯ�ϴ� �Լ�
};
void Player::setName(string name)
{
	this->name = name;
}

string Player::getName()
{
	return name; 
}
class GamblingGame { // GamblingGame Ŭ���� ����
	Player *p; 

public: 
	GamblingGame(string name, string name2); // ����ڷκ��� �÷��̾� �̸� �ΰ��� �Է¹޴� ������
	~GamblingGame(); // �Ҹ���
	void run(); // ������ �����ϴ� �Լ�
};
GamblingGame::GamblingGame(string name, string name2) // ����ڷκ��� �÷��̾� �̸��� �ΰ� �Է¹޴� ������
{
	p = new Player[2]; // �÷��̾� 2�� ���� ����
	p[0].setName(name); // p[0]�� �Ű����� name�� ����
	p[1].setName(name2); // p[1]�� �Ű����� name2�� ����
}
GamblingGame::~GamblingGame()
{
	delete[] p;
}
void GamblingGame::run() { // ������ �����ϴ� �Լ� ����
	int check = 2; // �÷��̾� 1 �������� 2 �������� üũ�ϱ� ���� ����
	cin.ignore(); // ������ ���� ������ ������
	while (1) // �ݺ��� ����
	{
		string enter;
		if (check == 2) { // ���� �÷��̾� 1�� ���ʶ�� check = 2
			cout << p[0].getName() << ": <Enter>";
			getline(cin, enter, '\n'); // ���� �Է¹ޱ�

			int rand_num0, rand_num1, rand_num2; // ���� ���� 3�� ����
			srand((unsigned int)time(0)); // �õ带 ���� �ð����� �ʱ�ȭ
			rand_num0 = rand() % 3; // ���� 1�� ����
			rand_num1 = rand() % 3; // ���� 1�� ����
			rand_num2 = rand() % 3; // ���� 1�� ����
			Sleep(1000); // ���� ���� ������ ��ġ�� �ʰ� �ϱ� ���� ������ 1�� �ֱ�

			if (rand_num0 == rand_num1 && rand_num1 == rand_num2) { // ���� ���� 1, 2, 3�� ��� ���� �����
				cout << rand_num0 << "\t" << rand_num1 << "\t" << rand_num2 << "\t"; // ���� ��� �Ŀ�
				cout << p[0].getName() << "�� �¸�!!" << endl; // �÷��̾� 1�� �¸���� ���
				break; // �¸������� �ݺ��� ���߱�
			}
			else { // ��� ���� ���� �ƴ϶��
				cout << rand_num0 << "\t" << rand_num1 << "\t" << rand_num2 << "\t"; // ���� ��� �Ŀ�
				cout << "�ƽ�����!" << endl;
				check = 3; // �÷��̾� 2�� ������ �ѱ��
			}
		}
		if (check == 3) // ���� �÷��̾� 2�� �������
		{
			cout << p[1].getName() << ": <Enter>";
			getline(cin, enter, '\n'); // ���� �Է¹ޱ�

			int rand_num0, rand_num1, rand_num2; // ���� ���� 3�� ����
			srand((unsigned int)time(0)); // �õ带 ���� �ð����� �ʱ�ȭ
			rand_num0 = rand() % 3; // ���� 1�� ����
			rand_num1 =	rand() % 3; // ���� 1�� ����
			rand_num2 = rand() % 3; // ���� 1�� ����
			Sleep(1000);// ���� ���� ������ ��ġ�� �ʰ� �ϱ� ���� ������ 1�� �ֱ�

			if (rand_num0 == rand_num1 && rand_num1 == rand_num2) { // ���� ���� 1, 2, 3�� ��� ���� �����
				cout << rand_num0 << "\t" << rand_num1 << "\t" << rand_num2 << "\t"; // ���� ��� �Ŀ�
				cout << p[1].getName() << "�� �¸�!!" << endl; // �÷��̾� 2�� �¸���� ���
				break; // �¸������� �ݺ��� ���߱�
			}
			else { // ��� ���� ���� �ƴ϶��
				cout << rand_num0 << "\t" << rand_num1 << "\t" << rand_num2 << "\t";
				cout << "�ƽ�����!" << endl; 
 				check = 2; // check�� 2�� �ٲپ �÷��̾� 1�� ������ �ѱ��
			}
		}
	}
}

int main() 
{
	cout << "***** ���� ������ �����մϴ�. *****" << endl; // ���� ���� ������ �˸��� �޼��� ���
	string first_name, second_name; // �÷��̾� 1, 2�� �̸��� �Է¹ޱ� ���� ���� ����
	cout << "ù��° ���� �̸� : ";
	cin >> first_name; // �÷��̾� 1 �̸� �Է� �ޱ�
	cout << "�ι�° ���� �̸� : "; 
	cin >> second_name; // �÷��̾� 2 �̸� �Է� �ޱ�
	GamblingGame Game(first_name, second_name); // �����ڷ� �÷��̾� 1, 2�� �̸� ����
	Game.run(); // ���� ����
	return 0;
}