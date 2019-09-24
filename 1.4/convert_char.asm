//code by Tobias van den Hoogen

.global convert_char //make funtion accesible trough other files

convert_char:
    push {r5, lr}          

checklowercase: 
    cmp  r0, #'a'           //compare the ascii value of the given char to the letter a 
    blo checkuppercase      //if ascii value is below a, go to branch checkuppercase
    cmp r0, #'z'            //compare the ascii value of the given char to the letter z 
    bhi exit                //if ascii value is below a, break
    sub  r0,r0,#('a' - 'A') //substract 32 of the ascii value of the given char so that it will be uppercase    
    b exit                  //break

checkuppercase:
    cmp  r0, #'A'           //compare the ascii value of the given char to the letter A
    blo exit                //if ascii value is below A, break
    cmp r0, #'Z'            //compare the ascii value of the given char to the letter z 
    bhi exit                //if ascii value is above Z, go to branch exit
    add  r0,r0,#('a' - 'A') //add 32 to the ascii value of the given char so that it will be lowercase    
    b exit                  //break

exit:
    pop {r5, pc}            //return char
