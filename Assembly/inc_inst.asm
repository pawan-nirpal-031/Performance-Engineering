section .data 
	count equ 3 

section .text
	global _start 

_start: 
	mov dword eax,4 
	mov dword ebx,1 
	mov ecx,count
	mov dword edx,1   
	int 80h 

	mov dword eax,1 
	int 80h 
