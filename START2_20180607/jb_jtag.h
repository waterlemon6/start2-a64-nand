/******************************************************************/
/*                                                                */
/* Module:       jb_jtag.h                                        */
/*                                                                */
/* Descriptions: Manages JTAG State Machine (JSM), loading of     */
/*               JTAG instructions and reading of data from TDO.  */
/*                                                                */
/* Revisions:    .0 02/22/02                                      */
/*               .1 07/07/2004                                    */
/*                                                                */
/******************************************************************/

#ifndef __JB_JTAG_H__
#define __JB_JTAG_H__

/* Flag bits for DriveSignal() function */ 
#define TMS_HIGH   1
#define TMS_LOW    0
#define TDI_HIGH   1
#define TDI_LOW    0
#define TCK_HIGH   1
#define TCK_LOW    0
#define TCK_TOGGLE 1
#define TCK_QUIET  0

/* Macro for port number */
#define PORT_0	   0
#define PORT_1	   1
#define PORT_2	   2

/* JTAG Configuration Signals */
#define SIG_TCK  0 /* TCK */
#define SIG_TMS  1 /* TMS */
#define SIG_TDI  2 /* TDI */
#define SIG_TDO  3 /* TDO */

/* States of JTAG State Machine */
#define JS_RESET         0
#define JS_RUNIDLE       1
#define JS_SELECT_IR     2
#define JS_CAPTURE_IR    3
#define JS_SHIFT_IR      4
#define JS_EXIT1_IR      5
#define JS_PAUSE_IR      6
#define JS_EXIT2_IR      7
#define JS_UPDATE_IR     8
#define JS_SELECT_DR     9
#define JS_CAPTURE_DR    10
#define JS_SHIFT_DR      11
#define JS_EXIT1_DR      12
#define JS_PAUSE_DR      13
#define JS_EXIT2_DR      14
#define JS_UPDATE_DR     15
#define JS_UNDEFINE      16

extern const int JI_EXTEST;       //= 0x000;
extern const int JI_PROGRAM;      //= 0x002;
extern const int JI_STARTUP;      //= 0x003;
extern const int JI_CHECK_STATUS; //= 0x004;
extern const int JI_SAMPLE;       //= 0x005;
extern const int JI_IDCODE;       //= 0x006;
extern const int JI_USERCODE;     //= 0x007;
extern const int JI_BYPASS;       //= 0x3FF;
extern const int JI_PULSE_NCONFIG;//= 0x001;
extern const int JI_CONFIG_IO;	  //= 0x00D;
extern const int JI_HIGHZ;		  //= 0x00B;
extern const int JI_CLAMP;		  //= 0x00A;

int AdvanceJSM(int);
int ReadTDO(int bits, int data, int inst);
void PrintJS(void);
void SetupChain(int dev_count, int dev_seq, int* ji_info, int action);

int LoadJI(int inst, int dev_count, int* ji_info);
int Ji_Extest(int device, int* ji_info);
int Ji_Program(int device, int* ji_info);
int Ji_Startup(int device, int* ji_info);
int Ji_Checkstatus(int device, int* ji_info);
int Ji_Sample(int device, int* ji_info);
int Ji_Idcode(int device, int* ji_info);
int Ji_Usercode(int device, int* ji_info);
int Ji_Bypass(int device, int* ji_info);
int Ji_Pulse_nConfig(int device, int* ji_info);
int Ji_Config_IO(int device, int* ji_info);
int Ji_HighZ(int device, int* ji_info);
int Ji_Clamp(int device, int* ji_info);

void Js_Reset(void);
void Js_Runidle(void);
int Js_Shiftdr(void);
int Js_Updatedr(void);

#endif
