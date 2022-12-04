#include <stdio.h>

int main(){

    FILE *fptr;
    int number[110] = {0};
    int index_n = 0;
    char a = 0;
    int temp[5] = {0};
    int index_t = 0;
    int length = 0;

    fptr = fopen("number.txt", "w");
    for(int n=1; n<=100; n++){
        fprintf(fptr, "%d%c", n, '\n');
    }
    if(fptr != NULL){
        fclose(fptr);
    }

    fptr = fopen("number.txt", "r");
    if(fptr == NULL){
        printf("[-] File cannot be opened.");
        return -1;
    }
    else{
        while((a=fgetc(fptr)) != EOF){
            
            if(a != '\n'){      //read until '\n' or your special character
                temp[index_t++] = a-48;
            }
            //************** character to integer conversion **************//
            else{
                length = index_t;   //number of character in temp array
                while((index_t) != 0){      // arranging integers to their respective number positions
                    if((length-index_t) == 0){  //for 10^0 case
                        temp[index_t-1] *= 1;
                    }
                    else{   //for 10^1 and above cases
                        for(int i=0; i < (length-index_t); i++){
                            temp[index_t-1] *= 10;
                        }
                    }
                    index_t--;
                }
                while(--length != -1){
                    number[index_n] += temp[length];    // combining integers with respective positional arrangement  
                                                        //for instance, if 12, number[index] = 10 + 2,and so on...
                }
                index_n++;
            }
            //***************** End of conversion **************************//
        }
        if(fptr != NULL){
            fclose(fptr);
        }
        printf("The values stored in the array: \n");
        for(int i=0; i < index_n; i++){
            printf("%d ", number[i]);
        }
    }
    return 0;
}