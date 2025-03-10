#include<stdio.h>
#include <unistd.h>
#include"cmd.h"

// 数字を２進数の文字列に変換する関数: n = 変換する数字、digit = 桁数
int print_binary(int n){
    int mask,digit = 4;
    printf("0b");
    for(mask=(0x1<<(digit-1)); mask>0; mask>>=1){
        printf("%d", mask&n ? 1 : 0);
    }
    printf("\n");
    return 0;
}

int main(void){
    int registerA = 0, registerB = 0, carry = 0;
    char input = 0, a=0;
    int len = sizeof data / sizeof data[0];   // 全体のメモリサイズ / 配列の要素一つ分の分の大きさ
    
    for(int i=0;i<len;i++){
        switch(data[i].opcode){

        case MOV_A:
            registerA = data[i].immediate;
            carry = 0;
            // printf("MOV_A,i=%d,%d\n",i,data[i].immediate);
            break;
        case MOV_B:
            registerB = data[i].immediate;
            carry = 0;
            // printf("MOV_B,i=%d,%d\n",i,data[i].immediate);
            break;
        case MOV_AB:
            registerA = registerB;
            carry = 0;
            // printf("MOV_AB,i=%d,%d\n",i,data[i].immediate);
            break;
        case MOV_BA:
            registerB = registerA;
            carry = 0;
            // printf("MOV_BA,i=%d,%d\n",i,data[i].immediate);
            break;
        case ADD_A:
            registerA += data[i].immediate;
            // printf("registerA=%d\n",registerA);
            if(registerA > 0b1111){
                carry = 1;
                registerA = 0b0000;
            }else{
                carry = 0;
            }
            // printf("ADD_A,i=%d,%d\n",i,data[i].immediate);
            break;
        case ADD_B:
            registerB += data[i].immediate;
            // printf("registerB=%d\n",registerB);
            if(registerB > 0b1111){
                carry = 1;
                registerB = 0b0000;
            }else{
                carry = 0;
            }
            // printf("ADD_B,i=%d,%d\n",i,data[i].immediate);
            break;
        case IN_A:
            scanf("%s",&input);    //入力データ
            registerA = input;
            carry = 0;
            // printf("IN_A,i=%d,%d\n",i,data[i].immediate);
            break;
        case IN_B:
            scanf("%s",&input);    //入力データ
            registerB = input;
            carry = 0;
            // printf("IN_B,i=%d,%d\n",i,data[i].immediate);
            break;
        case OUT_Im:
            print_binary(registerA);
            carry = 0;
            //  printf("OUT_Im,i=%d,%d\n",i,data[i].immediate);
            break;
        case OUT_B:
            print_binary(registerB);
            carry = 0;
            //  printf("OUT_B,i=%d,%d\n",i,data[i].immediate);
            break;
        case JMP:
            i = data[i].immediate-1;
            carry = 0;
            // printf("JMP,i=%d,%d\n",i,data[i].immediate);
            break;
        case JNC:
            // printf("JNC,i=%d,%d\n",i,data[i].immediate);
            if(carry == 0){
                i = data[i].immediate-1;
            }
            carry = 0;
            break;
        default:
            printf("Unknown\n");
            break;
        }
        usleep(1000000);
    }
    return 0; 
}

