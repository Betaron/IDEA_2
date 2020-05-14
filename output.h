#pragma once
#include <iostream>
#include <iomanip>
#include "Windows.h"
#include "MainHeader.h"
#include "Keys.h"

using namespace std;

class output {		//Выводит некоторый текст в консоль
private:
	void DrawHorisontal(char, char, char, char);		//Отрисовка горизонтальной линии
public:
	void SourceKey_invite();							//Приглашение на ввод исходного ключа
	void FileName_invite();								//Приглашение на ввод имени файла
	void ShowSubKeysTable(Keys*);						//Вывод таблицы подключей
};