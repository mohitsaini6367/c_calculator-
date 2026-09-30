// #ifndef CALCULATOR_H
// #define CALCULATOR_H

// //primery operations
// double add(double a, double b);
// double subtract(double a, double b);
// double multiply(double a, double b);
// double divide(double a, double b);

// //2nd step formation

// double calculate(double a, double b, char op);
// //the 3rd step formation

// void appendDigit(char display[], char digit);
// void clearDisplay(char display[]);
// void deleteLast(char display[]);

// int addDecimal(char display[]);

// // void startOperation(char display[], double *firstNumber, char *op);
// // double finishOperation(char display[], double firstNumber, char op);

// int pressEquals(char display[], double firstNumber, char op);
// void pressOperator(char display[], double *firstNumber, char *op, char newOp);

// void toggleSign(char display[]);


// void percentage(char display[]);


// #endif 


#ifndef CALCULATOR_H
#define CALCULATOR_H


// ========================================
// CALCULATOR STATE
// ========================================

typedef struct
{
    char display[100];

    double firstNumber;

    char operator;

    int hasOperator;
    int hasResult;

} CalculatorState;


// ========================================
// BASIC CALCULATIONS
// ========================================

double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

double calculate(double a, double b, char op);


// ========================================
// DISPLAY FUNCTIONS
// ========================================

void appendDigit(char display[], char digit);
void clearDisplay(char display[]);
void deleteLast(char display[]);
void toggleSign(char display[]);

int addDecimal(char display[]);

void percentage(char display[]);


// ========================================
// CALCULATOR STATE FUNCTIONS
// ========================================

void calculatorInit(CalculatorState *calc);

void calculatorPressDigit(
    CalculatorState *calc,
    char digit
);

void calculatorPressDecimal(
    CalculatorState *calc
);

void calculatorPressOperator(
    CalculatorState *calc,
    char op
);

void calculatorPressEquals(
    CalculatorState *calc
);

void calculatorPressClear(
    CalculatorState *calc
);

void calculatorPressDelete(
    CalculatorState *calc
);

void calculatorPressSign(
    CalculatorState *calc
);

void calculatorPressPercentage(
    CalculatorState *calc
);


#endif
