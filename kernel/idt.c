extern void keyboard_handler(void);
extern void load_idt(unsigned long *idt_ptr);
struct IDT_ENTRY
{
	unsigned short int offset_lowerbits;
	unsigned short int selector;
	unsigned char zero;
	unsigned char type;
	unsigned short int offset_higherbits;
};
struct IDT_ENTRY IDT[256];
unsigned int* videoaddress;

void create_IDT()
{
unsigned long keyboard_address;
unsigned long idt_address;
unsigned long idt_ptr[2];
keyboard_address = (unsigned long)keyboard_handler;
IDT[0x21].offset_lowerbits =keyboard_address & 0xffff;
IDT[0x21].selector = 0x08;
IDT[0x21].zero = 0;
IDT[0x21].type = 0x8e;
IDT[0x21].offset_higherbits = (keyboard_address & 0xffff0000) >> 16;

idt_address = (unsigned long)IDT ;
idt_ptr[0] = (sizeof (struct IDT_ENTRY) * 256) + ((idt_address & 0xffff) << 16);
idt_ptr[1] = idt_address >> 16 ;

load_idt(idt_ptr);
}