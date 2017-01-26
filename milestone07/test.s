
        mov      15, %r2
        st       %r2, [%r0+0]
        mov      23, %r3
        st       %r3, [%r0+4]
        mov      18, %r4
        st       %r4, [%r0+8]
        mov      29, %r5
        st       %r5, [%r0+12]

        ld       [%r0+0], %r16
        ld       [%r0+4], %r17
        ld       [%r0+8], %r18
        ld       [%r0+12], %r19

        sll      %r16, 2, %r23
        add      %r16, %r23, %r23
        sub      %r23, %r17, %r23
        add      %r18, %r19, %r22

        mov      0x0a, %r8
        set      0x2000, %r28

        st       %r23, [%r28+1]
        st       %r8, [%r28+0]

        st       %r22, [%r28+1]
        st       %r8, [%r28+0]

        or      %r0, %r1, %r0
        or      %r2, %r3, %r0
        or      %r4, %r5, %r0
        or      %r6, %r7, %r0
        or      %r8, %r9, %r0
        or      %r10, %r11, %r0
        or      %r12, %r13, %r0
        or      %r14, %r15, %r0
        or      %r16, %r17, %r0
        or      %r18, %r19, %r0
        or      %r20, %r21, %r0
        or      %r22, %r23, %r0
        or      %r24, %r25, %r0
        or      %r26, %r27, %r0
        or      %r28, %r29, %r0
        or      %r30, %r31, %r0

