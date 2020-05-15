using namespace std;

#include <iostream>
#include <fstream>
#include <string>
#include "MainHeader.h"
#include "ideamop.h"
#include "Keys.h"

class Filework //Класс работы с файлами
{
private:
	string SourceFileName;					//Название файла, получаемого программой на вход
	string OutputFileName;					//Название файла, который создаётся программой (.enc | .dec)
	ifstream fin;							//Файл для забора исходных данных
	ofstream fout;							//Файл - результат работы программы
	ideamop MM; /*MathMachine*/				//Объект для работы с математическими операциями
	uint16_t DataBlock[4] = {0, 0, 0, 0};	//64(16*4) битный блок, который подвергается шифрованию
	int SBC; /*SBC - SubBlock Counter*/		//Переменная хранящая положение подблока DataBlock[] (шаг 1 байт)
	int SBC_remainder;						//Определяет чётность подблока
	int SBC_half;							//Определяет в каком блоке находится подблок
	uint8_t ZerosCount;						//Количество нулей добавляемое в конец шифруемого файла 
	Keys* KeysBunch;						//Объект для работы с подключами
	void File_read();						//Чтение файла по 8 байт и последуещая запись в 'uint16_t DataBlock[4]'
	void File_addZeros();					//Добавление нулей в конец шифруемого файла
	void XXcryptionCycle();					//Цепь оперций для шифрования и дешифрования
	void File_write();						//Запись шифротекста в конечный файл (.enc)
	void Dec_File_write();					//Запись расшифрованного текста в файл (.dec)
public:
	Filework(Keys* K) {						//Конструктор. Принимает ссылку на объект класса Keys
		SBC = 0;
		SBC_remainder = 0;
		SBC_half = 0;
		ZerosCount = 0;
		KeysBunch = K;
	}
	void Files_open(string);				//Отрытие файлов 'fin' и 'fout'. Принимает расширение выходного файла.
	void File_encryption();					//Метод для шифрования
	void File_decryption();					//Метод для дешифрования
	void Files_close();						//Закрытие файлов 'fin' и 'fout'
};