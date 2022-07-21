solve(A,B,C,L):-
    write("For  Equation  "),
    write(A),
    write("*x^2  +  "),
    write(B),
    write("x  +"),
    write(C),
    write("  =0\n"),
    D  is  (B^2)  -  (4*A*C),
    write("D = "),write(D),nl,
    roots(A,B,C,D,L).

    roots(A,B,_C,D,L):-
        (
            D == 0,
            write("Equal  Real  Roots!"),nl,
            X  is  (-B/(2*A)),
            L=[X],!
        ).

    roots(A,B,_C,D,L):-
        (
            D > 0,
            write("Real  Roots!"),nl,
            S is sqrt(D),
            X1  is  (-B  +  S)/(2*A),
            X2  is  (-B  -  S)/(2*A),
            L=[X1,X2],!
        ).

    roots(A,B,_C,D,L):-
        (
            D<0,
            write("Imaginary  Roots!"),nl,
            S  is  sqrt(-D)/(2*A),
            X1  is  -B/(2*A),
            L=[[X1,S],[X1,-S]],!
        ).

