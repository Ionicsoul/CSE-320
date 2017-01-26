.global main

 .section ".text"
 .align 4

main: 	save 	%sp, -96, %sp
		clr 	%r16 				! Initialize character count
		clr 	%r17				! Initialize  newline
		clr 	%r18				! Initialize  whitespace
		clr 	%r19				! Initialize  octal
		clr 	%r20				! Initialize decimal
		clr 	%r21				! Initialize hexadecimal
		clr 	%r22				! Initialize letters

loop: 		call 	getchar ! Read one character (returned in %r8)
			nop
			cmp 	%r8, -1 ! Compare return value to EOF
			be 		end ! If EOF found, exit loop
			nop
			inc		%r16 ! Increment character count
			nop
			
	
ifnewline:	cmp	 	%r8, 0x0a
			bne 	ifwhitespace
			nop
			inc 	%r17
			nop
			inc 	%r18
			nop
			
ifwhitespace:	cmp		%r8, 0x20
				bne 	ifwhitespace2
				nop
				inc 	%r18
				nop
				
ifwhitespace2:	cmp 	%r8, 0x09
				bne 	ifoctaldigit
				nop
				inc     %r18
				
ifoctaldigit:	cmp		%r8, '0'
				bl		ifdecimal
				nop
				cmp		%r8, '7'
				bg 		ifdecimal
				nop
				inc 	%r19
				nop
			
ifdecimal:		cmp		%r8, '0'
				bl  	ifhexadecimal
				nop		
				cmp		%r8, '9'
				bg  	ifhexadecimal
				nop
				inc 	%r20
				nop
				inc 	%r21
				nop

ifhexadecimal:	cmp		%r8, 'a'
				bl  	ifhexadecimal2
				nop
				cmp 	%r8, 'f'
				bg  	ifhexadecimal2
				nop
				inc 	%r21
				nop
								
ifhexadecimal2:	cmp 	%r8, 'A'
				bl  	ifletters
				nop
				cmp 	%r8, 'F'
				bg  	ifletters
				nop
				inc 	%r21
				nop

ifletters:		cmp		%r8, 'a'
				bl 		ifletters2
				nop
				cmp 	%r8, 'z'
				bg 		ifletters2
				nop
				inc 	%r22
				nop

ifletters2:		cmp 	%r8, 'A'
				bl 	  	loop
				nop
				cmp 	%r8, 'Z'
				bg 		loop
				nop
				inc 	%r22
				nop
				
				ba 		loop
				nop
				
				call 	putchar
				nop
			
	
end: 	set 	fmt, %r8 			! First arg -- address of format string
		mov 	%r16, %r9			! Second arg -- character count
		call 	printf 				! Print the number of characters
		nop
		
		set 	fmt2, %r8
		mov 	%r17, %r9			! Newline
		call 	printf 				! Print the number of characters
		nop
		
		set 	fmt3, %r8
		mov 	%r18, %r9			! whitespace
		call 	printf 				! Print the number of characters
		nop
		
		set 	fmt4, %r8
		mov 	%r19, %r9			! octal
		call 	printf 				! Print the number of characters
		nop
		
		set 	fmt5, %r8
		mov 	%r20, %r9			! decimal
		call 	printf 				! Print the number of characters
		nop
		
		set 	fmt6, %r8
		mov 	%r21, %r9			! hexadecimal
		call 	printf 				! Print the number of characters
		nop
		
		set 	fmt7, %r8
		mov 	%r22, %r9 			! ifletters
		call 	printf 				! Print the number of characters
		nop
		ret
		restore
		
fmt: 	.asciz 	"\nTotal Characters = %d\n"
fmt2:	.asciz  "Newline = %d\n"
fmt3:	.asciz	"Whitespace = %d\n"
fmt4:	.asciz	"Octal = %d\n"
fmt5:	.asciz	"Decimal = %d\n"
fmt6:	.asciz	"Hexadecimal = %d\n"
fmt7:	.asciz	"Letters = %d\n"


