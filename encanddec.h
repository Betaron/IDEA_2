#pragma once
#include "MainHeader.h"
#include "output.h"
#include "Keys.h"
#include "Filework.h"

class encanddec		//класс с методами организующими шифрование и дешифрование
{
public:
	void encryption();		//шифрование файла
	void decryption();		//дешифрование файла
};