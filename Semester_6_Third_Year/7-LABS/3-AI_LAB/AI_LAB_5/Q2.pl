% 2. WAP To check whether the number is present in the list or not.

% If the Element is Equal to Head of the List
present(X, [X|_]).

% Recursive Call for Remaining List
present(X, [_|T]) :-
    present(X, T).
