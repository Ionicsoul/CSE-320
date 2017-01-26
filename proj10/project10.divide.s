
/******************************************************************************
  Given two integer values (4-byte twos complement values), convert into two
  floating point values (4-byte single precision values), then divide.
******************************************************************************/

        .section  ".text"
        .align    4
        .global   main
main:
        save      %sp, -112, %sp

        mov       5, %r16            ! Artificially put 5 into %r16
        mov       4, %r17            ! Artificially put 4 into %r17

        st        %r16, [%sp+104]    ! Convert first value to SP format:
        ld        [%sp+104], %f16    !   store %r16 into memory, load from
        fitos     %f16, %f24         !   memory into %f16, convert in %f24

        st        %r17, [%sp+108]    ! Convert second argument to SP format:
        ld        [%sp+108], %f17    !   store %r17 into memory, load from
        fitos     %f17, %f25         !   memory into %f17, convert in %f25

        fdivs     %f24, %f25, %f26   ! Divide and leave result in %f26

        call      iu_registers
        nop
        call      fpu_registers
        nop
        call      sp_registers
        nop

        ret
        restore

