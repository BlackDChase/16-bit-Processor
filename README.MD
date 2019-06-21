__Processor Written in HDL iVerilog__
    Instruction set is of 16 bit
    Memory is of 8 bit

_INPUT_
-   Input is having 15 instructions
-   Input is entered in `input.txt` file.
-   `iGiveUP.c` is our assembler which takes input in assembly our language and converts it into binary format. Finally storing it into `test.prog`.

*We have already entered those 15 instructions in `input.txt` file*

_Input Instructions type_
IMMIDEATE TYPE
    lw    reg_for_loading   reg_for_supplying   offset
    sw    reg_for_storing   reg_for_supplying   offset
    addi  reg_for_answer    reg_intake          immidiate_value

R TYPE

J TYPE

_Assembeling command_
```
    gcc iGiveUP.c
    cat input.txt | ./a.out
```
_Command to start the working of processor_
```
    iverilog -o cpu.vvp *.v
    vvp cpu.vvp
```
_Finally_
    Final memory is stored in  mem_res.dat
    Final register values are stored in result.dat

*This project is the work of Aditya Kumar, Abhinav Batta, Harsh Kochar, Kamran Hussain and Nikhil Gujrati*
*It is done under supervision of Dr.Bibhas Ghosal Asst. Prof. of IT dept. in IIIT Allahabad*
*Further Detailed in The Prestaion file `COA.pptx`*
IIT2018010 - Abhinav Batta
IIT2018036 - Kamran Hussain
IIT2018046 - Aditya Kumar
IIT2018048 - Nikhil Gujrati
IIT2018049 - Harsh Kochar