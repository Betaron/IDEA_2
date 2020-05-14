#include "encanddec.h"

void encanddec::decryption() {
	output Speaker;						//Выводит некоторый текст в консоль
	Keys* KeysBunch = new Keys;			//Работа с ключом и подключами
	Filework Librarian(KeysBunch);		//Производит работу с фалами

	Speaker.SourceKey_invite();				//Приглашение на ввод исходного ключа
	KeysBunch->SourseKey_enter();			//Ввод исходного ключа
	KeysBunch->DecKeysGen();				//Генерация таблицы подлючей для шфрования
	Speaker.ShowSubKeysTable(KeysBunch);	//Вывод таблицы подключей
	Speaker.FileName_invite();				//Приглашение на ввод имени файла
	Librarian.Files_open(".dec");			//Отрытие файлов для работы. Принимает расширение выходного файла.
	Librarian.File_decryption();			//Метод для дешифрования
	Librarian.Files_close();				//Закрытие файлов
	delete KeysBunch;

	system("pause");
	system("cls");
}