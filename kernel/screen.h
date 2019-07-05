#define VIDEO 0xb8000
#define MAX_ROW 80
#define MAX_COL 25

const char* vid=(char*)VIDEO;
char* cvaddress=(char*)VIDEO;
void clear_screen(void);
void prints(unsigned int X,unsigned int Y,const char* str);
int strlen(const char* str);
void printf(const char* str);