/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : Pressure_Detection                                    */
/* File          : linker_script.ld    			                         */
/* Date          : Jun 1, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

/* Linker script for STM32F103C8T6 based on Cortex-M3 */

MEMORY
{
	FLASH : ORIGIN = 0x08000000, LENGTH = 64k
	SRAM : ORIGIN = 0x20000000, LENGTH = 20k
}

SECTIONS
{
	.vector :
	{
	*(.vector*)
	}> FLASH
	
	.text :
	{
	*(.text*)
	*(.rodata*)
	_E_text = . ;
	}> FLASH

	.data :
	{
	_S_data = . ;
	*(.data*)
	. = ALIGN(4);
	_E_data = . ;
	}> SRAM AT> FLASH

	.bss :
	{
	_S_bss = . ;
	*(.bss*)
	. = ALIGN(4);
	_E_bss = . ;
	. = . + 0x500;
	_S_stack = . ;
	}>SRAM
}