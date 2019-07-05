#include "keys.h"
extern void keybord_mask(void);
extern void keybord_unmask(void);
char getchar()
{	char c,b;
	char* key_loc=(char*)0x5000;
	*key_loc=0;
	keybord_unmask();
	while(*key_loc==0);
	c=*key_loc;
	b=key[(unsigned char)c];
/*cvaddress=b;
	cvaddress+=1;
	*cvaddress=0x0f;
	cvaddress+=1;*/	
	keybord_mask();
	return b;
}


