#pragma once
#define IS_PRIME(T)
template <typename T>
bool isPrime(T number) {
	bool isPrime = true;
	if (number == 0 || number == 1) {
		isPrime = false;
	}

	for (int i = 2; i <= number / 2; ++i) {
		if (number % i == 0) {
			isPrime = false;
			break;
		}
	}

	return isPrime;
}