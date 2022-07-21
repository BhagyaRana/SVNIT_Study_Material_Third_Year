% WAP to Enter a Character Repeatedly and Decide UpperCase / LowerCase or Number 
% Print Message Accordingly [Exit on Entering Space]

is_char(A):-
    A == ' ',
    write("Exit!").

is_char(A):-
    A >= 'A',
    A =< 'Z',
    write("UpperCase!"),
    nl.

is_char(A):-
    A >= 'a',
    A =< 'z',
    write("LowerCase!"),
    nl.

is_char(A):-
    A >= '0',
    A =< '9',
    write("Digit!"),
    nl.

main:-
    write('Enter a Character'),
    read(C),
    is_char(C)
    .



