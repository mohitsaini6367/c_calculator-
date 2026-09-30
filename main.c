#include <windows.h>
#include "calculator.h"


// ========================================
// CONTROL IDs
// ========================================

#define ID_DISPLAY 100

#define ID_0 200
#define ID_1 201
#define ID_2 202
#define ID_3 203
#define ID_4 204
#define ID_5 205
#define ID_6 206
#define ID_7 207
#define ID_8 208
#define ID_9 209

#define ID_DECIMAL 210
#define ID_EQUALS 211

#define ID_ADD 212
#define ID_SUBTRACT 213
#define ID_MULTIPLY 214
#define ID_DIVIDE 215

#define ID_CLEAR 216
#define ID_DELETE 217
#define ID_PERCENT 218
#define ID_SIGN 219


// ========================================
// GLOBAL VARIABLES
// ========================================

HWND displayBox;

CalculatorState calculator;


// ========================================
// UPDATE DISPLAY
// ========================================

void updateDisplay(void)
{
    if (displayBox != NULL)
    {
        SetWindowText(
            displayBox,
            calculator.display
        );
    }
}


// ========================================
// CREATE BUTTON
// ========================================

void createButton(
    HWND hwnd,
    const char *text,
    int id,
    int x,
    int y,
    int width,
    int height
)
{
    CreateWindow(
        "BUTTON",
        text,
        WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
        x,
        y,
        width,
        height,
        hwnd,
        (HMENU)(INT_PTR)id,
        GetModuleHandle(NULL),
        NULL
    );
}


// ========================================
// WINDOW PROCEDURE
// ========================================

LRESULT CALLBACK WindowProc(
    HWND hwnd,
    UINT uMsg,
    WPARAM wParam,
    LPARAM lParam
)
{
    switch (uMsg)
    {
        // ====================================
        // CREATE
        // ====================================

        case WM_CREATE:
        {
            displayBox = CreateWindow(
                "EDIT",
                "",
                WS_VISIBLE |
                WS_CHILD |
                WS_BORDER |
                ES_RIGHT |
                ES_READONLY,
                20,
                20,
                340,
                55,
                hwnd,
                (HMENU)(INT_PTR)ID_DISPLAY,
                GetModuleHandle(NULL),
                NULL
            );


            // =================================
            // ROW 1
            // =================================

            createButton(hwnd, "C",
                ID_CLEAR,
                20, 90, 80, 50);

            createButton(hwnd, "DEL",
                ID_DELETE,
                110, 90, 80, 50);

            createButton(hwnd, "%",
                ID_PERCENT,
                200, 90, 80, 50);

            createButton(hwnd, "/",
                ID_DIVIDE,
                290, 90, 70, 50);


            // =================================
            // ROW 2
            // =================================

            createButton(hwnd, "7",
                ID_7,
                20, 150, 80, 50);

            createButton(hwnd, "8",
                ID_8,
                110, 150, 80, 50);

            createButton(hwnd, "9",
                ID_9,
                200, 150, 80, 50);

            createButton(hwnd, "*",
                ID_MULTIPLY,
                290, 150, 70, 50);


            // =================================
            // ROW 3
            // =================================

            createButton(hwnd, "4",
                ID_4,
                20, 210, 80, 50);

            createButton(hwnd, "5",
                ID_5,
                110, 210, 80, 50);

            createButton(hwnd, "6",
                ID_6,
                200, 210, 80, 50);

            createButton(hwnd, "-",
                ID_SUBTRACT,
                290, 210, 70, 50);


            // =================================
            // ROW 4
            // =================================

            createButton(hwnd, "1",
                ID_1,
                20, 270, 80, 50);

            createButton(hwnd, "2",
                ID_2,
                110, 270, 80, 50);

            createButton(hwnd, "3",
                ID_3,
                200, 270, 80, 50);

            createButton(hwnd, "+",
                ID_ADD,
                290, 270, 70, 50);


            // =================================
            // ROW 5
            // =================================

            createButton(hwnd, "+/-",
                ID_SIGN,
                20, 330, 80, 50);

            createButton(hwnd, "0",
                ID_0,
                110, 330, 80, 50);

            createButton(hwnd, ".",
                ID_DECIMAL,
                200, 330, 80, 50);

            createButton(hwnd, "=",
                ID_EQUALS,
                290, 330, 70, 50);


            return 0;
        }


        // ====================================
        // BUTTON CLICK
        // ====================================

        case WM_COMMAND:
        {
            int id = LOWORD(wParam);
            int event = HIWORD(wParam);


            // Only handle actual button clicks
            if (event != BN_CLICKED)
            {
                return 0;
            }


            // =================================
            // DIGITS
            // =================================

            switch (id)
            {
                case ID_0:
                    calculatorPressDigit(
                        &calculator, '0');
                    break;

                case ID_1:
                    calculatorPressDigit(
                        &calculator, '1');
                    break;

                case ID_2:
                    calculatorPressDigit(
                        &calculator, '2');
                    break;

                case ID_3:
                    calculatorPressDigit(
                        &calculator, '3');
                    break;

                case ID_4:
                    calculatorPressDigit(
                        &calculator, '4');
                    break;

                case ID_5:
                    calculatorPressDigit(
                        &calculator, '5');
                    break;

                case ID_6:
                    calculatorPressDigit(
                        &calculator, '6');
                    break;

                case ID_7:
                    calculatorPressDigit(
                        &calculator, '7');
                    break;

                case ID_8:
                    calculatorPressDigit(
                        &calculator, '8');
                    break;

                case ID_9:
                    calculatorPressDigit(
                        &calculator, '9');
                    break;


                // =================================
                // DECIMAL
                // =================================

                case ID_DECIMAL:
                    calculatorPressDecimal(
                        &calculator);
                    break;


                // =================================
                // OPERATORS
                // =================================

                case ID_ADD:
                    calculatorPressOperator(
                        &calculator, '+');
                    break;

                case ID_SUBTRACT:
                    calculatorPressOperator(
                        &calculator, '-');
                    break;

                case ID_MULTIPLY:
                    calculatorPressOperator(
                        &calculator, '*');
                    break;

                case ID_DIVIDE:
                    calculatorPressOperator(
                        &calculator, '/');
                    break;


                // =================================
                // EQUALS
                // =================================

                case ID_EQUALS:
                    calculatorPressEquals(
                        &calculator);
                    break;


                // =================================
                // CLEAR
                // =================================

                case ID_CLEAR:
                    calculatorPressClear(
                        &calculator);
                    break;


                // =================================
                // DELETE
                // =================================

                case ID_DELETE:
                    calculatorPressDelete(
                        &calculator);
                    break;


                // =================================
                // SIGN
                // =================================

                case ID_SIGN:
                    calculatorPressSign(
                        &calculator);
                    break;


                // =================================
                // PERCENT
                // =================================

                case ID_PERCENT:
                    calculatorPressPercentage(
                        &calculator);
                    break;


                default:
                    return 0;
            }


            // Update display
            updateDisplay();

            return 0;
        }


        // ====================================
        // CLOSE WINDOW
        // ====================================

        case WM_DESTROY:
        {
            PostQuitMessage(0);
            return 0;
        }
    }


    return DefWindowProc(
        hwnd,
        uMsg,
        wParam,
        lParam
    );
}


// ========================================
// PROGRAM START
// ========================================

int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow
)
{
    const char CLASS_NAME[] =
        "CalculatorWindow";


    // ====================================
    // INITIALIZE CALCULATOR
    // ====================================

    calculatorInit(
        &calculator
    );


    // ====================================
    // WINDOW CLASS
    // ====================================

    WNDCLASS wc = {0};

    wc.lpfnWndProc = WindowProc;

    wc.hInstance = hInstance;

    wc.lpszClassName =
        CLASS_NAME;

    wc.hCursor =
        LoadCursor(
            NULL,
            IDC_ARROW
        );

    wc.hbrBackground =
        (HBRUSH)(COLOR_WINDOW + 1);


    // ====================================
    // REGISTER WINDOW
    // ====================================

    if (!RegisterClass(&wc))
    {
        MessageBox(
            NULL,
            "RegisterClass failed!",
            "Error",
            MB_OK | MB_ICONERROR
        );

        return 0;
    }


    // ====================================
    // CREATE WINDOW
    // ====================================

    HWND hwnd = CreateWindowEx(
        0,
        CLASS_NAME,
        "C Calculator",
        WS_OVERLAPPED |
        WS_CAPTION |
        WS_SYSMENU |
        WS_MINIMIZEBOX,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        400,
        450,
        NULL,
        NULL,
        hInstance,
        NULL
    );


    if (hwnd == NULL)
    {
        MessageBox(
            NULL,
            "CreateWindowEx failed!",
            "Error",
            MB_OK | MB_ICONERROR
        );

        return 0;
    }


    // ====================================
    // SHOW WINDOW
    // ====================================

    ShowWindow(
        hwnd,
        nCmdShow
    );

    UpdateWindow(hwnd);


    // ====================================
    // MESSAGE LOOP
    // ====================================

    MSG msg;

    while (
        GetMessage(
            &msg,
            NULL,
            0,
            0
        ) > 0
    )
    {
        TranslateMessage(&msg);

        DispatchMessage(&msg);
    }


    return 0;
}