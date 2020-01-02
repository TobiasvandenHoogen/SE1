.global decompressor
.global compressed 

decompressor:
    push {r5, lr}       
loop:
    ldr r5 , =msg
    add r0, r0, #0   
    beq done         
    bl uart_put_char 
    add r5, r5, #1   
    b loop           
done:
    pop {r5, pc}    