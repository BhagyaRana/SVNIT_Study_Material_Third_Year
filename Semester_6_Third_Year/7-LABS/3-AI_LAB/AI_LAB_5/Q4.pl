% 4. WAP to concat two lists and store the result in third list.

% Usage - append_list(L1, L2, Concat_List)

% If L1 is empty, resultant list will be equal to L2 (base case)
append_list([], L2, L2). 

% Recursive Defination of List Concatanation
append_list([H | T], L2, [H | L3]) :-
    % Tail & L2 will be Concatanated to L3
    append_list(T, L2, L3).