/*
************************************************************************************************
*
* Name:		OS.h
* Author:	Ahmed Soubky
* Version:	1
* Date:		2013-10-20
* Descripton:   This header file contains the definitions of common data types used in OSEK OS.
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
typedef UINT8 TaskType;  

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
}TaskStateType; 

/* Reference to the state of a task */
typedef TaskStateType* TaskStateRefType; 


/* Data structure that is maintained by the CPU for every task */
typedef struct OS_TCB
{
	const char* name;
	UINT8 priority;
	TaskStateType status;
	UINT16 id;
	void* stackPointer;
	void* stackStart;
	UINT32 stackSize;
	UINT8 numberOfActivationRequests;
	UINT8 maxNumberOfActivationRequests;
	struct OS_TCB* nextTask;
	struct OS_TCB* prevTask;
}OS_TCB;

/* A macro that manipulates the user application task name into a function see OSEK Specifications 13.2.5 */
#define TASK (TaskName) StatusType OSEK_TASK_##TaskName (void)

/* A macro that manipulates the DeclareTask system service call */
#define DeclareTask ( TaskID ) extern void OSEK_TASK_##TaskID ( void );

/* OS specific error codes */
#define E_OS_ACCESS        ((StatusType)1U) 
#define E_CALLEVEL         ((StatusType)2U)
#define E_OS_ID            ((StatusTupe)3U)  
#define E_OS_LIMIT         ((StatusType)4U) 
#define E_OS_NOFUNC        ((StatusType)5U) 
#define E_OS_RESOURCE      ((StatusType)6U)
#define E_OS_STAT          ((StatusType)7U)
#define E_OS_VALUE         ((StatusType)8U)

/* Task Classification */
typedef enum TaskClassification 
{
	BASIC,EXTENDED
}TaskClassification;

/* Represents a resource for the OS */
typedef UINT8 ResourceType; 

/* Constant of datatype ResourceType */
#define RES_SCHEDULER ((ResourceType)1U)

/* Datatype that represents events that occur within the system */
typedef UINT16 EventMaskType;

/* Datatype that represents a reference to events within the system */
typedef EventMaskType* EventMaskRefType;

/* Datatype that represents a count value of tick */
typedef UINT16 TickType;

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
typedef UINT8 AlarmType;

/* Datatype that represents the application mode */
typedef UINT32 AppModeType;

/* Constant that represents the default application mode for OSEK OS */
#define OSDEFAULTAPPMODE  ((AppModeType) 1U) 
/*
================================Declarations of system services===================================
*/

void DeclareTask ( u_int8 TaskID ); 

extern StatusType ActivateTask( TaskType TaskID );
 
extern StatusType TerminateTask( void );

extern StatusType ChainTask ( TaskType TaskID );

extern StatusType Schedule ( void );

extern StatusType GetTaskID ( TaskRefType TaskID);

extern StatusType GetTaskState ( TaskRefType TaskID, TaskStateRefType State );

extern void EnableAllInterrupts ( void );

extern void DisableAllInterrupts ( void );

extern void ResumeAllInterrupts ( void );

extern void SuspendAllInterrupts ( void );

extern void ResumeOSInterrupts ( void );

extern void SuspendOSInterrupts ( void );

extern StatusType GetResource ( ResourceType ResID );

extern StatusType ReleaseResource ( ResourceType ResID );

extern void DeclareEvent ( EventMaskType EventID );

extern StatusType SetEvent ( TaskType TaskID, EventMaskType Mask );

extern StatusType ClearEvent ( EventMaskType Mask );

extern StatusType GetEvent ( TaskType TaskID, EventMaskRefType Mask );

extern StatusType WaitEvent ( EventMaskType Mask );

extern void DeclareAlarm ( AlarmType AlarmID );

extern StatusType GetAlarmBase ( AlarmType AlarmID, AlarmBaseRefType Info );

extern StatusType GetAlarm ( AlarmType AlarmID, TickRefType Tick ); 

extern StatusType SetRelAlarm ( AlarmType AlarmID, TickType increment, TickType cycle );

extern StatusType SetAbsAlarm ( AlarmType AlarmID, TickType start, TickType cycle );

extern StatusType CancelAlarm( AlarmType AlarmID );

extern AppModeType GetActiveApplicationModeType ( void );

extern void StartOS ( AppModeType Mode );

extern void ShutdownOS ( StatusType Error );



	


  



