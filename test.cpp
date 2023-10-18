#include "biguint.cpp"

#include <iostream>

using namespace std;

int main()
{
    biguint a;
    a.from_hex("1D77D50998A8ED9333C0EF87E2946CE8753C129D9E0DB8CB7240702CA70C4148D9C59B230E6353B5C37C80A4C477D46082015D8F08FE887D84FD");

    cout << "a-value (decimal): " << a << endl;
    cout << "a-value (big endian hex): " << a.to_hex() << endl;
    cout << "a-value (little endian hex): " << a.to_hex(false) << endl
         << endl;

    biguint b = biguint("4434324209464077133846440875277052707935587126215351570774663269529610673820");
    biguint m = biguint("665907216469697148974417454142955215233052237817138657625294803");

    cout << a << " + " << b << " = " << a + b << endl
         << endl;

    cout << a << " - " << b << " = " << a - b << endl
         << endl;

    cout << a << " * " << b << " = " << a * b << endl
         << endl;

    cout << a << " / " << b << " = " << a / b << endl
         << endl;

    cout << a << " % " << b << " = " << a % b << endl
         << endl;

    cout << "(" << a << " ^ " << b << ") % " << m << " = " << a.pow(b, m) << endl
         << endl;

    cout << "sqrt(" << a << ") = " << a.sqrt() << endl
         << endl;

    cout << "mod_inverse(" << a << ", " << m << ") = " << a.mod_inverse(m) << endl
         << endl;

    cout << "gcd(" << a << ", " << b << ") = " << a.gcd(b) << endl
         << endl;

    cout << "is_prime(" << a << ") = " << a.is_prime() << endl
         << endl;

    return 0;
}