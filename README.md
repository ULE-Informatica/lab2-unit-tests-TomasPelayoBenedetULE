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

Added a condition that matches when it's gonna be a wrapping with unsigned ints. Following this [link](https://wiki.sei.cmu.edu/confluence/display/c/INT30-C.+Ensure+that+unsigned+integer+operations+do+not+wrap) we can find this scheme:

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

Added a condition that matches when it's gonna be a wrapping with unsigned ints. It has been followed in the same way as the previous function
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

The problem appears when `ui_a` i 0, because there's a division by 0. Following this [link](https://wiki.sei.cmu.edu/confluence/display/c/INT30-C.+Ensure+that+unsigned+integer+operations+do+not+wrap) we can find this scheme:

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

So we add a condition so `ui_a` is not 0, as is it presented in the following lines:

```cpp
  unsigned umul = ui_a;
  
  if (ui_a == 0) { 
    return 0;
  }

  if (UINT_MAX / ui_a < ui_b) {
  ...
```

### wrapFunctionShift

### Test fix