#include <iostream>
#include <string>
using namespace std;
class Board {
	Board();
public:
	static int count;
	static void add(string str);
	static void print();
};
int Board::count = 0;
static string arr[100];
void Board::add(string str)
{
	arr[count] = str;
	count += 1;
}
void Board::print() {
	cout << "****** �Խ����Դϴ�. ******" << endl;
	for (int i = 0; i < count; i++)
		cout << i << ": "<< arr[i] << endl;
	cout << endl;
}
int main()
{
	Board::add("�߰����� ���� ���� ���� �����Դϴ�.");
	Board::add("�ڵ� ����� ���� �̿����ּ���.");
	Board::print();
	Board::add("���Ҹ� �л��� ������ȸ �Ի��Ͽ����ϴ�. �������ּ���");
	Board::print();
}