CSCI 340 Operating Systems Final Project
Professor Leclerc

Nathan Everette and Jacob Aden

1. How big is a cache block?
    The function get_cache_block_size will change the step of array iteration and observe the change in time taken for computation.
    The step('i' value) at which there is a significant change in time taken will correspond to the cache line size in bytes. 
2. How big is the cache?
    Cache size is determined by the adjunct levels of cache determined through the function get_cache_block_size.
3. How long does a reference to main memory take to complete?
    After determining the size of the L3 cache, the function main_ref_time creates an array just larger
    than L3 and times a single reference.
4. How long does a reference that can be satisfied from cache take to complete?
    The access times given by the function get_cache_block_size will be used to determine the time it takes for a reference from cache to complete.




Compiling and Running: (it will take a while)
    in terminal: make
                ./main

Expected output:

...
...
...
...
...
...
...
...
...
...
...
...
...
Cache Block Size: 32 bytes
L1 Cache Size: 64
L2 Cache Size: 128
L3 Cache Size: 512
Average Reference Time for Cache: 2.953527 ns
Main Memory Access Time: 0.000004 seconds


Issues:
    We discovered that any significant jump in the average time to reach cache, from one size to the next, indicated a jump to a new level of cache. 
The issue we had with this is that we were not sure exactly what difference in time would indicate a jump.
We settled on if the new time was 30% or more longer than that would indicate a level jump.

    Run time: Our project has a frankly massive run time. I beleive this is due to our comparison loop being iterated with an exponentially sized array.
Sorry for the inconvenience.

    Different CPU Architectures: With one of us using an x86 Intel chip and the other using an M1 arm chip we ran into some data issues. 
Often times our output exactly doubled the output of the others. 
