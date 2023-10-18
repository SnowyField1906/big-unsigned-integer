#ifndef BIGUINT_H
#define BIGUINT_H

#include <iostream>
#include <string>
#include <vector>
#include <complex>

using namespace std;

// Self-implemented biguint class
class biguint
{
private:
    // ATTRIBUTES --------------------------------------------------------------------------
    static const int CELL_LENGTH = 6;  // Chunk length
    static const int MODULO = 1000000; // For computing chunks
    vector<int> data;                  // Chunked number
    typedef complex<double> fft_base;  // Fast Fourier Transform base
    // -------------------------------------------------------------------------- ATTRIBUTES

protected:
    // PROTECTED METHODS -------------------------------------------------------------------
    void fft(vector<fft_base> &arg, bool invert) const; // Fast Fourier Transform algorithm
    void cleanup_zeroes();                              // Remove leading zeroes from chunk
    string reverse_endian(string s) const;              // Reverse endian of hex string

    // ------------------------------------------------------------------- PROTECTED METHODS

public:
    // CONSTRUCTORS ------------------------------------------------------------------------
    biguint();
    biguint(int x);
    biguint(const string &s);
    // ------------------------------------------------------------------------ CONSTRUCTORS

    //

    // I/0 OPERATORS -----------------------------------------------------------------------
    friend ostream &operator<<(ostream &os, const biguint &rhs);
    friend istream &operator>>(istream &is, biguint &rhs);
    // ----------------------------------------------------------------------- I/0 OPERATORS

    //

    // COMPARISION OPERATORS ---------------------------------------------------------------
    bool operator==(const biguint &rhs) const;
    bool operator!=(const biguint &rhs) const;
    bool operator<(const biguint &rhs) const;
    bool operator>(const biguint &rhs) const;
    bool operator<=(const biguint &rhs) const;
    bool operator>=(const biguint &rhs) const;
    // --------------------------------------------------------------- COMPARISION OPERATORS

    //

    // ARITHMETIC OPERATORS ----------------------------------------------------------------
    biguint operator+(const biguint &rhs) const;
    biguint operator-(const biguint &rhs) const;
    biguint operator*(const biguint &rhs) const;
    biguint operator/(const biguint &rhs) const;
    biguint operator%(const biguint &rhs) const;
    // ---------------------------------------------------------------- ARITHMETIC OPERATORS

    //

    // ASSIGNMENT OPERATORS ----------------------------------------------------------------
    biguint &operator=(const biguint &rhs);
    biguint &operator+=(const biguint &rhs);
    biguint &operator-=(const biguint &rhs);
    biguint &operator*=(const biguint &rhs);
    biguint &operator/=(const biguint &rhs);
    biguint &operator%=(const biguint &rhs);
    biguint operator++(int);
    biguint operator--(int);
    // ---------------------------------------------------------------- ASSIGNMENT OPERATORS

    //

    // ADVANCED CALCULATIONS ---------------------------------------------------------------
    biguint pow(biguint exp, const biguint &modulo) const; // Modular exponentiation
    biguint scale(int n) const;                            // Multiply by 10^n
    biguint scalar_mult(int n) const;                      // Scalar multiplication
    biguint sqrt() const;                                  // Square root
    biguint gcd(const biguint &rsh) const;                 // Greatest common divisor
    biguint mod_inverse(const biguint &modulo) const;      // Modular multiplicative inverse
    // --------------------------------------------------------------- ADVANCED CALCULATIONS

    //

    // INDEPENDENT METHODS ------------------------------------------------------------------
    biguint power_of_10(int n) const;       // Get 10^n
    biguint rand_of_num_len(int len) const; // Generate random with given number length
    biguint rand_of_bit_len(int len) const; // Generate random with given bit length
    biguint rand(biguint max) const;        // Generate random under a maximum value
    // ------------------------------------------------------------------ INDEPENDENT METHODS

    //

    // HELPER METHODS ----------------------------------------------------------------------
    int to_int() const;                          // Convert to int
    string to_string() const;                    // Convert to string
    string to_hex(bool is_big_endian) const;     // Convert to hex string
    void from_hex(string s, bool is_big_endian); // Convert from hex string
    bool is_odd() const;                         // Check if odd
    bool is_prime(int times) const;              // Check if prime using Miller-Rabin algorithm
    // ---------------------------------------------------------------------- HELPER METHODS
};

#endif // BIGUINT_H