
	global threexplusone
	section .text



threexplusone:
	push ebp
	mov ebp, esp
	push ebx
	mov eax, [esp+12]	;Optimization of locality: eax and ecx accessed
	mov ebx, eax		;togther frequently so they are close in memory
	cmp eax, 1		;location
	je  Equal_Loop
	mov esi, ebx
	and esi, 1
	cmp esi, 1
	jne Even_Loop
Odd_Loop:
	lea eax, [3*eax+1]	;use lea instead of imul
	push eax
	inc ecx
	call threexplusone
	jmp Done

Even_Loop:
	shr eax, 1  		;Use shift right to divide by 2 instead of idiv
	push eax		;and cdq
	inc ecx
	call threexplusone
	jmp Done
	
Equal_Loop:
	jmp Done
Done:
	mov eax, ecx
	pop ebx
	mov esp, ebp
	pop ebp
	ret
	
	
	