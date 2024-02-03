; visit the link for tutorial: https://faculty.kfupm.edu.sa/COE/shazli/coe205/Help/asm_tutorial_06.html

org 100h
include 'emu8086.inc'

jmp start:
normalString db 'code$'; try with more string to check Palindrome or not Palindrome like madam(Palindrome), itopinonavevanonipoti(Palindrome), abeg((Not Palindrome) etc
revString db '1234';

start:
lea si , normalString;
lea bx, revString; take it as 16 bit register to print by 21h register
mov ax, 0;

findLength:
	cmp [si], '$';
	je done;
	inc si;
	inc ax;
	inc bx;
jmp findLength;

done:
	printn "Normal String: code";
	print "NormalString Length: ";
	call print_num_uns;
	mov cx, ax;
	sub ax, 1;
;call print_num_uns;
lea si, normalString;
mov [bx], '$'; insert '$' into the last index of revString
dec bx; point to the last index 

printn "";

print "Reversed String: ";

reverseProcess:
	mov dl, [si];
	mov [bx], dl;
	inc si;
	dec bx;
loop reverseProcess;

; print the Reversed String
lea dx,revString;
mov ah,09h;
int 21h;

printn "";

load:
	lea bx, revString;
	lea si, normalString;
	mov cx, ax;
	mov ax, 0;

findLengthbx:
	cmp [bx], '$';
	je done2;
	inc bx;
	inc ax;
jmp findLengthbx;

done2:
print "Reversed String Length: ";
call print_num_uns;
printn "";

load_again:
	lea bx, revString;
	lea si, normalString;
	mov cx, ax;
	mov ax, 0;

checkPalindrome:
	mov al, [si];
	mov dl, [bx];
	inc si;
	inc bx;
	cmp al, dl;
	jne decision;
loop checkPalindrome;

print "Decision: Palindrome";
ret;

decision:
print "Decision: Not Palindrome";


; wait for any key press....
mov ah, 0;
int 16h;

define_print_num_uns;
