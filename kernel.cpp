// ===========================
// WinSmart OS - C++ Kernel
// ===========================
extern "C" void kernel_main();

// VGA memory for printing
volatile unsigned short* vga = (unsigned short*)0xB8000;
int cursor = 0;

// Print character
void print_char(char c) {
    if (c == '\n') {
        cursor = (cursor / 80 + 1) * 80;
        return;
    }
    vga[cursor++] = (0x0F << 8) | c;
}

// Print string
void print(const char* s) {
    while (*s) print_char(*s++);
}

// Kernel entry (called from assembly)
extern "C" void kernel_main() {
    print("WinSmart OS Booting...\n");
    print("C++ Kernel Loaded Successfully.\n\n");
    print("Welcome to WinSmart OS.\n");
    print("System Halted.\n");

    while (1) asm("hlt");
}
