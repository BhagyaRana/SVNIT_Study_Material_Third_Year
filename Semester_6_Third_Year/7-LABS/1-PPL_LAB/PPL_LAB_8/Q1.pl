calculator:-
    write("Enter  Number  1:"), read(A),
    write("Enter  Number  2:"), read(B),
    write("1.)Addition  \n2.)Subtraction  \n3.)Multiplication  \n4.)Division\n"),
    write("Select  your  choice:-"), 
    read(Choice),
    write("Ans="), 
    calculate(A,B,Choice).

    calculate(A,B,Choice):-
    (
        Choice = 1, 
        Ans  is  A+B,
        write(Ans),!
    ).

    calculate(A,B,Choice):-
    (
        Choice = 2, 
        Ans  is  A-B,
        write(Ans),!
    ).

    calculate(A,B,Choice):-
    (
        Choice = 3,
        Ans  is  A*B,
        write(Ans),!
    ).

    calculate(A,B,Choice):-
    (
        Choice = 4,
        (   
            B =:= 0,
            write("Divide by Zero Error!\n"),
            !
        );
        (
            Ans  is  A/B,
            write(Ans),
            !
        )
    ).

