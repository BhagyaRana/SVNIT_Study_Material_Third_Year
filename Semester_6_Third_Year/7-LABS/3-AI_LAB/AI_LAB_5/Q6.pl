% 6. WAP to sum the elements of a list of numbers.

% Base Case - Sum of Empty List = 0
sumlist([],0).

% Recursive Defination
sumlist([H|T],N) :- sumlist([T],N1), N is N1 + H.
