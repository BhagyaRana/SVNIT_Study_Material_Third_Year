% Print the Element of Euclidean Series [44 28 16 12 4 0]

go(X1,X2):-
    write(X1),
    write(' '),
    write(X2),
    write(' '),
    euclid(X1,X2).

euclid(_,0).
euclid(X1,X2):-
    R is X1 mod X2,
    write(R),
    write(' '),
    R > 0,      % Mod by Zero Error
    euclid(X2,R).