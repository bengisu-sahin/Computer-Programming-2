// Attempting to modify data through a
// nonconstant pointer to constant data.

void f(const int *); //prototype
                    //The declaration is read from right to left as 
                   //“countPtr is a pointer to an integer constant.
int main() {
	int y;
	f(&y);
	return 0;
}// xPtr cannot modify the value of constant variable to which it points
void f(const int *xptr) {
	*xptr = 100; //can not modify a const obj
}