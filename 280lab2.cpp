// REQUIRES: n >=1
// EFFECTS: Prints the hailstone sequence starting at n.
//      Uses iteration.
void hailstoneIterative(int n){
  
  // REPLACE WITH YOUR CODE
  cout << n << endl;
  
  while (n!=1)
  {
  
  	if (n%2 == 0)
  	{
     	cout << n/2 << endl;
     	n = n/2;
  	}
  
  	else if (n%2 == 1)
  	{
     	cout << 3*n+1 << endl;
     	n = 3*n+1;
  	}
  }
  
  cout << 1 << endl;
}

// REQUIRES: n >= 1
// EFFECTS: Prints the hailstone sequence starting at n.
//      Uses recursion.
void hailstoneTail(int n){
  
// REPLACE WITH YOUR CODE
  if (n == 1)
  {
    cout << 1 << endl;
    //hailstoneTest(n);
    return;
  }
  
  if (n % 2 ==0) 
  {  
    cout << n/2 <<endl;
    //hailstoneTest(n/2);
    hailstoneTail(n/2);
  }
  else if (n % 1 == 1) 
  {
    cout << 3*n+1 << endl;
    //hailstoneTest(3*n+1);
    hailstoneTail(3*n+1);
  }
  
}

// Helper function for testing code
void hailstoneTest(int n){
  cout << endl << "  Hailstone test for n = " << n << endl;
  cout << "    Iterative: "; hailstoneIterative(n);  cout << endl;
  cout << "    Recursive: "; hailstoneTail(n);  cout << endl;
}

// Testing code for hailstone
int main(){
  cout << "Running hailstone tests for lab 2..." << endl;
  hailstoneTest(5);
  hailstoneTest(8);
  hailstoneTest(14);
}























// REQUIRES: 0 <= digit <= 9, n >=0
// EFFECTS: Returns the number of times "digit" appears in "n".
//      Uses iteration.
int count_i = 0;
int count_r = 0;
int count_t = 0;
int countDigitsIterative(int n, int digit){
  
  while (!(n<=9))
  {
    int last_digit = n%10;
    if (last_digit == digit)
    {
      count_i++;
    }
    n = n/10; 
  }
  
  if (n == digit)
  {
    count_i++;
  }

  return count_i;
}

// REQUIRES: 0 <= digit <= 9, n >= 0
// EFFECTS: Returns the number of times "digit" appears in "n".
//      Uses recursion.
int countDigitsRecursive(int n, int digit){
  
  if (n <= 9) 
  {
    if (n == digit) count_r++;
    return count_r;
  }
  
  int last_digit = n%digit;
  if (last_digit == digit)
  {
    count_r++;
  }
  countDigitsIterative(n/10, digit);
  
}

// REQUIRES 0 <= digit <= 9, n >= 0
// EFFECTS: Returns the number of times "digit" appears int "n".
//      Uses tail recursion.
int countDigitsTail(int n, int digit){
  
  if (n <= 9) 
  {
    if (n == digit) count_t++;
    return count_t;
  }
  
  int last_digit = n%digit;
  if (last_digit == digit)
  {
    count_t++;
  }
  countDigitsIterative(n/10, digit);
  
}

// Helper function for testing code
void countDigitsTest(int n, int digit){
  cout << endl << "  CountDigits test.  How many " << digit << "s in " << n << endl;
  cout << "    Iterative:      " << countDigitsIterative(n, digit) << endl;
  cout << "    Recursive:      " << countDigitsRecursive(n, digit) << endl;
  cout << "    Tail Recursive: " << countDigitsTail(n, digit) << endl;
}

// Testing code for countDigits
int main() {
  cout << "Running tests for countDigits..." << endl;
  countDigitsTest(201220130, 2);
  countDigitsTest(201220130, 0);
  countDigitsTest(201220130, 7);
  countDigitsTest(0, 0);
  countDigitsTest(0, 8);
  
  return 0;
}