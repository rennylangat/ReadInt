Project: DIY Operating System
Programmed by: Naomi Burhoe, Temilolu Fayomi, Rawan Tohari 

Contents of this project include:
1.  README.txt - file that describes project parts to submit
2. bdos.txt - used to initiate BlackDos program
3. bootload - a bootloader for the project
4. compileOS.sh - the operating shell for the program
5. kasm.o - assembly level processing for program
6. kernel.c - C code for program processing

What was completed:
1- Implemented printString() function in Kernel.c
2 - Implemented handleInterrupt21() function in Kernel.c
3 - Implemented compileOS.sh shell for program
// for Lab2
4- Implemented readString(), readInt(),...

How to verify:
1. Open terminal and navigate to project folder
2. Compile OS via the command "./compileOS.sh"
3. Open bochs via the command 'echo "c" | bochs -f bdos.txt'
4. If the program has compiled correctly, the BlackDos logo should be displayed with
our author names under the logo.
5. Click the Power button for bochs to close the simulator.
6. Open the file 'printer.out' using whatever editor you like. We used the command
'nano printer.out' to open our file in the terminal. The editor should display the line
'Hello World from Naomi, Temi, and Rawan' or something similar.