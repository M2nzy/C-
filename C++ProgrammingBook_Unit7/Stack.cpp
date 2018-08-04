#include <iostream>
using namespace std;
class BaseArray {
private:
	int capacity;
	int *mem;
protected:
	BaseArray(int capacity = 100)
	{
		this->capacity = capacity;
		mem = new int[capacity];
	}
	~BaseArray() { delete[] mem; }
	void put(int index, int val) { mem[index] = val; }
	int get(int index) { return mem[index]; }
	int getCapacity() { return capacity; }
};

class MyStack : public BaseArray {
	int top = -1;
public:
	MyStack(int n) : BaseArray(n) {}
	void push(int n) { put(++top, n); }
	int Capacity() { return getCapacity(); }
	int length() { return top+1; }
	int pop() { return get(top--); }
};
int main()
{
	MyStack mStack(100);
	int n;
	cout << "스택에 삽입할 5개의 정수를 입력하라>> ";
	for (int i = 0; i < 5; i++)
	{
		cin >> n;
		mStack.push(n); //스택에 삽입
	}
	cout << "스택 용량 : " << mStack.Capacity() << ", 스택 크기 : " << mStack.length() << endl;
	cout << "스택의 모든 원소를 팝하여 출력한다>> ";
	while (mStack.length() != 0)
	{
		cout << mStack.pop() << ' ';//스택에서 팝
	}
	cout << endl << "스택의 현재 크기 : " << mStack.length() << endl;
}