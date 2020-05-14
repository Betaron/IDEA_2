#include "encanddec.h"

void encanddec::encryption() {
	output Speaker;						//Выводит некоторый текст в консоль
	Keys* KeysBunch = new Keys;			//Работа с ключом и подключами
	Filework Librarian(KeysBunch);		//Производит работу с фалами

	Speaker.SourceKey_invite();				//Приглашение на ввод исходного ключа
	KeysBunch->SourseKey_enter();			//Ввод исходного ключа
	KeysBunch->EncKeysGen();				//Генерация таблицы подлючей для шфрования
	Speaker.ShowSubKeysTable(KeysBunch);	//Вывод таблицы подключей
	Speaker.FileName_invite();				//Приглашение на ввод имени файла
	Librarian.Files_open(".enc");			//Отрытие файлов для работы. Принимает расширение выходного файла.
	Librarian.File_encryption();			//Метод для шифрования
	Librarian.Files_close();				//Закрытие файлов
	delete KeysBunch;
	system("pause");
	system("cls");
}