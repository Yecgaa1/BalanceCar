//
// Created by 星星 on 2021/2/14.
//

#ifndef BALANCECAR_SENSOR_H
#define BALANCECAR_SENSOR_H

#include <MPU6050/mpu6050.h>

struct sensor {
    float pitch;
    float gyroy;
    float gyroz;//TODO:???
    float Encoder_Left;
    float Encoder_Right;
    float UltrasonicWave_Distance;
}sensor;

void mpu6050_Get()
{
    Read_DMP();
    sensor.pitch=Pitch;
    sensor.gyroy=gyro[1];
}
void Encoder_Get()
{

}
#endif //BALANCECAR_SENSOR_H
