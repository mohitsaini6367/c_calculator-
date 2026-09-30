# C Calculator

A simple calculator application built in C with a Windows graphical user interface (GUI).

This project was created as a learning project to practice C programming, functions, mathematical operations, multiple source files, error handling, and Windows GUI development.

## Features

- Addition
- Subtraction
- Multiplication
- Division
- Percentage calculation
- Decimal numbers
- Negative numbers
- Positive/negative sign toggle
- Delete button
- Clear button
- Equals operation
- Chained calculations
- Divide-by-zero error handling
- Input length protection
- Windows graphical user interface
- User-friendly calculator display

## Technologies Used

- C Programming Language
- GCC Compiler
- Windows API (Win32)
- Visual Studio Code
- Windows

## Project Structure

```text
c_calculator-
│
├── main.c
├── calculator.c
├── calculator.h
└── README.md

## How to Build

Using GCC:

```bash
gcc main.c calculator.c -o calculator.exe -mwindows
