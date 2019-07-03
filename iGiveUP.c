#include<stdio.h>


int main()
{

    FILE *imem;
    //printf("\t\tEnter the number of commands you wan't to give: ");
    int commands;
    scanf("%d",&commands);
    imem=fopen("test.prog","w"); //yaha pe instructions jaynege
    int functional;
        char func[7];
        int i;
        char instructionset[25];
        char R1[4],R2[4],R3[4],c;
        int shift,jumpto,jumper,immidiate,r;
    while(commands--)
    {
        
        for(i=0;i<18;i++)
        {
            instructionset[i]='0';
        }
        instructionset[19]='\0';
        instructionset[4]='_';
        scanf("%s",func);
        functional=16;
        
        if(func[0]=='l'&&func[1]=='w') functional=0;                    // lw $a0 $a1
        if(func[0]=='s'&&func[1]=='w') functional=1;                    // sw $a0 $a1
        if(func[0]=='a'&&func[1]=='d'&&func[2]=='d') functional=2;          // add $a1 $a2 $a3
        if(func[0]=='s'&&func[1]=='u'&&func[2]=='b') functional=3;          // sub $a1 $a2 $a3
        if(func[0]=='c'&&func[1]=='o') functional=4;                        // comp $a0 $a1 
        if(func[0]=='s'&&func[1]=='l') functional=5;                        // sll $a0 $a1 2 
        if(func[0]=='s'&&func[1]=='r') functional=6;                        // srl $a0 $a1 2 
        if(func[0]=='a'&&func[1]=='n') functional=7;                         // and $a0 $a1 $a2
        if(func[0]=='o'&&func[1]=='r') functional=8;                          // or $a0 $a1 $a2
        if(func[0]=='x'&&func[1]=='o') functional=9;                           // xor $a0 $a1 $a2
        if(func[0]=='b'&&func[1]=='e') functional=10;                           // beq $a0 $a1 $a2
        if(func[0]=='b'&&func[1]=='n') functional=11;                           // bne $a0 $a1 $a2
        if(func[0]=='j') functional=12;                           // j 3             //isko dekh lo be
        if(func[0]=='a'&&func[3]=='i') functional=13;                           // addi $a0 $a1 5
        switch (functional)
        {
            case 0:                          //load R1 to R2 // lw $a0 $a1  //space se gap dena
                instructionset[0]='0';
                instructionset[1]='0';
                instructionset[2]='0';
                instructionset[3]='0';                          
                                            //BHai load word me kaha offset hota hai!
                    scanf("%s%s%d",R1,R2,&shift);
                    r = R1[2] -48;
                    
                    for(i=0;i<3;i++)
                    {
                        c=r%2+48;
                        instructionset[7-i]=c;
                        r=r/2;
                    }
                    r = R2[2] -48;
                    instructionset[8]='_';
                    for( i=0;i<3;i++)
                    {
                        c=r%2+48;
                        instructionset[11-i]=c;
                        r=r/2;
                    }     
                    instructionset[12]='_';
                    r = shift;
                    instructionset[8]='_';
                    for( i=0;i<6;i++)
                    {
                        c=r%2+48;
                        instructionset[18-i]=c;
                        r=r/2;
                    }  

                break;
            case 1:                          //store R2 in R1 // sw $a0 $a1
                instructionset[0]='0';
                instructionset[1]='0';
                instructionset[2]='0';
                instructionset[3]='1';                  
                                            //BHai store word me kaha offset hota hai! 
                   scanf("%s%s%d",R1,R2,&shift);
                    r = R1[2] -48;
                    
                    for(i=0;i<3;i++)
                    {
                        c=r%2+48;
                        instructionset[7-i]=c;
                        r=r/2;
                    }
                    r = R2[2] -48;
                    instructionset[8]='_';
                    for( i=0;i<3;i++)
                    {
                        c=r%2+48;
                        instructionset[11-i]=c;
                        r=r/2;
                    }     
                    instructionset[12]='_';
                    r = shift;
                    instructionset[8]='_';
                    for( i=0;i<6;i++)
                    {
                        c=r%2+48;
                        instructionset[18-i]=c;
                        r=r/2;
                    }  

                break;
            case 2:                          //add R1 + R2 ->R3 // add $a1 $a2 $a3
                instructionset[0]='0';
                instructionset[1]='0';
                instructionset[2]='1';
                instructionset[3]='0';
                scanf("%s%s%s",R1,R2,R3); 
                 
                     r = R1[2] -48;
                    for( i=0;i<3;i++)
                    {
                        c=r%2+48;
        
                        instructionset[7-i]=c;
                        r=r/2;
                    }
                    r = R2[2] -48;
                    instructionset[8]='_';
                    for( i=0;i<3;i++)
                    {
                        c=r%2+48;
                        instructionset[11-i]=c;
                        r=r/2;
                    }
                    r = R3[2] -48;
                    instructionset[12]='_';
                    for( i=0;i<3;i++)
                    {
                        c=r%2+48;
                        instructionset[15-i]=c;
                        r=r/2;
                    }
                break;
            case 3:                          //sub R1 - R2 ->R3 // sub $a1 $a2 $a3
                instructionset[0]='0';
                instructionset[1]='0';
                instructionset[2]='1';
                instructionset[3]='1';
                scanf("%s%s%s",R1,R2,R3);                             
                     r = R1[2] -48;
                    for( i=0;i<3;i++)
                    {
                        c=r%2+48;
                        instructionset[7-i]=c;
                        r=r/2;
                    }
                    r = R2[2] -48;
                    instructionset[8]='_';
                    for( i=0;i<3;i++)
                    {
                        c=r%2+48;
                        instructionset[11-i]=c;
                        r=r/2;
                    }
                    r = R3[2] -48;
                    instructionset[12]='_';
                    for( i=0;i<3;i++)
                    {
                        c=r%2+48;
                        instructionset[15-i]=c;
                        r=r/2;
                    }
                break;
            case 4:                          //compliment ~R1 -> R1      // comp $a0 $a1          //Check karo be
                instructionset[0]='0';
                instructionset[1]='1';
                instructionset[2]='0';
                instructionset[3]='0';               
                    scanf("%s%s",R1,R2);
                     r = R1[2] -48;
                 
                    for( i=0;i<3;i++)
                    {
                        c=r%2+48;
                        instructionset[7-i]=c;
                        instructionset[11-i]=c;
                        r=r/2;
                    }

                    r = R2[2] -48;
                    instructionset[8]='_';
                    instructionset[12]='_';

                    for( i=0;i<3;i++)
                    {
                        c=r%2+48;
                        instructionset[15-i]=c;
                        r=r/2;
                    }
                break;
            case 5:                          //Shift R1 left logical by N and save to R2 // sll $a0 $a1 $a2 
                instructionset[0]='0';
                instructionset[1]='1';
                instructionset[2]='0';
                instructionset[3]='1';   
                    scanf("%s%s%s",R1,R2,R3);                             
                     r = R1[2] -48;
                 
                    for( i=0;i<3;i++)
                    {
                        c=r%2+48;
                        instructionset[7-i]=c;
                        r=r/2;
                    }
                    r = R2[2] -48;
                    instructionset[8]='_';
                    for( i=0;i<3;i++)
                    {
                        c=r%2+48;
                        instructionset[11-i]=c;
                        r=r/2;
                    }
                    r = R3[2] -48;
                    instructionset[12]='_';
                    for( i=0;i<3;i++)
                    {
                        c=r%2+48;
                        instructionset[15-i]=c;
                        r=r/2;
                    }
                break;
            case 6:                          //Shift R1 right logical by N and save to R2 // srl $a0 $a1 $a2
                instructionset[0]='0';
                instructionset[1]='1';
                instructionset[2]='1';
                instructionset[3]='0';      
                scanf("%s%s%s",R1,R2,R3);                             
                     r = R1[2] -48;
                 
                    for( i=0;i<3;i++)
                    {
                        c=r%2+48;
                        instructionset[7-i]=c;
                        r=r/2;
                    }
                    r = R2[2] -48;
                    instructionset[8]='_';
                    for( i=0;i<3;i++)
                    {
                        c=r%2+48;
                        instructionset[11-i]=c;
                        r=r/2;
                    }
                    r = R3[2] -48;
                    instructionset[12]='_';
                    for( i=0;i<3;i++)
                    {
                        c=r%2+48;
                        instructionset[15-i]=c;
                        r=r/2;
                    }
                break;
            case 7:                          // R1 . R2 ->R3 logical // and $a0 $a1 $a2
                instructionset[0]='0';
                instructionset[1]='1';
                instructionset[2]='1';
                instructionset[3]='1';
                scanf("%s%s%s",R1,R2,R3);                             
                     r = R1[2] -48;
                    
                    for( i=0;i<3;i++)
                    {
                        c=r%2+48;
                        instructionset[7-i]=c;
                        r=r/2;
                    }
                    r = R2[2] -48;
                    instructionset[8]='_';
                    for( i=0;i<3;i++)
                    {
                        c=r%2+48;
                        instructionset[11-i]=c;
                        r=r/2;
                    }
                    r = R3[2] -48;
                    instructionset[12]='_';
                    for( i=0;i<3;i++)
                    {
                        c=r%2+48;
                        instructionset[15-i]=c;
                        r=r/2;
                    }
                break;
            case 8:                          // R1 + R2 ->R3 logical // or $a0 $a1 $a2
                instructionset[0]='1';
                instructionset[1]='0';
                instructionset[2]='0';
                instructionset[3]='0';
                scanf("%s%s%s",R1,R2,R3);                             
                     r = R1[2] -48;
                 
                    for( i=0;i<3;i++)
                    {
                        c=r%2+48;
                        instructionset[7-i]=c;
                        r=r/2;
                    }
                    r = R2[2] -48;
                    instructionset[8]='_';
                    for( i=0;i<3;i++)
                    {
                        c=r%2+48;
                        instructionset[11-i]=c;
                        r=r/2;
                    }
                    r = R3[2] -48;
                    instructionset[12]='_';
                    for( i=0;i<3;i++)
                    {
                        c=r%2+48;
                        instructionset[15-i]=c;
                        r=r/2;
                    }
                break;
            case 9:                          // R1 ^ R2 ->R3 // xor $a0 $a1 $a2
                instructionset[0]='1';
                instructionset[1]='0';
                instructionset[2]='0';
                instructionset[3]='1';
                scanf("%s%s%s",R1,R2,R3);                             
                     r = R1[2] -48;
                 
                    for( i=0;i<3;i++)
                    {
                        c=r%2+48;
                        instructionset[7-i]=c;
                        r=r/2;
                    }
                    r = R2[2] -48;
                    instructionset[8]='_';
                    for( i=0;i<3;i++)
                    {
                        c=r%2+48;
                        instructionset[11-i]=c;
                        r=r/2;
                    }
                    r = R3[2] -48;
                    instructionset[12]='_';
                    for( i=0;i<3;i++)
                    {
                        c=r%2+48;
                        instructionset[15-i]=c;
                        r=r/2;
                    }
                break;
            case 10:                          // if(R1 == R2) jump to address R3 // beq $a0 $a1 $a2
                instructionset[0]='1';
                instructionset[1]='0';
                instructionset[2]='1';
                instructionset[3]='0';
                                        scanf("%s%s%d",R1,R2,&shift);
                    r = R1[2] -48;
                    
                    for(i=0;i<3;i++)
                    {
                        c=r%2+48;
                        instructionset[7-i]=c;
                        r=r/2;
                    }
                    r = R2[2] -48;
                    instructionset[8]='_';
                    for( i=0;i<3;i++)
                    {
                        c=r%2+48;
                        instructionset[11-i]=c;
                        r=r/2;
                    }     
                    instructionset[12]='_';
                    r = shift;
                    instructionset[8]='_';
                    for( i=0;i<6;i++)
                    {
                        c=r%2+48;
                        instructionset[18-i]=c;
                        r=r/2;
                    }  

                break;
            case 11:                          // if(R1 != R2) jump to address R3 // bne $a0 $a1 $a2
                instructionset[0]='1';
                instructionset[1]='0';
                instructionset[2]='1';
                instructionset[3]='1';           
                                    scanf("%s%s%d",R1,R2,&shift);
                    r = R1[2] -48;
                    
                    for(i=0;i<3;i++)
                    {
                        c=r%2+48;
                        instructionset[7-i]=c;
                        r=r/2;
                    }
                    r = R2[2] -48;
                    instructionset[8]='_';
                    for( i=0;i<3;i++)
                    {
                        c=r%2+48;
                        instructionset[11-i]=c;
                        r=r/2;
                    }     
                    instructionset[12]='_';
                    r = shift;
                    instructionset[8]='_';
                    for( i=0;i<6;i++)
                    {
                        c=r%2+48;
                        instructionset[18-i]=c;
                        r=r/2;
                    }  

                break;
            case 12:                          // jump program counter by N  // j 3
                instructionset[0]='1';
                instructionset[1]='1';
                instructionset[2]='0';
                instructionset[3]='0';
                instructionset[4]='_';
                instructionset[8]='_';
                instructionset[12]='_';
                {
                    scanf("%d",&jumper);
                    for( i=0;i<4;i++)
                    {
                        c=jumper%2+48;
                        instructionset[18-i]=c;
                        jumper=jumper/2;
                    }
                }
                break;
            case 13:                          // add R1 + immidiate -> R2 // addi $a0 $a1 5
                instructionset[0]='1';
                instructionset[1]='1';
                instructionset[2]='0';
                instructionset[3]='0';
                    scanf("%s%s%d",R1,R2,&jumpto);
                     r = R1[2] -48;
        
                    for( i=0;i<3;i++)
                    {
                        c=r%2+48;
                        instructionset[7-i]=c;
                        r=r/2;
                    }
                    r = R2[2] -48;
                    instructionset[8]='_';
                    for( i=0;i<3;i++)
                    {
                        c=r%2+48;
                        instructionset[11-i]=c;
                        r=r/2;
                    }
                    instructionset[12]='_';
                    for( i=0;i<6;i++)
                    {
                        c=jumpto%2+48;
                        instructionset[18-i]=c;
                        jumpto=jumpto/2;
                    }
                break;
            default:
                printf("Invalid Command!\n");
                break;
        }
        
        fprintf(imem,"%s\n",instructionset);
        //printf("%s\n",instructionset);
        //fprintf(imem,"\b\b");
        //fprintf(imem,"\n");
    }
    fclose(imem);
}