#include <iostream>
using namespace std;
class Stack {
	int arr[10];
	int top;
public:
	Stack();
	Stack& operator<<(int a); //push
	Stack& operator>>(int &a); // pop
	bool operator! ();
	void show();
};
Stack::Stack()
{
	top = -1;
}
Stack& Stack::operator<<(int a)
{
	if (top == 9)
		cout << "더이상 추가할 수 없음" << endl;
	else arr[++top] = a;
	return *this;
}
Stack& Stack::operator>>(int &a)
{
	if (top == -1)
		cout << "스택 비었음" << endl;
	else a = arr[top--];
	return *this;
}

bool Stack::operator!() {
	if (top == -1)
		return true;
	else return false;
}
void Stack::show()
{
	int i;
	for (i = 0; i < top; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}
int main()
{
	Stack stack;
	stack << 3 << 5 << 10 << 1 << 2 << 6;
	while (true)
	{
		if (!stack) break;
		int x;
		stack >> x;
		cout << x << ' ';
	}
	cout << endl;
	return 0;
}