#include "encanddec.h"

void encanddec::decryption() {
	output Speaker;						//������� ��������� ����� � �������
	Keys* KeysBunch = new Keys;			//������ � ������ � ����������
	Filework Librarian(KeysBunch);		//���������� ������ � ������

	Speaker.SourceKey_invite();				//����������� �� ���� ��������� �����
	KeysBunch->SourseKey_enter();			//���� ��������� �����
	KeysBunch->DecKeysGen();				//��������� ������� �������� ��� ���������
	Speaker.ShowSubKeysTable(KeysBunch);	//����� ������� ���������
	Speaker.FileName_invite();				//����������� �� ���� ����� �����
	Librarian.Files_open(".dec");			//������� ������ ��� ������. ��������� ���������� ��������� �����.
	Librarian.File_decryption();			//����� ��� ������������
	Librarian.Files_close();				//�������� ������
	delete KeysBunch;

	system("pause");
	system("cls");
}