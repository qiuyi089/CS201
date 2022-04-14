#include "header.h"

//check for the right agruement
int check(char frac_bit[],char exp_bit[]){
	int	frac = strtol(frac_bit,NULL,10);//convert the fraction input to number
	int exp  = strtol(exp_bit,NULL,10);//convert the exponent input to number
	//check if it is in range of 2 and 10
	if(frac > 10 || frac < 2){
		printf("Invalid fraction bit(%d) should be between 2 and 10\n",frac);
		return 0;
	}
	//check if it is in range of 3 and 5
	else if(exp > 5 || exp < 3){
		printf("Invalid exponent bit(%d) should be between 3 and 5 \n",exp);
		return 0;
	}
	return 1;
}
//start the convert process
int start(char frac_bit[],char exp_bit[],char hex_num[]){
	int exp = find_exp(exp_bit,frac_bit,hex_num);//find the exponent number
	int frac = find_frac(frac_bit,hex_num);//find the fraction number
	int number = strtol(hex_num,NULL,16);//convert the hex to long 
	int32_t f_bit = strtol(frac_bit,NULL,10);//store the bit size of the fraction bit
	int32_t e_bit = strtol(exp_bit,NULL,10);//store the bit size of the exponent bit
	int sign = sign_bit(number,f_bit,e_bit);//store the sign bit
	int check = check_error(frac_bit,exp_bit,frac,exp,sign);//check for error with the information that the user provide
	//if it 0 then the program will terminate
	if(check == 0){
		printf("Program will now terminate. \n");
		return 0;
	}
	//else it will calculate the number
	else{
		calculate(f_bit,e_bit,frac,exp,sign);
		return 0;	
	}
	return 1;	
}
//convert the number into float number.
int calculate(int f_size,int e_size,int frac,int exp,int sign){
	int check = norm_or_denorm(exp,e_size);//check if it normalize or denormalize
	//if it is normalize then do the following way
	if(check == 1){
		float M = frac / pow(2,f_size);
		float bias = pow(2,f_size - 1) - 1;
		float E = 1 - bias;
		float v = M * pow(2,E);
		if(sign == 0)
			printf("The number is: %f \n",v);
		else if(sign == 1)
			printf("The number is: -%f \n",v);
	}
	//else use a different way to find the number
	else if(check == 2){
		float M = (frac/pow(2,f_size)) + 1;
		float  bias = pow(2,f_size - 1) - 1;
		float E = exp - bias;
		float v = M * pow(2,E);
		if(sign == 0)
			printf("The number is: %f \n",v);
		else if(sign == 1)
			printf("The number is: -%f \n",v);
	}
	return 0;
}
//check if it normalize or denormalize
int norm_or_denorm(int exp,int e_size){
	//if the exponent bit is all 0's then it normalize
	if(exp == 0){
		return 1;
	}
	//if all the exponent bit is mix then it is denormalize
	if(exp != 0 && exp != (pow(2,e_size) - 1)){
		return 2;
	}
	return 0;
}
//find and isolate tthe fraction bit using bit mapping
int find_frac(char frac_bit[],char hex_num[]){
	int32_t a = strtol(frac_bit,NULL,10);
	int32_t b = strtol(hex_num,NULL,16);
	int32_t c = pow(2,a) - 1;

	return b&c;
}
//find and isolate the sign bit using bit mapping
int sign_bit(int num,int frac,int exp){
	return num >> (frac + exp);
}
//find and isolate the exponent bit using bit mapping 
int find_exp(char exp_bit[],char frac_bit[],char hex_num[]){
	int32_t a = strtol(exp_bit,NULL,10);
	int32_t b = strtol(hex_num,NULL,16);
	int32_t c = strtol(frac_bit,NULL,10);
	int32_t d = b >> c;
	int32_t e = pow(2,a) - 1;

	return d&e;
}
//check for INF and NaN
int check_error(char fraction_bit[],char exp_bit[],int fraction,int expo,int sign){
	int32_t ex_bit = strtol(exp_bit,NULL,10);
	//if tthe exponent bit is all 1's and fracttion is all 0's
	if(expo == (pow(2,ex_bit) - 1) && fraction == 0){
		if(sign == 0){
			printf("+INF \n");
			return 0;
		}
		else if(sign == 1){
			printf("-INF \n");
			return 0;
		}
	}
	//if the exponent is all 1's and fracttion is not 0's
	if(expo == (pow(2,ex_bit) - 1) && fraction != 0){
		printf("NaN \n");
		return 0;
	}
	return 1;

}






