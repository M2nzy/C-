#include <iostream>
#include <string> 
using namespace std;

class Circle // Circle 클래스 선언
{
	int radius; 
	string name;
public: 
	void setCircle(string name, int radius); // 원의 이름과 반지름을 설정하는 함수
	double getArea(); // 원의 면적을 반환하는 함수
	string getName(); // 원의 이름을 반환하는 함수
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

class CircleManager { // 원을 배열로 관리하는 클래스
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
		cout << "원 " << i+1 << "의 이름과 반지름 >> "; 
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
	cout << "검색하고자 하는 원의 이름 >> "; 
	cin >> search_name; 
	for (int i = 0; i < size; i++)
	{
		if (search_name == p[i].getName()) 
			cout << p[i].getName() << "의 면적은 " << p[i].getArea() << endl;
	}
}
void CircleManager::searchByArea() {
	int small_size;
	cout << "최소 면적을 정수로 입력하세요 >> ";
	cin >> small_size;
	cout << small_size << "보다 큰 원을 검색합니다." <<endl; 
	for (int i = 0; i < size; i++)
	{
		if (p[i].getArea() > small_size)
		{
			cout << p[i].getName() << "의 면적은 " << p[i].getArea() << ", ";
		}
	}
	cout << endl; 
}

int main()
{
	cout << "원의 개수 >> ";
	int circle_size;
	cin >> circle_size;
	CircleManager::CircleManager(circle_size);
	return 0;
}