#include <stdio.h>
#include <stdlib.h>
#include "coin_change.h"

int determinate_no_coins(int amount, int *denomintaions, int iterator, int no_coins, int *count_coin_types){

    if(amount < denomintaions[0]){
        if(no_coins == 0){
            count_coin_types[0] = count_coin_types[0] + 1;
            return no_coins + 1;
        }else{
            count_coin_types[0] = count_coin_types[0] + 1;
            return no_coins;
        }
    }else{
        if(amount == denomintaions[iterator]){
            count_coin_types[iterator] = count_coin_types[iterator] + 1;
            return no_coins + 1;
        }else{
            if(amount > denomintaions[iterator]){
                no_coins = no_coins + 1;
                count_coin_types[iterator] = count_coin_types[iterator] + 1;
                return determinate_no_coins(amount - denomintaions[iterator], denomintaions, iterator, no_coins, count_coin_types);
            }else{
                return determinate_no_coins(amount, denomintaions, iterator - 1, no_coins, count_coin_types);
            }
        }
    }
}

void display_results(int *denominations, int iterator, int no_coins, int *count_coin_types, int no_coin_types){

    int amount;
    int iterator_1;

    printf("Please enter an integer amount between 0-10000 or -1 to exit:");
    scanf("%d",&amount);

    while(amount != -1){
        if( (amount >= 0) && (amount <= 10000) ){
            if(amount == 0){
                printf("The minimum number of coins needed is 0...\n");
            }else{
                determinate_no_coins(amount, denominations, iterator, no_coins, count_coin_types);
                for(iterator_1 = 0; iterator_1 < no_coin_types; iterator_1++){
                    printf("%d number of %d denomination coins used\n", count_coin_types[iterator_1], denominations[iterator_1]);
                }
            }
        }else{
            printf("Sorry you have entered wrong input...\n");
        }

        printf("Please enter an integer amount between 0-10000 or -1 to exit:");
        scanf("%d", &amount);
        no_coins = 0;
        count_coin_types = (int*)calloc(no_coin_types,sizeof(int));
    }
}

void read_denominations(int *denominations, int no_coin_types){

    int iterator;
    int temporary;

    for(iterator = 0; iterator < no_coin_types; iterator++){
        printf("The %d denomination is:", iterator + 1);
        scanf("%d", &temporary);
        denominations[iterator] = temporary;
    }

}

int read_no_coin_types(){
    int aux;

    printf("The number of coin types is:");
    scanf("%d", &aux);

    return aux;
}
