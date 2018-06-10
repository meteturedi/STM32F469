/* Autohor: Atilla Mete Turedi */

#ifndef CRC_H
 #define CRC_H
  
 /************* CRC clock related macros and defines *******************/
 
 #ifndef RCC_REG_BASE
  #define RCC_REG_BASE						0x40023800
 #endif
 
 #ifndef RCC_AHB1ENR_OFFSET
	#define RCC_AHB1ENR_OFFSET			0x30
 #endif
 
 #ifndef RCC_AHB1ENR
	#define RCC_AHB1ENR							(volatile unsigned int *)(RCC_REG_BASE + RCC_AHB1ENR_OFFSET)
 #endif
	
 #define RCC_AHB1ENR_crcen_pos		0xC
 #define RCC_AHB1ENR_crcen_mask		1U << RCC_AHB1ENR_crcen_pos
 
 #define __CRC_Clock_Enable()			*RCC_AHB1ENR |=  RCC_AHB1ENR_crcen_mask
 #define __CRC_Clock_Disable()		*RCC_AHB1ENR &= ~RCC_AHB1ENR_crcen_mask
	
 /**********************************************************************/
	
 #define CRC_REG_BASE							0x40023000
	
 #define CRC_DR_OFFSET 						0x00
 #define CRC_IDR_OFFSET						0x04
 #define CRC_CR_OFFSET						0x08
	
 #define CRC_POLYNOMIAL						0x4C11DB7
 
 #define CRC_DR										(volatile unsigned int *)	(CRC_REG_BASE + CRC_DR_OFFSET)
 #define CRC_IDR	 								(unsigned int *)					(CRC_REG_BASE + CRC_IDR_OFFSET)

 #define CRC_CR_reset_pos   			0x01
 #define CRC_CR_reset_mask  			1U << CRC_CR_reset_pos
 
 #define __CRC_Reset()						*CRC_DR |= CRC_CR_reset_mask
 
 unsigned int CRC_Calculate 			(unsigned int data);
 void 				CRC_Enable_Clock 		(void);
 void 				CRC_IDR_Write 			(char data);
 char 				CRC_IDR_Read 				(void);

#endif /* ifndef CRC_H */
