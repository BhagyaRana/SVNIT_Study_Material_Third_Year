grade(Marks,Grade):- 
    Marks >= 80, 
    Grade  =  'A',!.

grade(Marks,Grade):- 
    Marks >= 60, 
    Grade  =  'B',!.

grade(Marks,Grade):- 
    Marks >= 36, 
    Grade  =  'C',!.

grade(Marks,Grade):- 
    Marks >= 1,
    Grade  =  'D',!.