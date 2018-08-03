#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v;
	for (int i = 0; i < 5; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	for (vector<int>::iterator i = v.begin(); i != v.end(); ++i) {
		cout << (*i) << endl;
	}
	return 0;
}