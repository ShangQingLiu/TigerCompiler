L13:
mov 103,[ebp+8]
mov 102,[103+-4]
mov 105,[ebp+8]
mov 104,[105+-8]
add 101,104+102
mov 106,[ebp+8]
mov [106 + -4],101
mov 107,0
jmp L12
L12:

