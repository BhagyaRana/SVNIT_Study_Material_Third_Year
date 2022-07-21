nit([X|Xs], 1, Xs).

nit([Y|Xs], K, [Y|Ys]):-
    K > 1,
    K1 = K-1,
    nit(Xs,K1,Ys).