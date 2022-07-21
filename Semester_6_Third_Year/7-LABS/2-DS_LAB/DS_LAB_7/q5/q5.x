struct intpair{
    int a;
    int b;
};

program SWAP_PROG{
    version VERSION1 {
        intpair swap(intpair p) = 1;
    } = 1;
} =  0x4562877;