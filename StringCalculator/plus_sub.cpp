#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cout << "Please enter an expression such as 4+5-12+6-20 : ";
	getline(cin, str, '\n');
	int startIndex = 0;
	int result = 0;
	char last_oper = '+';
	string oper = "+-";
	if (str[0] == '-')
	{
		startIndex = 1;
		last_oper = '-';
	}
	while (1)
	{
		int fIndex = str.find_first_of(oper,startIndex);
		if (fIndex == -1) //not found '+', '-'
		{
			string part = str.substr(startIndex);
			if (part == " ")
				break;
			cout << part << endl;
			if (last_oper == '+') {
				result += stoi(part);
				break;
			}
			else if (last_oper == '-') {
				result -= stoi(part);
				break;
			}
		}
		int subIndex = fIndex - startIndex;
		string part = str.substr(startIndex, subIndex);
		cout << part << endl;

		if (last_oper == '+')
			result += stoi(part);
		else if (last_oper == '-')
			result -= stoi(part);

		if (str[fIndex] == '+')
			last_oper = '+';
		else if (str[fIndex] == '-')
			last_oper = '-';

		startIndex = fIndex + 1;
	}
	cout << "Result : " << result << endl;
}