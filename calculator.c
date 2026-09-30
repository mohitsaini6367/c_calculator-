#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "calculator.h"


// ========================================
// BASIC CALCULATIONS
// ========================================

double add(double a, double b)
{
    return a + b;
}


double subtract(double a, double b)
{
    return a - b;
}


double multiply(double a, double b)
{
    return a * b;
}


double divide(double a, double b)
{
    if (b == 0)
    {
        return 0;
    }

    return a / b;
}


double calculate(double a, double b, char op)
{
    switch (op)
    {
        case '+':
            return add(a, b);

        case '-':
            return subtract(a, b);

        case '*':
            return multiply(a, b);

        case '/':
            return divide(a, b);

        default:
            return 0;
    }
}


// ========================================
// DISPLAY FUNCTIONS
// ========================================

void appendDigit(char display[], char digit)
{
    int length = strlen(display);

    if (length < 99)
    {
        display[length] = digit;
        display[length + 1] = '\0';
    }
}


void clearDisplay(char display[])
{
    display[0] = '\0';
}


void deleteLast(char display[])
{
    int length = strlen(display);

    if (length > 0)
    {
        display[length - 1] = '\0';
    }
}


int addDecimal(char display[])
{
    int length = strlen(display);

    // Check if decimal already exists
    for (int i = 0; i < length; i++)
    {
        if (display[i] == '.')
        {
            return 0;
        }
    }

    // Prevent exceeding display limit
    if (length >= 99)
    {
        return 0;
    }

    display[length] = '.';
    display[length + 1] = '\0';

    return 1;
}


void toggleSign(char display[])
{
    int length = strlen(display);

    if (length == 0)
    {
        return;
    }


    // If number is already negative,
    // remove the minus sign
    if (display[0] == '-')
    {
        for (int i = 0; i < length; i++)
        {
            display[i] = display[i + 1];
        }
    }


    // Otherwise add minus sign
    else
    {
        if (length < 99)
        {
            for (int i = length; i >= 0; i--)
            {
                display[i + 1] = display[i];
            }

            display[0] = '-';
        }
    }
}


void percentage(char display[])
{
    double number;

    number = atof(display);

    number = number / 100;

    sprintf(display, "%.10g", number);
}


// ========================================
// CALCULATOR STATE
// ========================================

void calculatorInit(CalculatorState *calc)
{
    calc->display[0] = '\0';

    calc->firstNumber = 0;

    calc->operator = '\0';

    calc->hasOperator = 0;

    calc->hasResult = 0;
}


// ========================================
// DIGIT BUTTON
// ========================================

void calculatorPressDigit(CalculatorState *calc, char digit)
{
    // If previous operation produced a result,
    // start a new number
    if (calc->hasResult)
    {
        clearDisplay(calc->display);

        calc->hasResult = 0;
    }

    appendDigit(calc->display, digit);
}


// ========================================
// DECIMAL BUTTON
// ========================================

void calculatorPressDecimal(CalculatorState *calc)
{
    // If previous operation produced a result,
    // start a new number
    if (calc->hasResult)
    {
        clearDisplay(calc->display);

        calc->hasResult = 0;
    }


    // If user presses decimal first,
    // create "0."
    if (calc->display[0] == '\0')
    {
        appendDigit(calc->display, '0');
    }

    addDecimal(calc->display);
}


// ========================================
// OPERATOR BUTTON
// ========================================

void calculatorPressOperator(CalculatorState *calc, char op)
{
    // Cannot select operator without a number
    if (calc->display[0] == '\0')
    {
        return;
    }


    // Save current number
    calc->firstNumber = atof(calc->display);


    // Save operator
    calc->operator = op;


    // Tell calculator that an operator exists
    calc->hasOperator = 1;


    // Result mode is finished
    calc->hasResult = 0;


    // Clear display for second number
    clearDisplay(calc->display);
}


// ========================================
// EQUALS BUTTON
// ========================================

void calculatorPressEquals(CalculatorState *calc)
{
    double secondNumber;
    double result;


    // No operator selected
    if (!calc->hasOperator)
    {
        return;
    }


    // No second number entered
    if (calc->display[0] == '\0')
    {
        return;
    }


    // Convert display to number
    secondNumber = atof(calc->display);


    // Division by zero protection
    if (calc->operator == '/' && secondNumber == 0)
    {
        sprintf(calc->display, "Error");

        calc->hasOperator = 0;

        calc->hasResult = 1;

        return;
    }


    // Perform calculation
    result = calculate(
        calc->firstNumber,
        secondNumber,
        calc->operator
    );


    // Put result into display
    sprintf(calc->display, "%.2f", result);


    // Calculation is finished
    calc->hasOperator = 0;

    calc->hasResult = 1;
}


// ========================================
// CLEAR BUTTON
// ========================================

void calculatorPressClear(CalculatorState *calc)
{
    clearDisplay(calc->display);

    calc->firstNumber = 0;

    calc->operator = '\0';

    calc->hasOperator = 0;

    calc->hasResult = 0;
}


// ========================================
// DELETE BUTTON
// ========================================

void calculatorPressDelete(CalculatorState *calc)
{
    // Do not delete a finished result
    if (calc->hasResult)
    {
        return;
    }

    deleteLast(calc->display);
}


// ========================================
// SIGN BUTTON (+/-)
// ========================================

void calculatorPressSign(CalculatorState *calc)
{
    if (calc->display[0] == '\0')
    {
        return;
    }


    // Result can become negative/positive
    if (calc->hasResult)
    {
        calc->hasResult = 0;
    }

    toggleSign(calc->display);
}


// ========================================
// PERCENTAGE BUTTON
// ========================================

void calculatorPressPercentage(CalculatorState *calc)
{
    if (calc->display[0] == '\0')
    {
        return;
    }

    percentage(calc->display);
}
























// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include "calculator.h"

// //arthmatic oprator
// double add(double a, double b)
// {
//     return a + b;
// }

// double subtract(double a, double b)
// {
//     return a - b;
// }

// double multiply(double a, double b)
// {
//     return a * b;
// }

// double divide(double a, double b)
// {
//     if (b == 0)
//     {
//         return 0;
//     }

//     return a / b;
// }
// double calculate(double a, double b, char op)
// {
//     //case for option selection
//       switch (op)
//     {
//         case '+':
//             return add(a, b);

//         case '-':
//             return subtract(a, b);

//         case '*':
//             return multiply(a, b);

//         case '/':
//             return divide(a, b);

//         default:
//             return 0;
//     }
// }
//  //thired formation(((use this for display number only not like enter first number or seconed and oprater sign)))
// void appendDigit(char display[], char digit)
//     {
//        int length = strlen(display);

//         if (length < 99)
//         {
//              display[length] = digit;
//              display[length + 1] = '\0';
//         }
//     }
// void clearDisplay(char display[])
//     {
//          display[0]= '\0';
//     }
// void deleteLast(char display[])
//     {
//         int lenght = strlen(display);
//         if (lenght > 0)
//         {
//             display[lenght - 1] = '\0';
//         }
//     }
// int addDecimal(char display[])
//     {
//         int length = strlen(display);
//         for (int i = 0; i < length; i++)
//         {
//             if (display[i] == '.')
//             {
//                 return 0; 
//             }
//         }
//         display[length] = '.';
//         display[length + 1] = '\0';

//         return 1; 
//     }
// // void startOperation(char display[], double *firstNumber, char *op)
// //     {
// //         *firstNumber = atof(display);
// //         *op = *op;

// //         clearDisplay(display);
// //     }
// int pressEquals(char display[], double firstNumber, char op)
// {
//     double secondNumber;
//     double result;

//     secondNumber = atof(display);

//     if (op == '/' && secondNumber == 0)
//     {
//         sprintf(display, "Error");
//         return 0;
//     }

//     result = calculate(firstNumber, secondNumber, op);

//     sprintf(display, "%.2f", result);

//     return 1;
// }
//     void pressOperator(char display[], double *firstNumber, char *op, char newOp)   
//         {
//             *firstNumber = atof(display);

//             *op = newOp;

//             clearDisplay(display);
//         }
//     void toggleSign(char display[])
//         {
//             int length = strlen(display);

//             if (length == 0)
//             {
//                 return;
//             }

//             if (display[0] == '-')
//             {
//                 for (int i = 0; i < length; i++)
//                 {
//                     display[i] = display[i + 1];
//                 }
//             }
//             else
//             {
//                 if (length < 99)
//                 {
//                     for (int i = length; i >= 0; i--)
//                     {
//                         display[i + 1] = display[i];
//                     }

//                     display[0] = '-';
//                 }
//             }
//         }
//     void percentage(char display[])
//         {
//             double number;

//             number = atof(display);

//             number = number / 100;

//             sprintf(display, "%.10g", number);
//         }

//     void calculatorInit(CalculatorState *calc)
//         {
//             calc->display[0] = '\0';

//             calc->firstNumber = 0;

//             calc->operator = '\0';

//             calc->hasOperator = 0;
//             calc->hasResult = 0;
//         }
//     void calculatorPressEquals(CalculatorState *calc)
//         {
//             double secondNumber;
//             double result;

//             if (!calc->hasOperator)
//             {
//                 return;
//             }

//             if (calc->display[0] == '\0')
//             {
//                 return;
//             }

//             secondNumber = atof(calc->display);

//             if (calc->operator == '/' && secondNumber == 0)
//             {
//                 sprintf(calc->display, "Error");

//                 calc->hasOperator = 0;
//                 calc->hasResult = 1;

//                 return;
//             }

//             result = calculate(
//                 calc->firstNumber,
//                 secondNumber,
//                 calc->operator
//             );

//             sprintf(calc->display, "%.2f", result);

//             calc->hasOperator = 0;
//             calc->hasResult = 1;
//         }
//      void calculatorPressDelete(CalculatorState *calc)
//             {
//                 if (calc->hasResult)
//                 {
//                     return;
//                 }

//                 deleteLast(calc->display);
//             }

    