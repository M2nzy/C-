#include <iostream>
#include <string>
using namespace std;

typedef struct words
{
	string word;
	int cnt;
}WORDS;

int main()
{
	string str = "SPam sPam SPAM spam ham HAM sPaM jAVA c++ C++ java APPLE";
	int f, fcnt;
	WORDS w[100];
	int cnt = 0, len, startIndex = 0;
	len = str.length();
	for (int j = 0; j < len; j++)
		str[j] = toupper(str[j]);

	for (int i = 0; i < len; i++)
	{
		f = str.find(' ',startIndex);
		if (f == -1) {
			string part = str.substr(startIndex);
			for (int j = 0; j < 100; j++) {
				if (w[j].word.empty()) {
					w[j].word = part;
					w[j].cnt = 1;
					cnt++;
					break;
				}
				else {
					if (w[j].word == part)
					{
						w[j].cnt++;
						break;
					}
					else continue;
				}
			}
			break;
		}
		fcnt = f - startIndex;
		string part = str.substr(startIndex, fcnt);
		startIndex = f + 1;
		for (int j = 0; j < 100; j++) {
			if (w[j].word.empty()) {
				w[j].word = part;
				w[j].cnt = 1;
				cnt++;
				break;
			}
			else {
				if (w[j].word == part)
				{
					w[j].cnt += 1;
					break;
				}
			}
		}
	}
		
	for (int i = 0; i < 100; i++)
	{
		if (w[i].cnt > 0)
			cout << w[i].word << "의 수:" << w[i].cnt << endl;
		else continue;
	}
	cout << "단어 개수 : "<< cnt <<"개" << endl;
}