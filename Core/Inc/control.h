//
// Created by 星星 on 2021/2/14.
//

#ifndef BALANCECAR_CONTROL_H
#define BALANCECAR_CONTROL_H

#include "sensor.h"
#include "pid.h"
#include "direction.h"
#include "bluetooth.h"

float Balance_Pwm;
int i=0;
float Velocity_Pwm;
float Moto1,Moto2;

void Xianfu_Pwm(void)
{
    //===PWM满幅是7200 限制在7000
    if(Moto1<-7000 ) Moto1=-7000 ;
    if(Moto1>7000 )  Moto1=7000 ;
    if(Moto2<-7000 ) Moto2=-7000 ;
    if(Moto2>7000 )  Moto2=7000 ;
}

void Turn_Off(float angle)
{
    if(angle<-40||angle>40)	 //电池电压低于3.6V关闭电机
    {	                                   //===倾角大于40度关闭电机
        Moto1=0;
        Moto2=0;
    }
}

void Set_Pwm()
{
    //TODO:I Should Do it!
}
void control()
{

    Balance_Pwm =Angle_PID(sensor.pitch,pid.Mechanical_balance,sensor.gyroy);   //===平衡环PID控制
    Velocity_Pwm=Speed_PID(sensor.Encoder_Left,sensor.Encoder_Right);       //===速度环PID控制
    if(1==Flag_Left||1==Flag_Right)
        Turn_Pwm =turn(Encoder_Left,Encoder_Right,gyroz);        //===转向环PID控制
    else Turn_Pwm=(-0.5)*gyroz;
    Moto1=Balance_Pwm-Velocity_Pwm-Turn_Pwm;                 //===计算左轮电机最终PWM
    Moto2=Balance_Pwm-Velocity_Pwm+Turn_Pwm;                 //===计算右轮电机最终PWM
    Xianfu_Pwm();  																					 //===PWM限幅	    //===检查USB是否插入
    Turn_Off(sensor.pitch);																 //===检查角度以及电压是否正常
    Set_Pwm(Moto1,Moto2);                                    //===赋值给PWM寄存器
}

#endif //BALANCECAR_CONTROL_H
