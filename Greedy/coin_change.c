#include "coin_change.h"
#include <stdio.h>
#include <stdlib.h>

void read_denominations(int *denominations, int no_coin_types){
    int iterator;
    int temporary;

    for(iterator = 0; iterator < no_coin_types; iterator++){
        printf("The %d denomination is:", iterator + 1);
        scanf("%d", &temporary);
        denominations[iterator] = temporary;
    }
}

void display_results(int *count_coin_types, int *denominations, int no_coin_types){
    int amount;
    int iterator;

        printf("Please enter a integer amount between 0-10000 or -1 to exit:");
        scanf(" %d", &amount);

        while(amount != -1){
            count_coin_types = (int*)calloc(no_coin_types,sizeof(int));
            if( (amount >= 0) && (amount <= 10000) ){
                for(iterator = no_coin_types - 1; iterator >= 0; iterator--){
                    while(amount >= denominations[iterator]){
                        amount = amount - denominations[iterator];
                        count_coin_types[iterator] = count_coin_types[iterator] + 1;
                    }
                    if( (amount != 0) && (iterator == 0) ){
                        count_coin_types[0] = count_coin_types[0] + 1;
                    }
                    printf("%d number of %d denomination coins used\n", count_coin_types[iterator], denominations[iterator]);
                }
            }else{
                printf("Sorry u have entered wrong input...\n");
            }
            printf("Please enter a integer amount between 0-10000 or -1 to exit:");
            scanf(" %d", &amount);
        }
}

int read_no_coin_types(){
    int aux;

    printf("The number of coin types is:");
    scanf("%d", &aux);

    return aux;
}
