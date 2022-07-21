% U19CS012 - BHAGYA VINOD RANA

% What I Understood from Question 
% You are Given List Blist and You need to Check the Frequency of Alist in Blist 
% and Check it is Equal to Count

% Prolog F(x) to Check if Two Lists are Equal
same([], []).
same([H1|R1], [H2|R2]):-
    H1 = H2,
    same(R1, R2).

% Code to Get the Frequency of Alist in Blist
freq(Alist,[],0).
freq(Alist,[H|T], C):-
    (same(Alist,H)) ->
    (
        freq(Alist,T,Cnt),
        C is Cnt+1
    )
    ;
    (
        freq(Alist,T, C)
    ).

% Main Function 
memCount(Alist, Blist, Count):-
    % Function to Iterate the Blist and Count the Occurance of Alist in Ans
    freq(Alist,Blist,Ans),
    % Compare the Frequency Calculated with Count
    Ans = Count.