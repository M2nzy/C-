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
			cout << "잉크가 부족하여 프린트할 수 없습니다." << endl;	
		if (availableCount < printedCount)
			cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
		else 
		{
			for (int i = 0; i < printedCount; i++)
			{
				availableInk--;
				availableCount--;
			}
			cout << "프린트 하였습니다." << endl;
		}
	}
	virtual void show()
	{
		cout << "잉크젯 : " << model << ", " << manufactuer << ", " << availableCount << ", " << availableInk;
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
			cout << "토너가 부족하여 프린트할 수 없습니다." << endl;
		if (availableCount < printedCount)
			cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
		else
		{
			for (int i = 0; i < printedCount; i++)
			{
				availableToner--;
				availableCount--;
			}
			cout << "프린트 하였습니다." << endl;
		}
	}
	virtual void show()
	{
		cout << "레이저 : " << model << ", " << manufactuer << ", " << availableCount << ", " << availableToner;
	}
};

int main()
{
	inkjet *i = new inkjet("Officejet V40", "HP", 5, 10);
	laser *l = new laser("SCX-6x45", "삼성전자", 3, 20);
	cout << "현재 작동중인 2 대의 프린터는 아래와 같다." << endl;
	i->show(); cout << endl; l->show(); cout << endl << endl;
	char y_n = 'y';
	while (1)
	{
		if (y_n == 'y'|| y_n=='Y') {
			int menu, p_count;
			cout << "프린터(1:잉크젯 2:레이저)와 매수 입력 >> ";
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
				cout << "프린터(1:잉크젯 2:레이저)와 매수 입력 >> ";
				break;
			}
			i->show(); cout << endl; l->show(); cout << endl << endl;
			cout << "계속 프린트 하시겠습니까(Y/n)>>";
			cin >> y_n;
		}
		if (y_n == 'n' || y_n=='N')
			break;
	}
	return 0;
}