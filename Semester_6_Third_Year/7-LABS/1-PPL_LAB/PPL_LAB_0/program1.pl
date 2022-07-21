% Author - U19CS012 [Bhagya Rana]

% 1 - write and nl are built-in predicate
% ?-write('Welcome to SVNIT'),nl,write('Example of Prolog'),nl.

% 2 - Facts

% 'rottweiler is a dog'
dog(rottweiler).
% 'Munchkin Is A cat'.
cat(munchkin).

% 3 - If Condition

% "If A is an animal, then A is a dog".
animal(A) :- dog(A).
% It should return true if argument is dog, otherwise false.
