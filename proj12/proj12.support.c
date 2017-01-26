
#include "/user/cse320/Projects/project12.support.h"
#include "/user/cse320/Projects/project12.hardware.h"
#include <stdio.h>


/*
The program uses different set of instructions and uses write and read reg file function.
*/


void execute()
{
    unsigned OP, RDN, OP3, i, rs1n, rs2n, simm, OP3x, OP3y, carry, simm13, imm22, OP2;
    signal5 rd, rs1, rs2;
    signal32 RS1, RS2, RD;

    
    RDN = (IR << 2);         //Code for rd
    RDN = (RDN >> 27) & 0x1f;
    rd = RDN;

    OP = (IR >> 30) & 0x3;
    
    OP3 = (IR << 7);                //Code for OP3, OP3x and OP3y
    OP3 = (OP3 >> 26) & 0x3f;
    OP3y = OP3 & 0xf;
    OP3x = (OP3 >> 4) & 0x3;
    
    rs1n = (IR << 13);            //Code for rs1 using rs1n
    rs1n = (rs1n >> 27) & 0x1f;
    rs1 = rs1n;

    i = (IR >> 13);            //Code for i with shifting IR.
    i = i & 0x1;

    rs2n = IR & 0x1f;        //Code for rs2.
    rs2 = rs2n;
    
    simm = IR & 0xfff;            //Code for SIMM13
    simm13 = (signed) simm;

    carry = (PSR >> 20) & 0x1;      //Code for carry (20th bit)
    
    imm22 = (IR << 10);        //Code for im22 

    OP2 = (IR >> 22) & 0x7;            //Code for OP2

    printf("imm22: %d \n", imm22);
    printf("rs1n: %d \n", rs1n);
    printf("rs2n: %d \n", rs2n);
    printf("RDN: %d \n", RDN);
    printf("i: %d \n", i);
    printf("rd: %d \n", rd);
    printf("OP3x: %d \n", OP3x);
    printf("OP3: %d \n", OP3);
    printf("OP3y: %d \n", OP3y);
    printf("carry: %d \n", carry);
    printf("OP2: %d \n", OP2);
    printf("OP: %d \n", OP);
    
    read_reg_file( rs1, rs2, &RS1, &RS2 );            //Calling the function read_reg_file

    printf( "Inside execute -- rs1: %d  RS1: %08X\n\n", rs1, RS1 );        //Printing RS1 and RS2
    printf( "Inside execute -- rs2: %d  RS2: %08X\n\n", rs2, RS2 );

    if (OP==0)        //Sethi
    {
        printf("Sethi \n");
        if(OP2 == 4)
        {
            printf("Sethi check \n");
            RD = imm22;
            write_reg_file( rd, RD );
        }
        else 
        {
            printf("Not Allowed");
            PSR = PSR | 0x1;        
        }
    }
    
    else if (OP == 2)        //data manipulation
    {
    printf("data manipulation \n");

    if(i == 0) 
    {
      printf("Two Registers \n ");        //Two registers
      if(OP3x == 0 && OP3y == 0)
        {
          printf("ADD");            //Add
          RD = RS1 + RS2;
      write_reg_file( rd, RD );
        } 
      else if(OP3x == 1 && OP3y == 0){
      	 printf("ADDcc");   //Addcc
	 RD = RS1 + RS2;
	 write_reg_file( rd, RD );
      }
        else if(OP3x == 0 && OP3y == 8)
        {
          printf("ADDX");            //Addx
      RD = (RS1 + RS2) + carry;
      write_reg_file( rd, RD );
        }
	else if(OP3x == 1 && OP3y == 8){
	 printf("ADDXcc");
	 RD = (RS1 + RS2) + carry;
        write_reg_file( rd, RD );
 	write_reg_file( rd, RD );
 	}
        else if(OP3x == 0 && OP3y == 3)
        {
          printf("XOR");            //Xor
          RD = RS1 ^ RS2;
      write_reg_file( rd, RD );
        }
       else if(OP3x == 1 && OP3y == 3)
        {
          printf("XORcc");            //Xorcc
          RD = RS1 ^ RS2;
      write_reg_file( rd, RD );
        }
        else if(OP3x == 0 && OP3y == 2)
        {
          printf("OR");                //or
          RD = RS1 | RS2;
      write_reg_file( rd, RD );
        }
	else if(OP3x == 1 && OP3y == 2)
        {
          printf("ORcc");                //orcc
          RD = RS1 | RS2;
      write_reg_file( rd, RD );
        }

        else if(OP3x == 0 && OP3y == 7)
        {
          printf("XNOR");            //xnor
          RD = ~(RS1 ^ RS2);
      write_reg_file( rd, RD );
        }
        else if(OP3x == 0 && OP3y == 7)
        {
          printf("XNORcc");            //xnorcc
          RD = ~(RS1 ^ RS2);
      write_reg_file( rd, RD );
        }
        else if(OP3x == 0 && OP3y == 6)
        {
          printf("ORN");            //OrN
          RD = ~(RS1 | RS2);
      write_reg_file( rd, RD );
        }
        else if(OP3x == 1 && OP3y == 6)
        {
          printf("ORNcc");            //OrNcc
          RD = ~(RS1 | RS2);
      write_reg_file( rd, RD );
        }
        else if(OP3x == 0 && OP3y == 5)
        {
          printf("ANDN");            //AndN
          RD = ~(RS1 & RS2);
      write_reg_file( rd, RD );
        }
	else if(OP3x == 1 && OP3y == 5)
        {
          printf("ANDNcc");            //AndNcc
          RD = ~(RS1 & RS2);
      write_reg_file( rd, RD );
        }

         else if(OP3x == 0 && OP3y == 1)
        {
          printf("AND");            //and
          RD = RS1 & RS2;
      write_reg_file( rd, RD );
        }
	 else if(OP3x == 1 && OP3y == 1){	//andcc
	printf("ANDcc");
	RD = RS1 & RS2;
      write_reg_file( rd, RD );
	}
        else if(OP3x == 0 && OP3y == 4)
        {
          printf("SUB");            //Sub
          RD = RS1 - RS2;
      write_reg_file( rd, RD );
        }
         else if(OP3x == 0 && OP3y == 12)
        {
          printf("SUBX");            //subx
          RD = (RS1 - RS2) - carry;
          write_reg_file( rd, RD );
        }
	else if(OP3x == 1 && OP3y == 4){
	  printf("SUBcc");   //Subcc 
          RD = RS1 - RS2;
      write_reg_file( rd, RD );
 	}
	else if(OP3x == 2 && OP3y == 5){  //sll
         printf("sll");
	 RD = RS1 << (RS2 & 0x1f);	
write_reg_file( rd, RD );
	}
	else if(OP3x == 2 && OP3y == 6){  //srl
         printf("srl");
	 RD = RS1 >> (RS2 & 0x1f);	
write_reg_file( rd, RD );
	}
        else if(OP3x == 2 && OP3y == 7){  //sra
         printf("sra");
	 RD = RS1 >> (RS2 & 0x1f);	
write_reg_file( rd, RD );
	}
      else
        {
          printf("Not Allowed");
          PSR = PSR | 0x1;
write_reg_file( rd, RD );
        }
    }

    else if(i == 1) //simm 13 // register
    {
    printf("register and simm 13 \n");
        if(OP3x == 0 && OP3y == 8)
        {
          printf("ADDX");
      RD = (RS1 + simm13) + carry;
      write_reg_file( rd, RD );
        }
        else if(OP3x == 0 && OP3y == 7)
        {
          printf("XNOR");
          RD = ~(RS1 ^ simm13);
      write_reg_file( rd, RD );
        }
        else if(OP3x == 0 && OP3y == 6)
        {
          printf("ORN");
          RD = ~(RS1 | simm13);
      write_reg_file( rd, RD );
        }
        else if(OP3x == 0 && OP3y == 5)
        {
          printf("ANDN");
          RD = ~(RS1 & simm13);
      write_reg_file( rd, RD );
        }
        else if(OP3x == 0 && OP3y == 4)
        {
          printf("SUB");
          RD = RS1 - simm13;
      write_reg_file( rd, RD );
        }
        else if(OP3x == 0 && OP3y == 3)
        {
          printf("XOR");
          RD = RS1 ^ simm13;
      write_reg_file( rd, RD );
        }
        else if(OP3x == 0 && OP3y == 2)
        {
          printf("OR");
          RD = RS1 | simm13;
      write_reg_file( rd, RD );
        }
        else if(OP3x == 0 && OP3y == 1)
        {
          printf("AND");
          RD = RS1 & simm13;
      write_reg_file( rd, RD );
        }
      else if(OP3x == 0 && OP3y == 0)
        {
          printf("ADD");
          RD = RS1 + simm13;
      write_reg_file( rd, RD );
        } 
      else if(OP3x == 1 && OP3y == 0){
      	 printf("ADDcc");   //Addcc
	 RD = RS1 + RS2;
	 write_reg_file( rd, RD );
      }
      else if(OP3x == 0 && OP3y == 12)
        {
          printf("SUBX");
      RD = (RS1 - simm13) - carry;
      write_reg_file( rd, RD );
        }
	else if(OP3x == 2 && OP3y == 5){  //sll
         printf("sll");
	 RD = RS1 << (simm13 & 0x1f);	
write_reg_file( rd, RD );
	}
        else if(OP3x == 2 && OP3y == 6){  //srl
         printf("srl");
	 RD = RS1 >> (RS2 & 0x1f);	
write_reg_file( rd, RD );
	}
	else if(OP3x == 2 && OP3y == 7){  //sra
         printf("sra");
	 RD = RS1 >> (RS2 & 0x1f);	
write_reg_file( rd, RD );
	}
      else
        {
          printf("Not Allowed");
          PSR = PSR | 0x1;
        }
    }
    }
 else
  {
    PSR = PSR | 0x1;
  }
} 
