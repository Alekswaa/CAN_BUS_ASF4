#include <atmel_start.h>

int main(void)
{
	/* Initializing drivers and everything for MCU*/
	atmel_start_init();

	/* Init async CAN0 and CAN1 */
	CAN_1_example();
	CAN_0_example();
	
	// Can message variables
	uint8_t send_data[4];
	static uint8_t inc_num = 0;
	
	struct can_message msg;
	msg.id   = 0x45A;
	msg.type = CAN_TYPE_DATA;
	msg.data = send_data;
	msg.len  = 4;
	msg.fmt  = CAN_FMT_STDID;
	
	while (1) {
		//Send message CAN0
		can_async_write(&CAN_0, &msg);
		delay_ms(1000);
		send_data[0] = inc_num;
		send_data[1] = inc_num+50;
		send_data[2] = inc_num+100;
		send_data[3] = inc_num+150;
		
		delay_ms(1000);
		
		//Send message CAN1
		can_async_write(&CAN_1, &msg);
		send_data[0] = inc_num;
		send_data[1] = inc_num+5;
		send_data[2] = inc_num+10;
		send_data[3] = inc_num+15;
		inc_num++;
	}
}
