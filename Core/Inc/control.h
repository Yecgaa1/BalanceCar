//
// Created by 星星 on 2021/2/14.
//



#include "sensor.h"
#include "pid.h"
#include "direction.h"
#include "bluetooth.h"

float Balance_Pwm;
int i=0;
float Velocity_Pwm;
float Turn_Pwm;
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
    if(Moto1>0)
    {
        Moto1_forward();
    }
    else
    {
        Moto1_backward();
    }
    if(Moto2>0){
        Moto2_forward();
    }
    else{
        Moto2_backward();
    }
}
float myabs(float a)//取正数
{
    float temp;
    if(a<0)  temp=-a;
    else temp=a;
    return temp;
}
float turn(int encoder_left,int encoder_right,float gyro)//转向控制
{
    static float Turn_Target,Turn,Encoder_temp,Turn_Convert=0.9,Turn_Count;
    float Turn_Amplitude=44,Kp=20,Kd=0;
    //=============遥控左右旋转部分=======================//
    //这一部分主要是根据旋转前的速度调整速度的起始速度，增加小车的适应性
    if(1==Flag_Left||1==Flag_Right)
    {
        if(++Turn_Count==1)
            Encoder_temp=myabs(encoder_left+encoder_right);
        Turn_Convert=55/Encoder_temp;
        if(Turn_Convert<0.6)Turn_Convert=0.6;
        if(Turn_Convert>3)Turn_Convert=3;
    }
    else
    {
        Turn_Convert=0.9;
        Turn_Count=0;
        Encoder_temp=0;
    }
    if(1==Flag_Left)	           Turn_Target-=Turn_Convert;
    else if(1==Flag_Right)	     Turn_Target+=Turn_Convert;
    else Turn_Target=0;
    if(Turn_Target>Turn_Amplitude)  Turn_Target=Turn_Amplitude;    //===转向	速度限幅
    if(Turn_Target<-Turn_Amplitude) Turn_Target=-Turn_Amplitude;
    if(Flag_Forward==1||Flag_Back==1)  Kd=0.5;
    else Kd=0;   //转向的时候取消陀螺仪的纠正 有点模糊PID的思想
    //=============转向PD控制器=======================//
    Turn=-Turn_Target*Kp-gyro*Kd;                 //===结合Z轴陀螺仪进行PD控制
    return Turn;
}
void control()
{

    Balance_Pwm =Angle_PID(sensor.pitch,sensor.gyroy);   //===平衡环PID控制
    Velocity_Pwm=Speed_PID(sensor.Encoder_Left,sensor.Encoder_Right);       //===速度环PID控制
    if(1==Flag_Left||1==Flag_Right)
        Turn_Pwm =turn(sensor.Encoder_Left,sensor.Encoder_Right,sensor.gyroz);        //===转向环PID控制
    else Turn_Pwm=(-0.5)*sensor.gyroz;
    Moto1=Balance_Pwm-Velocity_Pwm-Turn_Pwm;                 //===计算左轮电机最终PWM
    Moto2=Balance_Pwm-Velocity_Pwm+Turn_Pwm;                 //===计算右轮电机最终PWM
    Xianfu_Pwm();  																					 //===PWM限幅	    //===检查USB是否插入
    Turn_Off(sensor.pitch);																 //===检查角度以及电压是否正常
    Set_Pwm();                                    //===赋值给PWM寄存器
}

