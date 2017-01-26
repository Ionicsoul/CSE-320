#include "/user/cse320/Projects/project11.support.h"
#include <stdio.h>
int main()
{
	unsigned PC = 0x00000001;
	unsigned PSR = 0x00000000; 
	unsigned IR = 0x00800001; 
	unsigned nPC = 0x00000000;	

	IR = 0x40002002; 
	nPC = update(nPC, PC, IR, PSR);
	printf("\nCall = %08x", nPC);
	
	IR = 0x02a00101; 
	nPC = update(nPC, PC, IR, PSR);
	printf("\nBE= %08x", nPC);

	IR = 0x40984002; 
	nPC = update(nPC, PC, IR, PSR);
	printf("\nJMPL= %08x", nPC);
	
	
	IR = 0x81186001; 
	nPC = update(nPC, PC, IR, PSR);
	printf("\nBN= %08x", nPC);

	
	IR = 0x00800002; 
	nPC = update(nPC, PC, IR, PSR);
	printf("\nBL= %08x", nPC);

	IR = 0x02800001; 
	nPC = update(nPC, PC, IR, PSR);
	printf("\nBLE= %08x", nPC);
	
	IR = 0x04800001;  
	nPC = update(nPC, PC, IR, PSR);
	printf("\nBLEU= %08x", nPC);


	IR = 0x0A800001;  
	nPC = update(nPC, PC, IR, PSR);
	printf("\nBCS= %08x", nPC);

	IR = 0x0E800001;  
	nPC = update(nPC, PC, IR, PSR);
	printf("\nBVS= %08x", nPC);

	
	IR = 0x10800001; 
	nPC = update(nPC, PC, IR, PSR);
	printf("\nBA= %08x", nPC); 
	

	IR = 0x0C800001;  
	nPC = update(nPC, PC, IR, PSR);
	printf("\nBNEG= %08x", nPC);


	IR = 0x14800001; 
	nPC = update(nPC, PC, IR, PSR);
	printf("\nBG= %08x", nPC);
	

	IR = 0x16800001; 
	nPC = update(nPC, PC, IR, PSR);
	printf("\nBGE= %08x", nPC);
	
	IR = 0x12800001; 
	nPC = update(nPC, PC, IR, PSR);
	printf("\nBNE= %08x", nPC);

	PSR = 0x00100000;
	IR = 0x18800001; 
	nPC = update(nPC, PC, IR, PSR);
	printf("\nBGU= %08x", nPC);


	IR = 0x1E800001; 
	nPC = update(nPC, PC, IR, PSR);
	printf("\nBVC= %08x", nPC);

	IR = 0x1C800001; 
	nPC = update(nPC, PC, IR, PSR);
	printf("\nBCC= %08x", nPC);


	PSR = 0x00080000;
	IR = 0x1C800001; 
	nPC = update(nPC, PC, IR, PSR);
	printf("\nBPOS= %08x", nPC);
	
	printf("\n");

}