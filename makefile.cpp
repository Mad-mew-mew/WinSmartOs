CXX=i686-elf-g++
LD=i686-elf-ld
AS=i686-elf-as

CXXFLAGS=-ffreestanding -O2 -Wall -Wextra -std=c++20
LDFLAGS=-T linker.ld -nostdlib -static

all: kernel.elf

kernel.elf: boot.o kernel.o
	$(LD) $(LDFLAGS) -o $@ boot.o kernel.o

boot.o: boot.s
	$(AS) boot.s -o boot.o

kernel.o: kernel.cpp
	$(CXX) $(CXXFLAGS) -c kernel.cpp -o kernel.o

iso: kernel.elf
	mkdir -p iso/boot/grub
	cp kernel.elf iso/boot/
	cp grub.cfg iso/boot/grub/
	grub-mkrescue -o winsmart.iso iso/

clean:
	rm -f *.o *.elf
	rm -rf iso winsmart.iso
