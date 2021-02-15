//
// Created by 星星 on 2021/2/14.
//

#ifndef BALANCECAR_SENSOR_H
#define BALANCECAR_SENSOR_H
struct sensor {
    float pitch;
    float gyroy;
    float gyroz;//TODO:???
    float Encoder_Left;
    float Encoder_Right;
}sensor;

void mpu6050_Get()
{

}
void Encoder_Get()
{

}
#endif //BALANCECAR_SENSOR_H
