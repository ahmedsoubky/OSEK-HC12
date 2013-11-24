/*
************************************************************************************************
*
* Name:		OS.h
* Author:	Ahmed Soubky
* Version:	0
* Date:		2013-10-20
* Descripton:   This header file includes the definitions of common data types used in OSEK OS.
************************************************************************************************
*/

#include "types.h"	

/* Represents the status of a task whether it is in error or otherwise.*/
#ifndef STATUSTYPEDEFINED 
#define STATUSTYPEDEFINE
typedef unsigned char StatusType;  
#define E_OK ((StatusType)0U) 
#endif

/* Datatype that represents a task */
typedef u_int8 TaskType;  

/* Reference to a certain task */
typedef TaskType* TaskRefType; 

/* Datatype that represents the state of a task */
typedef enum TaskStateType
{
	RUNNING, 
	WAITING,
	READY, 
	SUSPENDED,
	INVALID_TASK
}; 

/* Reference to the state of a task */
typedef TaskStateType* TaskStateRefType; 


/* Data structure that is maintained by the CPU for every task */
typedef struct OSTaskVar
{
	u_int16 ID;
	TaskType Type;
	TaskStateType Status;
	
}TaskVarType;

/* A macro that manipulates the user application task name into a function see OSEK Specifications 13.2.5 */
#define TASK (TaskName) StatusType OSEK_TASK_ ## TaskName (void)

/* OS specific error codes */
#define E_OS_ACCESS   ((StatusType)1U) 
#define E_CALLEVEL    ((StatusType)2U)
#define E_OS_ID       ((StatusTupe)3U)  
#define E_OS_LIMIT    ((StatusType)4U) 
#define E_OS_NOFUNC   ((StatusType)5U) 
#define E_OS_RESOURCE ((StatusType)6U)
#define E_OS_STAT     ((StatusType)7U)
#define VALUE         ((StatusType)8U)

/* Represents a resource for the OS */
typedef u_int8 ResourceType; 

/* Constant of datatype ResourceType */
#define RES_SCHEDULER ((ResourceType)1U)

/* Datatype that represents events that occur within the system */
typedef u_int16 EventMaskType;

/* Datatype that represents a reference to events within the system */
typedef EventMaskType* EventMaskRefType;

/* Datatype that represents a count value of tick */
typedef u_int16 TickType;

/* Datatype that represents a reference to TickType object */
typedef TickType* TickRefType;

/* Datatype that represents the structure of counter elements */
typedef struct 
{
	TickType maxallowedvalue;
	TickType ticksperbase;
	TickType mincycle;
}AlarmBaseType;

/* Datatype that represents a reference to AlarmBaseType object */
typedef AlarmBaseType* AlarmBaseRefType;

/* Datatype that represents an alarm object */
typedef u_int8 AlarmType;



  



