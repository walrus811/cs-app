### 3.1

| Address | Value | Register | Value |
| :-----: | :---: | :------: | :---: |
|  0x100  | 0xFF  |   %rax   | 0x100 |
|  0x104  | 0xAB  |   %rcx   |  0x1  |
|  0x108  | 0x13  |   %rdx   |  0x3  |
|  0x10C  | 0x11  |          |       |


|    Operand     | Value |
| :------------: | :---: |
|      %rax      |       |
|     0x104      |       |
|     $0x108     |       |
|     (%rax)     |       |
|    4(%rax)     |       |
|  9(%rax,%rdx)  |       |
| 260(%rcx,%rdx) |       |
| 0xFC(,%rcx,4)  |       |
| (%rax,%rdx,4)  |       |
