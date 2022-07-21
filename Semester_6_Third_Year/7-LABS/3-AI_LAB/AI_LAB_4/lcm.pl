% W.A.P.P to finding the GCD and LCM of two integers. [U19CS012]

% gcd(N,M) * lcm(N,M) = N*M  ... (1)

main :-
    write("Calculate GCD & LCM of Two Numbers!"),
    nl,
    write("Enter Number 1 : "),
    read(N),
    nl,
    write("Enter Number 2 : "),
    read(M),
    nl,
    gcd(N,M,X),
    write("GCD Of "),
    write(N),
    write(" & "),
    write(M),
    write(" is : "),
    write(X),nl,
    Z is N*M,
    Y is Z/X,
    write("LCM of "),
    write(N),
    write(" & "),
    write(M),
    write(" is : "),
    write(Y),
    nl.

% int gcd(int n, int m)
%    return m == 0 ? n : gcd(m, n % m);   ...(2)

% Base Case when M = 0
gcd(N, 0, Ans) :-
    Ans is N.

% gcd(n,m) = gcd(m, n%m)
gcd(N, M, Ans) :-
    M>0,
    Y is mod(N, M),
    gcd(M, Y, Ans).
