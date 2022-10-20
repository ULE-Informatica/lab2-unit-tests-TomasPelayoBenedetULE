# DPS-laboratory2

## How to install Google Tests (Arch Linux)

To install Google Tests, first install the Community package with the following line:

```bash
yay -S gtest
```

The second step is to set `GTEST_INCLUDE_DIRS` env variable with the following line:

```bash
GTEST_INCLUDE_DIRS=/usr/src/googletest
```

Now, GTest is installed

## How to run

There are a script that compile the exercise:

```bash
./compile.sh
```

Then to exec the binary generated:

```bash
./runTests
```

## Work done

### wrapFunctionAdd

Added a condition that matches when it's gonna be a wrapping with unsigned ints. Following this [link (INT30-C)](https://wiki.sei.cmu.edu/confluence/display/c/INT30-C.+Ensure+that+unsigned+integer+operations+do+not+wrap) we can find this scheme:

```cpp
void func(unsigned int ui_a, unsigned int ui_b) {
  unsigned int usum;
  if (UINT_MAX - ui_a < ui_b) {
    /* Handle error */
  } else {
    usum = ui_a + ui_b;
  }
  /* ... */
}
```

It has been written the following lines in our exercise:

```cpp
  unsigned int usum;
  if (UINT_MAX - ui_a < ui_b) {
    cout << "Error in wrapFuntionAdd with unsigned int wrapping!!!\nParameters:\n\tui_a=" << to_string(ui_a) << "\n\tui_b="<< to_string(ui_b) << "\n";
    usum = -1;
  }else{
    usum = ui_a + ui_b;
  }
  return usum;
```

### wrapFunctionMul

Added a condition that matches when it's gonna be a wrapping with multiplication. It has been followed in the same way as the previous function
It has been written the following lines in our exercise:

```cpp
  unsigned umul = ui_a;

  if (UINT_MAX / ui_a < ui_b) {
    cout << "Error in wrapFunctionMul with unsigned int wrapping!!!\nParameters:\n\tui_a=" << to_string(ui_a) << "\n\tui_b="<< to_string(ui_b) << "\n";
    umul = -1;
  }else{
    umul *= ui_b;
  }
  
  return umul;
```

Now appears a new problem, with the condition:

```cpp
  ...
  if (UINT_MAX / ui_a < ui_b) {
  ...
```

The problem appears when `ui_a` i 0, because there's a division by 0. Following this [link (INT33-C)](https://wiki.sei.cmu.edu/confluence/display/c/INT33-C.+Ensure+that+division+and+remainder+operations+do+not+result+in+divide-by-zero+errors) we can find this scheme:

```cpp
void func(signed long s_a, signed long s_b) {
  signed long result;
  if (s_b == 0) {
    /* Handle error */
  } else {
    result = s_a / s_b;
  }
  /* ... */
}
```

It's added a condition so `ui_a` is not 0, as is it presented in the following lines:

```cpp
  unsigned umul = ui_a;
  
  if (ui_a == 0) { 
    return 0;
  }

  if (UINT_MAX / ui_a < ui_b) {
  ...
```

### wrapFunctionShift

Added a condition that matches when it's gonna be a wrapping with shifting. Following this [link (INT34-C)](https://wiki.sei.cmu.edu/confluence/display/c/INT34-C.+Do+not+shift+an+expression+by+a+negative+number+of+bits+or+by+greater+than+or+equal+to+the+number+of+bits+that+exist+in+the+operand) we can find this two schemes, one for left shifting and other one for right shifting:


```cpp
extern size_t popcount(uintmax_t);
#define PRECISION(x) popcount(x)
  
void func(unsigned int ui_a, unsigned int ui_b) {
  unsigned int uresult = 0;
  if (ui_b >= PRECISION(UINT_MAX)) {
    /* Handle error */
  } else {
    uresult = ui_a << ui_b;
  }
  /* ... */
}
```

```cpp
extern size_t popcount(uintmax_t);
#define PRECISION(x) popcount(x)
  
void func(unsigned int ui_a, unsigned int ui_b) {
  unsigned int uresult = 0;
  if (ui_b >= PRECISION(UINT_MAX)) {
    /* Handle error */
  } else {
    uresult = ui_a >> ui_b;
  }
  /* ... */
}
```

In this case, popcount is no aviable for our version of C++ but we have `__builtin_popcount`, this do the same thing, no differences.

Because of efficiency, there are a constant variable that have the value of the funcion in `UINT32_MAX` that is the maxium value of an `uint32_t`.

It has been written the following lines in our exercise:

```cpp
const int popcount_var =__builtin_popcount(UINT32_MAX);
  ...
  uint32_t uShift = -1; 
  
  if (ui_b >= popcount_var) {
    cout << "Error in wrapFunctionShift!!!\nParameters:\n\tui_a=" << to_string(ui_a) << "\n\tui_b="<< to_string(ui_b) << "\n";
  } else {
    uShift = ui_a << ui_b | ui_a >> (32 - ui_b); 
  }

  return uShift;
```

### Test fix

To complete the exercise and pass with an `OK` all of tests it's necesary to do some changes in `tests.cpp`.

The first one is in the second test, it's necesary to put an `-1` instead of `0`, because now addition wrapping is fixed.

```cpp
TEST(wrapAddFunctionTest, WrappingNums) {
  ASSERT_EQ(-1, wrapFunctionAdd(UINT_MAX,1));
}
```

The second one is the fourth test, it's necesary to put an `-1` instead of `1`, because now multiplication wrapping is fixed.

```cpp
TEST(wrapMulFunctionTest, WrappingMulNums) {
    ASSERT_EQ(-1, wrapFunctionMul(UINT_MAX, UINT_MAX));
}
```