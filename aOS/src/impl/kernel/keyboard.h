// https://www.google.com/search?q=how+to+code+a+keyboard+driver+in+c&sxsrf=APq-WBu7x5N3R3Q700vQM_xR1RzFixRc0g%3A1644007196101&source=hp&ei=HI_9YZ2SA-ae_Qa994_ICA&iflsig=AHkkrS4AAAAAYf2dLF_4ZTuLY3fo7KRey4DZvCd7LEu7&oq=&gs_lcp=Cgdnd3Mtd2l6EAEYADIHCCMQ6gIQJzIHCCMQ6gIQJzIHCCMQ6gIQJzIHCCMQ6gIQJzIHCCMQ6gIQJzIHCCMQ6gIQJzIHCCMQ6gIQJzIHCCMQ6gIQJzIHCCMQ6gIQJzIHCCMQ6gIQJ1AAWABgmgtoAXAAeACAAccDiAHHA5IBAzQtMZgBALABCg&sclient=gws-wiz
#include <stdint.h>
typedef struct {
    uint8_t scancode;
    char chr; //Character it corresponds to.
} kbd_scancode;

static kbd_scancode regular_scancodes[] = {
  /* Numerical keys */
  {0x02, '1'}, {0x03, '2'}, {0x04, '3'}, {0x05, '4'}, {0x06, '5'}, {0x07, '6'}, {0x08, '7'}, {0x09, '8'}, {0x0A, '9'}, {0x0B, '0'},
  /* Some characters after numerical keys */
  {0x0C, '-'}, {0x0D, '='}, {0x0E, '\b'}, {0x0F, '\t'},
  /* Alphabet! */
  {0x10, 'q'}, {0x11, 'w'}, {0x12, 'e'}, {0x13, 'r'}, {0x14, 't'}, {0x15, 'y'}, {0x16, 'u'}, {0x17, 'i'}, {0x18, 'o'}, {0x19, 'p'}, {0x1A, '['}, {0x1B, ']'}, {0x1C, '\n'},
  {0x1E, 'a'}, {0x1F, 's'}, {0x20, 'd'}, {0x21, 'f'}, {0x22, 'g'}, {0x23, 'h'}, {0x24, 'j'}, {0x25, 'k'}, {0x26, 'l'}, {0x27, ';'}, {0x28, '\''}, {0x29, '`'},
  {0x2B, '\\'}, {0x2C, 'z'}, {0x2D, 'x'}, {0x2E, 'c'}, {0x2F, 'v'}, {0x30, 'b'}, {0x31, 'n'}, {0x32, 'm'}, {0x33, ','}, {0x34, '.'}, {0x35, '/'}, {0x37, '*'},
  {0x39, ' '}, {0x47, '7'}, {0x48, '8'}, {0x49, '9'}, {0x4A, '-'},
               {0x4B, '4'}, {0x4C, '5'}, {0x4D, '6'}, {0x4E, '+'},
               {0x4F, '1'}, {0x50, '2'}, {0x51, '3'},
               {0x52, '0'}, {0x53, '.'}, {0x00, '\0'}
};
static char kbd_buffer[256]= {};
static uint8_t kbd_buffer_current_pos=0;
static void kbd_buffer_push(char value)
{
   if(kbd_buffer_current_pos!=255)
      kbd_buffer[kbd_buffer_current_pos++]=value;
   else
   {
      return;//Buffer  overflow
   }
}
static char kbd_buffer_pop()
{
   if(kbd_buffer_current_pos>0)
      return kbd_buffer[kbd_buffer_current_pos--];
   else
      return 0;//Nothing  in  the  buffer
}
char convert(uint8_t c)
{
   for(int i=0;regular_scancodes[i].scancode!=0x00;i++)
   {
      if(regular_scancodes[i].scancode==c)
         return regular_scancodes[i].chr;
      return 0;
   }
}
void handler()
{
   uint8_t scancode=inb(0x60);
   kbd_buffer_push(convert(scancode));
}
char kbd_getchar()
{
   char ret=0;
   while(!ret)
   {
      ret=kbd_buffer_pop();
   }
   return ret;
}