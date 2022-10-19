# dps-laboratory2

## How to install (Arch Linux)

To install Google Tests, first install the Community package with the following line:

```bash
yay -S gtest
```

The second step is to set `GTEST_INCLUDE_DIRS` env variable with the following line:

```bash
GTEST_INCLUDE_DIRS=/usr/src/googletest
```