struct strpair{
    int len1;
    char* a;
    int len2;
    char* b;
};

program CONCAT_PROG{
    version VERSION1 {
        string concatenate(strpair p) = 1;
    } = 1;
} =  0x4562877;