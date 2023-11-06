/*
Functional cohesion is the strongest and best kind of cohesion, occurring when a routine performs one and only one operation.

Examples of highly cohesive routines include 
sin(), GetCustomerName(), EraseFile(), CalculateLoanPayment(), and AgeFromBirthdate().

*/
int add_five(int value){return value + 5;}
/*
Sequential cohesion exists when a routine contains operations that must be performed in a specific order,
that share data from step to step, and that don’t make up a complete function when done together.

An example of sequential cohesion is a routine that, given a birth date, calculates
an employee’s age and time to retirement. If the routine calculates the age and
then uses that result to calculate the employee’s time to retirement, it has
sequential cohesion. If the routine calculates the age and then calculates the
time to retirement in a completely separate computation that happens to use the
same birth-date data, it has only communicational cohesion.

*/
/*
Communicational cohesion occurs when operations in a routine make use of the
same data and aren’t related in any other way. If a routine prints a summary
report and then reinitializes the summary data passed into it, the routine has
communicational cohesion: the
*/