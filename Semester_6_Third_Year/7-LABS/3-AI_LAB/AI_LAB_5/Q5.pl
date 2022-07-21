% 5. WAP to delete an element {Single Occurance} from the list.

% Base Case - Remove X from List Containing [X], will lead to Empty List
list_del(X, [X], []). 

% If X is Present in the Head, Delete it
list_del(X,[X|Tail], Tail). 

% Recursive Function
list_del(X, [Head|Tail], [Head|NewTail]) :-
    % Recursively Braking List into Head & Tail 
    list_del(X,Tail,NewTail).