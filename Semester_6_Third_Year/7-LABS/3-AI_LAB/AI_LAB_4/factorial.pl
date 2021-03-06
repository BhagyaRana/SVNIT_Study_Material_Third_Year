% W.A.P.P to Find Factorial of a Number. [U19CS012]

main :-
   write("Enter a Positive Integer : "),
   read(N),
   fact(N,Ans),
   write("Factorial of "),
   write(N),
   write(" : "),
   write(Ans),
   nl.

% 0! = 1
fact(0, Ans) :-
   Ans is 1.

% n! = n*(n-1)!...0!
fact(N, Ans) :-
   N>0,
   New_N is N-1,
   fact(New_N,X1),
   Ans is X1*N.
