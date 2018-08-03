#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;
class Word {
	string korea;
	string english;
public:
	void setKorea(string korea) { this->korea = korea; }
	void setEnglish(string english) { this->english = english; }
	string getKorea() { return korea; }
	string getEnglish() { return english; }
};

class Console {
public:
	static int run();
};

int Console::run() {
	int menu;
	cout << "****** English Vocabulary Test. ******" << endl << "will exit when Input other than 1 to 4." << endl;
	cin >> menu;
	return menu;
}
int main() {
	vector<Word> v;
	srand(time(0));
	int random = rand() % v.size();
	Word A; A.setKorea("아기"); A.setEnglish("baby");
	Word B; B.setKorea("인간"); B.setEnglish("human");
	Word C; C.setKorea("사회"); C.setEnglish("society");
	Word D; D.setKorea("인형"); D.setEnglish("dall");
	Word E; E.setKorea("감정"); E.setEnglish("emotion");
	Word F; F.setKorea("사랑"); F.setEnglish("love");
	Word G; G.setKorea("동물"); G.setEnglish("animal");
	v.push_back(A); v.push_back(B); v.push_back(C); v.push_back(D); v.push_back(E); v.push_back(F); v.push_back(G);
	while (1) {
		switch (Console::run()) {
		case 1:
			
			if(answer == )
			break;
		case 2:
			exit = 1;
			break;
		case 3:
			exit = 1;
			break;
		case 4:
			exit = 1;
			break;
		default:
			return 0;
			break;
		}
	}
}