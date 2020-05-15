#include <iostream>
#include "Windows.h"
#include "encanddec.h"

using namespace std;

const char m1[] = {"1. Шифрование файла"};
const char m2[] = {"2. Дешифрование файла"};
const char m3[] = {"3. Выход"};
const  char* menu[] = { m1,m2,m3 };

int GetMenuItem() {
	int m;
	cout << ">> ";
	cin >> m;
	return m;
}

int main() {

	encanddec scientist;		//объект класса для шифрования и дешифрования

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Вас приветствует программа-реализация международного алгоритма шифрования данных - IDEA\n\n";
	cout << "Шифрование и дешифрование файла.\n";
	cout << "В результате работы программы вы получите файл(с расширением '.enc' или '.dec').\n";
	cout << "Он будет расположен в той же дирректории, что и исходный файл.\n";
	cout << "Для получения исходного файла при дешифровании необходимо использовать тот же ключ,\n";
	cout << "который использовался для шифрования файла. А также необходимо заменить расширение '.dec'\n";
	cout << "на расширение исходного файла.\n\n";
	while (42) {
		for ( uint8_t i = 0; i < 3; i++){
			cout << menu[i] << endl  ;
		}
		switch (GetMenuItem())
		{
		case 1:
			system("cls");
			scientist.encryption();		//шифрование
			break;
		case 2:
			system("cls");
			scientist.decryption();		//дешифрование
			break;
		case 3:
			system("cls");
			return 0;
		default:
			cin.clear();
			cin.ignore(1000, '\n');
			break;
		}
	}
	return 0;
}