positive_negative(0):-
    write('Zero'),!.

positive_negative(X):-
    X > 0,
    write('Positive'),!.
    
positive_negative(X):-   
    X < 0,
    write('Negative'),!.
    