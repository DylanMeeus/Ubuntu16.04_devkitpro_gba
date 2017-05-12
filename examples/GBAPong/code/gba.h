#ifndef GBA_H
#define GBA_H

#define REG_DISPLAYCONTROL *((volatile uint32*) (0x04000000))
#define VIDEO_MODE  0x0003
#define BG_MODE  0x0400
#define SCREEN_BUFFER ((volatile uint16*)0x06000000)
#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 160
#define REG_VCOUNT      (* (volatile uint16*) 0x04000006) // current row being drawn by hardware

// locate vram
#define MEM_VRAM        0x06000000
#define vid_mem         ((uint16*)MEM_VRAM)





#endif