//#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

/**********************************************************************
 * Function: is_int
 * Description: This function will output whether the input is an int or no.
 * Parameters: Says whether the input is an int not a number, so no floats.
 * Pre-Conditions: Input any value
 * Post_Conditions: Either a yes or a no (1 or 0) to indicate whether the input was an int or not
 * *********************************************************************/

bool is_int(char* num){
	bool c_num = 0;
	int len = 0;
	int l = strlen(num);

	while(num[len] != '\0'){
		if(((num[len]> 47) && (num[len] < 58)) || (num[len] == 45 )){
			len++;
		}
		else{
			break;
		}
	c_num = 1;
	}

	return c_num;
}

/*******************************************************************************
 * Function: get_int, get_float
 * Description: If the input was said to be an int or a float then this will convert the string to the int/float
 * Parameters: Not very precise, doesn't work with negatives
 * Pre-Conditions: Taking user input for a string
 * Post-Conditions: A string or float respectively
 * ************************/
/*int get_int (char* bin){
	int res = 0;
  int i;
	for ( i = 0;i < strlen(bin); i++){
		int check = bin[i]- '0';
    int w = strlen(bin);
    double idk = (w - i) -1;
    double woo = pow(10.0,2);
    //pow(10.0,strlen(bin));
//		int check2  = pow(10,bin.length()-i-1);
		//res = (check*pow(10,w-i-1)) + res;

//		cout << check << check2 << res << endl << endl << endl;
	}
	return res;
}
*/
int main(){

  srand(time(NULL));
  int s_height = 0;
  int s_width = 0;
  int height = 0;
  int width = 0;
  int ask = 0;
  int i =0;
  int k = 0;
  int z =0;
  int ll = 0;
  int **arr = NULL;

  do{
  printf("Enter your height: ");
  scanf("%d", &s_height);
}while ( (s_height > 10) || (s_height < 1) );


do{
printf("Enter your width: ");
scanf("%d", &s_width);
}while ( (s_width > 10) || (s_width < 1) );

//  printf("Height: %d, Width: %d ", s_height, s_width);
  //printf("10");

arr = malloc(sizeof(int*)*s_width);
//printf("1");

//printf("2");
for (i = 0; i < s_width; i++){
  arr[i] = malloc(sizeof(int)*s_height);
}
//printf("3");
printf("\n");

for (k = 0; k < s_width; k++){
  for (z = 0; z < s_height; z++){
  //printf("WOOOO");
  arr[k][z] = rand()%50+1;
  printf("%d\t", arr[k][z]);
  }
  printf("\n");
}

do{
printf("Enter your add number: ");
scanf("%d", &ask);
}while ( (ask > 10) || (ask < 1) );

for (k = 0; k < s_width; k++){
  for (z = 0; z < s_height; z++){
  //printf("WOOOO");
  arr[k][z] = arr[k][z] + ask;
  printf("%d\t", arr[k][z]);
  }
  printf("\n");
}

for (i =0; i < s_width; i++){
    free(arr[i]);
    printf("hhhhh");

}

free(arr);

  return 0;
}
