### 2.1.

A - `0011 1001 1010 0111 1111 1000`
B - `0xC97B`
C - `1101 0101 1110 0100 1010`
D - `0x26E7B6`

### 2.2.

|    n | 2^n(decimal) | 2^n(hexadecimal) |
| ---: | -----------: | ---------------: |
|    9 |          512 |            0x200 |
|   19 |    `524,288` |        `0x80000` |
| `14` |       16,384 |         `0x4000` |
| `16` |     `65,536` |        `0x10000` |
|   17 |    `131,072` |        `0x20000` |
|  `5` |           32 |           `0x20` |
|  `7` |        `128` |             0x80 |

### 2.3.

| decimal |   Binary    | Hexadecimal |
| ------: | :---------: | ----------: |
|       0 |  0000 0000  |        0x00 |
|     167 | `1010 0111` |      `0xA7` |
|      62 | `0011 1110` |      `0x3E` |
|     188 | `1011 1100` |      `0xBC` |
|    `55` |  0011 0111  |      `0x37` |
|   `136` |  1000 1000  |      `0x88` |
|   `243` |  1111 0011  |      `0xF3` |
|    `82` | `0101 0010` |        0x52 |
|   `172` | `1010 1100` |        0xAC |
|   `231` | `1110 0111` |        0xE7 |

### 2.4.

A. `0x5044`
B. `0x4FFC`
C. `0x507c`
D. `0x00AE`

### 2.5.

A. Little endian: `21`, Big endian: `87`
B. Little endian: `21 43`, Big endian: `87 65`
C. Little endian: `21 43 65`, Big endian: `87 65 43`

### 2.6.

A.
i: 00000000001101011001000101000001
f: 01001010010101100100010100000100

B.
i: 00000000001`101011001000101000001`
f: 010010100`101011001000101000001`00

By shifting the floating-point number two bits to the right, the number of matching bits can be maximized, resulting in 21 matching bits between two values.

C.

i: `00000000001`101011001000101000001
f: `010010100`101011001000101000001`00`

### 2.7.

`61 62 63 64 65 66`

### 2.8.

| Operation |   Result   |
| :-------: | :--------: |
|     a     |  01101001  |
|     b     |  01010101  |
|    ~a     | `10010110` |
|    ~b     | `10101010` |
|    a&b    | `01000001` |
|   a\|b    | `01111101` |
|    a^b    | `00111100` |

### 2.9.

|   R   |   G   |   B   |  Color  |
| :---: | :---: | :---: | :-----: |
|   0   |   0   |   0   |  Black  |
|   0   |   0   |   1   |  Blue   |
|   0   |   1   |   0   |  Green  |
|   0   |   1   |   1   |  Cyan   |
|   1   |   0   |   0   |   Red   |
|   1   |   0   |   1   | Magenta |
|   1   |   1   |   0   | Yellow  |
|   1   |   1   |   1   |  White  |

A.
Black(000) <-> White(111)
Blue(001) <-> Yellow(110)
Green(010) <-> Magenta(101)
Cyan(011) <-> Red(100)

B.
Blue | Green = 001 | 010 = 011 = `Cyan`
Yellow & Cyan = 110 & 011 = 010 = `Green`
Red & Magenta = 100 ^ 101 = 001 = `Blue`

### 2.10

|   Step    |  *x   |  *y   |
| :-------: | :---: | :---: |
| Initially |   a   |   b   |
|  Step 1   |  `a`  | `a^b` |
|  Step 2   |  `b`  | `a^b` |
|  Step 3   |  `b`  |  `a`  |

### 2.11

A.
midIdx - (0 + cnt - 1) / 2
first - `a[mid]`
last - `a[mid]`

B.
Because the first and last values refer to the same index, the two values are identical, and therefore `a ^ a = 0`.

C.

Just change the condition in the for loop to from `first <= last` `first < last` .

### 2.12

A.

`x & 0xFF`

B.

`x ^ ~0xFF`

C.

`x | 0xFF`


### 2.13

```c
int bool_or(int x, int y){
  int result = bis(x, y);
  return result
}

int bool_xor(int x, int y){
  int result = bis(bic(x, y), bic(y, x));
  return result
}
```

`bic` is the same with `x & ~m`. xor results 1 when only one of the inputs is 1, so `(x & ~y)` | `(y & ~x)` can achieve the same effect. That's why we use `bis` to combine the two `bic` results.

### 2.14

x = 0x66, 0110.0110
y = 0x39, 0011.1001
~x = 1001.1001
~y = 1100.0110


| Expression | Value  | Expression | Value  |
| :--------: | :----: | :--------: | :----: |
|    x&y     | `0x20` |   x && y   | `0x01` |
|   x \| y   | `0x7F` |  x \|\| y  | `0x01` |
|  ~x \| ~y  | `0xDF` | !x \|\| !y | `0x00` |
|   x & !y   | `0x00` |  x && ~y   | `0x01` |

### 2.15

`!(x^y)`

### 2.16
| a (Hex) | a (Binary)  | a << 3 (Binary) | a << 3 (Hex) | Logical a >> 2 (Binary) | Logical a >> 2 (Hex) | Arithmetic a >> 2 (Binary) | Arithmetic a >> 2 (Hex) |
| :-----: | :---------: | :-------------: | :----------: | :---------------------: | :------------------: | :------------------------: | :---------------------: |
|  0xC3   | `1100.0011` |   `0001.1000`   |    `0x18`    |       `0011.0000`       |        `0x30`        |        `1111.0000`         |         `0xF0`          |
|  0x75   | `0111.0101` |   `1010.1000`   |    `0xA8`    |       `0001.1101`       |        `0x1D`        |        `0001.1101`         |         `0x1D`          |
|  0x87   | `1000.0111` |   `0011.1000`   |    `0x38`    |       `0010.0001`       |        `0x21`        |        `1110.0001`         |         `0xE1`          |
|  0x66   | `0110.0110` |   `0011.0000`   |    `0x30`    |       `0001.1001`       |        `0x19`        |        `0001.1001`         |         `0x19`          |

### 2.17

|  Hex  |  Binary  |       B2U_4(x)       |       B2T_4(x)        |
| :---: | :------: | :------------------: | :-------------------: |
|  0xE  |  [1110]  |    2^3+2^2+2^1=14    |   -2^3+2^2+2^1 = -2   |
|  0x0  | `[0000]` |         `0`          |          `0`          |
|  0x5  | `[0101]` |     `2^2+2^0=5`      |      `2^2+2^0=5`      |
|  0x8  | `[1000]` |       `2^3=8`        |       `-2^3=-8`       |
|  0xD  | `[1101]` |   `2^3+2^2+2^0=13`   |   `-2^3+2^2+2^0=-3`   |
|  0xF  | `[1111]` | `2^3+2^2+2^1+2^0=15` | `-2^3+2^2+2^1+2^0=-1` |

### 2.18

A. 0x2e0 = `736`
B. -0x58 = `-88`
C. 0x28 = `28`
D. -0x30 = `-48`
E. 0x78 = `120`
F. 0x88 = `136`
G. 0x1f8 = `504`
H. 0xc0 = `192`
I. -0x48 = `-72`

### 2.19

|   x   | T2U_4(x) |
| :---: | :------: |
|  -8   |   `8`    |
|  -3   |   `13`   |
|  -2   |   `14`   |
|  -1   |   `15`   |
|   0   |   `0`    |
|   5   |   `5`    |

### 2.20

|   x   |    T2U_4(x)    |
| :---: | :------------: |
|  -8   | `-8 + 16 = 8`  |
|  -3   | `-3 + 16 = 13` |
|  -2   | `-2 + 16 = 14` |
|  -1   | `-1 + 16 = 15` |
|   0   |      `0`       |
|   5   |      `5`       |

### 2.21

|          Expression          |    Type    | Evaluation |          hex           |
| :--------------------------: | :--------: | :--------: | :--------------------: |
| -2147483647-1 == 2147483648U | `unsigned` |    `1`     | 0x80000000, 0x80000000 |
|  -2147483647-1 < 2147483647  |  `signed`  |    `1`     | 0x80000000, 0x7FFFFFFF |
| -2147483647-1U < 2147483647  | `unsigned` |    `0`     | 0x80000000, 0x7FFFFFFF |
| -2147483647-1 < -2147483647  |  `signed`  |    `1`     | 0x80000000, 0x80000001 |
| -2147483647-1U < -2147483647 | `unsigned` |    `1`     | 0x80000000, 0x80000001 |


-2147483647 - 1 = 0x80000001 - 0xFFFFFFFF = 0x80000000
-2147483647 - 1U =  0x80000001 - 0x00000001 = 0x80000000

### 2.22

A. [1011]

B2T_4([1011]) = -x_{3}*2^{3} + x_{2}*2^{2} + x_{1}*2^{1} + x_{0}*2^{0} =  -8 + 2 + 1 = -5

B. [11011]

B2T_5([11011]) = -x_{4}*2^{4} + x_{3}*2^{3} + x_{2}*2^{2} + x_{1}*2^{1} + x_{0}*2^{0} =  -16 + 8 + 2 + 1 = -5

B. [111011]

B2T_6([111011]) = -32 + 16 + 8 + 2 + 1 = -5

### 2.23

```c
int func1(unsigned word) {
  return (int) ((word << 24) >>24);
}

int func2(unsigned word) {
  return ((int) word << 24) >> 24;
}
```

- 32bit program, two's complement
- signed -> arithmetically right shift
- unsigned -> logical right shift

A. 

|     w      |   fun1(w)    |   fun2(w)    |
| :--------: | :----------: | :----------: |
| 0x00000076 | `0x00000076` | `0x00000076` |
| 0x87654321 | `0x00000021` | `0x00000021` |
| 0x000000C9 | `0x000000C9` | `0xFFFFFFC9` |
| 0xEDCBA987 | `0x00000087` | `0xFFFFFF87` |

B.

`func1` is useful when you only want to get the last byte.
`func2` is useful when you want to get the value of the last byte(it contains a sign bit).

### 2.24

| Hex (Original) | Hex (Truncated) | Unsigned (Original) | Unsigned (Truncated) | Two’s complement (Original) | Two’s complement (Truncated) |
| :------------: | :-------------: | :-----------------: | :------------------: | :-------------------------: | :--------------------------: |
|   0([0000])    |    0([000])     |          0          |         `0`          |              0              |             `0`              |
|   2([0010])    |    2([010])     |          2          |         `2`          |              2              |             `2`              |
|   9([1001])    |    1([001])     |          9          |         `1`          |             -7              |             `1`              |
|   B([1011])    |    3([011])     |         11          |         `3`          |             -5              |             `3`              |
|   F([1111])    |    7([111])     |         15          |         `7`          |             -1              |             `-1`             |

Equation 2.9 means that just do `mod 2^k`, so it's ok to use its unsgined value as is.
Equation 2.10 means that do `mod 2^k`, and consider MSB as a sign bit. 

### 2.25

```c
float sum_elements(float a[], unsigned length) {
  int i;
  float result = 0;

  for(i = 0; i <= length - 1; i++)
    result += a[i]
  return result;
}
```

When run with argument length of 0, this code causes a memory error. First of all,`length - 1` is casted to `(unsigned)(int)`, resulting in 0xFFFFFFFF(4,294,967,295) in a 32-bit program. Then `i` exceeds the bounds of the array a, leading to an out-of-bounds memory access.

### 2.26

```c
int strlonger(char *s, char *t) {
  return strlen(s) - strlen(t) > 0;
}
```

A.
It occurs when `s` is longer than `t`, that is, when `strlen(s) - strlen(t)` evaluates to a negative value.

B.

Since `size_t` is `unsigned`, the result of `strlen(s) - strlen(t)` is also `unsigned`. As a result,the MSB represents only a value weight rather than a sign bit. When the computed value is negative, the MSB is set to 1, making the value greater than 0. This is the root cause of the probelm.

C.

It is enough to change the expression `strlen(s) - strlen(t) > 0` to `strlen(s) > strlen(t)`

### 2.27

```c
int uadd_ok(unsigned x, unsigned y) {
  unsigned s = x + y;

  return s < x;
}
```

### 2.28

| x (Hex) | x (Decimal) | additive inverse (Decimal) | additive inverse (Hex) |
| :-----: | :---------: | :------------------------: | :--------------------: |
|    0    |     `0`     |            `0`             |         `0x0`          |
|    5    |     `5`     |            `11`            |         `0xB`          |
|    8    |     `8`     |            `8`             |         `0x8`          |
|    D    |    `13`     |            `3`             |         `0x3`          |
|    F    |    `15`     |            `1`             |         `0x1`          |


### 2.29

|    x    |    y    |  x + y   | x + y(Two's) |   Case   |
| :-----: | :-----: | :------: | :----------: | :------: |
|  `-12`  |  `-15`  |  `-27`   |     `3`      | `Case 1` |
| [10100] | [10001] | [100101] |   [00101]    |          |
|  `-8`   |  `-8`   |  `-16`   |    `-16`     | `Case 2` |
| [11000] | [11000] | [110000] |   [10000]    |          |
|  `-9`   |   `8`   |   `-1`   |     `-1`     | `Case 2` |
| [10111] | [01000] | [11111]  |   [11111]    |          |
|   `2`   |   `3`   |   `5`    |     `5`      | `Case 3` |
| [00010] | [00101] | [00111]  |   [00111]    |          |
|  `12`   |   `4`   |   `16`   |     `-1`     | `Case 4` |
| [01100] | [00100] | [10000]  |   [10000]    |          |

### 2.30

```c
int tadd_ok(int x, int y) {
  int s = x + y;

  if(x > 0 && y > 0 && s < 0)
    return 0;

  if(x < 0 && y < 0 && s > 0)
    return 0;

  return 1;
}
```

### 2.31

```c
/* buggy */
int tadd_ok(int x, int y) {
  int sum = x + y;
  return (sum-x == y) && (sum-y == x);
}
```

Two's complement is only a way to interpret a fixed-width bit vector. The machines always perform fixed-width addition modulo 2^w. Therefore, at the bit level, addition is always reversible, and the expression `(x+y) - x = y` holds regardless of wrap-around. As a result, `tadd_ok` always returns 1 and cannot detect overflow.

### 2.32

```c
int tsub_ok(int x, int y) {
  return tadd_ok(x, -y);
}
```

The bug occurs when x is 0 and y is `T_MIN_w`. The function must return 0(overflow). In Two's complement represiontation, `x` satisfies −2^(w−1) ≤ x ≤ 2^(w−1) − 1, so `x-y` is `2^(w-1)`, which is overflow.
However, The negation of `T_Min_w` yields the same bit vector, so `tadd_ok`' computes the sum as `T_Min_w` and incorrectly returns 1.

### 2.33

| x (Hex) | x (Decimal) | additive inverse (Decimal) | additive inverse (Hex) |
| :-----: | :---------: | :------------------------: | :--------------------: |
|    0    |     `0`     |            `0`             |          `0`           |
|    5    |     `5`     |            `-5`            |       `B(1011)`        |
|    8    |    `-8`     |            `8`             |       `8(1000)`        |
|    D    |    `-3`     |            `3`             |       `3(0011)`        |
|    F    |    `-1`     |            `1`             |       `1(0001)`        |

The resulting bit patterns in the two cases are the same, because under Two's complement representation, `T_MIN_w`'s addtivie inverse is itself.


### 2.34

|       Mode       |    x     |    y     |     x · y     | Truncated x · y |
| :--------------: | :------: | :------: | :-----------: | :-------------: |
|     Unsigned     | 4 [100]  | 5 [101]  | `20 [010100]` |    `4 [100]`    |
|     Unsigned     | 2 [010]  | 7 [111]  | `14 [001110]` |   `-2 [110]`    |
| Two’s complement | 2 [010]  | -1 [111] | `-2 [111110]` |    `6 [110]`    |
|     Unsigned     | 6 [110]  | 6 [110]  | `36 [100100]` |    `4 [100]`    |
| Two’s complement | -2 [110] | -2 [110] | `4 [000100]`  |   `-4 [100]`    |


### 2.35

```c
int tmult_ok(int x, int y){
  int p = x * y;
  return !x || p/x  == y; 
}
```

1.

`x*y` is 2w-bit two's complment number and we apply `mod 2^w` to it, so divide `x*y` into two parts, `u` denote the unsigned number represented by the lower `w` bits, and `v` denote the two's complement number represented by the upper `w` bits. we can get `x*y = v*2^w + u` by Equation 2.3.
By Equation 2.6, we can write `u = p + p_{w-1}*2^w`. `x*y = v*2^w + p + p_{w-1}*2^w = p + (v + p_{w-1}) * 2^w.` Anyway, `2^w` will be removed, so let  `t = v + p_{w-1}`. Now we have `x*y = p + t*2^w`.
When `t=0`, we have `x*y = p`; the multiplication does not overflow. When `t!=0`, we have `x*y != p`; the multiplication overflows.

2.

By definition of integer devision, `p = x * q + r`, where `|r| < |x|`

3.

Suppose `q = y`. Then we have `x * y = x * y + r + t*2^w`. With `r=t=0`, `x * y = x * q`.5

Addition and subtraction modulo 2^w from Abelian Group, making overfow undetectable. In contrast, multiplication modulo 2^w is not reversible: overflow discards the upper bits `v`, and division by `y` cannot recover the original result.


### 2.36

```c
int tmult_ok(int x, int y){
  int64_t p = (int64_t)x*y;
  return p == (int) p;
}
```

Since `int64_t` is large enough to hold the product `x * y`, the multiplication itself never overflows.
However, the value may not be representable as an `int`, so we compare `p` with `(int)p`.

### 2.37

```c
void* copy_elements(void *ele_src[], int ele_cnt, size_t ele_size) {
  uint64_t asize = ele_cnt * (uint64_t) ele_size;
  void *result = malloc(aisze);
  if(result == NULL)
    return NULL;
  void *next = result;
  int i;
  for(i = 0; i < ele_cnt; i++) {
    memcpy(next, ele_src[i], ele_size);
    next += ele_size;
  }
  return result;
}
```

A. No, `malloc` takes a `size_t` as its argument. There's no overflow when evaluating `asize`, but `malloc` is still executed even when the vale exceeds `SIZE_MAX`.

B.

I'd rather insert code as follows between lines 2 and 3.

```c
if(asize != size_t(asize))
  return NULL;
```

It prevents the function from the overflow problem.

### 2.38

In `(a << k) + b`, where k is one of `0`, `1`, `2`, or `3` and b is either `0` or `a`, the possible cases are as follows:

a << 0 -> `a`
a << 0 + a -> `2a`
a << 1 -> `2a`
a << 1 + a -> `3a`
a << 2 -> `4a`
a << 2 + a -> `5a`
a << 3 -> `8a`
a << 3 + a -> `9a`

A single LEA instruction can be used to compute `a`, `2a`, `3a`, `4a`, `5a`, `8a`, and `9a`.

### 2.39

If `n` is the MSB, `(x << (n+1))` overflows, so Form B reduces to `-(x << m)`

### 2.40

|   K   | Shifts | Add/Subs |        Expression        |
| :---: | :----: | :------: | :----------------------: |
|   6   |   2    |    1     |    `x << 2 + x << 1`     |
|  31   |   1    |    1     |       `x << 5 - x`       |
|  -6   |   2    |    1     |    `x << 1 - x << 3`     |
|  55   |   2    |    2     | `(x << 6 - x << 3 ) + x` |


### 2.41

A compiler should choose the form with fewer operations. The ruls is to choose form A when `n = m`, either form when `n = m + 1`, and form B when `n > m + 1`.
Assume that `m > 0` at first. When `n = m`, form A requires only a signle shift, while form B requires two shifts and a subtraction. When `n = m+1`, both forms require two shifts and either an addition or a subtraction. When `n > m + 1`, form B requires only two shifts and on subtraction, while form A requires `n - m + 1 > 2` shifts and `n - m > 1` additions. For the case of `m = 0`, we get one fewer shift for both forms A and B, and so the same rules apply for choosing between the two.

### 2.42

```c
int div16(int x){
  // If x is negative, (x >> 31) is 0xFFFFFFFF.
  // after aplying `&0xF` to bias, the bias becomes 0x0000000F.
  // If x is positive, (x >> 31) is 0, so bias is 0. 
  int bias = (x >> 31) & 0xF;
  return (x + bias) >> 4;
}
```

### 2.43

```c
#define M /* Mystery numer 1 */
#define N /* Mystery numer 2 */
int arith(int x, int y) {
  int result = 0;
  result = x * M + y / N;
  return result;
}
```

```c
int optarith(int x, int y) {
  int t = x;
  x <<= 5;
  x -= t;
  if(y < 0) y += 7;
  y >>= 3;
  return x + y;
}
```

`M` is `31`, because `x * M` changed to `(x << 5) - x`, and it is `31x`.
`N` is `8`, when `y` is positive, it shifts 3 bits to the right. when negative, it add bias, [111].

### 2.44

```c
int x = foo();
int y = bar();

unsigned ux = x;
unsigned uy = y;
```

A. (x > 0) || (x - 1 < 0)

`false`. 
`-2^31 -1` is `0x7FFFFFFF`.

B. (x & 7) != 7 || (x << 29 < 0)

`true`.
1) When `(x & 7) != 7` is true, the expression evaluates to `true`.
2) When `(x & 7) != 7` is false, the lowest three bits of `x` are [111], so `x<<29` must be negative. As a result, the expression evaluates to `true`.

C. (x * x) >= 0

`false`.
When x is `65,535(0xFFFF)`, `x*x` is `-131,071(0xFFFE0001)`.

D. x < 0 || -x <= 0

`true`

1) When `x < 0` is true, the expression evaluates to `true`.
2) When `x < 0` is false, x is 0 or positive. `-0` is the same with `0`, and the bits of positive numbers starts with `0`. When negate, its MSB is always '1', so `-x <= 0` is `true`. the expression evaluates to `true`. 

E. x > 0 || -x >= 0

`false`

1) When `x > 0` is true, the expression evaluates to `true`.
2) When `x > 0` is false, x is 0 or negative. `-0` is the same with `0`, `0x80000000` is the same as its negation. Therefore, the expression evaluates to `false`

F. x + y == uy + ux

`true`
Both values have the same bit vector, and their addition yields the same result.

G. x * ~y + uy * ux == -x

`true`
`~y` equals `-y-1` and `ux * uy` equals `x * y`. Therefore, the equation can be rewritten as `x * (-y - 1) + x * y == `-xy -x + xy`, which simplifies to `-x`.  

### 2.45

| Fractional value | Binary representation | Decimal representation |
| :--------------: | :-------------------: | :--------------------: |
|       1/8        |         0.001         |         0.125          |
|       3/4        |        `0.11`         |         `0.75`         |
|      25/16       |       `1.1001`        |        `1.5625`        |
|     `43/16`      |        10.1011        |        `2.6875`        |
|      `9/8`       |         1.001         |        `1.125`         |
|      `47/8`      |       `101.111`       |         5.875          |
|     `51/16`      |       `11.0011`       |         3.1875         |

### 2.46

A. 0.{[0]*23}1100[1100]
B. 0.1's first 1 is 20 bits away from `0.1-x`'s first 1, so its value can be calculated with `2^-20 * 1/10`, which is around `9.54 * 10^-8`
C. `9.54 * 10^-8 * 100 * 60 * 60 * 10 = 0.343 seconds`
D. 0.343 * 2000 = 687m.

1/16 + 1/32 = 0.09375
1/256 + 1/512 = 0.004304339172
1/4096 + 1/8192 = 0.0003662109375

### 2.47

V = (-1)^s * M * 2^E
Bias = 1

1. normalized

E = e - Bias
M = 1 + f

2. denormalized

E = 1 - Bias
M = f

|  Bits   |   e   |   E   |  2^E  |   f   |   M   | 2^E × M |   V   | Decimal |
| :-----: | :---: | :---: | :---: | :---: | :---: | :-----: | :---: | :-----: |
| 0 00 00 |  `0`  |  `0`  |  `1`  | `0/4` |  `0`  |  `0/4`  |  `0`  |   `0`   |
| 0 00 01 |  `0`  |  `0`  |  `1`  | `1/4` | `1/4` |  `1/4`  | `1/4` | `0.25`  |
| 0 00 10 |  `0`  |  `0`  |  `1`  | `2/4` | `2/4` |  `2/4`  | `1/2` |  `0.5`  |
| 0 00 11 |  `0`  |  `0`  |  `1`  | `3/4` | `3/4` |  `3/4`  | `3/4` | `0.75`  |
| 0 01 00 |  `1`  |  `0`  |  `1`  | `4/4` | `4/4` |  `4/4`  | `4/4` |   `1`   |
| 0 01 01 |   1   |   0   |   1   |  1/4  |  5/4  |   5/4   |  5/4  |  1.25   |
| 0 01 10 |  `1`  |  `0`  |  `1`  | `2/4` | `6/4` |  `6/4`  | `3/2` |  `1.5`  |
| 0 01 11 |  `1`  |  `0`  |  `1`  | `3/4` | `7/4` |  `7/4`  | `7/4` | `1.75`  |
| 0 10 00 |  `2`  |  `1`  |  `2`  | `0/4` | `4/4` |  `8/4`  |  `2`  |   `2`   |
| 0 10 01 |  `2`  |  `1`  |  `2`  | `1/4` | `5/4` | `10/4`  | `5/2` |  `2.5`  |
| 0 10 10 |  `2`  |  `1`  |  `2`  | `2/4` | `6/4` | `12/4`  |  `3`  |   `3`   |
| 0 10 11 |  `2`  |  `1`  |  `2`  | `3/4` | `7/4` | `14/4`  | `7/2` |  `3.5`  |
| 0 11 00 |  `-`  |  `-`  |  `-`  |  `-`  |  `-`  |   `-`   | `+∞`  |   `-`   |
| 0 11 01 |  `-`  |  `-`  |  `-`  |  `-`  |  `-`  |   `-`   | `NaN` |   `-`   |
| 0 11 10 |  `-`  |  `-`  |  `-`  |  `-`  |  `-`  |   `-`   | `NaN` |   `-`   |
| 0 11 11 |  `-`  |  `-`  |  `-`  |  `-`  |  `-`  |   `-`   | `NaN` |   `-`   |

### 2.48

number: 3,510,593

integer hex: 0x00359141
single-precision floating-point hex: 0x4A564504


Let's divide the binary vector of the floating-point value into sign, exp, frac as follows.

[0][10010100][10101100100010100000100]

Let's compare it with the binary vector of the integer value.

i(integer): 00000000001[101011001000101000001]
f(floating-point): 010010100[101011001000101000001]00

The frac part of f is in i as shown above, except for an implied leading 1.

### 2.49

A. Significand determines  which numbers are representable. Since normalized values have an implied leading 1,  we can get a `2^(n+1)` positive exactly. Therfore, `2^(n+1) + 1` is the smallest positive integer that cannot be represented exactly.

B. `16,777,217`

### 2.50

A. 10.010 -`10.0`, `2`

B. 10.011 - `10.1`, `2.5`

C. 10.110 - `11.0`, `3`

D. 11.001 - `11.0`, `3`

### 2.51

A. By the rule of round-to-even, `x` is approximated as 0.00011001100110011001101. It's 0.10000002384185791 in decimal and larget than 0.1.

B. `x′ - 0.1` is `0.0000000000000000000000[1100]`. It's the same with `2^-22 * 1/10`, which is around `2.38 * 10^-8`.

C. `100 * 60 * 60 * 10 * 2.38 * 10^-8 = 0.086 seconds`.

D. `2000 * 0.086 = 171m`

### 2.52

`V = M * 2^E`
`k` is the length of exp.
`n` is the length of frac.

Format A

`k = 3, Bias = 3, n = 4`

Format B

`k = 4, Bias = 7, n = 3`

4.5/8

7.5/8



| Format A Bits |   E   |   M   |  Format A Value  | Format B Bits |   E   |   M   |  Format B Value  |
| :-----------: | :---: | :---: | :--------------: | :-----------: | :---: | :---: | :--------------: |
|   011 0000    |   0   |   1   |        1         |   0111 000    |   0   |   1   |        1         |
|   101 1110    |   2   | 30/16 |   `15/2(7.5)`    |  `1001 111`   |   2   | 15/8  |   `15/2(7.5)`    |
|   010 1001    |  -1   | 25/16 | `25/32(0.78125)` |  `0110 100`   |  -1   | 12/8  |   `3/4(0.75)`    |
|   110 1111    |   3   | 31/16 |   `31/2(15.5)`   |  `1010 000`   |   3   | 16/8  |       `16`       |
|   000 0001    |  -2   | 1/16  | `1/64(0.015625)` |  `0001 000`   |  -6   |  /8   | `1/64(0.015625)` |

### 2.53

```c
#define POS_INFINITY 1e400
#define NEG_INFINITY (-POS_INFINITY)
#define NEG_ZERO (-1.0/POS_INFINITY)
```

### 2.54
```c
int x;
float f; // not a special value
double d; // not a special value
```

A. x == (int)(double) x
`true`

B. x == (int)(float) x
`false`

Values that have a binary representation longer than 24 bits will be rounded.
One example is `2,147,483,647 (TMax_32)`.

C. d == (double)(float) d
`false`

Double values cast to float can overflow or be rounded. `1e40` will be `POS_INFINITY`

D. f == (float)(double) f
`true`

E. f == -(-f)
`true`

F. 1.0/2 == 1/2.0
`true`

G. d*d >= 0.0
`true`

H. (f + d) - f == d
`false`

If `f` is too larger than values can represent it frac