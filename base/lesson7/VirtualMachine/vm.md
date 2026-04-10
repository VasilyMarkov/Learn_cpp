                    +----------------------+
                    |     Program / ROM    |
                    |  instructions array  |
                    +----------+-----------+
                               |
                               v
                    +----------------------+
                    |   Instruction Pointer|
                    |         (IP)         |
                    +----------+-----------+
                               |
                               v
                    +----------------------+
                    |   Instruction Fetch  |
                    |      + Decoder       |
                    +----------+-----------+
                               |
             +-----------------+-----------------+
             |                                   |
             v                                   v
 +----------------------+             +----------------------+
 |     Control Unit     |             |      Data Stack      |
 | executes operations  |<----------->|   push / pop / top   |
 +----------+-----------+             +----------+-----------+
            |                                    |
            |                                    v
            |                         +----------------------+
            |                         |   Arithmetic Logic   |
            +------------------------>|       Unit (ALU)     |
            |                         | add, sub, mul, div   |
            |                         +----------+-----------+
            |                                    |
            v                                    v
 +----------------------+             +----------------------+
 |    Call Stack /      |             |   Memory / RAM       |
 |   Return Addresses   |             | load / store values  |
 +----------------------+             +----------------------+


        +------------------------------------------+
        |              STACK MACHINE               |
        +------------------------------------------+
        | Registers:                               |
        |   IP  - instruction pointer              |
        |   SP  - stack pointer                    |
        |                                          |
        | Memory:                                  |
        |   code[]   - bytecode / instructions     |
        |   stack[]  - operand stack               |
        |   data[]   - variables / heap / RAM      |
        |                                          |
        | Units:                                   |
        |   fetch()   -> read code[IP]             |
        |   decode()  -> understand opcode         |
        |   execute() -> perform operation         |
        +------------------------------------------+


           code[IP] --> FETCH --> DECODE --> EXECUTE
                                                |
                                                v
                                        stack push / pop
                                                |
                                                v
                                        ALU or memory access
                                                |
                                                v
                                            next IP

--------------------------------------------------------------


if(1) { 
    print 2; 
} 
else { 
    print 3; 
}

x = 2
print x

entry:
    PUSH 1
    JZ bb0
    PUSH 2
    PRINT
    JMP bb1
bb0:
    PUSH 3
    PRINT
STORE
LOAD
PRINT


254 0xFE =  0b1111'1110 MSBit

0b0111'1111 LSBit

0b1110'1111 LSByte

0000: PUSH 1        -> 01 FF FF
0005: JZ bb0        -> 02 11 00
0008: PUSH 2        -> 01 02 00 00 00
000D: PRINT         -> 04 
000E: JMP bb1       -> 03 17 00
0011: PUSH 3        -> 01 03 00 00 00
0016: PRINT         -> 04
0020: PUSH 2        ->
0023: STORE 0x100   -> 06 10 00 00 00  
0026: LOAD 0x100  
0029: PRINT
0030: HALT          -> FF


