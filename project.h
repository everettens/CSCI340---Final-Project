/*
    Declarations...
*/

#define MAX_BLOCK_SIZE  4096

// #define block_size, cacheRefTime


#define KB 1024
// #define MB 1024 * 1024
#define MB 1 << 20


int get_cache_block_size(int maximum);

int get_cache_size(int block_size);

void main_ref_time(int cache_size);

void cache_ref_time(double time);
