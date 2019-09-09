# Camellia library for Arduino

This project is a library for the [Arduino](http://arduino.cc) platform. It
provides a simple interface to the
[Camellia Cipher](https://info.isl.ntt.co.jp/crypt/eng/camellia/source.html).   
It allows on Arduino IDE based projects to encrypt/decrypt 128 bit block.

## Features

Of the features on the Camellia Cipher, this library provides support for:

* Setting a secret key of either 128, 192, 256 bit.
* Encrypting 128bit block data with the generated secret key.
* Decrypting 128bit block data with the generated secret key.

## Examples and documentation

The [header file](Camellia.h) is well-commented, and the [examples](examples)
directory contains example sketches for immediate use.

## Installing

Place the `CamelliaLib` directory in the `libraries` subdirectory of your Arduino
sketch directory. On OS X, for example, your sketch directory might be:

    /Users/you/Documents/Arduino

In that case, you should put the `CamelliaLib` directory at:

    /Users/you/Documents/Arduino/libraries/CamelliaLib
