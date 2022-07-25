
#pragma once

const float GLOBAL_TS;

#define SINE_A_INIT     .bias = 0.0f, .ampl = 20.0f, .freq = 50.0f, .phsInDeg =    0.0f, 0.0f
#define SINE_B_INIT     .bias = 0.0f, .ampl = 20.0f, .freq = 50.0f, .phsInDeg = -120.0f, 0.0f
#define SINE_C_INIT     .bias = 0.0f, .ampl = 20.0f, .freq = 50.0f, .phsInDeg = 120.0f,  0.0f


#define LIMITS_INIT      .DUTY_MAX   = 1.0f,\
                         .DUTY_MIN   = 0.0f,\

#define __mminf32(X, Y) (((X) < (Y)) ? (X) : (Y))
#define __mmaxf32(X, Y) (((X) > (Y)) ? (X) : (Y))


#define SATURATION(input, lim_L, lim_H)\
                     (__mmaxf32(__mminf32((input), (lim_H)), (lim_L)))




typedef struct
{
    float  PI;
    float  PI_X2;
    float  PI_DIV3;
    float  PI_2DIV3;
    float  C_1DIV3;
    float  C_2DIV3;
    float  C_SQRT2;
    float  C_SQRT3;
    float  C_1DIV2PI;
    float  C_1DIVSQRT3;
    float  C_1DIVSQRT2;
    float  C_SQRT3DIV2;
}MathConstants;





typedef struct
{
    float DUTY_MAX;
    float DUTY_MIN;

}Limits;



typedef struct
{
    float bias;
    float ampl;
    union
    {
        float period;
        float freq;
    };
    union
    {
        float duty;
        float phsInDeg;
    };

    union
    {
        float count;
        float angle;
    };
}SignalGen;

#define ACQUIRE_MEASUREMENTS\
    MEAS(meas.vpv.s1,     1);    \
    MEAS(meas.vpv.s2,     2);    \
    MEAS(meas.ipv.s1,     3); \
    MEAS(meas.ipv.s2,     4); \
    MEAS(meas.iboost.s1,  5); \
    MEAS(meas.iboost.s2,  6); \
    MEAS(meas.vdc.s1,     7);    \
    MEAS(meas.vdc.s2,     8);    \
    MEAS(meas.iconv.a,    9);   \
    MEAS(meas.iconv.b,    10);   \
    MEAS(meas.iconv.c,    11);   \
    MEAS(meas.vgrid.a,    12);   \
    MEAS(meas.vgrid.b,    13);  \
    MEAS(meas.vgrid.c,    14);  \
    MEAS(meas.igrid.a,    15);  \
    MEAS(meas.igrid.b,    16);  \
    MEAS(meas.igrid.c,    17);  \
    MEAS(meas.vconv.a,    18);  \
    MEAS(meas.vconv.b,    19);  \
    MEAS(meas.vconv.c,    20);  \
    MEAS(meas.ibatt,      21);    \
    MEAS(meas.vbatt,      22)    \

//PS300_API void Signals_AcquireMeasurements_TRIG0(SignalMeas *const me);

float Signal_ramp(float init, float target, float step);
float Signal_GenerateSineWave(volatile SignalGen *const  wp);
void SetGlobalTs(float *const samplingTime, SimulationState const *const aState);

extern const MathConstants MATH_CONST;
extern const Limits LIMITS;

extern SignalGen sineWaweA;
extern SignalGen sineWaweB;
extern SignalGen sineWaweC;





