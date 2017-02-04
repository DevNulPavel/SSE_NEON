COMPILE:
	arm-linux-androideabi-as -o arm.o arm.s
	arm-linux-androideabi-ld -Ttext=0x0 -o arm.elf arm.o
	arm-linux-androideabi-objcopy -O binary arm.elf arm.bin

START:
	# qemu-system-arm -machine connex -pflash -nographic -serial /dev/null flash.bin 
	qemu-system-arm -machine connex -pflash flash.bin

CREATE_FLASH:
	dd if=/dev/zero of=flash.bin bs=4096 count=4096
	dd if=arm.bin of=flash.bin bs=4096 conv=notrunc