
#ifndef OS_H_
#define OS_H_

#include "std_types.h"

/* Timer counting time(Base Time) in ms */
#define OS_BASE_TIME 20

/* Function responsible for:
 * 1. Initialize the Os
 * 2. Execute the Init Task
 * 3. Start the Scheduler to run the tasks
 */
void Os_start(void);

/* The Engine of the Os Scheduler used for switch between different tasks */
void Os_scheduler(void);

/* Function called by the Timer Driver in the MCAL layer  */
void Os_newTimerTick(void);

#endif /* OS_H_ */
