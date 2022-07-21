% WAP to Print all the Fibonacci Numbers upto a Given Number N

main:-
    write('Enter N - '),
    read(N), 
    N >= 1,  
    write("1, "),
    write("1, "),
    fib(N,1,1).

fib(N,P1,P2):-
    F is P1+P2,
    F =< N,
    write(F),
    write(", "),
    fib(N,P2,F).