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
		index = str.find('a', 0); //ó�� ��ġ���� 'a'�� ã�´�
		if (index != -1) //'a'�� ã�Ҵٸ�
		{
			count++; //count ����
			str.erase(0, index + 1); //a�� ã������, ó�� ��ġ���� a�� ã�� �� ��ġ�� ������ŭ ���ڸ� �����
		}
		else if (index == -1) //a�� ���̻� ã�� ���Ѵٸ� break
			break;
	}
	cout << "'a' ������ ������ " << count << "�� �Դϴ�." << endl;
	return 0;
}