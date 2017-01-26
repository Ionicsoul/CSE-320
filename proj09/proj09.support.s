.global	is_nan			!is_nan function
	.section ".text"
	.align 4
is_nan:
	save	%sp, -96, %sp
	clr	%l0
	sll	%i0, 1, %l0		!Shift to the left, 1
	srl	%l0, 21, %l0	!Shift to the right, 21
 
second_if:
	cmp	%l0, (0x7ff)		!To check if exponent is all 1s
	bne	third_then			
	nop
	clr	%l1
	sll	%i0, 16, %l1		!Shift to the left, 16
	cmp	%l1, %r0		
	be	second_then			
	nop
	clr	%i0			
	inc	%i0				!Make it 1	
	ba	second_else
	nop
 
second_then:
	cmp	%i1, %r0		 
	be	third_then		
	nop
	clr	%i0		
	inc	%i0		!Make it 1
	ba	second_else
	nop
 
third_then:
	clr	%i0		!Make it 0	

second_else:
	ret
	restore
	
	
!------------------------------------------------------------

.global	is_zero			!is_zero function
	.section ".text"
	.align 4
is_zero:
	save	%sp, -96, %sp
 
third_if:
	cmp	%i0, %r0		!If first 32 bits are 0s
	bne	fourth_then	
	nop
	cmp	%i1, %r0		!If second 32 bits are 0s
	bne	fourth_then		
	nop
	clr	%i0			
	inc	%i0			!Make it 1
	ba third_else
	nop
	
fourth_then:
	clr	%i0			!Make it 0		

third_else:
	ret
	restore
	

!-----------------------------------------------------------
	
	
.global	is_denormal			!is_denormal function
	.section ".text"
	.align 4
is_denormal:
	save	%sp, -96, %sp
	clr	%l0
	sll	%i0, 1, %l0		!Shift 1 to the left
	fourth_if:
	cmp	%l0, %r0		!To check if exponent is all 0s
	bne	fifth_then1			
	nop
	clr	%l1
	sll	%i0, 16, %l1		!Shift left 16.
	cmp	%l1, %r0		
	be	fifth_then		
	nop
	clr	%i0			
	inc	%i0			!Make it 1
	ba	fifth_else
	nop
 
fifth_then:
	cmp	%i1, %r0		!TO see if its equal to zero. 
	be	fifth_then1			
	nop 
	clr	%i0			
	inc	%i0			!Make it 1
	ba	fifth_else
	nop
 
fifth_then1:
	clr	%i0			!Make it 0
 
fifth_else:
	ret
	restore

! ---------------------------------------------------------------

.global	is_infinity				!is_infinity function
	.section ".text"
	.align 4
is_infinity:				
	save	%sp, -96, %sp
	clr	%l0
	sll	%i0, 1, %l0		!Shift it to left 1 bit
	srl	%l0, 21, %l0	!Shift it to right 21 bits
 
 
fifth_if:
	cmp	%l0, (0x7ff)		!To check if exponent is all 1s
	bne	sixth_then			
	nop 
	clr	%l1
	sll	%i0, 16, %l1		!Shift it to left 16 bits
	srl	%l1, 16, %l1		!Shift it to right 16 bits
	cmp	%l1, %r0			!Compare to 0s
	bne	sixth_then			
	nop
	cmp	%i1, %r0		 
	bne	sixth_then		
	nop
	clr	%i0			
	inc	%i0			!Make it 1
	ba	sixth_else
	nop
 
sixth_then:
	clr	%i0			!Make it 0
 
sixth_else:
	ret
	restore
	
	
!------------------------------------------------------------------------------

.global	negate			!The negate function
	.section ".text"
	.align 4
negate:
	save	%sp, -96, %sp
	set	(0x80000000), %l0		! Set to a local register
	xor	%i0, %l0, %l0			! By using xor.
	std	%l0, [%i2]				! Store this value in %i2.
	ret
	restore
	
	
!------------------------------------------------------------------------------

.global	absolute
	.section ".text"
	.align 4
absolute:
	save	%sp, -96, %sp
	set	(0x7fffffff), %l0		! Set to a local register
	and	%i0, %l0, %l0			! By using and.
	std	%l0, [%i2]				! Store this value in %i2.
	ret
	restore
	
	
!-----------------------------------------------------------------------------


	.global	classify			!Classify function
	.section ".text"
	.align 4

classify:
	save	%sp, -96, %sp
	mov	%i0, %l0		! move the registers to local registers
	mov	%i1, %l1		! move the registers to local registers
	clr	%l7
 
sixth_if:					
	mov	%l0, %o0
	mov	%l1, %o1 
	call	is_zero			! check for zero
	nop
	cmp	%o0, 0
	be	seventh_if
	nop
	set	fmt5, %o0
	call	printf
	nop
 
seventh_if:
	mov	%l0, %o0
	mov	%l1, %o1
	call	is_denormal		! Check for denormal
	nop
	cmp	%o0, 0
	be	eight_if
	nop
	set	fmt6, %o0
	call	printf
	nop
	inc	%l7			!Make it 1
 
eight_if:
	mov	%l0, %o0
	mov	%l1, %o1
	call	is_infinity		! Check for infinite
	nop
	cmp	%o0, 0
	be	ninth_if
	nop
	set	fmt7, %o0
	call	printf
	nop
	inc	%l7			!Make it 1
 
ninth_if:
	mov	%l0, %o0
	mov	%l1, %o1
	call	is_nan			! Check for NaN
	nop
	cmp	%o0, 0
	be	tenth_if
	nop
	set	fmt8, %o0
	call	printf
	nop
	inc	%l7			!Make it 1
 
tenth_if:
	cmp	%l7, 0				! Check for Normal
	bne	eleventh_if
	nop
	set	fmt9, %o0
	call	printf
	nop
	
eleventh_if: 
	ret
	restore
 
 
fmt5:	.asciz	"zero\n"			!Print the output accordingly using printf.
fmt6:	.asciz	"denormal\n"
fmt7:	.asciz	"infinity\n"
fmt8:	.asciz	"not-a-number\n"
fmt9:	.asciz	"normal\n"	