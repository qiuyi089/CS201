#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int check(char frac_bit[],char  exp_bit[]);//check if the user enter the right agrument
int start(char frac_bit[],char exp_bit[],char hex_num[]);//start the conversion process
int find_frac(char frac_bit[], char hex_num[]);//find the fraction field and isolate it
int find_exp(char exp_bit[],char frac_bit[],char hex_num[]);//find the exponent field and isolate it
int check_error(char frac_bit[],char exp_bit[],int fraction,int expo,int sign);//check for INF and NaN
int sign_bit(int num,int frac,int exp);//find the sign bit and isolate it
int calculate(int f_size,int e_size,int frac,int exp,int sign);//convert the hex into the float
int norm_or_denorm(int exp,int e_size);//check whether it a normalize number or denormalize.




