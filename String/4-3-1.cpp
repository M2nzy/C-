#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	getline(cin, str, '\n');
	int strlen, isA = -1, count = 0;
	strlen = str.length();
	for (int i = 0; i < strlen; i++) {
		char ch = str.at(i);
		if (ch == 'a')
			count++;
	}
	cout << "문자 a는 " << count << "개 있습니다." << endl;
	return 0;
}