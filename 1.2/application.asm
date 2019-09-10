.global application

application:
    ldr r0, = msg
    bl print_asciz

.data
msg: .ascii "Hello world, the ANSWER is 42! @[]`{}~\n"
.end 