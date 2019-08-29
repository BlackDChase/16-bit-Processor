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
    sw    reg_for_supplying reg_for_storing     offset
    addi  reg_intake        reg_for_answer      immidiate_value
    bne   reg_intake        reg_for_answer      offset
    beq   reg_intake        reg_for_answer      offset

R TYPE
    add   reg_read1     reg_read2       reg_wite
    sub   reg_read1     reg_read2       reg_wite
    or   reg_read1     reg_read2       reg_wite
    and   reg_read1     reg_read2       reg_wite
    xor   reg_read1     reg_read2       reg_wite
    sll   reg_read1     reg_read2       reg_wite
    srl   reg_read1     reg_read2       reg_wite
    comp  reg_read      reg_dest       

J TYPE
    j jump_addr[4 bit]

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

__Credits__

IIT2018036 - Kamran Hussain & IIT2018049 - Harsh Kochar (BlackDChase@github):w
    Made ppt
    Desgined ALU
    Desgined Instruction Memory
    Desgined CU
    Desgined and Programmed Assembler 

IIT2018046 - Aditya Kumar (devill71@github) & IIT2018048 - Nikhil Gujrati
    Programmed all the modules
    


*This project is the work of Aditya Kumar, Abhinav Batta, Harsh Kochar, Kamran Hussain and Nikhil Gujrati*
*It is done under supervision of Dr.Bibhas Ghosal Asst. Prof. of IT dept. in IIIT Allahabad*

*Further Detailed in The Prestaion file `COA.pptx`*
