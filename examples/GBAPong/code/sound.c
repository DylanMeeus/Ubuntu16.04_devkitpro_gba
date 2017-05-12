#include "sound.h"
#include <stdbool.h>

i = 0;



// did we already init sound?
bool soundInit = false;

inline initSound(signed char* input){

}

void playSound(signed char* input){

        if(soundInit == true) {REG_DMA1CNT = 0; return;}

       soundInit = true;
       REG_TM0D   = TIMER_INTERVAL;
       REG_TM0CNT = TIMER_ENABLED;

       REG_SOUNDCNT_H = SND_OUTPUT_RATIO_100 |
                                DSA_OUTPUT_RATIO_100 |
                                DSA_OUTPUT_TO_BOTH |
                                DSA_TIMER0 |
                                DSA_FIFO_RESET;

        REG_DMA1SAD = (uint32)(input);
        REG_DMA1DAD = (uint32)REG_FIFO_A;
        REG_DMA1CNT = ENABLE_DMA | START_ON_FIFO_EMPTY | WORD_DMA | DMA_REPEAT;

}