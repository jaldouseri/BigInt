#ifndef BigInt_H
#define	BigInt_H

#include <string>
#include <iostream>
#include <istream>
#include <ostream>


using namespace std;

class BigInt {

public:

// ===================================================================================================
// constructor
// ===================================================================================================
    
    BigInt();

// ===================================================================================================
// input & output Overload
// ===================================================================================================
                                                    
    friend ostream& operator<<(ostream& os, const BigInt& bi);      // overload print
    friend istream& operator>>(istream& is, BigInt& bi);            // overlaod get
    void print();                                                   // direct print

// ===================================================================================================
// Logical Operators Overload functions
// ===================================================================================================

    bool operator==(const BigInt& bi);
    bool operator<(const BigInt& bi);
    bool operator>(const BigInt& bi);
    bool operator<=(const BigInt& bi);
    bool operator>=(const BigInt& bi);
    int NoSignCompare(const BigInt& bi);            // equal = 0 , grater than = 1, less than = -1

// ===================================================================================================
// Operators Overload
// ===================================================================================================

    bool operator=(const BigInt& bi);               // assign BigInt to BigInt
    bool operator=(const string value);             // assign string to BigInt
    BigInt operator+(const BigInt & bi);            // add with sign
    BigInt operator-(const BigInt& bi);             // subtract with sign
    BigInt operator*(const BigInt & bi);            // multiply
    BigInt operator/(const BigInt& bi);             // division
    BigInt operator%(const BigInt& bi);             // modulo
    BigInt operator++();                            // increment pre
    BigInt operator++(int dummy);                   // int dummy to make it post
    BigInt operator<<(const int bi);                // shift left input integer
    BigInt operator<<(const BigInt bi);             // shift left input BigInt
    BigInt operator>>(const int bi);                // shift right input integer
    BigInt operator>>(const BigInt bi);             // shift right input BigInt
    BigInt pow(const BigInt& bi);                   // exponent number repeat bi times 
    BigInt add(const BigInt& bi);                   // add without sign
    BigInt subtract(const BigInt& bi);              // subtract without sign
    BigInt absolute();                              // absolute value
    string BigIntToBinary();                        // covert one digit to 4 digit Binary
    BigInt BinaryToBigInt(const string binary);     // covert 4 digit Binary to one digit Decimal

private:
                            
    const static int MAX = 200;                     // MAX NUMBER
    int LEN = 1;                                    // length of number
    int sign = 1;                                   // 1 for + positive -1 for negative
    int digits[MAX];                                // max digits is 80
    int ResetLength();                              // reset the number                        
    int Reset();                                    // reset values to zero
};

#endif	                                            // BigInt_H 
