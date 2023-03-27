#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "project.h"



/*
    Instructions...



*/

int main(int argc, char *argv[])
{

    printf("This is going to take a while. Please be patient, we promise it runs. \n");
    int cache_size;
    // double cacheRefTime;

    int max = MAX_BLOCK_SIZE;
    cache_size = get_cache_block_size(max);
    main_ref_time(cache_size);
    printf("done\n");


    // printf("block size = %d\naverage reference to cache time = %ls", block_size, cache_ref_time);
    

    // -------
    

    return 0;
}