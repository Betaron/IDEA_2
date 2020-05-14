#pragma once
#include <iostream>
#include "MainHeader.h"
#include "ideamop.h"

class Keys{			//������ � ������ � ����������
private:
	uint16_t _Keys[56];						//������ �������� �������
	uint16_t GenRoundKeys[8];				//������ ��� �������� �������� ���������
public:
	void SourseKey_enter();					//���� ��������� �����
	void EncKeysGen();						//��������� ������� �������� ��� ���������
	void DecKeysGen();						//��������� ������� ��������� ��� ������������
	uint16_t GetSubKey(int, int);			//�����, ������������ ����������� �������
};