#include "encanddec.h"

void encanddec::encryption() {
	output Speaker;						//������� ��������� ����� � �������
	Keys* KeysBunch = new Keys;			//������ � ������ � ����������
	Filework Librarian(KeysBunch);		//���������� ������ � ������

	Speaker.SourceKey_invite();				//����������� �� ���� ��������� �����
	KeysBunch->SourseKey_enter();			//���� ��������� �����
	KeysBunch->EncKeysGen();				//��������� ������� �������� ��� ���������
	Speaker.ShowSubKeysTable(KeysBunch);	//����� ������� ���������
	Speaker.FileName_invite();				//����������� �� ���� ����� �����
	Librarian.Files_open(".enc");			//������� ������ ��� ������. ��������� ���������� ��������� �����.
	Librarian.File_encryption();			//����� ��� ����������
	Librarian.Files_close();				//�������� ������
	delete KeysBunch;
	system("pause");
	system("cls");
}