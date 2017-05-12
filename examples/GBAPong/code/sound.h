#ifndef SOUND_H
#define SOUND_H

typedef unsigned char   uint8;
typedef unsigned short  uint16;
typedef unsigned int       uint32;

// sound configuration
#define REG_SOUNDCNT_X *(uint32*)0x04000084
#define SND_ENABLED           0x00000080



#define DSA_OUTPUT_RATIO_100  0x0004
#define SND_OUTPUT_RATIO_100  0x0002
#define DSA_OUTPUT_TO_BOTH    0x0300
#define DSA_TIMER0            0x0000
#define DSA_FIFO_RESET        0x0800
#define REG_SOUNDCNT_H  (*(uint16*)0x04000082)

#define REG_DMA1SAD         *(uint32*)0x40000BC  // source address
#define REG_DMA1DAD         *(uint32*)0x40000C0  // destination address
#define REG_DMA1CNT         *(uint32*)0x40000C4  // control register

// DMA flags
#define WORD_DMA            0x04000000
#define HALF_WORD_DMA       0x00000000
#define ENABLE_DMA          0x80000000
#define START_ON_FIFO_EMPTY 0x30000000
#define DMA_REPEAT          0x02000000
#define DEST_REG_SAME       0x00400000

// Timer 0 register definitions
#define REG_TM0D            *(uint16*)0x4000100
#define REG_TM0CNT          *(uint16*)0x4000102

// Timer flags
#define TIMER_ENABLED       0x0080

// FIFO address defines
#define REG_FIFO_A          0x040000A0
#define REG_FIFO_B          0x040000A4

#define TIMER_INTERVAL      (0xFFFF - 761)


void playSound(signed char* input);


#endif