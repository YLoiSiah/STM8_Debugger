/*
 * swimSM.c
 *
 *  Created on: Aug 22, 2017
 *      Author: user2
 */

#include "swimSM.h"

void swimSmHandler(Swim *swim, Event event)
{
  switch (swim->currState)
  {
      case SWIM_START:
//          forcedLow_buffer[0] = period_16us * 1;
//          for(int i = 1; i < 9; i++)
//          {
//            forcedLow_buffer[i] =  getOCR(period_600us, forcedLow_buffer[i-1], period_500us);
//          }
//
//          for(int i = 0; i < 8; i++)
//          {
//            forcedLow_buffer[i+9] =  getOCR(period_600us, forcedLow_buffer[i+9-1], period_250us);
//          }
//
//          forcedLow_buffer[17] = period_600us + 1;
//          configureAndStart_OC_DMA(period_600us, forcedLow_buffer, OC_bufferSize);
    	  startSwimEntrySequence();
          start_TIM2_CH2_IC_DMA(icBuffer, 10);
          break;
      case SWIM_LISTEN_SYNCHRONIZATION:
          swim_send_header(SWIM_WOTF);
          start_TIM2_CH2_IC_DMA(icBuffer, 6);
          break;

      case SWIM_COMMAND_SRST:
          // code to be executed if n is equal to constant2;
          break;
      case SWIM_COMMAND_ROTF:
          // code to be executed if n is equal to constant2;
          break;
      case SWIM_COMMAND_WOTF:
          // code to be executed if n is equal to constant2;
          break;
      case SWIM_LISTEN_ACK:
          // code to be executed if n is equal to constant2;
          break;
      default:
          // code to be executed if n doesn't match any constant
    	  break;
  }
}
