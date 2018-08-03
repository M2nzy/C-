#include <iostream>
#include <string>
using namespace std;
class AbstractStack {
public:
	virtual bool push(int n) = 0;
	virtual bool pop(int &n) = 0;
	virtual int size() = 0;
};

class Stack : AbstractStack {
	int top = -1;
	int arr[10];
public:
	virtual bool push(int n) {
		if (top == arr[9])
			return false;
		else {
			arr[++top] = n;
			return true;
		}
	}
	virtual bool pop(int &n) {
		if (top == -1)
			return false;
		else {
			n = arr[top--];
			return true;
		}
	}
	virtual int size() { return top+1; }
};

int main()
{
	Stack Intstack;
	int n;
	cout << "stack pop : " << Intstack.pop(n) << endl; // false
	cout << "stack push : " << Intstack.push(3) << ' ' << Intstack.push(5) << endl; // true true
	cout << "stack size : " << Intstack.size() << endl; // 2
	cout << "stack pop : " << Intstack.pop(n) << endl; // true
	cout << "stack pop : " << Intstack.pop(n) << endl; // true
	cout << "stack size : " << Intstack.size() << endl; // 0

}