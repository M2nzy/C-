#include <iostream>
#include <string>
using namespace std;
class Console {
public:
	static int menu();
	static int resMenu();
};
int Console::menu() {
	cout << "Reservation:1, Cancel:2, Print:3, Exit:4 >>";
	int menu;
	cin >> menu;
	return menu;
}
int Console::resMenu() {
	cout << "TIME 07: 1, TIME 12: 2, TIME 17: 3 >> ";
	int menu;
	cin >> menu;
	return menu;
}
class Seat {
	string name;	
	int num;
public:
	void setName(string name) { this->name = name; }
	bool CheckSetName() { if (name != "") return true; else return false; }
	bool CheckName(string name) { if (this->name == name) return true; else return false; }
	string getName() { return name; }
	void setNum(int num) { this->num = num; }
};

class Schedule {
	int time;
public:
	void setTime(int time) { this->time = time; }
	Seat *a = new Seat[8];
	void print();
	void reserve();
	void Cancel();
};

void Schedule::print() {
	for (int i = 0; i < 8; i++)
	{
		if (a[i].CheckSetName()) {
			cout << a[i].getName()<<" ";
		}
		else cout << "--- ";
	}
	cout << endl;
}

void Schedule::reserve() {
	print();
	cout << "seat num >> ";
	int num;
	cin >> num;
	if (1 <= num && num <= 8) {
		cout << "input name >> ";
		string name;
		cin >> name;
		if (a[num - 1].CheckSetName()) {
			cout << "already reserved!!" << endl;
			return;
		}
		a[num - 1].setName(name); a[num - 1].setNum(num - 1);
	}
	else{
		cout << "input num 1 ~ 8" << endl;
		return;
	}
};

void Schedule::Cancel() {
	print();
	cout << "seat num >> ";
	int num;
	cin >> num;
	if (1 <= num && num <= 8) {
		if (!(a[num - 1].CheckSetName())) {
			cout << "Seats are not reserved !!" << endl;
			return;
		}
		cout << "input name >> ";
		string name;
		cin >> name;
		if (a[num - 1].CheckName(name))
			a[num - 1].setName("");
		else {
			cout << "Name does not match !!" << endl;
			return;
		}
	}
}

class AirlineBook {
	Schedule *p = new Schedule[3];
public:
	void run();
};
void AirlineBook::run() {
	while (1) {
		switch (Console::menu()) {
		case 1: {
			switch (Console::resMenu()) {
			case 1:
				cout << "TIME 07: ";
				p[0].reserve();
				p[0].setTime(07);
				break;
			case 2:
				cout << "TIME 12: ";
				p[1].reserve();
				p[1].setTime(12);
				break;
			case 3:
				cout << "TIME 17: ";
				p[2].reserve();
				p[2].setTime(17);
				break;
			default:
				cout << "Nonexistent menu!!" << endl;
				break;
			}
			break; 
		}
		case 2:{
			switch (Console::resMenu()) {
			case 1:
				cout << "TIME 07: ";
				p[0].Cancel();
				break;
			case 2:
				cout << "TIME 12: ";
				p[1].Cancel();
				break;
			case 3:
				cout << "TIME 17: ";
				p[2].Cancel();
				break;
			default:
				cout << "Nonexistent menu!!" << endl;
				break;
			}
			break; 
		}
		case 3: {
			cout << "TIME 07: ";
			p[0].print();
			cout << "TIME 12: ";
			p[1].print();
			cout << "TIME 17: ";
			p[2].print();
			break;
		}
		case 4:
			return;
			break;
		default:
			cout << "Nonexistent menu!!" << endl;
			break;
		}
	}
}
int main() {
	cout << "***** Hello, Airlines. *****" << endl;
	AirlineBook *p = new AirlineBook();
	p->run();
	return 0;
}