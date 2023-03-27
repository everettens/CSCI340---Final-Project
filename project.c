#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "project.h"

/* 
    Declare static variables, if needed

    
*/
double cacheRefTime;



/*
    Functions...

*/



int get_cache_block_size(int maximum){
    int block_size;
    long start;
    int lenChange = (8*MB) -1;
    double avgTime, currTime;
    int time = 0;
    int l1_size;
    int l2_size;
    int l3_size;
    int level_jump = 0;
    double temp_time_1, temp_time_2 = 0;
    static int array[8*MB];
    int i,j;
    unsigned int k;
    int count = 0;
    double cacheRefTime;
    
    int cache_size;

    

    // outer loop, tests 2^n
    for(i=1;i<=maximum;i*=2){
        temp_time_1 = avgTime;
        avgTime=0;
        //int cache_jump;
        //printf("DEBUG: temptime1: %lf\n", temp_time_1);


        
        for(j=0;j<6;j++){
            start = clock();

            // timing array, this is why it takes forever
            for(k=0;k<512*MB;k++){
                time +=array[(k*i)&lenChange];   
            }

            currTime = (double)(clock() - start)/CLOCKS_PER_SEC;
            avgTime += currTime;

            
            
        }
            
            avgTime /= 6;
            temp_time_2 = avgTime;
            //printf("DEBUG: For i value: %d    Time Taken:%lf\n",i,avgTime)
            
        if(count == 5){ 
            block_size = i;
        }


            
        if(level_jump == 1){
            l1_size = i;
            cacheRefTime = avgTime;
        }
        if(level_jump == 2){
            l2_size = i;
            cache_size = l2_size;
        }
        if(level_jump == 3){
            l3_size = i;
        }

        if (temp_time_1 > 0 && temp_time_1 != temp_time_2 && temp_time_2 >= temp_time_1) {
            double diff = temp_time_2 - temp_time_1;

            // any time the current cache time is greater than 30% of the previous time that indicates a jump in cache level
            if (diff > (temp_time_1 * 0.30)) {
                level_jump++;

                //cache_jump = i;
                //printf("DEBUG: cache jump at byte size: %d\n", cache_jump);
                
            }

        }
        printf("...\n");
        count++;
    } 
    printf("DEBUG: time variable - %d", time);
    printf("Cache Block Size: %d bytes\n", block_size);
    printf("L1 Cache Size: %d\n", l1_size << 2);
    printf("L2 Cache Size: %d\n", l2_size << 2);

    // might not hit l3 cache so
    if(l3_size == 3){
        cache_size = l3_size;
        printf("L3 Cache Size: %d\n", l3_size << 2);
    } else {
        printf("L3 Cache Size: undetermined\n");
    }
    
    cache_ref_time(cacheRefTime);


    return cache_size;
    
}



void main_ref_time(int cache_size){
    int x[cache_size + 1]; 
    int start = clock();
    x[0] = 1;
    double currTime = (double)(clock() - start)/CLOCKS_PER_SEC;
    printf("Main Memory Access Time: %lf seconds\n", currTime);
}



void cache_ref_time(double time){
    // actually implemented in get_cache_block
    printf("Average Reference Time for Cache: %f ns\n", time);
}

