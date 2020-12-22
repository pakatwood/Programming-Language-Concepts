last([X]):-
        write("\nLast element is : "),
        write(X).

    last([Y|Tail]):-
        last(Tail).
