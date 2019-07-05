[org 0x7c00]
mov bp,0x8000
mov sp,bp

mov ax,0x07e0
mov es,ax


mov ax,0x4f01
mov cx,0x0107
mov di,0x0000
int 10h

mov ax,0x4f02
mov bx,0x4107
int 10h

mov di,0x0028
mov al,[di]
cmp al,0
je ove

mov ah,0eh
mov al,'A'
int 10h

mov ah,0x42
mov dl,0x80
mov si,DAP1
int 13h

call switch
jmp $

ove:
jmp $

DAP1:
db 0x10
db 0x0
dw 0x30
dw 0x0000
dw 0x0900
dq 0x1

%include "gdt.asm"
%include "switch.asm"
[bits 32]
begin:
;mov ah,[0x7e2B]
;mov al,[0x7e2A]
;shl eax,16
;mov ah,[0x7e29]
;mov al,[0x7e28]
;mov ebx,0x7f
;mov ecx,0x140000
;.ef:
;mov [eax],ebx
;inc eax
;loop .ef

call 0x9000
msg db "VESA is Compatible",0
times 510-($-$$) db 0
dw 0xaa55
