#include "print.h"
unsigned char port_byte_in(uint16_t port) {
    unsigned char result;
    asm("in %%dx, %%al" : "=a" (result) : "d" (port));
    return result;
}
char* print_letter(uint8_t scancode) {
    switch (scancode) {
        case 0x0:
            return  "ERROR";
            break;
        case 0x1:
            return  "ESC";
            break;
        case 0x2:
            return  "1";
            break;
        case 0x3:
            return  "2";
            break;
        case 0x4:
            return  "3";
            break;
        case 0x5:
            return  "4";
            break;
        case 0x6:
            return  "5";
            break;
        case 0x7:
            return  "6";
            break;
        case 0x8:
            return  "7";
            break;
        case 0x9:
            return  "8";
            break;
        case 0x0A:
            return  "9";
            break;
        case 0x0B:
            return  "0";
            break;
        case 0x0C:
            return  "-";
            break;
        case 0x0D:
            return  "+";
            break;
        case 0x0E:
            return  "\033";
            break;
        case 0x0F:
            return  "Tab";
            break;
        case 0x10:
            return  "Q";
            break;
        case 0x11:
            return  "W";
            break;
        case 0x12:
            return  "E";
            break;
        case 0x13:
            return  "R";
            break;
        case 0x14:
            return  "T";
            break;
        case 0x15:
            return  "Y";
            break;
        case 0x16:
            return  "U";
            break;
        case 0x17:
            return  "I";
            break;
        case 0x18:
            return  "O";
            break;
        case 0x19:
            return  "P";
            break;
        case 0x1A:
            return  "[";
            break;
        case 0x1B:
            return  "]";
            break;
        case 0x1C:
            return  "\n";
            break;
        case 0x1D:
            return  "LCtrl";
            break;
        case 0x1E:
            return  "A";
            break;
        case 0x1F:
            return  "S";
            break;
        case 0x20:
            return  "D";
            break;
        case 0x21:
            return  "F";
            break;
        case 0x22:
            return  "G";
            break;
        case 0x23:
            return  "H";
            break;
        case 0x24:
            return  "J";
            break;
        case 0x25:
            return  "K";
            break;
        case 0x26:
            return  "L";
            break;
        case 0x27:
            return  ";";
            break;
        case 0x28:
            return  "'";
            break;
        case 0x29:
            return  "`";
            break;
        case 0x2A:
            return  "LShift";
            break;
        case 0x2B:
            return  "\\";
            break;
        case 0x2C:
            return  "Z";
            break;
        case 0x2D:
            return  "X";
            break;
        case 0x2E:
            return  "C";
            break;
        case 0x2F:
            return  "V";
            break;
        case 0x30:
            return  "B";
            break;
        case 0x31:
            return  "N";
            break;
        case 0x32:
            return  "M";
            break;
        case 0x33:
            return  ",";
            break;
        case 0x34:
            return  ".";
            break;
        case 0x35:
            return  "/";
            break;
        case 0x36:
            return  "Rshift";
            break;
        case 0x37:
            return  "Keypad *";
            break;
        case 0x38:
            return "LAlt";
            break;
        case 0x39:
            return " ";
            break;
        default:
            return "";
    }
}
static char* keyboard_callback() {
    uint8_t scancode = port_byte_in(0x60);
    return print_letter(scancode);
}
void kernel_main() {
    print_clear();
    print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
    print("Welcome to Antartic Operating System!\n");
    char* keyPrev = "";
    while (1) {
        char* key = keyboard_callback();
        if (key != keyPrev) {
            print(key);
        }
        keyPrev = key;
    }
}