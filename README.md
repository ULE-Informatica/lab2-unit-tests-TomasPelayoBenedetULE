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

```
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

```
  unsigned int usum;
  if (UINT_MAX - ui_a < ui_b) {
    cout << "Error in wrapFuntionAdd with wrapping!!!\nParameters:\n\tui_a=" << to_string(ui_a) << "\n\tui_b="<< to_string(ui_b) << "\n";
    usum = -1;
  }else{
    usum = ui_a + ui_b;
  }
  return usum;
```