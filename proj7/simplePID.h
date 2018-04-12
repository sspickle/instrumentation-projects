
unsigned long millis( void );

typedef struct PID_t {
    double input;       // current input
    double output;      // current output
    double setPoint;    // desired set point
    double lastInput;   // last value of input
    double outputSum;   // integrated error term
    double ki;          // I coefficient
    double kd;          // D coefficient
    double kp;          // P coefficient
    double outMax;      // max output
    double outMin;      // min output
    unsigned long lastTime; // last call to compute happened then
    unsigned long sampleTime; // how long between samples?
} PID;

void PID_Init(PID *pid, double input, double setPoint, double ki, double kd, double kp, double outMax, double outMin, unsigned long sampleTime);
void PID_Compute(PID *pid);

