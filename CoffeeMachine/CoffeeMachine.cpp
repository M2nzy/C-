#include <iostream> // iostream ������� ����
#include <string> // string ������� ����
using namespace std; //std ���ӽ����̽� ���

class Circle // Circle Ŭ���� ����
{
	int radius; // ���� ������ ���� ����
	string name; // ���ڿ� �̸� ���� ����
public: // ����� �� �ֵ��� public����
	void setCircle(string name, int radius); // ���� �̸��� �������� �����ϴ� �Լ�
	double getArea(); // ���� ������ ��ȯ�ϴ� �Լ�
	string getName(); // ���� �̸��� ��ȯ�ϴ� �Լ�
};

void Circle::setCircle(string name, int radius) // ���� �̸��� �������� �����ϴ� �Լ� �����ϱ�
{
	this->radius = radius; // �Ű������� radius�� Ŭ������ private ��� radius�� �ֱ�
	this->name = name; // �Ű������� name�� Ŭ������ private ��� name�� �ֱ�
}
double Circle::getArea(){ // ���� ������ ��ȯ�ϴ� �Լ� �����ϱ�
	return 3.14 * radius * radius; // ���� ������ ���Ͽ� ��ȯ
}
string Circle::getName() { // ���� �̸��� ��ȯ�ϴ� �Լ� �����ϱ�
	return name; // ���� �̸��� ��ȯ
}

class CircleManager { // ���� �迭�� �����ϴ� Ŭ����
	Circle *p; // Circle Ŭ������ ������
	int size; // �迭�� ũ��
public: // �� �� �ֵ��� public����
	CircleManager(int size); // sizeũ���� �迭�� ���� ����
	~CircleManager(); // �Ҹ���
	void searchByName(); // ����ڷκ��� ���� �̸��� �Է¹޾� ���� ���
	void searchByArea(); // ����ڷκ��� ������ �Է¹޾� �������� ū ���� �̸��� ������ ���
};
CircleManager::CircleManager(int size) { // size ũ���� �迭�� ���� �����ϴ� ������
	p = new Circle[size]; // ������ p�� size ũ���� �迭�� ���� ������
	this->size = size; // private ��� size�� �Ű����� size�� ����
	for (int i = 0; i < size; i++) // i=0���� size ������ �ݺ��ϸ� ����
	{
		string cin_name; // �Է¹��� �̸�
		int cin_radius; // �Է¹��� ������
		cout << "�� " << i+1 << "�� �̸��� ������ >> "; // ����ڿ��� �̸��� �������� �Է��϶�� ���
		cin >> cin_name; // �̸� �Է¹ޱ�
		cin >> cin_radius; // ������ �Է¹ޱ�
		p[i].setCircle(cin_name, cin_radius); // p�� i��° �迭���ٰ� �Է¹��� �̸��� �������� ������
	}
	searchByName(); // ����ڷκ��� ���� �̸��� �Է¹޾� ���� ����ϴ� �Լ� ����
	searchByArea(); // ����ڷκ��� ������ �Է¹޾� �������� ū ���� �̸��� ������ ����ϴ� �Լ� ����
}
CircleManager::~CircleManager() { // �Ҹ���
	delete [] p; // ���� ������ ���� ������
}
void CircleManager::searchByName() { // ����ڷκ��� ���� �̸��� �Է¹޾� ���� ����ϴ� �Լ�
	string search_name; // ã���� �ϴ� �̸� ����
	cout << "�˻��ϰ��� �ϴ� ���� �̸� >> "; // �Է� ���
	cin >> search_name; // ã���� �ϴ� �̸��� �Է¹���
	for (int i = 0; i < size; i++) // i=0���� size ������ i�� �����ϸ鼭 �ݺ�
	{
		if (search_name == p[i].getName()) // ���� �Է¹��� �̸��� p�� i��° �̸��� ���ٸ�
			cout << p[i].getName() << "�� ������ " << p[i].getArea() << endl; // p�� i��° �̸��� ������ ���
	}
}
void CircleManager::searchByArea() { // ����ڷκ��� ������ �Է¹޾� �������� ū ���� �̸��� ������ ����ϴ� �Լ�
	int small_size; // �ּ� ���� ���� ����
	cout << "�ּ� ������ ������ �Է��ϼ��� >> "; // �Է� ���
	cin >> small_size; // �ּ� ������ �Է¹���
	cout << small_size << "���� ū ���� �˻��մϴ�." <<endl; // �ȳ� �޼���
	for (int i = 0; i < size; i++) // i=0���� size ������ i�� �����ϸ鼭 �ݺ�
	{
		if (p[i].getArea() > small_size) // ���� p�� i��° ������ �ּ� �������� ũ�ٸ�
		{
			cout << p[i].getName() << "�� ������ " << p[i].getArea() << ", "; // p�� i��° �̸��� ������ ���
		}
	}
	cout << endl; // �ٹٲ�
}

int main() // ���� �Լ�
{
	cout << "���� ���� >> "; // �Է� ���
	int circle_size; // ���� ���� ����
	cin >> circle_size; // ���� ���� �Է¹���
	CircleManager::CircleManager(circle_size); // CircleManager::CircleManager(int size) ������ ������
	return 0; // ����
}