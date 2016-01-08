#ifdef UDOONEO



/*** INCLUDES ************************************************************************************/

#include <stdint.h> /* integers */
#include <unistd.h> /* usleep   */

#include "debug.h"

/*************************************************************************************************/



#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */



/*** API IMPLEMENTATION **************************************************************************/

int wiringSetup() {
  /* Do nothing */

  return 0;
}

void pinReset(int pin) {
  /* Do nothing */
}

void pinMode(int pin, int mode) {

}

void digitalWrite   (int pin, int value) {

}

int  digitalRead    (int pin) {
  syserror(1 == 1, return 0, "digitalRead %d", 3);
  return 0;
}

void analogWrite    (int pin, int value) {

}

int  analogRead     (int pin) {
  return 0;
}

int  analogReadRaw  (int pin) {
  return 0;
}

void analogWriteRaw (int pin, int value) {

}

/* Advanced I/O */
void          shiftOut (uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val) {

}

uint8_t       shiftIn  (uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder) {
  return 0;
}

unsigned long pulseIn  (uint8_t pin, uint8_t state) {
  return 0;
}

/* Time */
void delay(unsigned int milliseconds) {
  usleep(milliseconds * 1000);
}

void delayMicroseconds(unsigned int microseconds) {
  usleep(microseconds);
}

unsigned int millis    (void) {
  return 0;
}

unsigned int micros    (void) {
  return 0;
}

int             spi_getadapter    (uint32_t spi_bus_address) {
  return 0;
}

int             spi_openadapter   (uint8_t spi_bus) {
  return 0;
}

int             spi_setmode       (int spiId, unsigned short mode) {
  return 0;
}

int             spi_set_frequency (int spiId, int freq) {
  return 0;
}

uint8_t         spi_writebyte     (int spiId, uint8_t byte) {
  return 0;
}

unsigned char * spi_writebytes    (int spiId, uint8_t *bytes, uint8_t length) {
  return NULL;
}

int             spi_lsb_mode      (int spiId, unsigned char lsb) {
  return 0;
}

int             spi_bit_per_word  (int spiId, unsigned int bits) {
  return 0;
}

int             spi_closeadapter  (int spiId) {
  return 0;
}

int i2c_openadapter  (uint8_t i2c_bus) {
  return 0;
}

int i2c_setslave     (int i2cId, uint8_t addr) {
  return 0;
}

int i2c_writebyte    (int i2cId, uint8_t byte) {
  return 0;
}

int i2c_writebytes   (int i2cId, uint8_t *bytes, uint8_t length) {
  return 0;
}

int i2c_readbyte     (int i2cId) {
  return 0;
}

int i2c_closeadapter (int i2cId) {
  return 0;
}

int i2c_readbytes    (int i2cId, uint8_t *buf, int length) {
  return 0;
}

int i2c_readwrite    (int i2cId) {
  return 0;
}



int     serial_openadapter     (char *serial_bus) {
  return 0;
}

int     serial_set_speed       (int serial_id, int baud) {
  return 0;
}

int     serial_bytes_available (int serial_id) {
  return 0;
}

int     serial_closeadapter    (int serial_id) {
  return 0;
}

int     serial_writebyte       (int serial_id, uint8_t byte) {
  return 0;
}

int     serial_writebytes      (int serial_id, uint8_t *bytes, uint8_t length) {
  return 0;
}

uint8_t serial_readbyte        (int serial_id) {
  return 0;
}

int     serial_readbytes       (int serial_id, uint8_t *buf, int length) {
  return 0;
}

int     serial_flush           (int serial_id) {
  return 0;
}

/*************************************************************************************************/



#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* UDOONEO */
