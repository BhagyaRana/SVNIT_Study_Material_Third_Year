/* Facts */

female(mary).
female(sandra).
female(juliet).
female(lisa).

male(peter).
male(paul).
male(dick).
male(bob).
male(harry).

parent(bob, lisa).
parent(bob, paul).
parent(bob, mary).
parent(juliet, lisa).
parent(juliet, paul).
parent(juliet, mary).
parent(peter, harry).
parent(lisa, harry).
parent(mary, dick).
parent(mary, sandra).

/* Rules */

% Father
father(X, Y):-
    male(X),
    parent(X, Y).

% Mother
mother(X, Y):-
    female(X),
    parent(X, Y).

% Sister
sister(X, Y):-
    female(X),
    father(F, X),
    father(F, Y),
    X \= Y.

sister(X, Y):-
    female(X),
    mother(M, X),
    mother(M, Y),
    X \= Y.

% Grandmother
grandmother(X, Y):-
    female(X),
    parent(X, Z),
    parent(Z, Y).

% Cousin
sibling(X, Y):-
    father(Z, X),
    father(Z, Y),
    X \= Y.

cousin(X, Y):-
    mother(Z, X),
    mother(W, Y),
    sibling(Z, W).
