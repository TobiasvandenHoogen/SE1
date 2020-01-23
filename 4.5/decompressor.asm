
.cpu cortex-m0 
.text 
.align 2 
.global decompressor

decompressor:             //assign data to registers 
    push {r5, r6, r7, lr} //push the registers on the stack
    ldr r5, = msg         //load r5 with the string
    mov r3, r0      //load r3 with buffer array

checkChar:          //check each char 
    ldrb r4, [r5]   //load char in r0
    add r4, r4, #0  //if end of file
    beq done        //go to done
    cmp r4, #'@'    //if char is compression
    beq createMatch //go to create match
    mov r0, r4      //prepare to print char 
    bl uart_put_char //print char 
    bl bufferStart  //run bufferstart
    add r5, r5, #1  //go to next char
    b checkChar     //loop

createMatch:        //create the offset and length
    add r5, r5, #1  //go to next char
    ldrb r4, [r5]    //load next char
    mov r6, r4       // copy char to r4
    add r5, r5, #1   // go to next char
    ldrb r4, [r5]    //load char in r0
    mov r7, r4       //copy char to r7
    sub r6, r6, #48 //declare offset
    sub r7, r7, #48 //declare length

matchLoop:          //place the offset in the buffer
    cmp r7, #0       //if length is 0
    beq matchEnd    //go to matchend
    ldrb r4, [r3, r6]//load r0 with array[offset]
    mov r0, r4       //prepare to print
    bl uart_put_char //print char 
    bl bufferStart   //execute function bufferstart
    sub r7, r7, #1  //if r7 is 0
    b matchLoop      //loop

matchEnd:           //finish matchloop 
    add r5, r5, #1  //go to next char 
    b   checkChar   // go back to checkChar

bufferStart:         //prepare buffer
    push {r3, r4, lr}   //push r3 on the stack
    mov r1, #39     //set r0 as last index of array

bufferLoop:         //shift the buffer
    cmp r1, #0     //if index reached zero
    beq bufferDone  //go to bufferdone
    sub r2, r1, #1  //r2 = [index - 1]
    ldrb r0, [r3, r2]//load r4 as array[index - 1]
    strb r0, [r3, r1]//store the value of r4 in array[index]
    sub r1, r1, #1   //lower index 
    b bufferLoop    //loop

bufferDone:              //finish and return buffer 
    strb r4, [r3, #0]    //store the char in array[0]
    pop {r3, r4, pc}        //return

done:
    pop {r5, r6, r7, pc} //return 