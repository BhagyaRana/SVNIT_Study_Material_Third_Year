% male(person) - person is male
male(james1).  
male(charles1).
male(charles2).
male(james2).
male(george1).

% female(person) - person is female
female(catherine).
female(elizabeth).
female(sophia).

% parent(P,C) - P is parent of Child C
parent(james1, charles1).
parent(james1,elizabeth).

parent(charles1,charles2).
parent(charles1,catherine).
parent(charles1,james2).

parent(elizabeth,sophia).
parent(sophia,george1).

% Mother - M is the mother of X if she is a parent of X and is female
mother(M,X):-
    parent(M,X),
    female(M).

% Father - F is the father of X if he is a parent of X and is male  
father(F,X):-
    parent(F,X),
    male(F).

% X is a sibling of Y if they both have the same parent.
sibling(X,Y):-
    parent(P,X),
    parent(P,Y),
    X \= Y.

% sister
sister(X,Y):-
    female(X),
    parent(P,X),
    parent(P,Y),
    X \= Y.

% brother
brother(X,Y):-
    male(X),
    parent(P,X),
    parent(P,Y),
    X \= Y.

% [+] - Extra
% sibling(X, Y):- parent(Z, X), parent(Z, Y), X \= Y.
dist_sibling(X, Y) :- distinct(sibling(X, Y)).

% uncle 
uncle(X, Y):- dist_sibling(X, Z), parent(Z, Y), male(X).

% aunt
aunt(X, Y):- dist_sibling(X, Z), parent(Z, Y), female(X).

% grandparent
grandparent(G,C) :-
    parent(G, F),
    parent(F, C).

cousin(X,Y):-
    parent(P,X),
    parent(Q,Y),
    sibling(P,Q).