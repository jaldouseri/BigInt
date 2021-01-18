#include <string>
#include <iostream>
#include <cstdlib>
#include "BigInt.h"

using namespace std;

// ===================================================================================================
// Constructors & private functions
// ===================================================================================================

BigInt::BigInt() {
	for (int i = 0; i < MAX; i++) {
		digits[i] = 0;
	}
}

int BigInt::ResetLength() {

	int i = MAX - 1;
	bool LengthFound = false;

	while (i >= 0 && !LengthFound)
	{
		if (digits[i] > 0)
		{
			LengthFound = true;
			LEN = i + 1;
		}
		else if (i == 0 && !LengthFound)
		{
			LEN = 1;
			sign = 1;
			break;
		}
		else
		{
			i--;
		}
	}
	return 1;
}

int BigInt::Reset() {

	LEN = 1;
	sign = 1;

	for (int i = 0; i < MAX; i++) {
		digits[i] = 0;
	}
	return 1;
}

// ===================================================================================================
// input & output Overload functions
// ===================================================================================================

ostream& operator<<(ostream& os, const BigInt& bi)
{
	if (bi.sign == -1)
	{
		os << '-';
	}
	for (int i = bi.LEN-1; i >= 0; i--) {
		os << bi.digits[i];
	}
	os << " LEN : " << bi.LEN << " sign : " << bi.sign;
	return os;
}

istream& operator>>(istream& is, BigInt& bi)
{
	string temp;
	is >> temp;
	bi = temp;
	return is;
}

void BigInt::print() {
	if (sign == -1)
	{
		cout << '-';
	}
	for (int i = LEN - 1; i >= 0; i--) {
		cout << digits[i];
	}
	cout << endl;
	cout << " LEN : " << LEN << endl;
	cout << " sign : " << sign << endl;
}

// ===================================================================================================
// Logical Operators Overload functions
// ===================================================================================================

bool BigInt::operator==(const BigInt& bi) {

	if (LEN == bi.LEN && sign == bi.sign)
	{
		for (int i = LEN - 1; i >= 0; i--) {
			if (digits[i] != bi.digits[i])
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}
	return true;
}

bool BigInt::operator>(const BigInt& bi) {

	if (sign > bi.sign) { return true; }
	if (LEN > bi.LEN) { return true; }
	if (LEN < bi.LEN) { return false; }

	if (LEN == bi.LEN)
	{
		for (int i = LEN - 1; i >= 0; i--) {
			if (digits[i] > bi.digits[i])
			{
				return true;
			}
			else if (digits[i] < bi.digits[i]) {
				return false;
			}
		}
	}
	return false;
}

bool BigInt::operator>=(const BigInt& bi) {

	if (sign > bi.sign) { return true; }
	if (LEN > bi.LEN) { return true; }
	if (LEN < bi.LEN) { return false; }

	if (LEN == bi.LEN)
	{
		for (int i = LEN - 1; i >= 0; i--) {
			if (digits[i] > bi.digits[i])
			{
				return true;
			}
			else if (digits[i] < bi.digits[i]) {
				return false;
			}
		}
	}
	return true;
}

bool BigInt::operator<(const BigInt& bi) {

	if (sign < bi.sign) { return true; }
	if (LEN < bi.LEN) { return true; }
	if (LEN > bi.LEN) { return false; }

	if (LEN == bi.LEN)
	{
		for (int i = LEN - 1; i >= 0; i--) {
			if (digits[i] < bi.digits[i])
			{
				return true;
			}
			else if (digits[i] > bi.digits[i]) {
				return false;
			}
		}
	}
	return false;
}

bool BigInt::operator<=(const BigInt& bi) {

	if (sign < bi.sign) { return true; }
	if (LEN < bi.LEN) { return true; }
	if (LEN > bi.LEN) { return false; }

	if (LEN == bi.LEN)
	{
		for (int i = LEN - 1; i >= 0; i--) {
			if (digits[i] < bi.digits[i])
			{
				return true;
			}
			else if (digits[i] > bi.digits[i]) {
				return false;
			}
		}
	}
	return true;
}

int BigInt::NoSignCompare(const BigInt& bi)
{
	if (LEN == bi.LEN)
	{
		for (int i = LEN - 1; i >= 0; i--) {
			if (digits[i] > bi.digits[i])
			{
				return 1;
			}
			else if ((digits[i] < bi.digits[i]))
			{
				return -1;
			}
		}
	}
	else if (LEN > bi.LEN)
	{
		return 1;
	}
	else
	{
		return -1;
	}
	return 0;
}

// ===================================================================================================
// Math Operators Overload functions
// ===================================================================================================

bool BigInt::operator=(const BigInt& bi) {

	Reset();
	LEN = bi.LEN;
	sign = bi.sign;

	for (int i = 0; i < MAX; i++) {
		digits[i] = bi.digits[i];
	}
	return true;
}

bool BigInt::operator=(const string value) {

	Reset();
	int j = 0;
	int iend = 0;

	if (value[0] == '-')
	{									// if the negative value is zero
		sign = -1;
		iend = 1;
	}
										// ResetLength will fix the length
	LEN = value.length();
	if (LEN >= MAX)
	{
		cout << endl << " Length is " << LEN << " Max Length have been exceeded : " << MAX << endl;
		Reset();
		return false;
	}
	for (int i = LEN -1; i >= iend ; i--) {
										// if it not a digit zero it.
		if (value[i] >= 48 && value[i] <= 57)
		{
			digits[j] = value[i] - 48;
		}
		else
		{
			digits[j] = 0;
		}
		j++;
	}
										// protect the length of wrong input
	ResetLength();
	return true;
}

BigInt BigInt::operator+(const BigInt& bi) {

	BigInt result;

	if (sign == 1 && bi.sign == 1)
	{
		result = add(bi);
		result.sign = 1;
	}
	else if (sign == -1 && bi.sign == -1)
	{
		result = add(bi);
		result.sign = -1;
	}
	else
	{
		if ( NoSignCompare(bi) == 1)
		{
			result = subtract(bi);
			result.sign = sign;
		}
		else
		{
			result = bi;
			result = result.subtract(*this);
			result.sign = bi.sign;
		}

	}
	result.ResetLength();
	return result;
}

BigInt BigInt::operator-(const BigInt& bi) {

	BigInt result;

	if ((sign == 1 && bi.sign == 1) || (sign == -1 && bi.sign == -1))
	{
		if (NoSignCompare(bi) == 1)
		{
			result = subtract(bi);
			result.sign = sign;
		}
		else
		{
			result = bi;
			result = result.subtract(*this);
			result.sign = -1;
		}
	}
	else if (sign == -1 && bi.sign == 1) 
	{
		result = add(bi);
		result.sign = -1;
	}
	else 
	{
		result = add(bi);
		result.sign = 1;

	}
	result.ResetLength();
	return result;
}

BigInt BigInt::operator*(const BigInt& bi) {

	BigInt result, temp;
	int carry = 0;
	int value = 0;
	int digit = 0;
	int counter = 0;
	
	if ((LEN == 1 && digits[0] == 0) || (bi.LEN ==1 && digits[0] == 0))
	{
		result.sign = 1;
	}
	else
	{
		result.sign = sign * bi.sign;
	}

	for (int j = 0; j < bi.LEN; j++) {
		for (int i = 0; i < MAX; i++){

			value = bi.digits[j] * digits[i] + carry;
							// get digit value
			digit = value % 10;
							// get carry value
			carry = value / 10;
			if ((i + j) < MAX)
			{
				counter = i + j;
			}
			temp.digits[counter] = digit;
		}
		temp.ResetLength();
		result = result + temp;
		result.ResetLength();
		temp = "0";
	}
	return result;
}

BigInt BigInt::operator/(const BigInt& bi) {

	BigInt divisor, dividend, quotient;
	int quotientcounter = 0;
	int dividendPtr = 0;
	bool divisible = true;

	divisor = bi;
	quotient = "0";
	dividend.digits[dividendPtr] = digits[LEN - 1];

	if (bi.LEN == 1 && bi.digits[0] == 0)
	{
		throw runtime_error("Math error: Attempted to divide by Zero\n");
	}

	while (divisible)			// how many times we can subtract it.
	{
		if (dividend.NoSignCompare(divisor) >= 0)
		{
			quotientcounter++;
			dividend = dividend.subtract(divisor);
		}
		else
		{
			if (dividendPtr == LEN - 1)
			{
				divisible = false;
				quotient.digits[LEN - dividendPtr - 1] = quotientcounter;
				quotientcounter = 0;
			}
			else
			{
				dividend.LEN++;
				dividendPtr++;
				for (int i = dividendPtr; i > 0; i--)  // shift he digits
				{
					dividend.digits[i] = dividend.digits[i - 1];
				}
				dividend.digits[0] = digits[LEN - dividendPtr - 1];
				dividend.ResetLength();
				quotient.digits[LEN - dividendPtr] = quotientcounter;
				quotientcounter = 0;
			}
		}
	}
	quotient.sign = sign / bi.sign;
	quotient.ResetLength();
	return quotient;
}

BigInt BigInt::operator%(const BigInt& bi) {

	BigInt divisor, dividend, quotient;
	int quotientcounter = 0;
	int dividendPtr = 0;
	bool divisible = true;

	divisor = bi;
	quotient = "0";
	dividend.digits[dividendPtr] = digits[LEN - 1];

	if (bi.LEN == 1 && bi.digits[0] == 0)
	{
		throw runtime_error("Math error: Attempted to divide by Zero\n");
	}

	while (divisible)			// how many times we can subtract it.
	{
		if (dividend.NoSignCompare(divisor) >= 0)
		{
			quotientcounter++;
			dividend = dividend.subtract(divisor);
		}
		else
		{
			if (dividendPtr == LEN - 1)
			{
				divisible = false;
				quotient.digits[LEN - dividendPtr - 1] = quotientcounter;
				quotientcounter = 0;
			}
			else
			{
				dividend.LEN++;
				dividendPtr++;
				for (int i = dividendPtr; i > 0; i--)  // shift he digits
				{
					dividend.digits[i] = dividend.digits[i - 1];
				}
				dividend.digits[0] = digits[LEN - dividendPtr - 1];
				dividend.ResetLength();
				quotient.digits[LEN - dividendPtr] = quotientcounter;
				quotientcounter = 0;
			}
		}
	}
	dividend.sign = (sign * 4) % (bi.sign * 3);
	dividend.ResetLength();
	return dividend;
}

BigInt BigInt::operator++() {

	BigInt temp;
	temp = "1";
	*this = *this + temp;
	return *this;
}

BigInt BigInt::operator++(int dummy) {
	BigInt temp, returned;
	temp = "1";
	returned = *this;
	*this = *this + temp;
	return returned;
}

BigInt BigInt::operator<<(const int shift) {

	BigInt result, Two, DigitValue;
	Two = "2";
	DigitValue = "1";

	for (int i = 0; i < shift; i++) {
		DigitValue = Two * DigitValue;
	}
	result = *this * DigitValue;

	result.ResetLength();
	return result;
}

BigInt BigInt::operator<<(const BigInt bi) {

	BigInt result, Two, DigitValue, i;
	Two = "2";
	DigitValue = "1";

	for (i = "0"; i < bi; i++) {
		DigitValue = Two * DigitValue;
	}
	result = *this * DigitValue;

	result.ResetLength();
	return result;
}

BigInt BigInt::operator>>(const int shift) {

	BigInt result, Two, DigitValue;
	Two = "2";
	DigitValue = "1";

	for (int i = 0; i < shift; i++) {
		DigitValue = Two * DigitValue;
	}
	result = *this / DigitValue;

	result.ResetLength();
	return result;
}

BigInt BigInt::operator>>(const BigInt bi) {

	BigInt result, Two, DigitValue, i;
	Two = "2";
	DigitValue = "1";

	for (i = "0"; i < bi; i++) {
		DigitValue = Two * DigitValue;
	}
	result = *this / DigitValue;
	result.sign = sign;

	result.ResetLength();
	return result;
}

BigInt BigInt::pow(const BigInt& bi) {

	BigInt result, i;

	if ((bi.LEN == 1 && bi.digits[0] == 0))
	{
		result = "0";
	}
	else
	{
		result = "1";
		for (i = "1"; i <= bi; i++) {
			result = result * *this;
											// Protect from reaching MAX
			if (result.LEN >= MAX)
			{
				break;
			}
			result.ResetLength();
		}
	}
	return result;
}

BigInt BigInt::add(const BigInt& bi) {
	// Simple add without sign .
	BigInt result;
	int carry = 0;
	int value = 0;
	int digit = 0;

	for (int i = 0; i < MAX; i++) {
		value = digits[i] + bi.digits[i] + carry;
		digit = value % 10;								// get digit value
		carry = value / 10;								// get carry value
		result.digits[i] = digit;
	}
	result.ResetLength();

	return result;
}

BigInt BigInt::subtract(const BigInt& bi) {
	// can not used alone .
	// can only used if this bigger than bi .
	BigInt result;
	result = *this;

	for (int i = 0; i < MAX; i++) {
		if (result.digits[i] < bi.digits[i])
		{
			result.digits[i] += 10;
			result.digits[i] = result.digits[i] - bi.digits[i];
			if (i + 1 != MAX)
			{
				result.digits[i + 1] += -1;
			}
		}
		else {
			result.digits[i] = result.digits[i] - bi.digits[i];
		}
	}
	result.ResetLength();

	return result;
}

BigInt BigInt::absolute() {

	BigInt result;
	result = *this;
	result.sign = 1;

	return result;
}

string BigInt::BigIntToBinary() {

	BigInt dividend,zero, one, Two, Remainder;
	string result = "";
	bool divisible = true;

	dividend = *this;
	Two = "2";
	Remainder = "0";
	one = "1";
	zero = "0";

	if (dividend == zero)
	{
		return "0";
	}
	while (dividend >= one)
	{
		Remainder = dividend % Two;
		result = to_string(Remainder.digits[0]) + result;
		dividend = dividend / Two;
	}

	return result;
}

BigInt BigInt::BinaryToBigInt(const string binary) {

	BigInt result, Two, DigitValue, Digit;
	string dummy;

	Two = "2";
	DigitValue = "1";

	for (int i = binary.length()-1; i >= 0; i--)
	{
		dummy = binary[i];
		Digit = dummy;
		result = result + ( Digit * DigitValue);
		DigitValue = Two * DigitValue;
	}
	return result;
}

