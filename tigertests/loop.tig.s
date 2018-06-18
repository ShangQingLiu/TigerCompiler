#BEGIN function
L18:
L15:
li t2, 1
li t3, 10
li t4, 5
bgt t3, t4, L12
L13:
li t5, 0
L12:
li t6, 0
beq t1, t6, L14
L16:
li t8, 6
addi t7, t8, 5
lw t9, 8(ebp)
sw t7, -4(t9)
j L15
L14:
j L17
L17:

#END function

