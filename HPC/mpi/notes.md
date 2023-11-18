shared memory (uma : uniform memory access) : 
    One memory bank shared by mutiple physical cpus. All cpus take unifrom amount of time to access memory.

shared memory (numa : non uniform memory access ) : 
    each cpu pair ( two physical cpus binded togather) gets its own memory bank and the cpus/nodes ( a node is cpu pair + its memory bank ) connected via a high bandwidth interconnet. So each memory bank is shared among two physically bound cpus and this makes up a node, and multiple such nodes are connected via an interconnet. So as a result a cpu from any given node say n1 takes more time to access data from any another node's memory, but it can quickly access it's own node's memory, hence non uniform memory access. 

Distrubuted memory :
    each node consists of a cpu + memory bank, unlike shared memory (numa architecture) only one cpu per node. And nodes are connected on a network ( this network may span geographically) This uses mpi (message passing interface) this is called distrubuted memory arch. 

Hybrid memory : 
    (shared + distributed.) In a single node 2 or more cpus with a memory bank (this local nodes runs openmp for local parallelism) and nodes are connected via a network which uses mpi for inter node communication for distrubuted computing. 


