#include<stdio.h> 

int decode( int num, const char* a, char* b){
	int loop;			//Counter for the loop.
	for (loop = 0; loop < 24; loop++) {			//For replacing all the random characters with whitespaces, without this, wierd characters would show up.
      b[loop] = ' ';
	}
	
	
	char flag='p';			//To determine the number enetered is positive or negative.
	if(num>0){
		flag = 'p';
	}
	else{
		flag='n';
		num = num*(-1);
	}
	
	
	if(a=="hex"){			//If the conversion is to be hexadecimal.
		int index = 0;		//Counter.
		int temp;			//Stores the current character.
		while(num!=0){			//Loop for the acutal conversion.	
			temp = num % 16;			
			num = num / 16;
			if (temp >= 10) {			
				b[index++] = temp + '7';
			} else {
				b[index++] = temp + '0';
			}
		}
		if(flag=='p'){			//Adds a '+' or a '-' sign appropriately at the end.
			b[index++]='+';
		}
		else{
			b[index++]='-';
		}
		int j,k, count;
		
		char temporary;
		for(k=index-1,j=0;k > j;k--,j++){			//Reverses the the char array.
			temporary = b[k];
			b[k] = b[j];
			b[j] = temporary;
			count++;
		}
		
	}
	else if(a=="dec"){		//If the conversion is to be decimal.
		int index = 0;		//Counter
		int temp;			//Stores the current character.
		while(num!=0){			//Loop for the acutal conversion.
			temp = num % 10;
			num = num / 10;
			b[index++] = temp + '0';
		}
		if(flag=='p'){			//Adds a '+' or a '-' sign appropriately at the end.
			b[index++]='+';
		}
		if(flag=='n'){
			b[index++]='-';
		}
		int j,k;
		char temporary;
		for(k=index-1,j=0;k > j;k--,j++){		//Reverses the the char array.
			temporary = b[k];
			b[k] = b[j];
			b[j] = temporary;
		}
	} 
	else if(a=="oct"){		//If the conversion is to be octal.
		int index = 0;		//Counter
		int temp;			//Stores the current character.
		while(num!=0){			//Loop for the actual conversion.
			temp = num % 8;	
			num = num / 8;
			b[index++] = temp + '0';
		}
		if(flag=='p'){			//Adds a '+' or a '-' sign appropriately at the end.
			b[index++]='+';
		}
		else{
			b[index++]='-';
		}
		int j,k;
		char temporary;
		for(k=index-1,j=0;k > j;k--,j++){			//Reverses the the char array.
			temporary = b[k];
			b[k] = b[j];
			b[j] = temporary;
		}
	} 	
	else if(a=="bin"){
		int index = 0;
		int temp;
		while(num!=0){
			temp = num % 2;
			num = num / 2;
			// printf("%c", (temp+'0'));
			b[index++] = temp + '0';
		}
		if(flag=='p'){			//Adds a '+' or a '-' sign appropriately at the end.
			b[index++]='+';
		}
		else{
			b[index++]='-';
		}
		int j,k;
		char temporary;
		for(k=index-1,j=0;k > j;k--,j++){			//Reverses the the char array.
			temporary = b[k];
			b[k] = b[j];
			b[j] = temporary;
		}
	}
}
