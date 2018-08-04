#include <iostream>
using namespace std;
class Matrix {
	int m_arr[4];
public:
	Matrix();
	Matrix(int a, int b, int c, int d);
	void operator<< (int arr[]);
	void operator>>(int arr[]);
	void show();
};
Matrix::Matrix()
{
	int m_arr[] = { 0,};
}
Matrix::Matrix(int a, int b, int c, int d) 
{
	m_arr[0] = a;
	m_arr[1] = b;
	m_arr[2] = c;
	m_arr[3] = d;
}
void Matrix::operator<<(int arr[])
{
	for (int i = 0; i < 4; i++)
	{
		m_arr[i] = arr[i];
	}
}
void Matrix::operator>>(int arr[])
{
	for (int i = 0; i < 4; i++)
	{
		arr[i] = m_arr[i];
	}
}
void Matrix::show() {
	cout << "Matrix =  { ";
	for (int i = 0; i < 4; i++)
	{
		cout << m_arr[i] << ' ';
	}
	cout << "}" << endl;
}
int main()
{
	Matrix a(4, 3, 2, 1), b;
	int x[4], y[4] = { 1,2,1,3 };
	a >> x;
	b << y;

	for (int i = 0; i < 4; i++)		cout << x[i] << ' ';
	cout << endl;
	b.show();
	return 0;
}