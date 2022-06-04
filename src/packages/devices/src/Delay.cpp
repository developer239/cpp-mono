#include <ApplicationServices/ApplicationServices.h>
#include "Delay.h"

void delay(unsigned int ms) {
  usleep(ms * 1000);
}
