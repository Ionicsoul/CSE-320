
        or      %r0, 0x111, %r1
        or      %r0, 0x222, %r2
        or      %r0, 0x333, %r3
        or      %r0, 0x444, %r4
        or      %r0, 0x555, %r5
        or      %r0, 0x666, %r6
        or      %r0, 0x777, %r7
        or      %r0, 0x888, %r8
        or      %r0, 0x999, %r9

        add     %r2, %r3, %r10
        and     %r4, %r5, %r11
        or      %r6, %r7, %r12
        xor     %r8, %r9, %r13

        sub     %r2, 0xff, %r14
        andn    %r4, 0xff, %r15
        orn     %r6, 0xff, %r16
        xnor    %r8, 0xff, %r17

        addcc   %r2, %r3, %r18
        andcc   %r4, %r5, %r19
        orcc    %r6, %r7, %r20
        xorcc   %r8, %r9, %r21

        subcc   %r2, 0xff, %r22
        andncc  %r4, 0xff, %r23
        orncc   %r6, 0xff, %r24
        xnorcc  %r8, 0xff, %r25

        sll     %r2, %r8, %r26
        srl     %r3, %r8, %r27
        sra     %r4, %r8, %r28

        sll     %r5, 16, %r29
        srl     %r6, 16, %r30
        sra     %r7, 16, %r31

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

