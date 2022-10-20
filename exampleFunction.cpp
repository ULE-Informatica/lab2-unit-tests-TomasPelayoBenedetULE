#include <math.h>
#include <limits.h>
#include <stdio.h>
#include <stdint.h>
#include <bit> 
#include "iostream"

using namespace std;

unsigned int wrapFunctionAdd(unsigned int ui_a, unsigned int ui_b) {
  // INT30-C. Ensure that unsigned integer operations do not wrap
  // URL: https://wiki.sei.cmu.edu/confluence/display/c/INT30-C.+Ensure+that+unsigned+integer+operations+do+not+wrap
  unsigned int usum;
  if (UINT_MAX - ui_a < ui_b) {
    cout << "Error in wrapFuntionAdd with unsigned int wrapping!!!\nParameters:\n\tui_a=" << to_string(ui_a) << "\n\tui_b="<< to_string(ui_b) << "\n";
    usum = -1;
  }else{
    usum = ui_a + ui_b;
  }
  return usum;
}

unsigned int wrapFunctionMul(unsigned int ui_a, unsigned int ui_b) {
  unsigned umul = ui_a;
  
  // INT33-C. Ensure that division and remainder operations do not result in divide-by-zero errors
  // URL: https://wiki.sei.cmu.edu/confluence/display/c/INT33-C.+Ensure+that+division+and+remainder+operations+do+not+result+in+divide-by-zero+errors
  if (ui_a == 0) { 
    return 0;
  }

  // INT30-C. Ensure that unsigned integer operations do not wrap
  // URL: https://wiki.sei.cmu.edu/confluence/display/c/INT30-C.+Ensure+that+unsigned+integer+operations+do+not+wrap
  if (UINT_MAX / ui_a < ui_b) {
    cout << "Error in wrapFunctionMul with unsigned int wrapping!!!\nParameters:\n\tui_a=" << to_string(ui_a) << "\n\tui_b="<< to_string(ui_b) << "\n";
    umul = -1;
  }else{
    umul *= ui_b;
  }
  
  return umul;
}

// Const variable to keep efficiency
const int popcount_var =__builtin_popcount(UINT32_MAX);

uint32_t wrapFunctionShift(uint32_t ui_a, unsigned int ui_b) {

  uint32_t uShift = -1; 

  // INT34-C. Do not shift an expression by a negative number of bits or by greater than or equal to the number of bits that exist in the operand
  // URL:s https://wiki.sei.cmu.edu/confluence/display/c/INT34-C.+Do+not+shift+an+expression+by+a+negative+number+of+bits+or+by+greater+than+or+equal+to+the+number+of+bits+that+exist+in+the+operand
  if (ui_b >= popcount_var) {
    cout << "Error in wrapFunctionShift!!!\nParameters:\n\tui_a=" << to_string(ui_a) << "\n\tui_b="<< to_string(ui_b) << "\n";
  } else {
    uShift = ui_a << ui_b | ui_a >> (32 - ui_b); 
  }

  return uShift;
}
