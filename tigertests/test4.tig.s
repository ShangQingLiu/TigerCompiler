#BEGIN function
L16:
mov eax,[ebp+12]
mov edx,0
cmp eax,edx
je L12
L13:
mov eax,[ebp+12]
mov eax,eax
mov edx,[ebp+12]
sub edx,edx-1
push edx
mov ebx,[ebp+8]
push ebx
call L11
mov ebx,L11
mul eax,eax*ebx
mov eax,eax
L14:
jmp L15
L12:
mov eax,1
mov eax,eax
jmp L14
L15:

#END function

