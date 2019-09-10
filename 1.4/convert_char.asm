.global convert_char

convert_char:
push {r5, lr}
mov r5, r0

checklowercase:
cmp  r0, #'a'
blo checkuppercase
cmp r0, #'z'
bhi exit
sub  r0,r0,#('a' - 'A') 
b exit

checkuppercase:
cmp  r0, #'A'
blo exit
cmp r0, #'Z'
bhi exit
add  r0,r0,#('a' - 'A') 
b exit

exit:
mov r5, r0
pop {r5, pc}
