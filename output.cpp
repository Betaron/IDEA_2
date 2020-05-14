#include "output.h"

void output::DrawHorisontal(char leftC, char fillC, char midleC, char rightC) {
	cout << endl << setw(10) << setfill(' ') << leftC << setw(5) << setfill(fillC);
	for (int i = 0; i < 5; i++) {
		cout << midleC << setw(5) << setfill(fillC);
	}
	cout << rightC << endl;
}

void output::SourceKey_invite(){
	system("cls");
	cout << endl << setw(44) << "\t== ¬вод ключа ==" << endl;
	cout << "\t люч должен состо€ть из 8 шестнадцатиричных четырЄхзначных чисел" << "\n\n>> ";
}

void output::FileName_invite(){
	cout << endl << setw(50) << "\t== ¬вод имени файла ==" << "\n\n>> ";
}

void output::ShowSubKeysTable(Keys* Bunch) {
	SetConsoleOutputCP(866);
	cout << endl << setw(12) << setfill(' ');
	for (int i = 0; i < 6; i++) {
		cout << "  K" << i + 1 << " ";
	}
	DrawHorisontal((char)218, (char)196, (char)194, (char)191);
	for (int i = 0; i < 9; i++) {
		cout << " Round " << i + 1 << " " << (char)179;
		for (int j = 0; j < 6; j++) {
			if ((i == 8) && (j > 3)) cout << " " << (char)196 << (char)196 << " ";
			else cout << hex << setw(4) << setfill('0') << (*Bunch).GetSubKey(i, j);
			cout << dec << (char)179;
		}
		if (i != 8) DrawHorisontal((char)195, (char)196, (char)197, (char)180);
		else DrawHorisontal((char)192, (char)196, (char)193, (char)217);
	}
	SetConsoleOutputCP(1251);
	cout << setfill(' ');
}