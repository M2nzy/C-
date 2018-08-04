#include <iostream>
#include <string>
using namespace std;
int big(int x, int y){
	int re = 100;
	if (x > 100 || y > 100)
		return re;
	return x > y ? x : y;
}
int big(int x, int y, int z)
{
	int max = x;
	if (max <= y)
		max = y;
	if (max <= z)
		max = z;
	if (max > 50) {
		max = 50;
		return max;
	}
	return max;
}

int main()
{
	int x = big(3, 5);
	int y = big(300, 60);
	int z = big(30, 60, 50);
	cout << x << ' ' << y << ' ' << z << endl;
}