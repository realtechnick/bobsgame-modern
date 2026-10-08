//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================
#ifndef DEBUG_H
#define DEBUG_H
//==============================================================================

//================
//defines
//================



//================
//variables
//================

//CAPTION* fpscaption = NULL;

//================
//prototypes
//================


void DEBUG_init();
void DEBUG_main();/*PORT: was missing*/
void DEBUG_vbl();
void calculate_fps();

// PORT: stutter-debug overlay + hitch log (F3 toggles the overlay; the hitch log is always on)
extern int stuttermeter;
void DEBUG_stutter_frame(float total_ms, float logic_ms, float vbl_ms, float wait_ms);



//==============================================================================
#endif
//==============================================================================



