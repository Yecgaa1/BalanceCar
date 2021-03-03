//
// Created by 星星 on 2021/2/14.
//

#ifndef BALANCECAR_BLUETOOTH_H
#define BALANCECAR_BLUETOOTH_H
#define RXBUFFERSIZE  256     //最大接收字节数
char RxBuffer[RXBUFFERSIZE];   //接收数据
u_int8_t Flag_Left,Flag_Right,Flag_Forward,Flag_Back;
void bluetooth()
{
    if (strcmp(RxBuffer, "F#") == 0)Flag_Forward=1;
    else if (strcmp(RxBuffer, "B#") == 0)Flag_Back=1;
    else if (strcmp(RxBuffer, "L#") == 0)Flag_Left=1;
    else if (strcmp(RxBuffer, "R#") == 0)Flag_Right=1;
}

#endif //BALANCECAR_BLUETOOTH_H
