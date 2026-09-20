# Firmware Static Analyzer

A simple firmware static analysis tool written in C.

The program reads a binary file and displays basic information about its contents without executing it.

## Features

* Opens firmware or binary files in binary mode
* Displays the file size
* Prints the first bytes in hexadecimal
* Detects several common file signatures:

  * ELF
  * gzip
  * SquashFS
* Extracts printable strings from the file
* Marks strings containing potentially interesting keywords such as:

  * `password`
  * `passwd`
  * `admin`
  * `root`
  * `ssh`
  * `telnet`
  * `busybox`
  * `token`
  * `key`

## What I practiced

* Binary file handling
* `fread`, `fseek` and `ftell`
* Working with raw bytes
* File signatures and magic bytes
* String extraction
* Basic static analysis concepts

## Build

```bash
gcc firmware-static-analyzer-main.c -o fwscan
```

## Usage

```bash
./fwscan <firmware_file>
```

Example:

```bash
./fwscan test-binary.bin
```

This project is mainly for learning C and basic firmware analysis techniques
