#include <iostream>
using namespace std;
bool average(int a[], int size, double& result)
{
	if (size <= 0) return false;
	for (int i = 0; i < size; i++)
		result += a[i];
	result /= size;
	return true;
}

int main()
{
	cout << "size ? : ";
	int n;
	cin >> n;
	if (n <= 0) {
		cout << "error! size > 0" << endl;
		return 0;
	}
	int *p = new int[n];
	if (!p)
	{
		cout << "'new' error" << endl;
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		int m;
		cout << "input num : ";
		cin >> m;
		p[i] = m;
	}
	double aver = 0;
	if (average(p, n, aver)) cout << "average : " << aver<<endl;
	else cout << "calculate error!" << endl;
	delete[] p;
}