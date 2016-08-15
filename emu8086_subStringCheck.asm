org 100h
include 'emu8086.inc'

jmp start:
str1 db 'assembly', 0;
str2 db 'sdf', 0;

start:
mov si, 0;
mov di, 0;
mov ax, 0;

lengthOfFirstString:
	cmp str1[si],0;
	je gotLengthOne;
	inc ax;
	inc si;
jmp lengthOfFirstString;

gotLengthOne:
	print "First String Length: ";
	call print_num_uns;
	printn "";
	mov ax, 0;
	mov si, 0;
	mov di, 0;


lengthOfSecondString:
	cmp str2[di], 0;
	je gotLengthTwo;
	inc di;
	inc ax;
jmp lengthOfSecondString;

gotLengthTwo:
	print "Second String Length: ";
	call print_num_uns;
	printn "";
	mov di, 0;
	mov si, 0;
	mov bx, ax;
	mov ax, 0;

substringCheck:
	cmp str1[si], 0;
	je stop;
	
	mov dl, str1[si];
	mov cl , str2[di];
	
	cmp str1[si], 0;
	je stop;
	
	cmp str2[di], 0;
	je stop;
	
	inc si;
	inc di;
	
	cmp dl, cl;
	je one;
	jne two;
	
jmp substringCheck;

one:
		inc ax;
		jmp substringCheck;
two:
	cmp ax, 1;
	je temp;

	mov ax, 0;
	mov di, 0;
	jmp substringCheck;

temp:
	dec si;
	mov ax, 0;
	mov di, 0;
	jmp substringCheck;
	
stop:
	cmp bx, ax;
	je decision;
	
	printn "Decision: Not Substring";
	ret;
	
decision:
	printn "Decision: Substring";
	
define_print_num_uns;
ret;
