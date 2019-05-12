
#include <stdio.h>
Status = 0;
StatusMain = 0;
MainType = 0;
SenType = CMD_ERR;
static uint16_t PreTime;

parse_lcd_command()
{
	if(have_lcd_cmd)
	{
		Type = get_command_type();
		precommand = type
	}
	switch (precommand) {
		case BT_1:
			set_status(4);
			bt_respose();
			serial.wirte("g1");
			break;
		case CMD_OK:
			Status--;
		default:
			break;
	}
}

void set_status(uint8_t std)
{
	if (nstatus == 0)
	{
		Status = std;
		nstatus = 1;
	}
}

void mins_status(void)
{
	if (nstatus)
	{
		Status--;
	}
}

void plus_status(void)
{
	if (nstatus)
	{
		Status++;
	}
}
uint8_t get_status(void)
{
	if(nstatus)
	{
		return Status;
	}
}

void bt_respose(uint8_t sta)
{
	static prestatus = 0;
	if( prestatus )
	{	
		prestatus == sta;
		lcd_respose(cmd1);
	}
	if(Status == 2)
	{
		lcd_respose(cmd2);
	}
}

//超时处理函数
#define timeout 10;
uint8_t static timecount = 0;
lcd_respose(uint8_t * cmd)
{	
	send_lcd_command(cmd);
	for(i=0;i<RESPONE_TIME;i++)
	{
		if(i < RESPONE_TIME -1)
		{
			if(millis() - PreTime > 10)
			{
				PreTime = millis();
				send_lcd_command();
			}
		}
		if(i = RESPONE_TIME -1 )
		{
			if(millis() - PreTime > 10)
			{
				PreTime = millis();
				Status ++;
			}
		}
	}
}
