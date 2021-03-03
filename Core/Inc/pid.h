//
// Created by 星星 on 2021/2/10.
//

#ifndef BALANCECAR_PID_H
#define BALANCECAR_PID_H

#include <stdio.h>
#include <bluetooth.h>
#include <sensor.h>
float Movement;
struct pid{
    float Bias;//角度差
    float balance;//角度PWM
    float SetSpeed;
    float ActualSpeed;
    float Speed_err;
    float Speed_err_last;
    //float Angle_err;
    //float Angle_err_last;
    float Angle_Kp,Angle_Kd,Speed_Kp,Speed_Ki,Speed_Kd; 		//定义比例、积分、微分系数
    float voltage; 			//定义电压值（控制执行器的变量
    float integral;		    //定义积分值
    float umax;
    float umin;
    float Mechanical_balance;//机械中值
    u_int8_t flag_UltrasonicWave;
}pid;


void PID_init(float Mechanical_balance){
    printf("PID_init begin \n");
    pid.Bias=0.0;
    pid.balance=0.0;
    pid.SetSpeed=0.0;
    pid.ActualSpeed=0.0;
    pid.Speed_err=0.0;
    pid.Speed_err_last=0.0;
    pid.voltage=0.0;
    pid.integral=0.0;
    pid.Angle_Kp=0.2;				
    pid.Angle_Kd=0.2;			
    pid.Speed_Kp=0.2;				
    pid.Speed_Ki=0.015;
    pid.Speed_Kd=0.2;
    pid.umax=400;
    pid.umin=-200;
    pid.Mechanical_balance=Mechanical_balance;
    printf("PID_init end \n");
}

float Angle_PID(float Now_Angle,float Gyro)
{
    //pid.Angle_err=pid.SetAngle-Now_Angle;
    //pid.SetSpeed=pid.Angle_Kp*pid.Angle_err+pid.Angle_Kd*(pid.Angle_err-pid.Angle_err_last);
    //pid.Angle_err_last=pid.Angle_err;
    pid.Bias=Now_Angle-pid.Mechanical_balance;//TODO:Will change if···
    //pid.Angle_err=pid.SetAngle-Now_Angle;
    pid.balance=pid.Angle_Kp*pid.Bias+pid.Angle_Kd*Gyro;
    //pid.Angle_err_last=pid.Angle_err;
    return pid.balance;
}

float Speed_PID(float encoder_left,float encoder_right)
{
    if(1==Flag_Forward)
    {
        pid.flag_UltrasonicWave=0;//无论前面是否有障碍物,蓝牙遥控优先级最高。将标志位置0
        Movement=20;
    }
    else if(1==Flag_Back)//接收到蓝牙APP遥控数据
    {
        pid.flag_UltrasonicWave=0;//无论前面是否有障碍物,蓝牙遥控优先级最高。将标志位置0
        Movement=-20;//设定速度
    }
        /*当超声波的距离低于10cm时,即10cm处存在障碍物,将超声波标志位置并且赋积分值使其后退,这里做了个简单的P比例计算*/
    else if(sensor.UltrasonicWave_Distance<10)
    {
        pid.flag_UltrasonicWave=1;
        Movement=sensor.UltrasonicWave_Distance*(-2);
    }
    else//没有接受到任何的数据
    {
        pid.flag_UltrasonicWave=0;
        Movement=0;
    }
    pid.integral+=Movement;
    pid.ActualSpeed=(encoder_left+encoder_right)/2;
    int index;
    pid.SetSpeed=0;
    pid.Speed_err=pid.SetSpeed-pid.ActualSpeed;
    if(pid.ActualSpeed>pid.umax)  //灰色底色表示抗积分饱和的实现
    {

        if((pid.Speed_err)>200)      //蓝色标注为积分分离过程
        {
            index=0;
        }else{
            index=1;
            if(pid.Speed_err<0)
            {
                pid.integral+=pid.Speed_err;
            }
        }
    }else if(pid.ActualSpeed<pid.umin){
        if((pid.Speed_err)>200)      //积分分离过程
        {
            index=0;
        }else{
            index=1;
            if(pid.Speed_err>0)
            {
                pid.integral+=pid.Speed_err;
            }
        }
    }else{
        if((pid.Speed_err)>200)                    //积分分离过程
        {
            index=0;
        }else{
            index=1;
            pid.integral+=pid.Speed_err;
        }
    }

    pid.voltage=pid.Speed_Kp*pid.Speed_err+index*pid.Speed_Ki*pid.integral+pid.Speed_Kd*(pid.Speed_err-pid.Speed_err_last);

    pid.Speed_err_last=pid.Speed_err;

    return pid.voltage;
}

#endif //BALANCECAR_PID_H
