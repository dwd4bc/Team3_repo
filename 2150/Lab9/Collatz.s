	.file	"Collatz.cpp"
	.text
	.align	16, 0x90
	.type	__cxx_global_var_init,@function
__cxx_global_var_init:                  # @__cxx_global_var_init
.Ltmp2:
	.cfi_startproc
# BB#0:
	push	EBP
.Ltmp3:
	.cfi_def_cfa_offset 8
.Ltmp4:
	.cfi_offset ebp, -8
	mov	EBP, ESP
.Ltmp5:
	.cfi_def_cfa_register ebp
	sub	ESP, 24
	lea	EAX, DWORD PTR [_ZStL8__ioinit]
	mov	DWORD PTR [ESP], EAX
	call	_ZNSt8ios_base4InitC1Ev
	lea	EAX, DWORD PTR [_ZNSt8ios_base4InitD1Ev]
	lea	ECX, DWORD PTR [_ZStL8__ioinit]
	lea	EDX, DWORD PTR [__dso_handle]
	mov	DWORD PTR [ESP], EAX
	mov	DWORD PTR [ESP + 4], ECX
	mov	DWORD PTR [ESP + 8], EDX
	call	__cxa_atexit
	mov	DWORD PTR [EBP - 4], EAX # 4-byte Spill
	add	ESP, 24
	pop	EBP
	ret
.Ltmp6:
	.size	__cxx_global_var_init, .Ltmp6-__cxx_global_var_init
.Ltmp7:
	.cfi_endproc
.Leh_func_end0:

	.globl	_Z7collatzi
	.align	16, 0x90
	.type	_Z7collatzi,@function
_Z7collatzi:                            # @_Z7collatzi
.Ltmp10:
	.cfi_startproc
# BB#0:
	push	EBP
.Ltmp11:
	.cfi_def_cfa_offset 8
.Ltmp12:
	.cfi_offset ebp, -8
	mov	EBP, ESP
.Ltmp13:
	.cfi_def_cfa_register ebp
	sub	ESP, 24
	mov	EAX, DWORD PTR [EBP + 8]
	mov	DWORD PTR [EBP - 8], EAX
	cmp	DWORD PTR [EBP - 8], 1
	jne	.LBB1_2
# BB#1:
	mov	DWORD PTR [EBP - 4], 0
	jmp	.LBB1_5
.LBB1_2:
	mov	EAX, DWORD PTR [EBP - 8]
	mov	ECX, EAX
	shr	ECX, 31
	add	ECX, EAX
	and	ECX, -2
	sub	EAX, ECX
	mov	ECX, 2
	cmp	EAX, 0
	mov	DWORD PTR [EBP - 12], ECX # 4-byte Spill
	jne	.LBB1_4
# BB#3:
	mov	EAX, DWORD PTR [EBP - 8]
	mov	ECX, EAX
	shr	ECX, 31
	add	ECX, EAX
	sar	ECX
	mov	EAX, 2
	mov	DWORD PTR [ESP], ECX
	mov	DWORD PTR [EBP - 16], EAX # 4-byte Spill
	call	_Z7collatzi
	add	EAX, 1
	mov	DWORD PTR [EBP - 4], EAX
	jmp	.LBB1_5
.LBB1_4:
	imul	EAX, DWORD PTR [EBP - 8], 3
	add	EAX, 1
	mov	DWORD PTR [ESP], EAX
	call	_Z7collatzi
	add	EAX, 1
	mov	DWORD PTR [EBP - 4], EAX
.LBB1_5:
	mov	EAX, DWORD PTR [EBP - 4]
	add	ESP, 24
	pop	EBP
	ret
.Ltmp14:
	.size	_Z7collatzi, .Ltmp14-_Z7collatzi
.Ltmp15:
	.cfi_endproc
.Leh_func_end1:

	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
.Ltmp18:
	.cfi_startproc
# BB#0:
	push	EBP
.Ltmp19:
	.cfi_def_cfa_offset 8
.Ltmp20:
	.cfi_offset ebp, -8
	mov	EBP, ESP
.Ltmp21:
	.cfi_def_cfa_register ebp
	sub	ESP, 24
	mov	EAX, 27
	mov	DWORD PTR [EBP - 4], 0
	mov	DWORD PTR [ESP], 27
	mov	DWORD PTR [EBP - 8], EAX # 4-byte Spill
	call	_Z7collatzi
	lea	ECX, DWORD PTR [_ZSt4cout]
	mov	DWORD PTR [ESP], ECX
	mov	DWORD PTR [ESP + 4], EAX
	call	_ZNSolsEi
	lea	ECX, DWORD PTR [_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_]
	mov	DWORD PTR [ESP], EAX
	mov	DWORD PTR [ESP + 4], ECX
	call	_ZNSolsEPFRSoS_E
	mov	ECX, DWORD PTR [EBP - 4]
	mov	DWORD PTR [EBP - 12], EAX # 4-byte Spill
	mov	EAX, ECX
	add	ESP, 24
	pop	EBP
	ret
.Ltmp22:
	.size	main, .Ltmp22-main
.Ltmp23:
	.cfi_endproc
.Leh_func_end2:

	.align	16, 0x90
	.type	_GLOBAL__I_a,@function
_GLOBAL__I_a:                           # @_GLOBAL__I_a
.Ltmp26:
	.cfi_startproc
# BB#0:
	push	EBP
.Ltmp27:
	.cfi_def_cfa_offset 8
.Ltmp28:
	.cfi_offset ebp, -8
	mov	EBP, ESP
.Ltmp29:
	.cfi_def_cfa_register ebp
	sub	ESP, 8
	call	__cxx_global_var_init
	add	ESP, 8
	pop	EBP
	ret
.Ltmp30:
	.size	_GLOBAL__I_a, .Ltmp30-_GLOBAL__I_a
.Ltmp31:
	.cfi_endproc
.Leh_func_end3:

	.type	_ZStL8__ioinit,@object  # @_ZStL8__ioinit
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.ctors,"aw",@progbits
	.align	4
	.long	_GLOBAL__I_a

	.section	".note.GNU-stack","",@progbits
