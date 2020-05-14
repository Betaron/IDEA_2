#include "Keys.h"

using namespace std;

ideamop MM;

void Keys::SourseKey_enter() {
	for (char i = 0; i < 8; i++) {
		cin >> hex >> _Keys[i] >> dec;
	}
	if (!cin) {
		cin.clear();
		cin.ignore(5000);
	}
}

void Keys::EncKeysGen() {
	for (uint8_t Round = 1; Round < 7; Round++) {
		for (int i = 0; i < 8; i++) {
			GenRoundKeys[i] = _Keys[(Round - 1) * 8 + i];
		}
		uint16_t SubKeyBuf = GenRoundKeys[0];

		for (int i = 0; i < 7; i++) {
			GenRoundKeys[i] = GenRoundKeys[i + 1];
		}
		GenRoundKeys[7] = SubKeyBuf;

		SubKeyBuf = GenRoundKeys[0] >> 7;
		GenRoundKeys[0] <<= 9;
		uint16_t KeyPart = 0;
		for (int i = 1; i < 8; i++) {
			KeyPart = GenRoundKeys[i] >> 7;
			GenRoundKeys[i] <<= 9;
			GenRoundKeys[i - 1] |= KeyPart;
		}
		GenRoundKeys[7] |= SubKeyBuf;

		for (int i = 0; i < 8; i++) {
			_Keys[Round * 8 + i] = GenRoundKeys[i];
		}
	}
}

void Keys::DecKeysGen() {
	EncKeysGen();
	uint16_t buf;
	for (uint8_t i = 0; i < 4; i++) {
		Swap(_Keys[i * 6], _Keys[(8 - i) * 6], buf);
		Swap(_Keys[i * 6 + 1], _Keys[(8 - i) * 6 + 1], buf);
		Swap(_Keys[i * 6 + 2], _Keys[(8 - i) * 6 + 2], buf);
		Swap(_Keys[i * 6 + 3], _Keys[(8 - i) * 6 + 3], buf);
		Swap(_Keys[i * 6 + 4], _Keys[(7 - i) * 6 + 4], buf);
		Swap(_Keys[i * 6 + 5], _Keys[(7 - i) * 6 + 5], buf);
	}
	for (uint8_t i = 1; i < 8; i++) {
		Swap(_Keys[i * 6 + 1], _Keys[i * 6 + 2], buf);
	}
	for (uint8_t i = 0; i < 9; i++) {
		_Keys[i * 6 + 0] = MM.ModMultiplicativeInversion(_Keys[i * 6 + 0]);
		_Keys[i * 6 + 1] = MM.ModAdditiveInversion(_Keys[i * 6 + 1]);
		_Keys[i * 6 + 2] = MM.ModAdditiveInversion(_Keys[i * 6 + 2]);
		_Keys[i * 6 + 3] = MM.ModMultiplicativeInversion(_Keys[i * 6 + 3]);
	}
}

uint16_t Keys::GetSubKey(int Round, int Number) {
	return _Keys[Round * 6 + Number];
}