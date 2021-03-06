#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>

#include "avr_i2c.h"
#include "common/i2c_common.h"

int main(void){

    // Enable global interrupts
    sei();

    I2C_init(0x50);

    volatile uint16_t x = 0;
    volatile uint16_t y = 0;

    uint16_t in_names[16];
    uint16_t in_data[16];
    uint16_t out_names[16];
    uint16_t out_data[16];

    I2C_pack_one(0xfff3, 0x8);

    while (true) {
        x++;
        if (x % 1000) {
            y++;
        }
        if (y % 10000) {
            I2C_pack_one(0xfffa, y);
        }
        I2C_pack_one(0xfffb, 0x7777);

        //if (i2c_new_data) {
            //int len = I2C_unpack(in_names, in_data);
            //for (int i=0; i<len; ++i) {
                //volatile int16_t val = restore_signed(in_data[i]);
                //printf(in_names[i], val);
            //}
        //}

        //out_names[0] = 0xfff0;
        //out_data[0] = 0x4321;
        //out_names[1] = 0xfff1;
        //out_data[1] = 0x8765;
        //I2C_pack(out_names, out_data, 2);
    }
}
