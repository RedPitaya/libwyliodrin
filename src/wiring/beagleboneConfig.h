/**************************************************************************************************
 * Author: Razvan Madalin MATEI <matei.rm94@gmail.com>
 * Date last modified: July 2014
 *
 * This file contains the declarations of all configuration functions for the BeagleBone Black.
 *
 * CONTENT:
 * 1.Constants
 * 2.General
 * 3.Device Tree
 * 4.GPIO
 * 5.User LEDs
 * 6.PWM
 * 7.AIN
 *************************************************************************************************/

#ifndef BEAGLEBONE_CONFIG_H
#define BEAGLEBONE_CONFIG_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif



/**************************************************************************************************
 * 1.Constants
 *************************************************************************************************/

#define MAX_BUF 64

// Paths
#define SYSFS_GPIO_DIR "/sys/class/gpio"
#define SYSFS_LEDS_DIR "/sys/class/leds"
#define SYSFS_PWM_DIR  "/sys/class/pwm"

// Direction
#define INPUT  0
#define OUTPUT 1

// Value
#define LOW  0
#define HIGH 1

// Edge
#define NONE    0
#define RISING  1
#define FALLING 2
#define BOTH    3

// Trigger
#define NONE        0
#define NAND_DISK   1
#define MMC0        2
#define MMC1        3
#define TIMER       4
#define ONESHOT     5
#define HEARTBEAT   6
#define BACKLIGHT   7
#define GPIO        8
#define CPU0        9
#define DEFAULT_ON 10
#define TRANSIENT  11

#define isLed(gpio) (53 <= (gpio) && (gpio) <= 56)

typedef unsigned char byte;
typedef unsigned int  uint;
typedef unsigned long ulong;

typedef struct pin_t {
  const char *name;
  const char *key;
  byte gpio;
  byte pwmMuxMode;
  byte ain;
  byte isAllocatedByDefault;
} pin_t;

typedef struct pwmNode_t {
  const char *key;
  const char *pathPwmTest;

  struct pwmNode_t *next;
} pwmNode_t;

typedef enum {
  ERROR   = 0,
  SUCCESS = 1
} result_t;



/**************************************************************************************************
 * 2.General
 *************************************************************************************************/

#define DEBUG 1
#define debug(...)                                                                 \
  do {                                                                             \
    if (DEBUG) {                                                                   \
      fprintf(stderr, "Debug alert in file %s at line %d:\n", __FILE__, __LINE__); \
      fprintf(stderr, __VA_ARGS__);                                                \
      fprintf(stderr, "\n");                                                       \
      perror(NULL);                                                                \
    }                                                                              \
  } while (0)                                                                      \

result_t buildPath (const char *dirPath, const char *prefix, char *fullPath, int fullPathLen);



/**************************************************************************************************
 * 3.Device Tree
 *************************************************************************************************/

result_t loadDeviceTree   (const char *name);
result_t unloadDeviceTree (const char *name);



/**************************************************************************************************
 * 4.GPIO
 *************************************************************************************************/

void        beagleTest       ();

byte        getGpioByName    (const char *name);
byte        getGpioByKey     (const char *key);
const char* getKeyByGpio     (byte gpio);

bool        gpioIsValid      (byte gpio);
bool        gpioIsExported   (byte gpio);

void        gpioExport       (byte gpio);
void        gpioUnexport     (byte gpio);

void        gpioSetDir       (byte gpio, byte dir);
byte        gpioGetDir       (byte gpio);

void        gpioSetValue     (byte gpio, byte value);
byte        gpioGetValue     (byte gpio);

void        gpioSetActiveLow (byte gpio, byte value);
byte        gpioGetActiveLow (byte gpio);

void        gpioSetEdge      (byte gpio, byte edge);
byte        gpioGetEdge      (byte gpio);



/**************************************************************************************************
 * 5.User LEDs
 *************************************************************************************************/

void   ledSetTrigger (byte gpio, byte trigger);

void   ledSetValue   (byte gpio, byte value);
byte   ledGetValue   (byte gpio);

void   ledReset      (byte gpio);



/**************************************************************************************************
 * 6.PWM
 *************************************************************************************************/

void       pwmInit        ();
bool       pwmIsValid     (byte gpio);
pwmNode_t* pwmGetPin      (const char *key);

result_t   pwmEnable      (const char *key);
result_t   pwmDisable     (const char *key);

result_t   pwmSetPeriod   (const char *key, ulong period);
ulong      pwmGetPeriod   (const char *key);

result_t   pwmSetDuty     (const char *key, ulong duty);
ulong      pwmGetDuty     (const char *key);

result_t   pwmSetPolarity (const char *key, byte polarity);
byte       pwmGetPolarity (const char *key);

result_t   pwmSetRun      (const char* key, byte run);
byte       pwmGetRun      (const char* key);



/**************************************************************************************************
 * 7.AIN
 *************************************************************************************************/

void ainInit     ();
int  ainGetValue (byte ain);




#ifdef __cplusplus
}
#endif

#endif // BEAGLEBONE_CONFIG_H
