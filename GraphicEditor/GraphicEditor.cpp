#include <iostream> 
using namespace std; 
class Shape {
	Shape* next; 
protected: 
	virtual void draw() = 0; 
public: 
	Shape() { next = NULL; } //생성자 처음 생성할때는 next에 아무것도 없으므로
	virtual ~Shape() {  }
	void paint(); 
	Shape* add(Shape* p); 
	Shape* getNext() { return next; } 
	Shape* setNext(Shape* p) { next = p; return this; } };
Shape* Shape::add(Shape* p)
{	this->next = p; 
	return p; 
}
void Shape::paint()
{	draw(); 
}
class Circle : public Shape {
protected:
	virtual void draw() {
		cout << "Circle" << endl;
	} 
};
class Rect : public Shape {
protected:
	virtual void draw() { 
		cout << "Rect" << endl;
	}
};
class Line : public Shape {
protected:
	virtual void draw() {
		cout << "Line" << endl;
	}
};
class UI { 
public:
	static int Insert() {
		int a; 
		cout << "선:1, 원:2, 사각형:3 >> ";
		cin >> a; 
		return a;
	}
	static int Delete() {
		int a;
		cout << "삭제하고자 하는 도형의 인덱스 >> ";
		cin >> a;
		return a;
	}
};
class GraphicEditor {
public:
	Shape *pStart = NULL; //Start에는 아무것도 없으니 NULL
	Shape *pLast = NULL; //처음 도형 Last에는 아무것도 없으니 NULL
	int count = 0;
	void call() {
		cout << "그래픽 에디터입니다." << endl;
		GraphicEditor *p = new GraphicEditor();
		while (1)
		{
			int n;
			cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
			cin >> n;
			switch (n)
			{
			case 1:
				switch (UI::Insert())
				{
				case 1:
					if (count == 0) { //도형이 아무것도 생성되어있지 않으면
						pStart = new Line();
						pLast = pStart; //pLast는 pStart랑 같으므로
						count++;
					}
					else { //도형이 하나라도 생성되어 있으면
						pLast = pLast->add(new Line());
						count++; 
					}
					break;
				case 2:
					if (count == 0) { //도형이 아무것도 생성되어있지 않으면
						pStart = new Circle();
						pLast = pStart; //pLast는 pStart랑 같으므로
						count++;
					}
					else {
						pLast = pLast->add(new Circle());
						count++;
					}
					break; 
				case 3: 
					if (count == 0) { //도형이 아무것도 생성되어 있지 않으면
						pStart = new Rect();
						pLast = pStart; //pLast는 pStart랑 같으므로
						count++;
					}
					else {//도형이 하나라도 생성되어 있으면
						pLast = pLast->add(new Rect()); //pLast에 도형 생성
						count++;
					}
					break;
				default:
					break;
				}
				break;
			case 2: {
				Shape* p = pStart;
				int index = UI::Delete(); //삭제할 인덱스를 새로운 인덱스 변수 선언에 넣어줌
				for (int i = 0; i < count; i++) // 도형이 생성된 개수만큼 for문 반복
				{
					if (index == 0)
					{ 
						if (count == 1)
						{
							pStart = NULL;
							count = 0;
							break;
						}
						else if (count == 0)
							return; 
						else
						{ 
							Shape *tmp = pStart;
							p = tmp->getNext();
							count--;
							delete tmp;
							pStart = p;
							break;
						}
					}
					else if (index == (i+1)) //index가 0일때 처리해주었으니 i+1일때 처리
					{
						Shape *q = pLast;
						Shape *tmp = pLast->getNext();
						if (tmp == NULL) { //Last가 NULL이면 다음걸 지울 수 없음
							q = NULL;
							p = p->setNext(q);
							count--; 
							delete tmp;
							break;
						}
						else
						{ 
							Shape *tmp = p->getNext();
							p = p->setNext(tmp->getNext());
							count--;
							delete tmp;
							break;
						}
					}
					else p = p->getNext(); //전부 아닐 때
				} 
				break;
			}
			case 3: { 
				Shape *p = pStart; 
				for (int i = 0; i < count; i++) // 도형 개수만큼
				{
					cout << i << ": ";
					p->paint();
					p = p->getNext();
				}
				delete p;
				break;
			} 
			case 4: 
				return;
				break; 
			default: //예외
				return; 
				break; 
			}
		}
	}
};
int main() 
{
	GraphicEditor *p = new GraphicEditor; //포인터 p 생성
	p->call();  
	delete p; 
	return 0; 
}