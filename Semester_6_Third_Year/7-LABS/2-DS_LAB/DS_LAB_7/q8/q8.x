struct strpair{
    int len1;
    char* a;
    int len2;
    char* b;
};

program ARR_PROG{
    version VERSION1 {
        int substring(strpair p) = 1;
    } = 2;
} =  0x20000007;