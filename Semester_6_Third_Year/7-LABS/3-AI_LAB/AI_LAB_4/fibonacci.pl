% W.A.P.P to Print Fibonacci Series. [U19CS012]

main:-
        write("Enter 'n' for nth Fibonacci Term (n>0) : "),
        read(N),
        fib(N,X),
        write("Fibonacci Series "),
        write(N),
        write(" th Term"),
        write(" is : "),
        write(X),
        nl.

% fib(1) = 1
fib(1,Ans) :-
        Ans is 1.

% fib(2) = 1
fib(2,Ans) :-
        Ans is 1.

% fib(n) = fib(n-1) + fib(n-2) ... if(n>2)
fib(N,Ans) :-
        N>2,
        Y is N-1,
        Z is N-2,
        fib(Y,X1),
        fib(Z,X2),
        Ans is X1+X2.
