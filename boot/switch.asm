[bits 16]
switch:
cli
lgdt [gdt_descriptor]

mov eax, cr0
or eax,0x1
mov cr0,eax

jmp CODE:init


[bits 32]
init:
mov ax,DATA
mov ds,ax
mov ss,ax
mov es,ax
mov fs,ax
mov gs,ax

mov ebp,0x90000
mov esp,ebp

call begin