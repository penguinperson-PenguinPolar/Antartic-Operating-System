void keyboard(void)
{
   int i=0;
   while(i<5000)
   {
   i++;
   handler();
   }
   terminal_writestring("Cought  key..");
   terminal_writestring(kbd_getchar());
}