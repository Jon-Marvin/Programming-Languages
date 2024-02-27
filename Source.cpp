//==================================
// Name: Jon Marvin
// Date: 1/24/2024
// CS - 210 Programming Languages
// SNHU
//==================================


#include <iostream>
#include <chrono>
#include <thread>
#include <tuple>
#include <iomanip>
#include <stdlib.h>
using namespace std;

int dataEdit;
int hour24 = 0;
int minute = 0;
int hour = 0;
int second = 0;
bool menuLoop = true;
//Adding AM and PM to the 12 hour clock
string am_pm() {
	if ((hour24 >= 12) && (hour24 <= 23)) {
		return " P.M.";
	}
	else {
		return " A.M.";
	}
}

//Using a tuple to ensure clock rolls time over to the next minute/hour
tuple <int, int, int, int> timeCheck() {
	if (second >= 60) {
		second = 0;
		minute++;
	}
	if (minute >= 60) {
		hour++;
		hour24++;
		minute = 0;
	}
	if ((hour == 12) && (second > 59)) {
		hour = 1;
	}
	if (hour24 >= 24) {
		hour24 = 0;
	}
	return make_tuple(hour, minute, second, hour24);
}
//Display for 12 hour clock
void show12HourTime() {
	cout << setfill('0') << setw(2) << get<0>(timeCheck()) << ":";
	cout << setfill('0') << setw(2) << get<1>(timeCheck()) << ":";
	cout << setfill('0') << setw(2) << get<2>(timeCheck()) << am_pm();
}
//Display for 24 hour clock
void show24HourTime() {
	cout << setfill('0') << setw(2) << get<3>(timeCheck()) << ":";
	cout << setfill('0') << setw(2) << get<1>(timeCheck()) << ":";
	cout << setfill('0') << setw(2) << get<2>(timeCheck());
}
//Shows both clocks on screen
void printTime() {
	cout << "*******************************************************" << endl;
	cout << "*      12 Hour Clock     *  *      24 Hour Clock      *" << endl;
	cout << "*       ";
	show12HourTime();
	cout << "    *" << "  *        ";
	show24HourTime();
	cout << "         *" << endl;
	cout << "*******************************************************" << endl;
	cout << endl;
}
//Menu for the user to interact with
void menuDisplay()
{
	while (menuLoop) {
		cout << "***************************" << endl;
		cout << "*     1 - Add a Hour      *" << endl;
		cout << "*     2 - Add a Minute    *" << endl;
		cout << "*     3 - Add a Second    *" << endl;
		cout << "*     4 - Exit Program    *" << endl;
		cout << "***************************" << endl;
		cin >> dataEdit;

		switch (dataEdit) {
		case 1:
			hour++;
			hour24++;
			printTime();
			break;

		case 2:
			minute++;
			printTime();
			break;

		case 3:
			second++;
			printTime();
			break;

		case 4:
			cout << "Goodbye!" << endl;
			menuLoop = false;
			break;
		}
	}
}
//Main function to show clocks and menu
int main() {
	printTime();

	menuDisplay();

	return 0;
}


