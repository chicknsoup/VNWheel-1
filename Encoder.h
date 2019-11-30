#ifndef ENCODER_h
#define ENCODER_h

#include <Arduino.h>
#include "WheelConfig.h"

#define interruptA 0
#define interruptB 1
#define interruptZ 2
#define interruptR 3

#define encoderPinA 0
#define encoderPinB 1
#define encoderPinZ 2



class Encoder {
  public:
    Encoder(void);
    ~Encoder(void);
    uint32_t cPR;
    uint16_t maxAngle;
    int32_t maxValue;
    int32_t  minValue;    
    
    bool inverted;
    bool usePinZ;
    bool z1stUp;
    uint64_t lastEncoderTime;
    
    int32_t  currentPosition;
    int32_t  lastPosition;
    int32_t  correctPosition;    
    int32_t  currentPositionVelocity;
    int32_t  lastPositionVelocity;
    int32_t  positionAcceleration;
    int32_t  positionChange;
    void setConfig(WheelConfig wheelConfig);
    void initVariables(void);
    void updatePosition(void);

  private:
   
    bool resetPosition;
    volatile bool currentPinA;
    volatile bool lastPinA;
    volatile bool currentPinB;
    volatile bool lastPinB;
    volatile bool currentPinZ;
    volatile bool lastPinZ;
    int8_t parsePosition();


};

#endif
