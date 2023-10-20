/**
 * @file MathTemplates.h
 *
 * @brief Template declerations for simple math funcs.
 *
 *
 * @author Salih Eren Degirmenci
 * Contact: S.E.Degirmenci2@newcastle.ac.uk
 */

#pragma once

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

template<typename T>
bool isSquare(T number) {
	if (number < 0) {
		return false;
	}

	int squareRoot = static_cast<int>(std::sqrt(number));
	return squareRoot * squareRoot == number;
}

template<typename T>
bool isComposite(T number) {
	if (number <= 1) {
		return false;
	}

	for (int i = 2; i <= number / 2; i++) {
		if (number % i == 0) {
			return true;
		}
	}

	return false;
}

template <typename T>
int countDigits(T number) {
	int digitCount = 1;

	while (number >= 10) {
		number /= 10;
		digitCount++;
	}

	return digitCount;
}

template <typename T>
bool haveCommonPrimeFactor(T numOne, T numTwo) {
	while (numTwo != 0) {
		int temp = numTwo;
		numTwo = numOne % numTwo;
		numOne = temp;
	}
	return numOne > 1;
}

template<typename T>
int getGreatestCommonDivisior(T numOne, T numTwo) {
	while (numTwo != 0) {
		int temp = numTwo;
		numTwo = numOne % numTwo;
		numOne = temp;
	}
	return numOne;
}