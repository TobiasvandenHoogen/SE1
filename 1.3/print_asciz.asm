
.global print_asciz // make function accesible trough other files

print_asciz:
    push {r5, lr}   
    mov r5, r0       //assign r5 as the given char 
loop:
    ldrb r0, [ r5 ]  //assign r0 as r5
    add r0, r0, #0   
    beq done         //if r0 is equal to r0 + 0, break
    bl uart_put_char //go to function uart_put_char
    add r5, r5, #1   //go to next char 
    b loop           
done:
    pop {r5, pc}    //pop register 5 and pc from the stack