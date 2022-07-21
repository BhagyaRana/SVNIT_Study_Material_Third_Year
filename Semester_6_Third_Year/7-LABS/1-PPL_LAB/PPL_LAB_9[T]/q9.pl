% WAP to determine the Number of Odd and Even Numbers in List

count_even_odd([],E,O):-
    E is 0,
    O is 0.

count_even_odd([H|T],Even,Odd):-
    R is H mod 2,
    R =:= 0,
    count_even_odd(T,E,O),
    Even is E+1,
    Odd is O.

count_even_odd([H|T],Even,Odd):-
    R is H mod 2,
    R =:= 1,
    count_even_odd(T,E,O),
    Even is E,
    Odd is O+1.



