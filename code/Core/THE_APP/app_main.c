#include "app_main.h"

#define NUM_ROWS 2
GPIO_TypeDef* RowPorts[] = {ROW1_GPIO_Port, ROW7_GPIO_Port};
uint16_t RowPins[] = {ROW1_Pin, ROW7_Pin};

#define NUM_COLS 2
GPIO_TypeDef* ColPorts[] = {COLUMN10_GPIO_Port, COLUMN9_GPIO_Port};
uint16_t ColPins[] = {COLUMN10_Pin, COLUMN9_Pin};

void do_work()
{
//	HAL_GPIO_WritePin(CAPS_LOCK_GPIO_Port, CAPS_LOCK_Pin, GPIO_PIN_SET);
//	HAL_Delay(200);
//	HAL_GPIO_WritePin(CAPS_LOCK_GPIO_Port, CAPS_LOCK_Pin, GPIO_PIN_RESET);
//	HAL_Delay(200);

	for (int i = 0; i < NUM_ROWS; i++)
	{
		HAL_GPIO_WritePin(RowPorts[i], RowPins[i], GPIO_PIN_SET);
		for (int j = 0; j < NUM_COLS; j++)
		{
			if(HAL_GPIO_ReadPin(ColPorts[j], ColPins[j]))
			{
				HAL_GPIO_WritePin(CAPS_LOCK_GPIO_Port, CAPS_LOCK_Pin, GPIO_PIN_SET);
			}
			else
			{
				HAL_GPIO_WritePin(CAPS_LOCK_GPIO_Port, CAPS_LOCK_Pin, GPIO_PIN_RESET);
			}
		}
		HAL_GPIO_WritePin(RowPorts[i], RowPins[i], GPIO_PIN_RESET);
	}
}
