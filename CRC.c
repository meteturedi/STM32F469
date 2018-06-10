#include "CRC.h"

 /* CRC Enable Clock Function */
 
 void CRC_Enable_Clock (void){
	 
	 __CRC_Clock_Enable();
	 
 }

 /* Calculate CRC Function */
 
 unsigned int CRC_Calculate (unsigned int data){
	 
	 /* Polynomial: 0x4C11DB7 */
	 
	 volatile unsigned int* ptr;

	 __CRC_Reset();
	 
	 ptr 	 = CRC_DR;
	 *ptr  = data;
	 
	 return *ptr;
	 
 }
 
  /* CRC write to independent data register */
 
 void CRC_IDR_Write (char data){
	 
	 unsigned int		*ptr;
	 
	 ptr 	 					= CRC_IDR;
	 *ptr 					= data;
	 
 }
 
   /* CRC read from independent data register */
 
 char CRC_IDR_Read (void){
	 
	 unsigned int 	*ptr;
	 char 					data;
	 
	 ptr 	 					= CRC_IDR;
	 data 					= *ptr;
	 
	 return data;
	 
 }
