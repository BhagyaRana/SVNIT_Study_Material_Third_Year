% [U19CS012] BHAGYA VINOD RANA

% Facts

% male(person) - person is male
male(f).
male(i).
male(s1).
male(s2).

% female(person) - person is female
female(w).
female(d).

% husband(h,w) - h is the husband of w
husband(i,w).
husband(f,d).

% father(f,s) - f is the father of s
father(i,s1).
father(f,s2).
father(f,i).

% mother(m,s) - m is the mother of s
mother(d,s2).
mother(w,s1).
mother(w,d).

% Relationships [Rules]

% Wife Relation [X is Wife of Y, if Y is the Husband of X]
wife(X, Y) :- husband(Y, X).

% For Married Condition, X should be either Husband
married(X, Y) :- husband(X, Y).
married(X, Y) :- wife(X, Y).

% biological parent
bio_parent(X, Y) :- father(X, Y).
bio_parent(X, Y) :- mother(X, Y).

% daughter Relationship
daughter(X, Y) :- female(X), bio_parent(Y, X).

% son
son(X, Y) :- male(X), bio_parent(Y,X).

% step parent -> someone which your father/mother marries after
% old relationship ends
step_parent(X, Z) :- married(X, Y), bio_parent(Y, Z), \+ bio_parent(X, Z).

step_father(X, Z):- step_parent(X, Z), male(X).
step_mother(X, Z):- step_parent(X, Z), female(X).
step_daughter(X, Y):- female(X), step_parent(Y, X).
step_son(X, Y):- male(X), step_parent(Y,X).

parent(X, Y) :- step_parent(X, Y).
parent(X, Y) :- bio_parent(X, Y).

% the father of one's husband or wife.
father_in_law(X, Y):- married(Y, Z), parent(X, Z), \+ parent(X, Y), male(X).
mother_in_law(X, Y):- married(Y, Z), parent(X, Z), \+ parent(X, Y), female(X).
parent_in_law(X, Y) :- father_in_law(X, Y). parent_in_law(X, Y) :- mother_in_law(X, Y).
son_in_law(X, Y):- parent_in_law(Y, X), male(X).
daughter_in_law(X, Y):- parent_in_law(Y, X), female(X).

% grandfather relationship
grandfather(X, Z) :- parent(X, Y), parent(Y, Z), male(X).

sibling(X, Y):- parent(Z, X), parent(Z, Y), X \= Y.
dist_sibling(X, Y) :- distinct(sibling(X, Y)).

% brother in law - the brother of one's wife or husband.
brother_in_law(X, Z):- married(Y, Z), sibling(X, Y), male(X).
sister_in_law(X, Z):- married(Y, Z), dist_sibling(X, Y), female(X).

% uncle
uncle(X, Y):- dist_sibling(X, Z), parent(Z, Y), male(X).

