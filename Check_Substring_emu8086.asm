org 100h
include 'emu8086.inc'

jmp start:
str1 db "assembly", 0;
str2 db "sscdgf", 0;

start:
lea si , str1;
lea di , str2;
mov ax, 0;
mov cx, 0;

findLengthOne:
cmp [si], 0;
je done1;
inc si;
inc ax;
jmp findLengthOne;

done1:
printn "Main String: assembly";
print "Length: ";
call print_num_uns;
mov ax, 0;

findLengthTwo:
cmp [di], 0;
je done2;
inc di;
inc ax;
jmp findLengthTwo;

done2:
printn "";
printn "Second String: sscdgf";
print "Length: ";
call print_num_uns;
mov dx, ax;

load:
lea si, str1;
lea di, str2;
mov dx, ax;
mov ax, 0;

check:
mov bl, [si];
mov bh, [di];

cmp [si] , 0;
je stop:

cmp bl,bh;
je one;

inc si;

jmp check;

one:
inc ax;
inc di;
jmp check;

stop:
;call print_num_uns;
cmp dx, ax;
je decision:

printn "";
print "Decision: Not Available in the Main String->Not Substring";
ret;

decision:
printn "";
print "Decision: Found the String->Substring";


define_print_num_uns;
