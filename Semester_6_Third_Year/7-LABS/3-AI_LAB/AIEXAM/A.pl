% U19CS012 BHAGYA VINOD RANA

% Assumption Made : Since the Diseases needed Symptoms to be Given Beforehand

% Patient(P_Id,name,address(building_name,city,zipcode),treatment(doctor_code, [diseases])).

patient(10,"Bhagya",address("ABC","Surat","395007"),treatment("D1", ["flu","common_cold","chicken_pox","measles"])).
patient(11,"Nobita",address("DEF","Delhi","110002"),treatment("D2", ["common_cold"])).
patient(12,"Giyan",address("GHI","Ahmedabad","380001"),treatment("D3", ["flu","chicken_pox","measles"])).
patient(13,"Tom",address("ABC","Delhi","110002"),treatment("D4", ["flu","measles"])).
patient(14,"Shisuka",address("DEF","Surat","100433"),treatment("D5", ["measles"])).
patient(15,"Mickey",address("GHI","Ahmedabad","380001"),treatment("D2", ["flu","measles"])).
patient(16,"Donald",address("ABC","Surat","395009"),treatment("D3", ["chicken_pox"])).
patient(17,"Garfield",address("DEF","Surat","395009"),treatment("D1", ["flu","measles"])).
patient(18,"Jerry",address("GHI","Delhi","110002"),treatment("D4", ["flu","common_cold","measles"])).

% 1. Find the total number of diseases for each patient.
display_patients_diseases_cnt():-
    write("---------------------------------------"),
    nl,
    write("Patient Name | Total Number of Diseases"),
    nl,
    write("---------------------------------------"),
    nl,
    forall(
        patient(_,Pname,address(_,_,_),treatment(_,Diseases)),
        (
            write(Pname),
            write(" -> "),
            length(Diseases,K),
            write(K),
            nl
        )
    ),
    write("---------------------------------------"),
    nl.


% 2. Find the name and zip code of each patient.
display_name_zip():-
    write("---------------------------------------"),
    nl,
    write("Patient Name | Zip Code"),
    nl,
    write("---------------------------------------"),
    nl,
    forall(
        patient(_,Pname,address(_,_,Zipcode),treatment(_,_)),
        (
            write(Pname),
            write(" -> "),
            write(Zipcode),
            nl
        )
    ),
    write("---------------------------------------"),
    nl.


% 3. Write P_Id and name of all patients staying in Delhi.
display_delhi_person(City_Name):-
    write("---------------------------------------"),
    nl,
    write("Patient ID | Patient Name | City "),
    nl,
    write("---------------------------------------"),
    nl,
    forall(
        patient(Pid,Pname,address(_,City_Name,_),treatment(_,_)),
        (
            write(Pid),
            write(" -> "),
            write(Pname),
            write(" -> "),
            write(City_Name),
            nl
        )
    ),
    write("---------------------------------------"),
    nl.

% 4. List name of all patients treated by doctor D1.
display_patient_doc(DocID):-
    write("---------------------------------------"),
    nl,
    write("Patient ID | Patient Name | Doctor ID"),
    nl,
    write("---------------------------------------"),
    nl,
    forall(
        patient(Pid,Pname,address(_,_,_),treatment(DocID,_)),
        (
            write(Pid),
            write(" -> "),
            write(Pname),
            write(" -> "),
            write(DocID),
            nl
        )
    ),
    write("---------------------------------------"),
    nl.

% 5. List roll no. of all patients suffering from Common cold
display_patient_disease(Diseases):-
    write("---------------------------------------"),
    nl,
    write("Patient ID | Patient Name | Diseases"),
    nl,
    write("---------------------------------------"),
    nl,
    forall(
        patient(Pid,Pname,address(_,_,_),treatment(_, Diseases)),
        (
            write(Pid),
            write(" -> "),
            write(Pname),
            write(" -> "),
            write(Diseases),
            nl
        )  
    ),
    write("---------------------------------------"),
    nl.

% 6. List building_name and city_code for all patients in the given format (format: [(building_name, citycode)]).
display_building_city():-
    write("---------------------------------------"),
    nl,
    write("Patient ID | Building Name | City Zipcode"),
    nl,
    write("---------------------------------------"),
    nl,
    forall(
        patient(_,Pname,address(Build_Name,_,Zipcode),treatment(_,_)),
        (
            write(Pname),
            write(" -> "),
            write(Build_Name),
            write(" -> "),
            write(Zipcode),
            nl
        )
    ),
    write("---------------------------------------"),
    nl.

% 7. List all doctors for each given patient.
list_all_doc(Pname):-
    write("---------------------------------------"),
    nl,
    write("Patient ID | Doctor ID"),
    nl,
    write("---------------------------------------"),
    nl,
    forall(
        patient(_,Pname,address(_,_,_),treatment(DocID,_)),
        (
            write(Pname),
            write(" -> "),
            write(DocID),
            nl
        )
    ),
    write("---------------------------------------"),
    nl.

% CODE THAT IS NOT USED

solve :-
    write("What is the Patient's Name (in small letters) : "),
    read(Patient),
    % get_single_char(Code),
    predict_disease(Patient,Disease),
    write_list([Patient,', probably has ',Disease,'.']),nl.
    
solve :-
    write('Sorry, I don''t seem to be able to'),nl,
    write('diagnose the disease.'),nl.

% symptom(name,indication)
% name : Patient's name
% indication : fever, rash, headache, runny_nose, conjunctivitis, cough, body_ache, chills, sore_throat, sneezing   

symptom(Patient,fever) :- 
    verify(Patient," have a fever (y/n) ? ").

symptom(Patient,rash) :- 
    verify(Patient," have a rash (y/n) ? ").

symptom(Patient,headache) :- 
    verify(Patient," have a headache (y/n) ? ").

symptom(Patient,runny_nose) :- 
    verify(Patient," have a runny_nose (y/n) ? ").

symptom(Patient,conjunctivitis) :- 
    verify(Patient," have a conjunctivitis (y/n) ? ").

symptom(Patient,cough) :-  
    verify(Patient," have a cough (y/n) ? ").

symptom(Patient,body_ache) :- 
    verify(Patient," have a body_ache (y/n) ? ").

symptom(Patient,chills) :- 
    verify(Patient," have a chills (y/n) ? ").

symptom(Patient,sore_throat) :- 
    verify(Patient," have a sore_throat (y/n) ? ").

symptom(Patient,sneezing) :- 
    verify(Patient," have a sneezing (y/n) ? ").


ask(Patient,Question) :-
    write(Patient),
    write(", Do You"),
    write(Question),
    read(N),
    ( 
        (N == yes ; N == y) -> 
        assert(yes(Question)) 
        ;
        assert(no(Question)), 
        fail
    ).
:- dynamic yes/1,no/1.		

% Function to Ask the Question and Based on the Response Return True/False
verify(P,S) :-
       (
           yes(S) -> true 
           ;
           (
               no(S) -> fail 
               ;
               ask(P,S)
            )
        ).

undo :- retract(yes(_)),fail. 
undo :- retract(no(_)),fail.
undo.


% Flu : if patient has fever, headache, body_ache, conjunctivitis, chills, sore_throat, runny_nose, cough
predict_disease(Patient,flu) :-
    symptom(Patient,fever),
    symptom(Patient,headache),
    symptom(Patient,body_ache),
    symptom(Patient,conjunctivitis),
    symptom(Patient,chills),
    symptom(Patient,sore_throat),
    symptom(Patient,runny_nose),
    symptom(Patient,cough).

% Common Cold : if patient has headache, sneezing, sore_throat, runny_nose, chills
predict_disease(Patient,common_cold) :-
    symptom(Patient,headache),
    symptom(Patient,sneezing),
    symptom(Patient,sore_throat),
    symptom(Patient,runny_nose),
    symptom(Patient,chills).

% Chicken pox : if patient has fever, chills, body_ache, rash
predict_disease(Patient,chicken_pox) :-
    symptom(Patient,fever),
    symptom(Patient,chills),
    symptom(Patient,body_ache),
    symptom(Patient,rash).

% Measles : if patient has cough, sneezing, runny_nose
predict_disease(Patient,measles) :-
    symptom(Patient,cough),
    symptom(Patient,sneezing),
    symptom(Patient,runny_nose).

% F(X) to write the List
write_list([]).
write_list([H|T]) :-
    write(H),
    write_list(T).

% response(Reply) :-
%     get_single_char(Code),
%     put_code(Code),
%     nl,
%     char_code(Reply, Code).
