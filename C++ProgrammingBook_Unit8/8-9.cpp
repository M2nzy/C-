#include <iostream>
#include <string>
using namespace std;
class printer {
protected:
	string model;
	string manufactuer;
	int printedCount;
	int availableCount;
	virtual void print(int pages) = 0;
	virtual void show() = 0;
public:
	printer(string model, string manufactuer, int availableCount) 
	{
		this->model = model;
		this->manufactuer = manufactuer;
		this->availableCount = availableCount;
	}
};

class inkjet : public printer {
	int availableInk;
public:
	inkjet(string name, string f_name, int p_cnt, int a_cnt) : printer(name, f_name, p_cnt) { availableInk = a_cnt; }
	virtual void print(int pages)
	{
		printedCount = pages;
		if (availableInk < printedCount)
			cout << "��ũ�� �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;	
		if (availableCount < printedCount)
			cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
		else 
		{
			for (int i = 0; i < printedCount; i++)
			{
				availableInk--;
				availableCount--;
			}
			cout << "����Ʈ �Ͽ����ϴ�." << endl;
		}
	}
	virtual void show()
	{
		cout << "��ũ�� : " << model << ", " << manufactuer << ", " << availableCount << ", " << availableInk;
	}
};
class laser : public printer {
	int availableToner;
public:
	laser(string name, string f_name, int p_cnt, int a_cnt) : printer(name, f_name, p_cnt) { availableToner = a_cnt; }
	virtual void print(int pages)
	{
		printedCount = pages;
		if (availableToner < printedCount)
			cout << "��ʰ� �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
		if (availableCount < printedCount)
			cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
		else
		{
			for (int i = 0; i < printedCount; i++)
			{
				availableToner--;
				availableCount--;
			}
			cout << "����Ʈ �Ͽ����ϴ�." << endl;
		}
	}
	virtual void show()
	{
		cout << "������ : " << model << ", " << manufactuer << ", " << availableCount << ", " << availableToner;
	}
};

int main()
{
	inkjet *i = new inkjet("Officejet V40", "HP", 5, 10);
	laser *l = new laser("SCX-6x45", "�Ｚ����", 3, 20);
	cout << "���� �۵����� 2 ���� �����ʹ� �Ʒ��� ����." << endl;
	i->show(); cout << endl; l->show(); cout << endl << endl;
	char y_n = 'y';
	while (1)
	{
		if (y_n == 'y'|| y_n=='Y') {
			int menu, p_count;
			cout << "������(1:��ũ�� 2:������)�� �ż� �Է� >> ";
			cin >> menu;
			switch (menu)
			{
			case 1:
				cin >> p_count;
				i->print(p_count);
				break;
			case 2:
				cin >> p_count;
				l->print(p_count);
				break;
			default:
				cout << "������(1:��ũ�� 2:������)�� �ż� �Է� >> ";
				break;
			}
			i->show(); cout << endl; l->show(); cout << endl << endl;
			cout << "��� ����Ʈ �Ͻðڽ��ϱ�(Y/n)>>";
			cin >> y_n;
		}
		if (y_n == 'n' || y_n=='N')
			break;
	}
	return 0;
}