% if year is divisible by 400 then is_leap_year
% else if year is divisible by 100 then not_leap_year
% else if year is divisible by 4 then is_leap_year
% else not_leap_year

is_leap_year(Year):-
    write(Year),
    (0 is Year  mod  400) ->
         write(" is a Leap Year!")
    ;
    (
        (0 is Year mod 100) ->
             write(" is Not a Leap Year!\n")
        ;
        (
            (0 is Year mod 4) ->
                 write(" is a Leap Year!\n")
            ;
             write(" is Not a Leap Year!\n")
        )
    ).
