#include <iostream> 
using namespace std; 
class Shape {
	Shape* next; 
protected: 
	virtual void draw() = 0; 
public: 
	Shape() { next = NULL; } //������ ó�� �����Ҷ��� next�� �ƹ��͵� �����Ƿ�
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
		cout << "��:1, ��:2, �簢��:3 >> ";
		cin >> a; 
		return a;
	}
	static int Delete() {
		int a;
		cout << "�����ϰ��� �ϴ� ������ �ε��� >> ";
		cin >> a;
		return a;
	}
};
class GraphicEditor {
public:
	Shape *pStart = NULL; //Start���� �ƹ��͵� ������ NULL
	Shape *pLast = NULL; //ó�� ���� Last���� �ƹ��͵� ������ NULL
	int count = 0;
	void call() {
		cout << "�׷��� �������Դϴ�." << endl;
		GraphicEditor *p = new GraphicEditor();
		while (1)
		{
			int n;
			cout << "����:1, ����:2, ��κ���:3, ����:4 >> ";
			cin >> n;
			switch (n)
			{
			case 1:
				switch (UI::Insert())
				{
				case 1:
					if (count == 0) { //������ �ƹ��͵� �����Ǿ����� ������
						pStart = new Line();
						pLast = pStart; //pLast�� pStart�� �����Ƿ�
						count++;
					}
					else { //������ �ϳ��� �����Ǿ� ������
						pLast = pLast->add(new Line());
						count++; 
					}
					break;
				case 2:
					if (count == 0) { //������ �ƹ��͵� �����Ǿ����� ������
						pStart = new Circle();
						pLast = pStart; //pLast�� pStart�� �����Ƿ�
						count++;
					}
					else {
						pLast = pLast->add(new Circle());
						count++;
					}
					break; 
				case 3: 
					if (count == 0) { //������ �ƹ��͵� �����Ǿ� ���� ������
						pStart = new Rect();
						pLast = pStart; //pLast�� pStart�� �����Ƿ�
						count++;
					}
					else {//������ �ϳ��� �����Ǿ� ������
						pLast = pLast->add(new Rect()); //pLast�� ���� ����
						count++;
					}
					break;
				default:
					break;
				}
				break;
			case 2: {
				Shape* p = pStart;
				int index = UI::Delete(); //������ �ε����� ���ο� �ε��� ���� ���� �־���
				for (int i = 0; i < count; i++) // ������ ������ ������ŭ for�� �ݺ�
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
					else if (index == (i+1)) //index�� 0�϶� ó�����־����� i+1�϶� ó��
					{
						Shape *q = pLast;
						Shape *tmp = pLast->getNext();
						if (tmp == NULL) { //Last�� NULL�̸� ������ ���� �� ����
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
					else p = p->getNext(); //���� �ƴ� ��
				} 
				break;
			}
			case 3: { 
				Shape *p = pStart; 
				for (int i = 0; i < count; i++) // ���� ������ŭ
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
			default: //����
				return; 
				break; 
			}
		}
	}
};
int main() 
{
	GraphicEditor *p = new GraphicEditor; //������ p ����
	p->call();  
	delete p; 
	return 0; 
}