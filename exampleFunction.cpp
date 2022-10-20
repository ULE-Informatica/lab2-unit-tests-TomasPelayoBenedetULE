#include <math.h>
#include <limits.h>
#include <stdio.h>
#include <stdint.h> 
#include "iostream"

using namespace std;

unsigned int wrapFunctionAdd(unsigned int ui_a, unsigned int ui_b) {
  // INT30-C. Ensure that unsigned integer operations do not wrap
  // URL: https://wiki.sei.cmu.edu/confluence/display/c/INT30-C.+Ensure+that+unsigned+integer+operations+do+not+wrap
  unsigned int usum;
  if (UINT_MAX - ui_a < ui_b) {
    cout << "Error in wrapFuntionAdd with wrapping!!!\nParameters:\n\tui_a=" << to_string(ui_a) << "\n\tui_b="<< to_string(ui_b) << "\n";
    usum = -1;
  }else{
    usum = ui_a + ui_b;
  }
  return usum;
}

unsigned int wrapFunctionMul(unsigned int ui_a, unsigned int ui_b) {
  unsigned umul = ui_a;
  umul *= ui_b;
  return umul;
}

uint32_t wrapFunctionShift(uint32_t ui_a, unsigned int ui_b) {
  uint32_t uShift = ui_a << ui_b | ui_a >> (32 - ui_b); 
  return uShift;
}
