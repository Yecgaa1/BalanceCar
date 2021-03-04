//
// Created by 星星 on 2021/2/14.
//

#ifndef BALANCECAR_SENSOR_H
#define BALANCECAR_SENSOR_H

#include <MPU6050/mpu6050.h>
int time_count=0;
struct sensor {
    float pitch;
    float gyroy;
    float gyroz;
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

    sensor.Encoder_Left = __HAL_TIM_GET_COUNTER(&htim2)/0.975;
    sensor.Encoder_Right = __HAL_TIM_GET_COUNTER(&htim3)/0.975;
}
void Ultrasound()
{

}

#endif //BALANCECAR_SENSOR_H
