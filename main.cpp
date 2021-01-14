#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>
#include "BigInt.h"

using namespace std;


int main() {

    BigInt a, b, c, d, e, f, g, h;
    int i=-7;
    bool bo = true;
    
    a = "123456922434343";
    b = "-12";   // 15
    c = "-343433336433333333333433333333333333333344333"; // 17
    d = "-3000000000000000000000000000000000000000000000000000000000000000000000000000000";
    e = "0";
    f = "-1";
    g = "-123456922434343";
    h = "4";

    cout << " a: " << a << endl << " b: " << b << endl << " c: " << c << endl;
    cout << " d: " << d << endl << " e: " << e << endl << " f: " << f << endl;
    cout << " g: " << g << endl;

    if (b <= a) cout << " b <= a true " << endl; else cout << " b <= a false " << endl;
    if (a - b >=  e) cout << " a - b >  e true " << endl; else cout << " a - b >  e false " << endl;

    cout << endl << endl;
    cout << " a + b : " << a + b << endl;
    cout << " a - b : " << a - b << endl;
    cout << " b - d : " << b - d << endl;
    cout << " c * b : " << c * b << endl;
    cout << " c * d : " << c * d << endl;

    cout << " a / b : " << a / b << endl;
    cout << " b / a : " << b / a << endl;
    cout << " e / a : " << e / a << endl;
    cout << " d / g : " << d / g << endl;
    cout << " d / b : " << d / b << endl;

    cout << " a % b : " << a % b << endl;
    cout << " b % a : " << b % a << endl;
    cout << " e % a : " << e % a << endl;
    cout << " d % g : " << d % g << endl;
    cout << " d % b : " << d % b << endl;
    
    cout << " a.BigIntToBinary : " << a.BigIntToBinary() << endl;
    cout << " b.BigIntToBinary : " << b.BigIntToBinary() << endl;
    cout << " c.BigIntToBinary : " << c.BigIntToBinary() << endl;
    cout << " d.BigIntToBinary : " << d.BigIntToBinary() << endl;
    cout << " e.BigIntToBinary : " << e.BigIntToBinary() << endl;
    cout << " f.BigIntToBinary : " << f.BigIntToBinary() << endl;
    cout << " g.BigIntToBinary : " << g.BigIntToBinary() << endl << endl;

    cout << " a.BinaryToBigInt : " << a.BinaryToBigInt("11100000100100010001110000000011011101100100111") << endl;
    cout << " b.BinaryToBigInt : " << b.BinaryToBigInt("1100") << endl;
    cout << " c.BinaryToBigInt : " << c.BinaryToBigInt("1111011001100110101111011101111111011100011011111010000010010001101111001110010100111111011000000001001101011011100001001011110101011000000001001101") << endl;
    cout << " d.BinaryToBigInt : " << d.BinaryToBigInt("110011110100010010011110100111100100010011111011001010111000000100100101010100000001110111001011101000101011010001100100110100101011111111101110111100111011011110001000110101010111011000000000000000000000000000000000000000000000000000000000000000000000000000000") << endl;
    cout << " e.BinaryToBigInt : " << e.BinaryToBigInt("0") << endl;
    cout << " f.BinaryToBigInt : " << f.BinaryToBigInt("1") << endl;
    cout << " g.BinaryToBigInt : " << g.BinaryToBigInt("11100000100100010001110000000011011101100100111") << endl;

    cout << endl;

    f = a << h;
    cout << " a << 4 : " << f << endl;
    f = b << h;
    cout << " b << 4 : " << f << endl;
    f = c << 4;
    cout << " c << 4 : " << f << endl;
    f = d << 4;
    cout << " d << 4 : " << f << endl;
    f = e << 4;
    cout << " e << 4 : " << f << endl;

    cout << endl;

    f = a >> h;
    cout << " a >> 4 : " << f << endl;
    f = b >> h;
    cout << " b >> 4 : " << f << endl;
    f = c >> h;
    cout << " c >> 4 : " << f << endl;
    f = d >> 4;
    cout << " d >> 4 : " << f << endl;
    f = e >> 4;
    cout << " e >> 4 : " << f << endl;


    return 0;
}