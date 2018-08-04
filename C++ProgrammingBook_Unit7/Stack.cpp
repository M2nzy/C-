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
	cout << "���ÿ� ������ 5���� ������ �Է��϶�>> ";
	for (int i = 0; i < 5; i++)
	{
		cin >> n;
		mStack.push(n); //���ÿ� ����
	}
	cout << "���� �뷮 : " << mStack.Capacity() << ", ���� ũ�� : " << mStack.length() << endl;
	cout << "������ ��� ���Ҹ� ���Ͽ� ����Ѵ�>> ";
	while (mStack.length() != 0)
	{
		cout << mStack.pop() << ' ';//���ÿ��� ��
	}
	cout << endl << "������ ���� ũ�� : " << mStack.length() << endl;
}