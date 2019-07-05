unsigned char* address;
#include "screen.c"
#include "keyscan.c"
#include "idt.c"


void _start()
{	
	create_IDT();
	
	graphics_init();
	
	charf((char*)address);
	return;
}
