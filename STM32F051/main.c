/*
    ChibiOS/RT - Copyright (C) 2006-2013 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#include "ch.h"
#include "hal.h"
#include "test.h"
#include "shell.h"
#include "cmd.h"
#include "chprintf.h"
#include "cmdadc.h"
#include "hardware.h"

#define SHELL_WA_SIZE   THD_WA_SIZE(512)
MemoryPool mp;
#define NUM_THREADS_POSSIBLE 3 
int threadCount =0;
Thread* threadArray[NUM_THREADS_POSSIBLE];
WORKING_AREA(thread_area0, 512);
WORKING_AREA(thread_area1, 512);
WORKING_AREA(thread_area2, 512);

Thread *sh = NULL;


/*
 * Blue LED blinker thread, times are in milliseconds.
 */
static WORKING_AREA(waThread1, 128);
static msg_t Thread1(void *arg) {

  (void)arg;
  chRegSetThreadName("blinker1");
  while (TRUE) {
    palClearPad(GPIOC, GPIOC_LED4);
    chThdSleepMilliseconds(500);
    palSetPad(GPIOC, GPIOC_LED4);
    chThdSleepMilliseconds(500);
  }
  return 0;
}



/*
 * Green LED blinker thread, times are in milliseconds.
 */
static WORKING_AREA(waThread2, 128);
static msg_t Thread2(void *arg) {

  (void)arg;
  chRegSetThreadName("blinker2");
  while (TRUE) {
    palClearPad(GPIOC, GPIOC_LED3);
    chThdSleepMilliseconds(250);
    palSetPad(GPIOC, GPIOC_LED3);
    chThdSleepMilliseconds(250);
  }
  return 0;
}

/*
 * Application entry point.
 */
int main(void) {

//	chPoolFree(&mp, thd2);
	Thread *sh = NULL;
  /*
   * System initializations.
   * - HAL initialization, this also initializes the configured device drivers
   *   and performs the board-specific initializations.
   * - Kernel initialization, the main() function becomes a thread and the
   *   RTOS is active.
   */
  halInit();
  chSysInit();
  hardwareInitialise();
	chPoolInit(&mp, THD_WA_SIZE(512), NULL);
	chPoolFree(&mp, thread_area0);
	chPoolFree(&mp, thread_area1);
	chPoolFree(&mp, thread_area2);

  /*
   * Activates the serial driver 1 using the driver default configuration.
   * PA9 and PA10 are routed to USART1.
   */
	sdStart(&SD1, NULL);
	palSetPadMode(GPIOA, 9, PAL_MODE_ALTERNATE(1));       /* USART1 TX.       */
	palSetPadMode(GPIOA, 10, PAL_MODE_ALTERNATE(1));      /* USART1 RX.       */
	palSetGroupMode(GPIOC, PAL_PORT_BIT(0) | PAL_PORT_BIT(1), 0, PAL_MODE_INPUT_ANALOG);


  /*
   * Creates the blinker threads.
*/
	threadArray[0] =chThdCreateFromMemoryPool(&mp, NORMALPRIO, outputResponse, &SD1);
	threadCount++;
	chThdCreateStatic(waThread1, sizeof(waThread1), NORMALPRIO, Thread1, NULL);
	chThdCreateStatic(waThread2, sizeof(waThread2), NORMALPRIO, Thread2, NULL);

  /*
   * Normal main() thread activity, in this demo it does nothing except
   * sleeping in a loop and check the button state, when the button is
   * pressed the test procedure is launched with output on the serial
   * driver 1.
   */

    /*
    * Starts an ADC continuous conversion.
    */
	shellInit();

		//call bt function
		if (!sh)
			sh = shellCreate(&shCfg, SHELL_WA_SIZE, NORMALPRIO);
		else if (chThdTerminated(sh)) {
			chThdRelease(sh);
			sh = NULL;
		}

	while (TRUE)
	{

    		chThdSleepMilliseconds(1000);
    	}

}
