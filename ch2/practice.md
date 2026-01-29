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

### 2.28

### 2.29

### 2.30

### 2.31

### 2.32

### 2.33