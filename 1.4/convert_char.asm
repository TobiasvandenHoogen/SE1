.global convert_char //delcare function as global

convert_char:
push {r5, lr} //push register 5 and the link register to the stack
mov r5, r0   

checklowercase: 
cmp  r0, #'a' //compare the ascii value of register 0 to the letter a 
blo checkuppercase //if ascii value is below a, go to branch checkuppercase
cmp r0, #'z' //compare the ascii value of register 0 to the letter z 
bhi exit    //if ascii value is above z, go to branch exit
sub  r0,r0,#('a' - 'A') //substract 32 of the ascii value of register 0 so that the char it will be uppercase    
b exit      //go to branch exit

checkuppercase:
cmp  r0, #'A' //compare the ascii value of register 0 to the letter A
blo exit      //if ascii value is below a, go to branch exit
cmp r0, #'Z'  //compare the ascii value of register 0 to the letter z 
bhi exit      //if ascii value is above Z, go to branch exit
add  r0,r0,#('a' - 'A') //add 32 to the ascii value of register 0 so that the char it will be lowercase    
b exit        //go to branch exit

exit:
mov r5, r0
pop {r5, pc}
