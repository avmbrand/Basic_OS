[bits 32]
[extern _start]
global keyboard_handler
global keybord_unmask
global keybord_mask
global keybord_listen
global load_idt

call init_pic
call _start
jmp $

init_pic:
mov dx,0x20
mov al,0x11
out   dx, al
mov dx,0xA0	; initialization
mov al,0x11
out   dx, al

mov dx,0x21
mov al,0x20
out   dx, al 
mov dx,0xA1 ; offset
mov al,0x28
out   dx, al

mov dx,0x21
mov al,0x00
out   dx, al	; setup cascading
mov dx,0xA1
mov al,0x00
out   dx, al

mov dx,0x21
mov al,0x01
out   dx, al
mov dx,0xA1	;environment
mov al,0x01
out   dx, al

mov dx,0x21
mov al,0xff
out   dx, al
mov dx,0xA1	; masking
mov al,0xff
out   dx, al

ret

keybord_unmask:
mov dx,0x21
mov al,0xFD
out   dx, al
ret

EOI:
mov dx,0x20
mov al,0x20
out   dx, al
ret

keybord_listen:
call EOI
mov dx,0x60
in al, dx
;mov ebx,0xb8000
;mov [ebx],al
mov ebx,0x5000
mov [ebx],al
ret

keybord_mask:
mov dx,0x21
mov al,0xFF
out   dx, al
ret


load_idt:
mov edx,[esp + 4]
lidt [edx]
sti
ret

keyboard_handler:
	call keybord_listen
iretd