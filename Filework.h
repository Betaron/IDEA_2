using namespace std;

#include <iostream>
#include <fstream>
#include <string>
#include "MainHeader.h"
#include "ideamop.h"
#include "Keys.h"

class Filework //����� ������ � �������
{
private:
	string SourceFileName;					//�������� �����, ����������� ���������� �� ����
	string OutputFileName;					//�������� �����, ������� �������� ���������� (.enc | .dec)
	ifstream fin;							//���� ��� ������ �������� ������
	ofstream fout;							//���� - ��������� ������ ���������
	ideamop MM; /*MathMachine*/				//������ ��� ������ � ��������������� ����������
	uint16_t DataBlock[4] = {0, 0, 0, 0};	//64(16*4) ������ ����, ������� ������������ ����������
	int SBC; /*SBC - SubBlock Counter*/		//���������� �������� ��������� �������� DataBlock[] (��� 1 ����)
	int SBC_remainder;						//���������� �������� ��������
	int SBC_half;							//���������� � ����� ����� ��������� �������
	uint8_t ZerosCount;						//���������� ����� ����������� � ����� ���������� ����� 
	Keys* KeysBunch;						//������ ��� ������ � ����������
	void File_read();						//������ ����� �� 8 ���� � ����������� ������ � 'uint16_t DataBlock[4]'
	void File_addZeros();					//���������� ����� � ����� ���������� �����
	void XXcryptionCycle();					//���� ������� ��� ���������� � ������������
	void File_write();						//������ ����������� � �������� ���� (.enc)
	void Dec_File_write();					//������ ��������������� ������ � ���� (.dec)
public:
	Filework(Keys* K) {						//�����������. ��������� ������ �� ������ ������ Keys
		SBC = 0;
		SBC_remainder = 0;
		SBC_half = 0;
		ZerosCount = 0;
		KeysBunch = K;
	}
	void Files_open(string);				//������� ������ 'fin' � 'fout'. ��������� ���������� ��������� �����.
	void File_encryption();					//����� ��� ����������
	void File_decryption();					//����� ��� ������������
	void Files_close();						//�������� ������ 'fin' � 'fout'
};