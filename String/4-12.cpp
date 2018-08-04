#include <iostream>
#include <string> 
using namespace std;

class Circle // Circle Ŭ���� ����
{
	int radius; 
	string name;
public: 
	void setCircle(string name, int radius); // ���� �̸��� �������� �����ϴ� �Լ�
	double getArea(); // ���� ������ ��ȯ�ϴ� �Լ�
	string getName(); // ���� �̸��� ��ȯ�ϴ� �Լ�
};

void Circle::setCircle(string name, int radius)
{
	this->radius = radius;
	this->name = name;
}
double Circle::getArea(){
	return 3.14 * radius * radius;
}
string Circle::getName() { 
	return name;
}

class CircleManager { // ���� �迭�� �����ϴ� Ŭ����
	Circle *p; 
	int size;
public:
	CircleManager(int size); 
	~CircleManager();
	void searchByName(); 
	void searchByArea();
};
CircleManager::CircleManager(int size) {
	p = new Circle[size]; 
	this->size = size; 
	for (int i = 0; i < size; i++) 
	{
		string cin_name;
		int cin_radius; 
		cout << "�� " << i+1 << "�� �̸��� ������ >> "; 
		cin >> cin_name; 
		cin >> cin_radius; 
		p[i].setCircle(cin_name, cin_radius);
	}
	searchByName();
	searchByArea();
}
CircleManager::~CircleManager() { 
	delete [] p; 
}
void CircleManager::searchByName() { 
	string search_name;
	cout << "�˻��ϰ��� �ϴ� ���� �̸� >> "; 
	cin >> search_name; 
	for (int i = 0; i < size; i++)
	{
		if (search_name == p[i].getName()) 
			cout << p[i].getName() << "�� ������ " << p[i].getArea() << endl;
	}
}
void CircleManager::searchByArea() {
	int small_size;
	cout << "�ּ� ������ ������ �Է��ϼ��� >> ";
	cin >> small_size;
	cout << small_size << "���� ū ���� �˻��մϴ�." <<endl; 
	for (int i = 0; i < size; i++)
	{
		if (p[i].getArea() > small_size)
		{
			cout << p[i].getName() << "�� ������ " << p[i].getArea() << ", ";
		}
	}
	cout << endl; 
}

int main()
{
	cout << "���� ���� >> ";
	int circle_size;
	cin >> circle_size;
	CircleManager::CircleManager(circle_size);
	return 0;
}