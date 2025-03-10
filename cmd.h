/*プログラムファイル*/
#include"opcode.h"

struct command{
    /* data */
    int opcode;
    int immediate;
};

typedef struct command program;

program data[16]= {
    {OUT_Im,0b0111},
    {ADD_A,0b0001},
    {JNC,0b0001},
    {ADD_A,0b0001},
    {JNC,0b0011},
    {OUT_Im,0b0110},
    {ADD_A,0b0001},
    {JNC,0b0110},
    {ADD_A,0b0001},
    {JNC,0b1000},
    {OUT_Im,0b0000},
    {OUT_Im,0b0100},
    {ADD_A,0b0001},
    {JNC,0b1010},
    {OUT_Im,0b1000},
    {JMP,0b1111}
};
