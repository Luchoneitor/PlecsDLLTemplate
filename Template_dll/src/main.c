#include <stddef.h>
#include <string.h>
#include "pch.h"

/*Paramters from PLECS*/
float Ts;
float test_input;


void plecsSetSizes(SimulationSizes *aSizes)
{
    *aSizes = (SimulationSizes){ SIMULATION_SIZES };
}



void plecsStart(SimulationState *aState)
{
    /*Import the parameters from the DLL block of the plecs model*/
    SetGlobalTs(&GLOBAL_TS, aState); // By default this is parameter number 1


    /*Delete the scopes value the default value is -123.0*/
    CLEAR_SCOPES;

  

}



void plecsOutput(SimulationState *aState)
{
    if (TRIG_0){

        /***********************/
        /*     Measurements    */
        /***********************/

        MEAS(test_input, 1);





        /***********************/
        /*  Signal Processing  */
        /***********************/








        /***********************/
        /*     Set Outputs     */
        /***********************/
        SCOPE(test_input, 1);
    }

}



void plecsTerminate(SimulationState *aState)
{

}


