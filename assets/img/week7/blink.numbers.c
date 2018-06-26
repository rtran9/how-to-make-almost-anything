// Robert Tran
// Modified from

// hello.ftdi.16E5.blink.c
//
// 16E5 blink
//
// Neil Gershenfeld
// 10/27/15
//
// (c) Massachusetts Institute of Technology 2015
// This work may be reproduced, modified, distributed,
// performed, and displayed for any purpose. Copyright is
// retained and must be preserved. The work is provided
// as is; no warranty is provided, and users accept all 
// liability.
//

#include <avr/io.h>
#include <util/delay.h>

#define VPORTA VPORT0 // pre-mapped virtual port A
#define VPORTC VPORT1 // pre-mapped virtual port C
#define VPORTD VPORT2 // pre-mapped virtual port D
#define VPORTR VPORT3 // pre-mapped virtual port R

#define DELAY 500 // blink delay
#define LED PIN4_bm // LED bit mask

#define NUM_0 ~PIN7_bm & (PIN0_bm | PIN1_bm | PIN2_bm | PIN4_bm | PIN5_bm | PIN6_bm)
#define NUM_1 ~PIN7_bm & (PIN2_bm | PIN4_bm)
#define NUM_2 ~PIN7_bm & (PIN0_bm | PIN1_bm | PIN3_bm | PIN4_bm | PIN6_bm)
#define NUM_3 ~PIN7_bm & (PIN0_bm | PIN2_bm | PIN3_bm | PIN4_bm | PIN6_bm)
#define NUM_4 ~PIN7_bm & (PIN2_bm | PIN3_bm | PIN4_bm | PIN5_bm)
#define NUM_5 ~PIN7_bm & (PIN0_bm | PIN2_bm | PIN3_bm | PIN5_bm | PIN6_bm)
#define NUM_6 ~PIN7_bm & (PIN0_bm | PIN1_bm | PIN2_bm | PIN3_bm | PIN5_bm | PIN6_bm)
#define NUM_7 ~PIN7_bm & (PIN2_bm | PIN4_bm | PIN6_bm)
#define NUM_8 ~PIN7_bm 
#define NUM_9 ~PIN7_bm & (PIN0_bm | PIN2_bm | PIN3_bm | PIN4_bm | PIN5_bm | PIN6_bm)

int main(void) {
   //
   // set up clock
   //
   OSC.CTRL = OSC_RC32MEN_bm; // enable 32MHz clock
   while (!(OSC.STATUS & OSC_RC32MRDY_bm)); // wait for clock to be ready
   CCP = CCP_IOREG_gc; // enable protected register change
   CLK.CTRL = CLK_SCLKSEL_RC32M_gc; // switch to 32MHz clock
   //
   // set up port
   //
   VPORTA.DIR = LED;
   VPORTC.DIR = NUM_8;
   
   //VPORTD.DIR = PIN3_bm;
   //VPORTD.OUT = PIN3_bm;
   // main loop
   //
   int count = 0;
   while (1) {
      count = count + 1;
      
      VPORTA.OUT = LED;
      
      if (count % 10 == 0) {
         VPORTC.OUT = NUM_0;
      }
      if (count % 10 == 1) {
         VPORTC.OUT = NUM_1;
      }
      if (count % 10 == 2) {
         VPORTC.OUT = NUM_2;
      }
      if (count % 10 == 3) {
         VPORTC.OUT = NUM_3;
      }
      if (count % 10 == 4) {
         VPORTC.OUT = NUM_4;
      }
      if (count % 10 == 5) {
         VPORTC.OUT = NUM_5;
      }
      if (count % 10 == 6) {
         VPORTC.OUT = NUM_6;
      }
      if (count % 10 == 7) {
         VPORTC.OUT = NUM_7;
      }
      if (count % 10 == 8) {
         VPORTC.OUT = NUM_8;
      }
      if (count % 10 == 9) {
         VPORTC.OUT = NUM_9;
      }
  
      _delay_ms(DELAY);
 
      VPORTA.OUT = 0;
      VPORTC.OUT = 0;
      
      _delay_ms(DELAY);
   }
}
