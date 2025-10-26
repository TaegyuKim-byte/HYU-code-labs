#include "msp.h"
#include "Clock.h"
#include <stdio.h>

uint8_t sensor;
int count;

void ir_init(void) {
    P5->SEL0 &= ~BIT3;
    P5->SEL1 &= ~BIT3;
    P5->DIR  |= BIT3;
    P5->OUT  &= ~BIT3;

    P9->SEL0 &= ~BIT2;
    P9->SEL1 &= ~BIT2;
    P9->DIR  |= BIT2;
    P9->OUT  &= ~BIT2;

    P7->SEL0 &= ~0xFF;
    P7->SEL1 &= ~0xFF;
    P7->DIR  &= ~0xFF;
}

void motor_init(void) {
    P3->SEL0 &= ~0xC0;
    P3->SEL1 &= ~0xC0;
    P3->DIR  |= 0xC0;
    P3->OUT  |= 0xC0;   

    P5->SEL0 &= ~0x30;
    P5->SEL1 &= ~0x30;
    P5->DIR  |= 0x30;
    P5->OUT  &= ~0x30;  
}

void pwm_init(void) {
    P2->DIR  |= BIT6 | BIT7;
    P2->SEL0 |= BIT6 | BIT7;
    P2->SEL1 &= ~(BIT6 | BIT7);

    TIMER_A0->CCR[0] = 2400-1;     
    TIMER_A0->CCTL[3] = 0xE0;      
    TIMER_A0->CCTL[4] = 0xE0;      
    TIMER_A0->CCR[3] = 0;          
    TIMER_A0->CCR[4] = 0;
    TIMER_A0->CTL = 0x0214;        
}

void stop_motor(void) {
    TIMER_A0->CCR[3] = 0;   
    TIMER_A0->CCR[4] = 0;   
}

void move_motor_forward(void) {
    P5->OUT &= ~0x30;       
    P3->OUT |= 0xC0;        
    TIMER_A0->CCR[3] = 120;  
    TIMER_A0->CCR[4] = 120;  
}



    void main(void) {
    ir_init();
    motor_init();
    pwm_init();
    P2->SEL0 &= ~0x07;
    P2->SEL1 &= ~0x07;
    P2->DIR |= 0x07;
    P2->OUT &= ~0x07;

    printf("init\n");

    int cnt=0;
    while(1) {
        // 1) IR LED 켜기
        P5->OUT |= BIT3;
        P9->OUT |= BIT2;

        // 2) Capacitor 충전
        P7->DIR = 0xFF;
        P7->OUT = 0xFF;
        Clock_Delay1us(10);

        // 3) 입력으로 전환
        P7->DIR = 0x00;
        Clock_Delay1us(1000);

        // 4) 센서 값 읽기
        sensor = P7->IN & 0xFF;


        uint8_t temp = sensor;
//        while(temp) {
//            count += temp & 1;
//            temp >>= 1;
//        }

//        move_motor_forward();


        if(temp == 0b00011000){
            cnt=100;
        }
        else{
            cnt--;
        }

        if (cnt>0) {
            move_motor_forward();
            P2->OUT = 0b00000001;
        }
        else {
            stop_motor();
            P2->OUT = 0b00000000;
        }

        //move_motor_forward():

        // 5) 조건 판별
//        if (count >= 4) {
//            stop_motor();
//        } else if (count >= 2) {
//            move_motor_forward();
//        } else {
//            stop_motor();
//        }

        // 6) IR LED 끄기
        P5->OUT &= ~BIT3;
        P9->OUT &= ~BIT2;

        //Clock_Delay1us(10);
    }
}