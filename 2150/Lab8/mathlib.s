	global product
	
	section .text


product:

	mov eax, [esp+4]
	mov ecx, [esp+8]
	mov edx, eax
	cmp ecx, 0
	mov eax, 0
	jle product_done
	cmp ecx, 0
	jle product_done
	
product_loop:
	add eax, edx		
	dec ecx
	cmp ecx, 0
	jg product_loop

product_done:
	ret 	
	
     global power
        
        section .text
power:
        mov     eax, [esp+4]
	mov	ecx, [esp+8]
	cmp	eax, 1
	je	L3
        cmp     ecx, 1                  
        je      L3                      
        cmp     ecx, 0                 
        je      L3
L1:
        dec     ecx                   
        push    eax
        push	eax
        call    power             
        add     esp, 8                  
        call	product           

L3:
	ret

