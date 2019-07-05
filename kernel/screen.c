
void graphics_init()
{
unsigned char* add1 =(char*)0x7e2B;
	unsigned char data1 = *add1;
	unsigned char* add2 =(char*)0x7e2A;
	unsigned char data2 = *add2;
	unsigned char* add3 =(char*)0x7e29;
	unsigned char data3 = *add3;
	unsigned char* add4 =(char*)0x7e28;
	unsigned char data4 = *add4;

	unsigned int value = data4 | (data3<<8) | (data2<<16) | (data1<<24);
	
	address=(char*) value;
	return;
}

	
	
void pos_x_y(unsigned short int x,unsigned short int y,unsigned char color,unsigned char* start_add)
{
	unsigned char* current_address;
	current_address=start_add+(1280*y-1)+x;
	*current_address=color;
}	
	


void charf(char* start_add)
{

	unsigned short int i,j;
	for (j=0; j <20 ; j++)
	{
		for (i = 0; i <10 ; i++)
		{
			pos_x_y(i,j,0x00,start_add);
		
		}
	}
	for (i=4; i <=10 ; i++)
	{
		pos_x_y(i,5,0x0f,start_add);
		pos_x_y(i,6,0x0f,start_add);
		pos_x_y(i,11,0x0f,start_add);
		pos_x_y(i,12,0x0f,start_add);
	}
	for (j=6; j <=20 ; j++)
	{
		pos_x_y(3,j,0x0f,start_add);
		pos_x_y(4,j,0x0f,start_add);
	}
	
return;
}