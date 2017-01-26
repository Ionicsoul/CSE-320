#include "/user/cse320/Projects/project11.support.h"


unsigned update( unsigned nPC, unsigned PC, unsigned IR, unsigned PSR ){
	
	unsigned op, op2, op3, rs1, rs2, condition, nzvc, n, z, v, c, simm13, i, disp30, disp22;

	op = IR >> 30;
	
	op3 = IR << 7;
	op3 = op3 >> 26;
	
	op2 = (IR << 7) >> 29;
	
	rs1 = (IR << 13) >> 27;
	
	rs2 = (IR << 27) >> 27;
	
	condition = ((IR << 3) >> 28);
	
	unsigned val;
	val = IR >> 29;
	
	
	n = PSR << 8;
	n = n >> 31;
	
	z = PSR << 9;
	z = z >> 31;
	
	v = PSR << 10;
	v = v >> 31;
	c = PSR << 11 >> 31;
	
	simm13 = (IR << 19) >> 19;
	
	disp30 = IR << 2;
	disp30 = IR >> 2;
	
	unsigned res;
	unsigned temp;
	
	if(op == 1){
		res = PC + (((IR << 2 )>> 2) * 4);
		return res;
	}
	else if(op == 2 && op3 == 56){
		if(i == 0){
			temp = (rs2 << 24) + (rs2 << 16);
			temp = temp + (rs2 << 8) + rs2;
		}
		else{
			temp = simm13;
		}
		res = (rs1 << 24) + (rs1 << 16);
		res = res + (rs1 << 8) + rs1;
		res = res + temp;
		return res;
	}
	else if(op == 0 && op2 == 2){
		if(val == 0 && condition ==0){
			res = nPC + 4;
			return res;
		} 
		else if(val == 0 && condition == 1 && z == 1){
			res = disp22 * 4 + PC;
			return res;
		}
		else if(val == 0 && condition == 1){
			res = nPC + 4;
			return res;
		}
		else if(val ==0 && condition == 2){
			unsigned boo = z || (n ^ v);
			if(boo){
				res = disp22*4 + PC;
				return res;
			}
			else
				res = nPC + 4;
		}
		if (val ==0 && condition == 3) {
			unsigned boo = n^v;
                if(!boo)
                    res = nPC + 4;
                else
					res = disp22 * 4 + PC;                    
				return res;
		}

		if (val ==0 && condition == 4) {
			unsigned boo = c || z;
			if(!boo)
				res = nPC + 4;
			else
				res = disp22 * 4 + PC;
			return res;
		}

		if (val ==0 && condition == 5) {
			if(!c)
				res = nPC + 4;
			else
				res = disp22 * 4 + PC;
			return res;
		}

		if (val ==0 && condition == 6) {
			if(!n)
				res = nPC + 4;
			else
				res = disp22 * 4 + PC;
			return res;
		}

		if (val ==0 && condition == 7) {
			if(!v)
				res = nPC + 4;
			else
				res = disp22 * 4 + PC;
			return res;
		}

		if (val ==0 && condition == 8) {
			res = disp22 * 4 + PC;
			return res;
		}

		if (val ==0 && condition == 9) {
			if(z)
				res = nPC + 4;
			else
				res = disp22 * 4 + PC;
			return res;
		}

		if (val ==0 && condition == 10) {
			if(!(z || (n ^ v)))
				res = disp22 * 4 + PC;
			else
				res = nPC + 4;
			return res;
		}

		if (val ==0 && condition == 11) {
			if(!(n ^ v))
				res = disp22 * 4 + PC;
			else
				res = nPC + 4;
			return res;	
		}

		if (val ==0 && condition == 12) {
			if(c==0 && z==0)
				res = disp22 * 4 + PC;
			else
				res = nPC + 4;
			return res;
		}

		if (val ==0 && condition == 13) {
			if(c)
				res = nPC + 4;
			else
				res = disp22 * 4 + PC;
			return res;
		}

		if (val ==0 && condition == 14) {
			if(n)
				res = nPC + 4;
			else
				res = disp22 * 4 + PC;
			return res;
		}

		if (val ==0 && condition == 15) {
			if(v)
				res = nPC + 4;
			else
				res = disp22 * 4 + PC;
			return res;
		}
	}
	else{
		res = nPC + 4;
		return res;
	}
}
