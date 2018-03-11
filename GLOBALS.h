#define AVERAGEINTERVAL 300 //how many EMG samples to average over
#define A_MAX 885   //maximum of angle sensor
#define A_MIN 362  //minimum
#define athr 30   //when it starts restricting torque
#define send_counter_max 200
static int mai = 0;   //moving average iterator
static int bs[AVERAGEINTERVAL] = {0}, ts[AVERAGEINTERVAL] = {0}; //globals for average
static bool lastDir = 0; //keeps track of direction
static float bScale = 1;
static float tScale = 1;
static int tFloating = 0;
static int bFloating = 0;
int bforce;
int tforce;
static float forceIntegral = 0;  //for PID controller
static int prevError = 0;  //for derivative PID controller
static bool PIDmode = 0;   //1 if PID is active
int sendCounter = 0;

//pins
#define relayPin 2
#define dirPin1   21
#define dirPin2   22
#define DACPin    A14
#define potPin    A2
#define tricepPin A3
#define bicepPin  A4
#define forcePin1 A0
#define forcePin2 A1
#define LEDpin 29 //arm indicator LED
