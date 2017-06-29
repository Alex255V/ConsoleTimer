#include <iostream>
#include <Windows.h>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

int main(int argc, char ** argv);

void timer(int);

const int con = 60;

unsigned int s, m, h;
unsigned int timVal;

int main(int argc, char** argv)
{

	cout << " +------------------------------------------+" << endl;
	cout << " |Enter a number with a value               |" << endl;
	cout << " |Otherwise, the number will take in seconds|" << endl;
	cout << " |1h - 1 hour; 1m - 1 minute                |" << endl;
	cout << " +------------------------------------------+" << endl;
	cout << "Enter a number: ";

	int size = 0;
	char str[10];
	cin >> str;
	for (int i = 0; i < sizeof(str); i++) {
		if (str[i] == '\0') {
			break;
		}
		size++;
	}
	char *coun = new char[size];
	char *time = new char[size];
	char index = ' ';
	for (int i = 0; i < size; i++) {
		coun[i] = str[i];
	}


	for (int i = 0; i < size; i++) {
		if ((coun[i] != 'm') || (coun[i] != 'h')) {
			time[i] = coun[i];
		}
		if (coun[i] == 'm') { index = 'm'; }
		if (coun[i] == 'h') { index = 'h'; }

	}
	int t = atoi(time);

	delete[] coun;
	delete[] time;

	if (index == 'm') {
		timVal = t*con;
	}
	else if (index == 'h') {
		timVal = t*con*con;
	}
	else {
		timVal = t;
	}

	if ((index == ' ') || (index == 'm') || (index == 'h')) {
		if (timVal > 1) { timVal++; }

		int temp = timVal;
		if (temp > 3600) {
			h = 1;
			while (true) {
				temp = temp - 3600;
				if (temp < 3600) {
					timVal = temp;
					break;
				}
				else if (temp > 3600) {
					h++;
					continue;
				}
			}
		}
		if (temp > 60) {
			m = 1;
			while (true) {
				temp = temp - 60;
				cout << "sour " << temp << endl;
				if (temp < 60) {
					timVal = temp;
					break;
				}
				else if (temp > 60) {
					m++;
					cout << "min " << m << endl;
					continue;
				}
				if (m == 10) { return 0; }
			}
		}
	}

	timer(timVal);

	SoundBuffer soundBuffer;
	soundBuffer.loadFromFile("sound1.wav");
	Sound sound(soundBuffer);
	sound.play();
	sound.setLoop(true);
	sound.setVolume(80);

	system("pause");
	return 0;
}

void timer(int timVal) {
	s = timVal;

	while (true) {

		system("cls");

		cout << " +------------------------------------------+" << endl;
		cout << " |Enter a number with a value               |" << endl;
		cout << " |Otherwise, the number will take in seconds|" << endl;
		cout << " |1h - 1 hour; 1m - 1 minute                |" << endl;
		cout << " +------------------------------------------+" << endl;

		if (s > 0) {
			s--;
		}
		else if ((s == 0) && (m > 0)) {
			m--; s = con;
			continue;
		}
		else if ((s == 0) && (m == 0) && (h > 0)) {
			h--; m = con - 1; s = con;
			continue;
		}
		else if ((s == 0) && (m == 0) && (h == 0)) {
			cout << "end..." << endl;
			break;
		}
		cout.fill('0');
		cout.width(2);
		cout << "\t\t|" << h << ":";
		cout.fill('0');
		cout.width(2);
		cout << m << ":";
		cout.fill('0');
		cout.width(2);
		cout << s << "|" << endl;

		Sleep(1000);
	}
}
