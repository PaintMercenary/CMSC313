AUTHOR: L.MOORE CMSC313 M/W 2:30-3:45PM
PURPOSE OF SOFTWARE: Shoddy hex to ASCII converter.
FILES:
ascii.asm (You're not gonna believe what this does)

BUILD INSTRUCTIONS:
nasm -f elf32 -g -F dwarf -o ascii.o ascii.asm
ld -m elf_i386 ascii.o -o ascii

TESTING METHODOLOGY: Took the sample input from the homework, slapped it in.
ADDITIONAL INFORMATION: It runs.
