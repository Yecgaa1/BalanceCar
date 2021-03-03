//
// Created by 星星 on 2021/2/9.
//

#ifndef BALANCECAR_DIRECTION_H
#define BALANCECAR_DIRECTION_H
void Moto1_forward()
{
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5,1);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4,0);
}

void Moto1_backward()
{
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5,0);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4,1);

}
void Moto2_forward()
{

    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3,1);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,0);
}
void Moto2_backward()
{

    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3,0);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15,1);
}
#endif //BALANCECAR_DIRECTION_H
