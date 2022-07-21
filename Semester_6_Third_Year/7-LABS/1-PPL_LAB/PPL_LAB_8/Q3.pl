even_odd(X):-
    Mod is X mod 2,
    (
        Mod  =  0,
        write('Even Number!'),
        !
        ;
        write('Odd Number!')
    ).

