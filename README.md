## Big Unsigned Integer implementation

### Overview

This is a simple implementation of a **Big-Unsigned Integer** - `biguint` in C++.

The main idea is to divide the number into blocks of 6 digits and do the calculations on these blocks. The maximum value of a block is between $[10^6; 10^7 - 1]$.

On 64-bit machines, the size of `int` is $32(bits) = 4(bytes)$. Therefore, the limit size of `vector<int>` is $2^{64}/4 - 1 = 2^{62} - 1$. \
From this, we can calculate the maximum size of a `biguint` number:

$$
\begin{align*}
    \text{maximum allocated size} &= \frac{2^{64}}{4}  - 1 \\
    &\approx 2^{62} \quad \text{(bytes)} \\
    \text{maximum actual size} &\in [ln(10^6) \times (2^{62} - 1); \enspace ln(10^7 - 1) \times (2^{62} - 1)) \\
    &\approx 2^{59} \quad \text{(bytes)} \\
    \text{maximum value} &\in [2^{62} \times 10^6; \enspace 2^{62} \times (10^7 - 1)) \\
    &\approx 2^{82} \quad \text{(bytes)}
\end{align*}
$$

### Implementation

#### Supported operators

- I/O operators: `<<`, `>>`
- Comparision operators: `==`, `!=`, `<`, `>`, `<=`, `>=`
- Arithmetic operators: `+`, `-`, `*`, `/`, `%`
- Assignment operators: `=`, `+=`, `-=`, `*=`, `/=`, `%=`, `++`, `--`

#### Supported calculations

- Modular exponentiation: `pow(exp, modulo)`
- Multiplication by $10^n$: `scale(n)`
- Scalar multiplication: `scalar_mult(n)`
- Square root: `sqrt()`
- Greatest common divisor: `gcd(rhs)`
- Modular multiplicative inverse: `mod_inverse(modulo)`

#### Independent methods

- Get $10^n$: `power_of_10(n)`
- Generate random with given number length: `rand_of_num_len(len)`
- Generate random with given bit length: `rand_of_bit_len(len)`
- Generate random under a maximum value: `rand(max)`

#### Helper methods

- Convert to `int`: `to_int()`
- Convert to `string`: `to_string()`
- Convert to `hex`: `to_hex(is_big_endian)`
- Convert from `hex`: `from_hex(s, is_big_endian)`
- Check if odd: `is_odd()`
- Check if prime: `is_prime(times)`

### Algorithms and techniques

- [Fast Fourier Transform](https://en.wikipedia.org/wiki/Fast_Fourier_transform) and [Schönhage–Strassen Algorithm](https://en.wikipedia.org/wiki/Sch%C3%B6nhage%E2%80%93Strassen_algorithm) for `*` (multiplication)
- [Right-to-left binary method](https://en.wikipedia.org/wiki/Modular_exponentiation#Memory-efficient_method) for `pow(exp, modulo)`
- [Bisection Method](https://en.wikipedia.org/wiki/Bisection_method) for `sqrt()`
- [Extended Euclidean Algorithm](https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm) for `mod_inverse(modulo)`
- [Euclidean Algorithm](https://en.wikipedia.org/wiki/Euclidean_algorithm) for `gcd(rhs)`
- [Miller-Rabin Algorithm](https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test) for `is_prime(times)`

