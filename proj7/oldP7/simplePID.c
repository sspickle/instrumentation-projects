
/*
**
** SimplePID
**
**/

#include "project.h"
#include "simplePID.h"

static unsigned long timer0;

unsigned long millis( void ) {
    return timer0 - Timer_1_ReadCounter();
}

void PID_Init(PID *pid, double input, double setPoint, double ki, double kd, double kp, double outMax, double outMin, unsigned long sampleTime) {

    Timer_1_Start();
    timer0 = Timer_1_ReadCounter();
    
    pid->input = input;
    pid->setPoint = setPoint;
    pid->ki = ki;
    pid->kd = kd;
    pid->kp = kp;
    pid->lastInput = input;
    pid->outputSum = 0.0;
    pid->lastTime = millis();
    pid->outMin = outMin;
    pid->outMax = outMax;
    pid->sampleTime = sampleTime;
}

void PID_Compute(PID *pid) {

    unsigned long now = millis();
    unsigned long timeChange = (now - pid->lastTime);

    if(timeChange>=pid->sampleTime)
    {
        double input = pid->input;
        double error = pid->setPoint - input;
        double dInput = (input - pid->lastInput);

        pid->outputSum += (pid->ki * error);

        if(pid->outputSum > pid->outMax) {
            pid->outputSum = pid->outMax;
        } else if (pid->outputSum < pid->outMin) {
            pid->outputSum = pid->outMin;
        }

        pid->output = pid->kp * error + pid->outputSum - pid->kd * dInput;

        if(pid->output > pid->outMax) {
            pid->output = pid->outMax;
        } else if(pid->output < pid->outMin) {
            pid->output = pid->outMin;
        }

        pid->lastInput = pid->input;
        pid->lastTime = now;
    }
}
