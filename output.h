#pragma once
#include <iostream>
#include <iomanip>
#include "Windows.h"
#include "MainHeader.h"
#include "Keys.h"

using namespace std;

class output {		//������� ��������� ����� � �������
private:
	void DrawHorisontal(char, char, char, char);		//��������� �������������� �����
public:
	void SourceKey_invite();							//����������� �� ���� ��������� �����
	void FileName_invite();								//����������� �� ���� ����� �����
	void ShowSubKeysTable(Keys*);						//����� ������� ���������
};