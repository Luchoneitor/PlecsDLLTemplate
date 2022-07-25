#include"pch.h"
#include"Signals.h"


#define M_PI  3.1415926535897932384626433832795f
#define M_E   2.7182818284590452353602874713527f
#define SQRT2 1.4142135623730950488016887242097f
#define SQRT3 1.7320508075688772935274463415059f

#define MATH_CONST_INIT  .PI          = M_PI,                \
                         .PI_X2       = 2.0f*M_PI,           \
                         .PI_DIV3     = (M_PI /3.0f),        \
                         .PI_2DIV3    = (2.0f * M_PI/ 3.0f), \
                         .C_1DIV3     = (1.0f/3.0f),         \
                         .C_2DIV3     = (2.0f/3.0f),         \
                         .C_SQRT2     = SQRT2,               \
                         .C_SQRT3     = SQRT3,               \
                         .C_1DIV2PI   = 1.0f/(2.0f*M_PI),    \
                         .C_1DIVSQRT3 = (1.0f/SQRT3),        \
                         .C_1DIVSQRT2 = (1.0f/SQRT2),        \
                         .C_SQRT3DIV2 = (0.5f * SQRT3)




float  Signal_GenerateSineWave(volatile SignalGen *const wp)
{
    const float phs = wp->phsInDeg * MATH_CONST.PI / 180.0f;

    wp->angle= wp->angle+ MATH_CONST.PI_X2 * wp->freq * GLOBAL_TS;
    if (wp->angle >= MATH_CONST.PI_X2)  wp->angle = 0.0f;

    return wp->bias + wp->ampl * sinf(wp->angle + phs);

}



void SetGlobalTs(float *const samplingTime, SimulationState const *const aState)
{

    PARAM(*samplingTime, 1);

}




float Signal_ramp(float init, float target, float step)
{
    static float output;
    output = init + step;
    if (step < 0.0f && output <= target)
    {
        output = target;
    }
    else if (step > 0.0f && output >= target)
    {
        output = target;
    }
    return output;
}



const MathConstants MATH_CONST = { MATH_CONST_INIT };
const Limits LIMITS = { LIMITS_INIT };


SignalGen sineWaweA;
SignalGen sineWaweB;
SignalGen sineWaweC;




