/* Notes
   An internal peripheral that can be used as a timer or counter
   Timer -- Counting clock ticks
   Counter -- Counting external events
   
   Want a delay? Use a Timer/Counter. It runs in the background and frees the CPU for other tasks
   
   Timer/Counter 0
     - 8 bits
     - 256 step resolution
     
   Timer/Counter 1
     - 16 bits
     - 65,536 step resolution
     
   Timer/Counter 2
     - 8 bits
     - 356 step resolution

   Counting Clock Cycles
     - Delay is based on clock frequency
     - Arduino has a 16 MHz Clock
       1/16MHz = 62.5 ns
       100 counts of the clock = 6.25 us
       
   REGISTERS
   TCNTn
      Timer/Counter Register
      - Current count is stored in an internal timer/counter register
      - Read current count from TCNT or write to it
      - Wanna make a stopwatch?
          - Write 0 to TCNT
          - Do something
          - Read TCNT to see how much time has passed
      - TCNT0  8 bits
      - TCNT2  8 bits
       
   Flags:
      - TOVn
         - Overflow flag
         - TCNTn has reached max count
      - OCFnA
         - Output compare match A flag
         - TCNTn has reached the value in OCRnA
      - OCFnB
         - Output compare match B flag
         - TCNTn has reached the value in OCRnB
      When a timer / counter reaches its max value, it overflows, returns to 0 and the TOVn flag is set
   
   OCRn 
      Output Compare Register
      - Used to set a time
      - Lets you know when a certain count value is reached
      - OCR0A, OCR0B   8 bits
      - OCR2A, OCR2B   8 bits
      
   Timer/Counter 1...
      16 bits needed to store current time
      - TCNT1H is the high byte (8 MSB)
      - TCNT1L is the low  byte (8 LSB)
      
   TCCRnN
      Timer Control Register
      - Used to set up functionality of timers
         - Mode of operation
         - What to do on compare match
         - Force output compare
         - And more
      - TCCRnA
      - TCCRnB
   
   MODES OF OPERATION
      Normal Mode
      - Counts to 255 or 65,535 and then rolls over
      - Used a lot when counting ticks or timing an event
      - TCNTn increments each clock period
      - When max count is reached, a flag is set and TCNTn rolls back to 0
      
      CTC Mode
      - Clear Timer on Compare match mode
      - Counter cleared to 0 when TCNTn matched OCRnA
      
   TIFR0
      - Timer/Counter 0 Interrupt Flag Register
      - TOV0 bit is set when an overflow occurs in Timer/Counter 0
      - TOV0 is cleared by writing a 1 to it
 */
   
// Normal Mode -- 10 us delay in program using timer 0
   // Determine number of clock counts in 10 us
   // 10 us = counts * 62.5 ns ... counts = 160
  
  // Determine where to start TCNT0 so that it rolls over after 160 counts
  // 255 - 160 = 95
