#pragma once
#include <iostream>

class ideamop { /*IDEA math operations*/		//класс реализующий математические операции прменяемые в IDEA
public:
	uint16_t ModMultiplication(uint32_t a, uint32_t b) {		//Умножение по модулю (2^16 + 1) [(a*b) mod 0x10001]
		if (a == 0) a = 0x10000;
		if (b == 0) b = 0x10000;
		return (((a % 0x10001) * (b % 0x10001)) % 0x10001);
	}

	uint16_t ModAddition(uint16_t a, uint16_t b) {				//Сложение по модулю (2^16) [(a*b) mod 0x10000]
		return (((a % 0x10000) + (b % 0x10000)) % 0x10000);
	}

	uint16_t ModMultiplicativeInversion(uint16_t a) {			//Мультипликативная инверсия по модулю (2^16 + 1)
		for (uint32_t i = 1; i < 0x10001; i++) {				//[a * a^(-1) = 1 mod 0x10001]
			if ((a * i) % 0x10001 == 1)
				return i;
		}
		return 0;
	}

	uint16_t ModAdditiveInversion(uint16_t a) {					//Аддитивная инверсия по модулю (2^16)
		for (uint32_t i = 1; i < 0x10001; i++) {				//[a + (-a) = 0 mod 0x10000]
			if ((a + i) % 0x10000 == 0)
				return i;
		}
		return 0;
	}
};