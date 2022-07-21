struct arraysize{
    int* arr;
    int size;
};

program ARR_PROG{
    version VERSION1 {
        arraysize arrop(arraysize arr) = 1;
    } = 2;
} =  0x20000005;