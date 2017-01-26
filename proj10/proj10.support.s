		.global delete
		.global search
		.global insert
		
		.section ".text"
		.align 4


!Delete function
delete:
        save    %sp, -104, %sp
        mov     %i0, %l1                ! Store the address in l1
        mov     %i1, %l0                ! Store the student id l0
        lduh    [%l1+2], %l5            ! get student count
        cmp     %l5, 0                  !Check if the its empty or no records exist, if yes then go to no_delete.
        be      no_delete           	!Delete function wont be performed
        nop
        mov     %l1, %o0                !Search function
        mov     %l0, %o1
        mov     %sp, %o2                
        call    search
        nop
        mov     %o0, %l3                !Move results from search to %l3
        ld      [%o2], %l6              !Copy the address
        cmp     %l3, 0					!Compare to 0, to check if the id exists.
        be      no_delete               !Delete function wont be performed
        nop
	
		!Calculate the address.
        ld      [%l1+8], %l7            !Address of the first student
        sub     %l6, %l7, %l7           !Using sub to calculate the bytes 
        sdiv    %l7, 48, %l7            
        sub     %l5, %l7, %l7           
        smul    %l7, 48, %o2           
		
        cmp     %l7, 1

        be      delete_al
        cmp     %l3, 0					!Compare it to 0 to check if the id exists
        be      no_delete        	    !If yes then go to no_delete.
        nop
        ld      [%l1+8], %l7            !Address of the first student
        sub     %l6, %l7, %l7           !Using sub to calculate the bytes 
        sdiv    %l7, 48, %l7            
        sub     %l5, %l7, %l7           
        smul    %l7, 48, %o2            !multiply students left by offset and now we know how much data to move
        cmp     %l7, 1					!Compare to 1 if equal then go to delete_al, success.
        be      delete_al
        nop
        mov     %l6, %o0               
        add     %o0, 48, %o1           
        call    memmove
        nop
		
delete_al:
        sub     %l5, 1, %l5             !Increment count by 1
        stuh    %l5, [%i0+2]            !Count for Table
        set     1, %i0					!Return 1 for delete success
        ba      end_delete
        nop
no_delete:
        set     0, %i0					!Return 0 for delte fail
end_delete:
        ret
        restore

!Insert function
insert:
	save	%sp, -104, %sp
	mov	%i1, %l0				! Store the student id l0
	mov	%i0, %l1				! Store the address in l1
	lduh	[%l1+2], %l5		! Count for student
	lduh	[%l1+0], %l4		! Capacity
	
	cmp	%l5, %l4		!Check to see for maximum capacity
	bge	unsuccessful	!If yes then move to unsuccessful
	nop

	mov	%l1, %o0		!Value from search function
	mov	%l0, %o1
	mov 	%sp, %o2

	call	search
	nop

	mov	%o0, %l3		!Move search value to %l3 
	ld	[%o2], %l6		!Get the address

	cmp 	%l3, 1
	be	unsuccessful		!If Id already exists then wont insert
	nop

	ld	[%l1+8], %l7		!Address of the first student	
	sub	%l6, %l7, %l7		!Using sub to calculate the bytes 
	sdiv	%l7, 48, %l7		
	sub	%l5, %l7, %l7		
	smul	%l7, 48, %o2
	

	mov	%l6, %o1		    
	add	%o1, 48, %o0		
	
	call 	memmove			!Check here
	nop

call_insert:

	add	 %l5, 1, %l5			!Increment the count
	stuh %l5, [%i0+2]		

	st	 %i1, [%l6]				!Store ID number	-- Inserting data into table
	stuh %i5, [%l6+44]		!Exam 3
	stuh %i4, [%l6+42]		!Exam 2
	stuh %i3, [%l6+40]		!Exam 1
	

	clr 	%l2				! clear register for adding points

	
	add	%l2, %i3, %l2		! get total points	
	add	%l2, %i4, %l2		! get total points
	add	%l2, %i5, %l2		! get total points
	
	st	%l2, [%l6+36]		!Storing the value

							!Calculate the average
	clr	%l5					!Clear register l5
	ld	[%i0+4], %l5		!Load the points calculated
	st	%l2, [%sp+96]		!Store them into sp
	ld	[%sp+96], %f4		!Using f4 load the points into floating register
	fitos	%f4, %f4		!Converting the integer value to floating point
	st	%l5, [%sp+96]		
	ld	[%sp+96], %f5		
	fitos	%f5, %f5		
	fdivs	%f4, %f5, %f6	!Dividing the calculated points by total points available
	st	%f6, [%l6+32] 		!Store the value in average
	 


	mov	%i2, %l1		!Address of character array
	mov	%l6, %l0		!Student Address
	add	%l0, 4, %l0		

character_loop:
	clr	%l2				    !clear &l2
	ldub	[%l1], %l2		!load a byte
	stb	%l2, [%l0]
	cmp	%l2, %g0		    !Compare to new line and if it is then end the insert function.
	be	finish_insert		
	nop
	
	add	%l1, 1, %l1		!Add the byte
	add	%l0, 1, %l0
	ba	character_loop
	nop

finish_insert:
	set	1, %i0			!Return 1 for success
	ba	end_of_insert
	nop
	
unsuccessful:
	set	0, %i0			!Return 0 for failure
end_of_insert:
	ret
	restore
	


search:
	save	%sp, -104, %sp

	mov	%i0, %l1		!Address of table
	
	mov	%i1, %l0		!Student Id 
	lduh	[%i0+2], %l4		!COunt of student
	ld	[%i0+8], %l2		!Load into l2 with 8 bytes right.

	clr	%l3

loop_for_search:
	cmp	%l4, %l3
	ble	search_fail
	nop
	
	ld	[%l2+0], %l5		!load Id for comparison	in %l5
	cmp	%l5, %i1			!Compare the IDS
	be	search_success		!If found then go to search_success
	nop
	
	cmp	%l5, %i1		!Compare to see if its greater
	bg	search_fail		!If its greater then go to search_fail
	nop

	inc	%l3				!else increment count and then loop
	
	add	%l2, 48, %l2		
	ba	loop_for_search
	nop
	
search_fail:
	set	0, %i0			!Return 0 for fail search
	st      %l2, [%i2+0]
    !mov     %l2, %i2

	ba	end_of_search
	nop

search_success:
	set	1, %i0			!Return 1 for success
	st	%l2, [%i2+0]
	!mov	%l6, %i2
	
end_of_search:
	ret
	restore



