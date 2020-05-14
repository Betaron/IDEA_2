#include "Filework.h"

void Filework::Files_open(string extension) {
	fin.exceptions(ifstream::badbit | ifstream::failbit);
	
	while (!fin.is_open()) {
		cin.ignore();
		getline(cin, SourceFileName);
		try
		{
			cout << "Попытка открыть файл..." << endl;
			fin.open(SourceFileName, ios::in | ios::binary);
			cout << "Файл открыт." << endl;
		}
		catch (const ifstream::failure& ex)
		{
			cout << ex.what() << endl;
			cout << ex.code() << endl;
			cout << "Ошибка! Попробуйте снова." << endl << ">> ";
			continue;
		}
		if (fin.peek() == EOF) {
			cout << "Файл пуст. Выберите другой." << endl;
			fin.close();
		}
	}
	uint32_t PointPos = SourceFileName.length();
	for (uint32_t i = 0; i < SourceFileName.length(); i++) {
		if (SourceFileName[i] == '.') PointPos = i;
	}
	OutputFileName.resize(PointPos, '0');
	for (uint32_t i = 0; i < (PointPos); i++)OutputFileName[i] = SourceFileName[i];
	OutputFileName += extension;
	fout.open(OutputFileName, ios::out | ios::binary);
	if (extension == ".enc") {
		fin.seekg(0, ios::end);
		ZerosCount = 8 - (fin.tellg() % 8);
		fout << ZerosCount;
		fin.seekg(0, ios::beg);
	}
}

void Filework::File_read() {
	for (uint8_t i = 0; i < 4; i++) *(DataBlock + i) = 0;
	for (; SBC < 8 && !fin.eof(); SBC++) {
		SBC_remainder = SBC % 2;
		SBC_half = SBC / 2;
		if (SBC_remainder == 0) {
			*(DataBlock + SBC_half) |= (fin.get() << 8);
		}
		if (SBC_remainder != 0) {
			*(DataBlock + SBC_half) |= fin.get();
		}
	}
}

void Filework::File_addZeros() {
	for (; SBC < 8 && fin.eof(); SBC++) {
		if (SBC_remainder != 0) {
			*(DataBlock + SBC_half) &= 0x00ff;
		}
		if (SBC_remainder == 0) {
			*(DataBlock + SBC_half) &= 0x0000;
			SBC++;
		}
	}
}

void Filework::XXcryptionCycle() {
	enum { A, B, C, D, E, F };
	for (int i = 0; i < 8; i++) {
		uint16_t Buf[6] = { 0 };
		uint16_t SubBuf = 0;
		Buf[A] = MM.ModMultiplication(*(DataBlock + 0), (*KeysBunch).GetSubKey(i, 0));
		Buf[B] = MM.ModAddition(*(DataBlock + 1), (*KeysBunch).GetSubKey(i, 1));
		Buf[C] = MM.ModAddition(*(DataBlock + 2), (*KeysBunch).GetSubKey(i, 2));
		Buf[D] = MM.ModMultiplication(*(DataBlock + 3), (*KeysBunch).GetSubKey(i, 3));
		Buf[E] = Buf[A] ^ Buf[C];
		Buf[F] = Buf[B] ^ Buf[D];

		SubBuf = MM.ModMultiplication(MM.ModAddition(Buf[F], MM.ModMultiplication(Buf[E], (*KeysBunch).GetSubKey(i, 4))), (*KeysBunch).GetSubKey(i, 5));
		*(DataBlock + 0) = Buf[A] ^ SubBuf;
		*(DataBlock + 1) = Buf[C] ^ SubBuf;
		SubBuf = MM.ModAddition(MM.ModMultiplication(Buf[E], (*KeysBunch).GetSubKey(i, 4)), SubBuf);
		*(DataBlock + 2) = Buf[B] ^ SubBuf;
		*(DataBlock + 3) = Buf[D] ^ SubBuf;
	}
	{
		uint16_t SubBuf = 0;
		*(DataBlock + 0) = MM.ModMultiplication(DataBlock[0], (*KeysBunch).GetSubKey(8, 0));
		*(DataBlock + 1) = MM.ModAddition(DataBlock[1], (*KeysBunch).GetSubKey(8, 2));
		*(DataBlock + 2) = MM.ModAddition(DataBlock[2], (*KeysBunch).GetSubKey(8, 1));
		Swap(DataBlock[1], DataBlock[2], SubBuf);
		*(DataBlock + 3) = MM.ModMultiplication(DataBlock[3], (*KeysBunch).GetSubKey(8, 3));
	}
}

void Filework::File_write() {
	for (uint8_t i = 0; i < 4; i++) {
		fout << (char)(*(DataBlock + i) >> 8);
		fout << (char)(*(DataBlock + i) & 0x00ff);
	}
}

void Filework::Dec_File_write() {
	if (fin.peek() == EOF) {
		for (uint8_t i = 0; i < 8 - ZerosCount; i++) {
			if (i % 2 == 0)
				fout << (char)(*(DataBlock + i/2) >> 8);
			if (i % 2 != 0)
				fout << (char)(*(DataBlock + i/2) & 0x00ff);
		}
	}
	else{
		File_write();
	}
}

void Filework::File_encryption() {
	/*Reading*/
	fin.exceptions(ifstream::goodbit);
	SBC_remainder = 0;
	SBC_half = 0;
	while (!fin.eof()) {
		if (fin.peek() == EOF) break;
		SBC = 0;
		File_read();
		File_addZeros();
		/* => DataBlock[] */
		XXcryptionCycle();
		File_write();
	}
}

void Filework::File_decryption() {
	/*Reading*/
	fin.exceptions(ifstream::goodbit);
	SBC_remainder = 0;
	SBC_half = 0;
	ZerosCount = fin.get();
	while (!fin.eof()) {
		if (fin.peek() == EOF) break;
		SBC = 0;
		File_read();
		/* => DataBlock[] */
		XXcryptionCycle();
		Dec_File_write();
	}
}

void Filework::Files_close() {
	fin.close();
	if (!fin.is_open())
	cout << dec << "Файл " << SourceFileName << " закрыт." << endl;
	else cout << "Файл " << SourceFileName << " не удалось закрыть." << endl;
	fout.close();
	if (!fout.is_open())
	cout << "Файл " << OutputFileName << " закрыт." << endl;
	else cout << "Файл " << OutputFileName << " не удалось закрыть." << endl;
}