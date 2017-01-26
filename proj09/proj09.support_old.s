.global	is_nan
	.section ".text"
	.align 4
is_nan:
	save	%sp, -96, %sp
 
	clr	%l0
	sll	%i0, 1, %l0		!shift left 1 to extract neg bit
	srl	%l0, 21, %l0		!shift right 21 for comparison placement
 
 
if2:
	cmp	%l0, (0x7ff)		!check if exponent area is equal to all ones
	bne	then2			!break if not equal to all ones
	nop
 
	clr	%l1
	sll	%i0, 16, %l1		!get first part of fraction by left shifting
	cmp	%l1, %r0		!check if first 20 bits of fraction area is equal to zero
	be	then2a			!break if it is equal to zero
	nop
 
	clr	%i0			!clear register
	inc	%i0			!increment register
	ba	else2
	nop
 
then2a:
	cmp	%i1, %r0		!check if remaining bits of fraction area is zero 
	be	then2			!break if equal to zero
	nop
 
	clr	%i0			!clear register
	inc	%i0			!increment register
 
	ba	else2
	nop
 
then2:
	clr	%i0			!clear register (no increment)
 
else2:
	ret
	restore
	
	
	! ---------------------------------------------
.global	is_zero
	.section ".text"
	.align 4
is_zero:
	save	%sp, -96, %sp
 
if:
	cmp	%i0, %r0		!compare first 32 bits to zero
	bne	then			!if not equal to zero break to then
	nop
 
	cmp	%i1, %r0		!compare second 32 bits to zero
	bne	then			!if not equal to zero break to then
	nop
 
	clr	%i0			!clear register
	inc	%i0			!increment by 1 to show its a zero
 
	ba else
	nop
 
then:
	clr	%i0			!clear register (no increment)
else:
	ret
	restore
	

	! -------------------------------------------------
	
	
.global	is_denormal
	.section ".text"
	.align 4
is_denormal:
	save	%sp, -96, %sp
 
	clr	%l0
	sll	%i0, 1, %l0		!shift right 1 to extract neg bit
 
if1:
	cmp	%l0, %r0		!check if exponent area is equal to zero
	bne	then1			!break if not equal to zero
	nop
 
	clr	%l1
	sll	%i0, 16, %l1		!get first part of fraction by left shifting
	cmp	%l1, %r0		!check if first 20 bits of fraction area is equal to zero
	be	then1a			!break if it is equal to zero
	nop
 
	clr	%i0			!clear register
	inc	%i0			!increment register
	ba	else1
	nop
 
then1a:
	cmp	%i1, %r0		!check if remaining bits of fraction area is zero 
	be	then1			!break if equal to zero
	nop
 
	clr	%i0			!clear register
	inc	%i0			!increment register
 
	ba	else1
	nop
 
then1:
	clr	%i0			!clear register (no increment)
 
else1:
	ret
	restore

! ---------------------------------------------------------------

.global	is_infinite
	.section ".text"
	.align 4
is_infinite:				!working on it
	save	%sp, -96, %sp
 
	clr	%l0
	sll	%i0, 1, %l0		!shift left 1 to extract neg bit
	srl	%l0, 21, %l0		!shift right 21 for comparison placement
 
 
if3:
	cmp	%l0, (0x7ff)		!check if exponent area is equal to all ones
	bne	then3			!break if not equal to all ones
	nop
 
	clr	%l1
 
	sll	%i0, 16, %l1		!get first part of fraction by left shifting
	srl	%l1, 16, %l1
	cmp	%l1, %r0		!check if first 20 bits of fraction area is equal to zero
	bne	then3			!break if it is not equal to all zeros
	nop
 
	cmp	%i1, %r0		!check if remaining bits of fraction area is zero 
	bne	then3			!break if NOT equal to all zeros
	nop
 
	clr	%i0			!clear register
	inc	%i0			!increment register
 
	ba	else3
	nop
 
then3:
	clr	%i0			!clear register (no increment)
 
else3:
	ret
	restore
	
	
! -----------------------------------------------------------------------------

.global	negate
	.section ".text"
	.align 4
negate:
	save	%sp, -96, %sp
 
	set	(0x80000000), %l0		! Must set local register in order to compute value
	xor	%i0, %l0, %l0			! Using above value, negate only the leftmost bit
	std	%l0, [%i2]			! Store new value into memory location %i2 (double*)
 
	ret
	restore
	
	
! -----------------------------------------------------------------------------

.global	absolute
	.section ".text"
	.align 4
absolute:
	save	%sp, -96, %sp
 
	set	(0x7fffffff), %l0		! Must set local register in order to compute value
	and	%i0, %l0, %l0			! Using above value, set leftmost bit to zero (always positive)
	std	%l0, [%i2]			! Store new value into memory location %i2 (double*)
 
	ret
	restore
	
	
! ----------------------------------------------------------------------------

! Display:
! Will display an appropriate message which 
! classifies its argument ("normalized", "zero", 
! "denormal", "infinity" or "not-a-number").
	.global	display
	.section ".text"
	.align 4
display:
	save	%sp, -96, %sp
 
	mov	%i0, %l0		! Copy input register to local registers for is_infinite function call
	mov	%i1, %l1		! Copy input register to local registers for is_infinite function call
 
	clr	%l7
 
 
if5:					
	mov	%l0, %o0
	mov	%l1, %o1
 
	call	is_zero			! check if number is zero
	nop
 
	cmp	%o0, 0
	be	if10
	nop
 
	set	fmt5, %o0
	call	printf
	nop
 
if6:
	mov	%l0, %o0
	mov	%l1, %o1
 
	call	is_denormal		! Check if number is denormal
	nop
 
	cmp	%o0, 0
	be	if10
	nop
 
	set	fmt6, %o0
	call	printf
	nop
 
	inc	%l7
 
if7:
	mov	%l0, %o0
	mov	%l1, %o1
 
	call	is_infinite		! Check if number is infinite
	nop
 
	cmp	%o0, 0
	be	if10
	nop
 
	set	fmt7, %o0
	call	printf
	nop
 
	inc	%l7
 
if8:
	mov	%l0, %o0
	mov	%l1, %o1
 
	call	is_nan			! Check if number is NaN
	nop
 
	cmp	%o0, 0
	be	if10
	nop
 
	set	fmt8, %o0
	call	printf
	nop
 
	inc	%l7
 
if9:
 
	cmp	%l7, 0			! Check if number is Normal
	bne	if10
	nop
 
	set	fmt9, %o0
	call	printf
	nop
 
if10:
	ret
	restore
 
 
fmt5:	.asciz	"zero\n"
fmt6:	.asciz	"denormal\n"
fmt7:	.asciz	"infinity\n"
fmt8:	.asciz	"not-a-number\n"
fmt9:	.asciz	"normal\n"	