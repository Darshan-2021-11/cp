#include<stdio.h>

int numberPlateCompare(char *plate1, char *plate2) {
	char x, y;
	for (int i = 0; i < 6; ++i) {
		x = *plate1++, y = *plate2++;
		if (x != y) return x < y;
	}
	// if same, return 2
	return 2;
}

int main() {
	char numberPlate[2][7];
	_Bool act = 0;
	while (scanf("%s",numberPlate[act]) != EOF) {
		act= 1 - act;
		if(act == 0){
			// Call your string compare function here on numberPlate[0] and numberPlate[1].
			printf("%d\n", numberPlateCompare(numberPlate[0], numberPlate[1]));
		}
	}
	return(0);
}
