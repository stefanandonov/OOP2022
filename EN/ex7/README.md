Implement a class for students. Each student has a name (dynamically allocated char array), dynamically allocated array of grades, their count and academic year (integer). Implement the following:

Constructors and destructor

- operator ++ that will increment the academic year for +1
- operator += for addition of a grade to a student
- operator << for printing a student with all the information
- operator >> for reading a student from input
- operator > for comparing two students by their average.

Then implement a class for a faculty that keeps dynamically allocated array of students and their number. For this class implement:

Constructors and destructor

- operator += for adding new student in the group

- operator ++ for increasing the school year for +1

- operator << for printing all the students in the group

- method reward that print only students that have an average higher than 9.0.

- method highestAverage that will print the highest average of the group.
- operator [] for mutable access to the student on position idx