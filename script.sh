cd boot
nasm -f bin boot.asm -o ../x86_Binary/boot.bin
cd ..
cd kernel
nasm -f elf kernel_entry.asm -o kernel_entry.o
i386-elf-gcc -ffreestanding -c kernel.c -o kernel.o
i386-elf-ld -o ../x86_Binary/kernel.bin -Ttext 0x9000 kernel_entry.o kernel.o --oformat binary
cd ../x86_Binary
cat boot.bin kernel.bin > BasicOS
qemu-system-i386 BasicOS
