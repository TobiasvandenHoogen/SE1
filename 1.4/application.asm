//code made by Tobias van den Hoogen

.global application  //make function accesible trough other files

application:
    ldr r0, = msg    //assign register 0 with the value of variable msg
    bl print_asciz   //branch to function print_asci

.data
    msg: .ascii "Hello world, the ANSWER is 42! @[]`{}~\n" //initialise the variable msg with a ascii value
.end 
