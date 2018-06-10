section .text
"	
	.db	""
	
	.db	"ÄXe`Ω"
	 .	.db	"Ä3e"
	 O	.db	"†3e"
L60:
mov ecx,[ebp+12]
mov eax,[ebp+8]
cmp ecx,eax
je L56
L56:
mov eax,[ebp+8]
push eax
L57:
mov eax,0
mov ecx,eax
mov eax,[ebp+8]
sub eax,eax-1
mov edx,eax
mov eax,1
mov [ebp+-16],eax #spill
mov esi,0
mov eax,[ebp+8]
sub eax,eax-1
cmp esi,eax
jle L54
L54:
=L53:
mul esi,ecx*4
mov eax,[ebp+8]
add eax,eax+esi
mov esi,0
cmp eax,esi
je L37
L37:
mov eax,1
mov esi,[ebp+12]
add esi,ecx+esi
mul edi,esi*4
mov esi,[ebp+8]
add esi,esi+edi
mov edi,0
cmp esi,edi
je L40
L41:
mov eax,0
L40:
mov esi,eax
L38:
mov eax,0
mov esi,eax
L39:
mov eax,0
cmp esi,eax
je L43
L42:
mov eax,1
mov esi,eax
i=mov eax,[ebp+12]
add edi,ecx+7
sub eax,edi-eax
mul edi,eax*4
mov eax,[ebp+8]
add eax,eax+edi
mov ebx,0
cmp eax,ebx
je L45
L46:
mov eax,0
mov esi,eax
L45:
mov eax,esi
L43:
mov eax,0
L44:
mov ebx,0
cmp eax,ebx
je L48
L47:
L48:
cmp ecx,edx
jl L49
L49:
add eax,ecx+1
mov ecx,eax
L50:
mov eax,0
mov [ebp+-16],eax #spill
L51:
L52:
mov ebx,0
mov eax,[ebp+-16] #spill
cmp eax,ebx
je L36
L36:
L55:
mov eax,0
L58:
L59:

L62:
®Ò‹yòmov eax,0
mov [ebp+-36],eax #spill
mov eax,[ebp+8]
sub eax,eax-1
mov ecx,eax
mov [ebp+-28],ecx #spill
mov eax,1
mov [ebp+-32],eax #spill
mov eax,0
mov ecx,[ebp+8]
sub ecx,ecx-1
cmp eax,ecx
jle L33
L33:
L32:
mov eax,0
mov edx,eax
mov eax,[ebp+8]
sub eax,eax-1
mov edi,eax
mov eax,1
mov esi,eax
mov ecx,0
mov eax,[ebp+8]
sub eax,eax-1
cmp ecx,eax
jle L25
L25:
∆eÄÛêL24:
”eπÒˆêmov eax,[ebp+8]
push eax
cmp edx,edi
jl L20
L20:
add eax,edx+1
mov edx,eax
L21:
mov eax,0
mov esi,eax
L22:
L23:
mov eax,0
cmp esi,eax
je L14
L14:
L26:
mov eax,[ebp+8]
push eax
mov ecx,[ebp+-28] #spill
mov eax,[ebp+-36] #spill
cmp eax,ecx
jl L28
L28:
mov eax,[ebp+-36] #spill
add eax,eax+1
mov [ebp+-36],eax #spill
L29:
mov eax,0
mov [ebp+-32],eax #spill
L30:
L31:
mov ecx,0
mov eax,[ebp+-32] #spill
cmp eax,ecx
je L13
L13:
L34:
mov eax,[ebp+8]
push eax
L61:

