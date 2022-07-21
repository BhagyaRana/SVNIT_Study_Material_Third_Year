class Big
{
    int i;
    float f;
    void fun1() throw float
    {
        ...
        try
        {
            ... 
            throw i;
            ... 
            throw f;
            ...
        }
        // Correction in Asssignment {instead of 'float' -> 'int'}
        catch (int){ ... }
        ...
    }
};

class Small
{
    int j;
    float g;
    void fun2() throw float
    {
        ...
        try
        {
            ...
            try
            {
                Big.fun1();
                ... 
                throw j;
                ... 
                throw g;
                ...
            }
            catch (int) { ... }
            ...
        }
        catch (float){ ... }
    }
};
