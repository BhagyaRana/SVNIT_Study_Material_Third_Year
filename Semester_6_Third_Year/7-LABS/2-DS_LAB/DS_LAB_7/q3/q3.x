struct intpair{
    int a;
    int b;
};

program GCD_PROG{
    version VERSION1 {
        int gcd(intpair p) = 1;
    } = 1;
} =  0x4562877;