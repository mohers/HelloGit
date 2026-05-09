How to compile and run my program?

Using CLion:

1. Download main.c, waveform.c, waveform.h, io.c and io.h. 
2. Open these files in CLion
3. set CMakeLists.txt line 4 to set(CMAKE_C_STANDARD 99)
4. ensure the downloaded files are listed as executables
5. Press Run on CLion
6. Enter full name of your .CSV file (Including suffix)
7. open results.txt for your results

Using GCC:

if GCC is installed use the command "gcc -std=99 main.c waveform.c io.c -o desiredname -lm" whilst on powershell