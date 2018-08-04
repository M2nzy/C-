#include <iostream>
#include <string>
using namespace std;
int big(int x = 0, int y = 0, int z=0);
int big(int x, int y, int z) {
	int re;
	if (x > 0 && y > 0 && z == 0)
	{
		re = 100;
		if (x > 100 || y > 100)
			return re;
		return x > y ? x : y;
	}
	else if (x > 0 && y > 0 && z > 0)
	{
		int max = x;
		re = 50;
		if (x > 50 || y > 50 || z > 50)
			return re;
		if (max <= y)
			max = y;
		if (max <= z)
			max = z;
		return max;
	}
}
int main()
{
	int x = big(20,10);
	int y = big(200,60);
	int z = big(20,50,10);
	cout << x << ' ' << y << ' ' << z << endl;
}