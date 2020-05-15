#include <iostream>
#include "Windows.h"
#include "encanddec.h"

using namespace std;

const char m1[] = {"1. ���������� �����"};
const char m2[] = {"2. ������������ �����"};
const char m3[] = {"3. �����"};
const  char* menu[] = { m1,m2,m3 };

int GetMenuItem() {
	int m;
	cout << ">> ";
	cin >> m;
	return m;
}

int main() {

	encanddec scientist;		//������ ������ ��� ���������� � ������������

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "��� ������������ ���������-���������� �������������� ��������� ���������� ������ - IDEA\n\n";
	cout << "���������� � ������������ �����.\n";
	cout << "� ���������� ������ ��������� �� �������� ����(� ����������� '.enc' ��� '.dec').\n";
	cout << "�� ����� ���������� � ��� �� �����������, ��� � �������� ����.\n";
	cout << "��� ��������� ��������� ����� ��� ������������ ���������� ������������ ��� �� ����,\n";
	cout << "������� ������������� ��� ���������� �����. � ����� ���������� �������� ���������� '.dec'\n";
	cout << "�� ���������� ��������� �����.\n\n";
	while (42) {
		for ( uint8_t i = 0; i < 3; i++){
			cout << menu[i] << endl  ;
		}
		switch (GetMenuItem())
		{
		case 1:
			system("cls");
			scientist.encryption();		//����������
			break;
		case 2:
			system("cls");
			scientist.decryption();		//������������
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