#pragma once
#include <iostream>
#include "MainHeader.h"
#include "ideamop.h"

class Keys{			//Работа с ключом и подключами
private:
	uint16_t _Keys[56];						//Массив хранящий подлючи
	uint16_t GenRoundKeys[8];				//Массив для создания создания подключей
public:
	void SourseKey_enter();					//Ввод исходного ключа
	void EncKeysGen();						//Генерация таблицы подлючей для шфрования
	void DecKeysGen();						//Генерация таблицы подключей для дешифрования
	uint16_t GetSubKey(int, int);			//Метод, возвращающий определённый подключ
};