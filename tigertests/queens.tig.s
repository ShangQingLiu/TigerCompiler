section .text
	L35:	db	"\n"
	L27:	db	"\n"
	L16:	db	" ."
	L15:	db	" O"
#BEGIN function
L60:
mov ecx,[ebp+12]
mov eax,[ebp+8]
mov eax,[eax+-4]
cmp ecx,eax
je L56
L56:
mov eax,[ebp+8]
push eax
call L11
mov eax,L11
jmp L58
L57:
mov eax,0
mov ecx,eax
mov eax,0
mov eax,[ebp+8]
mov eax,[eax+-4]
sub eax,eax-1
mov edx,eax
mov eax,0
mov eax,1
mov eax,eax
mov [ebp+-16],eax #spill
mov eax,0
mov esi,0
mov eax,[ebp+8]
mov eax,[eax+-4]
sub eax,eax-1
cmp esi,eax
jle L54
L54:
jmp L52
L53:
mul esi,ecx*4
mov eax,[ebp+8]
mov eax,[eax+-8]
add eax,eax+esi
mov eax,[eax]
mov esi,0
cmp eax,esi
je L37
L37:
mov eax,1
mov eax,eax
mov esi,[ebp+12]
add esi,ecx+esi
mul edi,esi*4
mov esi,[ebp+8]
mov esi,[esi+-16]
add esi,esi+edi
mov esi,[esi]
mov edi,0
cmp esi,edi
je L40
L41:
mov eax,0
mov eax,eax
L40:
mov esi,eax
jmp L39
L38:
mov eax,0
mov esi,eax
jmp L39
L39:
mov eax,0
cmp esi,eax
je L43
L42:
mov eax,1
mov esi,eax
mov eax,[ebp+12]
add edi,ecx+7
sub eax,edi-eax
mul edi,eax*4
mov eax,[ebp+8]
mov eax,[eax+-20]
add eax,eax+edi
mov eax,[eax]
mov ebx,0
cmp eax,ebx
je L45
L46:
mov eax,0
mov esi,eax
L45:
mov eax,esi
jmp L44
L43:
mov eax,0
mov eax,eax
jmp L44
L44:
mov ebx,0
cmp eax,ebx
je L48
L47:
mov eax,0
L48:
mov eax,0
cmp ecx,edx
jl L49
L49:
add eax,ecx+1
mov ecx,eax
jmp L51
L50:
mov eax,0
mov eax,eax
mov [ebp+-16],eax #spill
jmp L51
L51:
mov eax,0
L52:
mov ebx,0
mov eax,[ebp+-16] #spill
cmp eax,ebx
je L36
L36:
mov eax,0
L55:
mov eax,0
mov eax,eax
jmp L58
L58:
jmp L59
L59:

#END function

#BEGIN function
L62:
mov eax,0
mov eax,eax
mov [ebp+-36],eax #spill
mov eax,0
mov eax,[ebp+8]
mov eax,[eax+-4]
sub eax,eax-1
mov ecx,eax
mov [ebp+-28],ecx #spill
mov eax,0
mov eax,1
mov eax,eax
mov [ebp+-32],eax #spill
mov eax,0
mov eax,0
mov ecx,[ebp+8]
mov ecx,[ecx+-4]
sub ecx,ecx-1
cmp eax,ecx
jle L33
L33:
jmp L31
L32:
mov eax,0
mov edx,eax
mov eax,0
mov eax,[ebp+8]
mov eax,[eax+-4]
sub eax,eax-1
mov edi,eax
mov eax,0
mov eax,1
mov esi,eax
mov eax,0
mov ecx,0
mov eax,[ebp+8]
mov eax,[eax+-4]
sub eax,eax-1
cmp ecx,eax
jle L25
L25:
jmp L23
L24:
mov eax,[ebp+8]
mov eax,[eax+8]
push eax
call L0
cmp edx,edi
jl L20
L20:
add eax,edx+1
mov edx,eax
jmp L22
L21:
mov eax,0
mov esi,eax
jmp L22
L22:
mov eax,0
L23:
mov eax,0
cmp esi,eax
je L14
L14:
mov eax,0
L26:
mov eax,0
mov eax,[ebp+8]
mov eax,[eax+8]
push eax
call L0
mov ecx,[ebp+-28] #spill
mov eax,[ebp+-36] #spill
cmp eax,ecx
jl L28
L28:
mov eax,[ebp+-36] #spill
add eax,eax+1
mov eax,eax
mov [ebp+-36],eax #spill
jmp L30
L29:
mov eax,0
mov eax,eax
mov [ebp+-32],eax #spill
jmp L30
L30:
mov eax,0
L31:
mov ecx,0
mov eax,[ebp+-32] #spill
cmp eax,ecx
je L13
L13:
mov eax,0
L34:
mov eax,0
mov eax,[ebp+8]
mov eax,[eax+8]
push eax
call L0
jmp L61
L61:

#END function

