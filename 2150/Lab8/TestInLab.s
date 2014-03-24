	.file	"TestInLab.cpp"
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

	.globl	_Z7findMaxPi
	.align	16, 0x90
	.type	_Z7findMaxPi,@function
_Z7findMaxPi:                           # @_Z7findMaxPi
# BB#0:
	sub	ESP, 12
	mov	EAX, DWORD PTR [ESP + 16]
	mov	DWORD PTR [ESP + 8], EAX
	mov	EAX, DWORD PTR [ESP + 8]
	mov	EAX, DWORD PTR [EAX]
	mov	DWORD PTR [ESP + 4], EAX
	mov	DWORD PTR [ESP], 0
.LBB1_1:                                # =>This Inner Loop Header: Depth=1
	cmp	DWORD PTR [ESP], 4
	ja	.LBB1_6
# BB#2:                                 #   in Loop: Header=BB1_1 Depth=1
	mov	EAX, DWORD PTR [ESP]
	mov	ECX, DWORD PTR [ESP + 8]
	mov	EAX, DWORD PTR [ECX + 4*EAX]
	cmp	EAX, DWORD PTR [ESP + 4]
	jle	.LBB1_4
# BB#3:                                 #   in Loop: Header=BB1_1 Depth=1
	mov	EAX, DWORD PTR [ESP]
	mov	ECX, DWORD PTR [ESP + 8]
	mov	EAX, DWORD PTR [ECX + 4*EAX]
	mov	DWORD PTR [ESP + 4], EAX
.LBB1_4:                                #   in Loop: Header=BB1_1 Depth=1
# BB#5:                                 #   in Loop: Header=BB1_1 Depth=1
	mov	EAX, DWORD PTR [ESP]
	add	EAX, 1
	mov	DWORD PTR [ESP], EAX
	jmp	.LBB1_1
.LBB1_6:
	mov	EAX, DWORD PTR [ESP + 4]
	add	ESP, 12
	ret
.Ltmp8:
	.size	_Z7findMaxPi, .Ltmp8-_Z7findMaxPi

	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
.Ltmp11:
	.cfi_startproc
# BB#0:
	push	EBP
.Ltmp12:
	.cfi_def_cfa_offset 8
.Ltmp13:
	.cfi_offset ebp, -8
	mov	EBP, ESP
.Ltmp14:
	.cfi_def_cfa_register ebp
	sub	ESP, 56
	lea	EAX, DWORD PTR [.L_ZZ4mainE1x]
	mov	ECX, 20
	lea	EDX, DWORD PTR [EBP - 24]
	mov	DWORD PTR [EBP - 4], 0
	mov	DWORD PTR [ESP], EDX
	mov	DWORD PTR [ESP + 4], EAX
	mov	DWORD PTR [ESP + 8], 20
	mov	DWORD PTR [EBP - 28], ECX # 4-byte Spill
	call	memcpy
	lea	EAX, DWORD PTR [EBP - 24]
	mov	DWORD PTR [ESP], EAX
	call	_Z7findMaxPi
	lea	ECX, DWORD PTR [_ZSt4cout]
	mov	DWORD PTR [ESP], ECX
	mov	DWORD PTR [ESP + 4], EAX
	call	_ZNSolsEi
	lea	ECX, DWORD PTR [_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_]
	mov	DWORD PTR [ESP], EAX
	mov	DWORD PTR [ESP + 4], ECX
	call	_ZNSolsEPFRSoS_E
	mov	ECX, DWORD PTR [EBP - 4]
	mov	DWORD PTR [EBP - 32], EAX # 4-byte Spill
	mov	EAX, ECX
	add	ESP, 56
	pop	EBP
	ret
.Ltmp15:
	.size	main, .Ltmp15-main
.Ltmp16:
	.cfi_endproc
.Leh_func_end2:

	.align	16, 0x90
	.type	_GLOBAL__I_a,@function
_GLOBAL__I_a:                           # @_GLOBAL__I_a
.Ltmp19:
	.cfi_startproc
# BB#0:
	push	EBP
.Ltmp20:
	.cfi_def_cfa_offset 8
.Ltmp21:
	.cfi_offset ebp, -8
	mov	EBP, ESP
.Ltmp22:
	.cfi_def_cfa_register ebp
	sub	ESP, 8
	call	__cxx_global_var_init
	add	ESP, 8
	pop	EBP
	ret
.Ltmp23:
	.size	_GLOBAL__I_a, .Ltmp23-_GLOBAL__I_a
.Ltmp24:
	.cfi_endproc
.Leh_func_end3:

	.type	_ZStL8__ioinit,@object  # @_ZStL8__ioinit
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.type	.L_ZZ4mainE1x,@object   # @_ZZ4mainE1x
	.section	.rodata,"a",@progbits
	.align	4
.L_ZZ4mainE1x:
	.long	1                       # 0x1
	.long	4                       # 0x4
	.long	3                       # 0x3
	.long	8                       # 0x8
	.long	10                      # 0xa
	.size	.L_ZZ4mainE1x, 20

	.section	.ctors,"aw",@progbits
	.align	4
	.long	_GLOBAL__I_a

	.section	".note.GNU-stack","",@progbits
