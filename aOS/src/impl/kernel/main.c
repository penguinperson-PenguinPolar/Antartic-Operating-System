#include "print.h"
#include "keyboard.h"
void terminal() {
   int i=0;
   while(1)
   {
   print("Caught  key..");
   print(kbd_getchar());
   }
}
void kernel_main() {
    print_clear();
    print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
    print("Welcome to Antartic Operating System!\n");
    print("Press enter to continue");
    terminal();
}