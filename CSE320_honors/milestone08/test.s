
main:
        set      0x00002000, %r14

        mov      15, %r8
        mov      10, %r9
        call     process
        nop

        mov      20, %r8
        mov      10, %r9
        call     process
        nop

        or      %r8, %r9, %r0
        or      %r14, %r15, %r0
        or      %r28, %r29, %r0

        call     done
        nop

process:
        add      %r14, -4, %r14
        st       %r15, [%r14]

        add      %r8, %r9, %r8
        sll      %r8, 2, %r8

        call     print
        nop

        ld       [%r14], %r15
        add      %r14, 4, %r14

        jmpl     %r15+8, %r0
        nop

print:
        add      %r14, -12, %r14
        st       %r15, [%r14]
        st       %r28, [%r14+4]
        st       %r29, [%r14+8]

        set      0x00002000, %r28
        mov      0x0a, %r29

        st       %r8,  [%r28+1]
        st       %r29, [%r28+0]

        ld       [%r14+8], %r29
        ld       [%r14+4], %r28
        ld       [%r14], %r15
        add      %r14, 12, %r14

        jmpl     %r15+8, %r0
        nop

done:

