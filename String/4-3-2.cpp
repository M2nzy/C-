#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	int count = 0;
	getline(cin, str, '\n');
	while(1)
	{
		int index = 0;
		index = str.find('a', 0); //처음 위치부터 'a'를 찾는다
		if (index != -1) //'a'를 찾았다면
		{
			count++; //count 증가
			str.erase(0, index + 1); //a를 찾았으니, 처음 위치부터 a를 찾은 그 위치의 개수만큼 문자를 지운다
		}
		else if (index == -1) //a를 더이상 찾지 못한다면 break
			break;
	}
	cout << "'a' 문자의 갯수는 " << count << "개 입니다." << endl;
	return 0;
}