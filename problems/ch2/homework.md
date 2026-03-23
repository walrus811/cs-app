### 2.55

I tried two machine I have as follows.

Apple M4 Pro: little endian
Intel Xeon Platinum 8175M (2) @ 2.499GHz: little endian

### 2.56

🪄✨

### 2.57

Just wrap show_bytes with appropriate parameters.

### 2.58

```c
int is_little_endian(){
  unsigned int x = 1;
  char *c = (char*)&x;

  //If the machine uses big-endain, the first byte of x's value must be 0x0001`
  return *c == 1;
}
```

### 2.59

```c
(x & 0xFF) | (y & ~0xFF)
```

### 2.60

```c
unsigned replace_byte(unsigned x, int i, unsigned char b)
{
  unsigned n = sizeof(unsigned);
  if (i < 0 || (unsigned)i >= n)
    return x;

  unsigned shift = (unsigned)i * 8;
  unsigned mask = 0xFFu << shift;

  return (x & ~mask) | ((unsigned)b << shift);
}
```

### 2.61

A.

`!!x`

B.

`!!~x`

C.

`!!(x & 0xFF)`

D.

`!!(~x & (0xFF << 24))`

### 2.62

`codes/int_shifts_are_arithmetic.c`

### 2.63

`codes/srl_sra.c`

### 2.64

```c
// assume w=32
int any_odd_one(unsigned x) {
  return !!(x & 0xAAAAAAAA);
}
```

### 2.65

```c
int odd_ones(unsigned x)
{
  x ^= x >> 16;
  x ^= x >> 8;
  x ^= x >> 4;
  x ^= x >> 2;
  x ^= x >> 1;

  return x & 1;
}
```

### 2.66

```c
int leftmost_one(unsigned x) {
  x |= x >> 1;
  x |= x >> 2;
  x |= x >> 4;
  x |= x >> 8;
  x |= x >> 16;

  return x ^ (x >> 1);
}
```

### 2.67

A. The C standard doesn't define the behavior when the shift count is greater than or equal to the width of the type (k >= w, where w is the bit width of the type). On a 32-bit SUN SPARC machine, shift counts appear to be taken modulo 32(the bit width of int). As a result, `1 << 32` behaves as `1 << 0` and evaluates to 1.

B. 

```c
int int_size_is_32(){
  unsigned set_msb = 1u << 31;
  unsigned beyond_msb = set_msb << 1;

  return set_msb && !beyond_msb;
}
```

C.

```c
int int_size_is_16(){
  unsigned set_msb = 1u << 15;
  unsigned beyond_msb = set_msb << 1;

  return set_msb && !beyond_msb;

}
```

### 2.68

`codes/lower_one_mask.c`

### 2.69

`codes/rotate_left.c`

### 2.70

`codes/fits_bits.c`

### 2.71

Conditions:
-  4 signed bytes into a 32-bit unsigned.
-  2's complement
-  arithmetic right-shifts


```c
typedef unsigned packed_t;

int xbyte(packet_t word, int bytenum){

}

int xbyte_wrong(packet_t word, int bytenum)
{
  return (word >> (bytenum << 3)) & 0xFF;
}
```

A. `x & 0xFF` only extracts the last byte and sets other bits 0, so even if the target byte is negative, the result's MSB becomes 0. 

B. 

`codes/xbyte.c`

### 2.72

A. `sizeof` returns a value of type `size_t`, which is unsigned. Therefore, subtracting it from a smaller integer causes unsigned underflow and produces a very larget value.

B.

`codes/copy_int.c`

### 2.73


`codes/saturating_add.c`

### 2.74

`codes/tsub_ok.c`

### 2.75

```c
unsigned unsigned_high_prod(unsigned x, unsigned y)
{
    unsigned w = sizeof(unsigned) << 3;
    unsigned msb_x = x >> (w - 1);
    unsigned msb_y = y >> (w - 1);

    unsigned signed_high = (unsigned) signed_high_prod((int)x, (int)y);

    return signed_high + x_msb * y + y_msb * x;
}
```

Suppose `signed x` is x and `signed y` is y, while their unsigned counterparts are x' and y'.

By the nature of two's-complment representation, we can express unsigned values as follows:

x' = x + x_msb * 2^w
y' = y + y_msb * 2^w

x' · y' = (x + x_msb·2^w) * (y + y_msb·2^w) 
= x * y + x_msb * y * 2^w + y_msb * x * 2^w + x_msb * y_msb * 2^(2w)

The high-order w bits of x' · y' are obtained by shifting the product right by w bits.

x' · y' >> w = (x*y) >> w + x_msb * y + y_msb * x = `signed_high + x_msb * y + y_msb * x`.

### 2.76

`codes/calloc.c`

### 2.77

A. K = 17

(x << 4) + x

B. K = −7

x - (x << 3)

C. K = 60

(x << 6) - (x << 2)

D. K = −112

(x << 7) - (x << 4)

### 2.78

`codes/divide_power2.c`

### 2.79

`codes/mul3div4.c`

### 2.80

`codes/threefourths.c`

### 2.81

A. 

`~0 << k`

B.

`~(~0 << k) << j`

### 2.82

A. (x<y) == (-x>-y)

`0`, `-INT_MIN` will be `INT_MIN`. In the case of `x = INT_MIN, y = 1`, `-x > -y` is `INT_MIN > -1`.

B. ((x + y) << 4) + y - x == 17 * y + 15 * x

`1`.In two's complement arithmetic, addition is performed modulo 2^w. Therefore, overflows don't change the result, since all operations are carried out in the ring of integers modulo 2^w. The expression (x + y) << 4 is equivalent to multiplying (x +y) by 16, also modulo 2^w. By distributivity in modular arithmetic, the expression simplifies to 15x + 17y.

C. ~x + ~y + 1 == ~(x + y)

`1`. By the properties of two’s complement arithmetic, `~x = -1 -x`. Therefore, `~x + ~y + 1 = (-x -1) + (-y -1) + 1 = -x -y -1`. On the other hand, `~(x + y) = -(x + y) -1 = -x -y -1`, Hence, `~x + ~y + 1 = ~(x+y)`. So the expression always evaluates to 1.

D. (ux - uy) == -(unsigned)(y - x)

`1`. By equation 2.5, `ux = x + 2^32`. Therefore, `ux - uy = (x + 2^32) - (y + 2^32) = x - y`. On the other hand, `-(unsigned)(y - x) = `-(unsigned)((y + 2^32) - (x + 2^32)) = -(unsigned)(y-x) = -(y - x + 2^32) = x - y + 2^32`. Two's complement addition is performed modulo 2^w, where w is the bit length. Therefore, the 2^32 term is eliminated, and `-(unsigned)(y - x) = x - y`. So the expression always evaluates to 1. 

E. ((x >> 2) << 2) <= x

`1`. `(x >> 2) << 2` is equivalent to `floor(x/4) * 4`, so the lowest two bits are discarded. Hence the expression always evaluates to 1.

### 2.83

A.
`x = Y / (2^k - 1)`

Let `x = 0.yyyyy...`. If you multiply 2^k to the both, `2^k * x = y.yyyyy...`. Therefore, `2^k*x - x = y`. Hence, `x = Y / (2^k - 1)`.

B.

(a) 101 = 5/7
(b) 0110 = 6/15 = 2/5
(c) 010011 = 19/63

### 2.84

```c
int float_le(float x, float y) {
  unsigned ux = f2u(x);
  unsigned uy = f2u(y);

  /* Get the sign bits */
  unsigned sx = ux >> 31;
  unsigned sy = uy >> 31;

  /* Given an expression using only ux, uy, sx, and sy */
  return ((ux << 1) == 0 && (uy << 1) == 0) ||
       ((sx ^ sy) && sx) ||
       (!(sx ^ sy) && ((sx && ux >= uy) || (!sx && ux <= uy)));
}
```

### 2.85

A. The number 7.0

Becuase `7 = 111`, we can write

`V = 1.11 * 2^2`.

Thus `E = 2` and the exponent field is

`e = E + bias = 2 + bias`

Since e is neither 0 nor 2^(k-1), this number is normalized.

The sifnificand is

M = 1.11 = 1 + 1/2 + 1/4

For normalized numbers, M = 1 + f, Therefore

f = M - 1 = 1/2 + 1/4

So the fraction field is

f = 0.11000...0

where remaining bits are zeros to fill t he n-bit fraction field.

B.

Let the length of exponent bit vector is  k, and the length of fractions bit vector is n. For normalized numbers, the significand has n+1 bits of precision.

Therefore, all integers up to 2^(n+1) can be represented exactly.
The larget odd integer in this range is
2^(n+1) - 1

In binary this is

111...111 (n+1 bits)

which can be written in normalized form as

`V = 1.111...111 * 2^n`

where the fraction field contains n ones.

C.

For the smallest positive normalized value, the fraction field must be 0.
Thus f = 0 and M = 1.

For normalized numbers, the smallest exponent field is e = 1.

Since bias = 2^(k−1) − 1,

E = e − bias
  = 1 − (2^(k−1) − 1)
  = 2 − 2^(k−1)

Thus the smallest positive normalized value is

V = 2^(2 − 2^(k−1))

The reciprocal is

1/V = 2^(2^(k−1) − 2)

### 2.86
 
| Description                    |            Value            |      Decimal      |
| :----------------------------- | :-------------------------: | :---------------: |
| Smallest positive denormalized |   `2^(-63) * 2^(-16382)`    | `3.98×10^(−4951)` |
| Smallest positive normalized   |      `1 * 2^(-16382)`       | `1.1×10^(−4932)`  |
| Largest normalized             | `(2 - 2^(-63)) * 2^(16383)` | `1.19 * 10^4932`  |

### 2.87

IEEE 754-2008

- a sign bit
- k = 5(exp)
- n = 10(frac)
- bias  = 2^4 -1 = 15

| Description                           |  Hex   |      M      |   E   |       V        |        D         |
| :------------------------------------ | :----: | :---------: | :---: | :------------: | :--------------: |
| −0                                    | `8000` |     `0`     |  `-`  |       -0       |       -0.0       |
| Smallest value > 2                    | `4001` | `1025/1024` |  `1`  | `1025*2^(-9)`  |  `2.001953125`   |
| 512                                   | `6000` |     `1`     |  `9`  |      512       |      512.0       |
| Largest denormalized                  | `03FF` | `1023/1024` | `-14` | `1023*2^(-24)` | `6.09 * 10^(-5)` |
| −∞                                    | `F800` |      —      |   —   |       -∞       |        -∞        |
| Number with hex representation `3BB0` |  3BB0  |  `123/64`   | `-1`  |  `123*2^(-6)`  |   `0.9609375`    |

### 2.88

Format A

- a sign bit
- k = 5, bias = 15
- n = 3

Format B

- a sign bit
- k = 4, bias = 7
- n = 4

| Format A Bits |   Value   | Format B Bits |  Value   |
| :-----------: | :-------: | :-----------: | :------: |
| `1 01111 001` |  `-9/8`   | `1 0111 0010` |  `-9/8`  |
| `0 10110 011` |   `176`   | `0 1110 0110` |  `176`   |
| `1 00111 010` | `-5/1024` | `1 0000 0100` | `-1/256` |
| `0 00000 111` | `7/2^17`  | `0 0000 0001` | `1/2^10` |
| `1 11100 000` |  `-8192`  | `1 1110 1111` |  `-248`  |
| `0 10111 100` |   `384`   | `0 1111 0000` |   `+∞`   |

### 2.89

A. (float) x == (float) dx

`1`. A double can represent any 32-bit int exactly, so dx = (double)x holds the exact value of x. Therefore (float)x and (float)dx perform the same rounding and produce identical float values.

B. dx - dy == (double) (x - y)

`0`. If `x = INT_MAX(2,147,483,647) and y = -1, then x - y overflows a 32-bit int and typically becomes INT_MIN. However, dx - dy equals 2,147,483,648 because double can represent values beyond the 32-bit integer range.

C. (dx + dy) + dz == dx + (dy + dz)

`1`. INT_MAX + INT_MAX + INT_MAX = 3(2^31 − 1), which is less than 2^33. Since double has 53-bit precision, all intermediate results are represented exactly, so no rounding occurs and the equality holds.

D. (dx * dy) * dz == dx * (dy * dz)

`0`. Let x=67108865, y=134217729, z=3. Since x*y exceeds 2^53, dx*dy is rounded, and the rounding occurs at different steps, so (dx*dy)*dz != dx*(dy*dz).

E. dx / dx == dz / dz

`0`, Let `x = 0 and z = 1`. Since 0/0 is NaN and 1/1 is 1, the equation doesn't hold.

### 2.90

```c
float fpwr2(int x)
{
  /* Result exponent and fraction */
  unsigned exp, frac;
  unsigned u;

  if(x < -149){
    /* Too small. Return 0.0 */
    exp = 0;
    frac = 0;
  } else if(x < -126) {
    /* Denormalized result */
    exp = 0;
    frac = 1u << (x + 149);
  } else if(x < 128) {
    /* Normalized result */
    exp = x + 127;
    frac = 0;
  } else {
    /* Too big. Return +Infinity */
    exp = 0xFF;
    frac = 0;
  }

  /* Pack exp and frac into 32 bits */
  u = exp << 23 | frac;
  /* Return as float */
  return u2f(u);
}
```

### 2.91

- 0x40490FDB

A. 11.0010010000111111011011
B. 11.(001), where 011 repeats.
C. 9th

### 2.92

`codes/float_negate.c`

### 2.93

`codes/float_absval.c`

### 2.94

`codes/float_twice.c`

### 2.95

`codes/float_half.c`