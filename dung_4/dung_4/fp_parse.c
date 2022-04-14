#include "header.h"


int main(int argc, char * argv[]){
	//check if the user enter in the acceptable range of number
	int num = check(argv[1],argv[2]);	
	if(num == 0){
		printf("Program will now terminated. \n");
		return 0;
	}
	//if they did then convert the hex number to float base on the given information
	start(argv[1],argv[2],argv[3]);
	return 1;
}







