org 100h
include 'emu8086.inc'

jmp start:
str1 db "assembly", 0;
str2 db "se", 0;

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
printn "Second String: sembly";
print "Length: ";
call print_num_uns;
mov dx, ax;

load:
lea si, str1;
lea di, str2;
mov dx, ax;
mov ax, 0;



check:
        mov cl,[si]
        mov bl,[di]
        
        cmp [si],0
        je stop    
        
        cmp [di],0
        je stop
        
        inc si
        inc di
        
   
        
        cmp cl,bl
        je one
        jne two



one:
        inc ax   
        printn "check"
        
        jmp check

two:             
        printn "check not"
        cmp ax,1
        je ree         
        
        mov ax,0
        lea di,str2
        jmp check     
        

ret
         
stop:    
printn "gf"
call print_num_uns;
cmp dx, ax;
je decision:

printn "";
print "Decision: Not Available in the Main String->Not Substring";
ret;

decision:
printn "";
print "Decision: Found the String->Substring";

ret


ree:
    dec si     
    printn "accessing" 
    mov ax,0
    lea di,str2
    jmp check

ret

define_print_num_uns;
