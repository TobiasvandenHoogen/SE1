

.global print_asciz //declare function global

print_asciz:
    push {r5, lr}  
    mov r5, r0
loop:
    ldrb r0, [ r5 ]
    add r0, r0, #0   //register 0 = register 0 + parameter
    beq done
    bl convert_char
    bl uart_put_char
    add r5, r5, #1   //register 0 = register 0 + parameter
    b loop
done:
    pop {r5, pc}