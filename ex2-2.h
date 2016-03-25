typedef struct {
 double real;
 double image;
} Cplex;


inline double division_real(Cplex, Cplex);
inline double division_image(Cplex, Cplex);

inline Cplex cplex_add(Cplex, Cplex);
inline Cplex cplex_minus(Cplex, Cplex);
inline Cplex cplex_multi(Cplex, Cplex);
inline Cplex cplex_division(Cplex, Cplex);
Cplex complexOperation(Cplex, Cplex, char);
void printComplex(Cplex*);



