#include <stdio.h>
#include "driver/i2c.h"

#define I2C_MASTER_NUM 0
#define I2C_MASTER_TX_BUF_DISABLE   0                          
#define I2C_MASTER_RX_BUF_DISABLE   0
#define I2C_MASTER_CLOCK 100000
#define I2C_MASTER_TIMEOUT_MS 1000
#define SENSOR_ADDR 0x68  
#define LCD_SET_DDRAM_ADDR      0x80


// LCD instructions
#define LCD_CLEAR               0x01        // replace all characters with ASCII 'space'
#define LCD_HOME                0x02        // return cursor to first position on first line
#define LCD_ENTRY_MODE          0x06        // shift cursor from left to right on read/write
#define LCD_DISPLAY_OFF         0x08        // turn display off
#define LCD_DISPLAY_ON          0x0C        // display on, cursor off, don't blink character
#define LCD_FUNCTION_RESET      0x30        // reset the LCD
#define LCD_FUNCTION_SET_4BIT   0x28        // 4-bit data, 2-line display, 5 x 7 font
#define LCD_SET_CURSOR          0x80        // set cursor position


int i2c_master_port = I2C_MASTER_NUM;

static esp_err_t i2c_init() {

    i2c_config_t conf = {

        .mode = I2C_MODE_MASTER,
        .sda_io_num = 2,
        .scl_io_num = 4,
        .sda_pullup_en = GPIO_PULLUP_ENABLE,
        .scl_pullup_en = GPIO_PULLUP_ENABLE,
        .master.clk_speed = I2C_MASTER_CLOCK,

    };


    i2c_param_config(i2c_master_port, &conf);
    return i2c_driver_install(i2c_master_port, conf.mode, I2C_MASTER_RX_BUF_DISABLE, I2C_MASTER_TX_BUF_DISABLE, 0);

}

