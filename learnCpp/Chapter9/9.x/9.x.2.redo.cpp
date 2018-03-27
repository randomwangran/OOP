// You're not using assert anywhere
// #include <cassert>
#include <cassert>
#include <iostream>
 
class IntArray
{
  int m_size;
  // You used an uninitialized variable. That's how you can easily waste 3 hours
  // of your day.
  //> I can see you point, I always like to initialize class members
  //> by direct initialization by using constructor. I will discard
  //> this bad behavior and embrace the uniformly initialization
  //> list. But I don't know the reason why this is a better
  //> choice. Alex write on section 8.5a
  //> http://www.learncpp.com/cpp-tutorial/8-5a-constructor-member-initializer-lists/:
  //> We strongly encourage you to begin use this new syntax as
  //> initialization lists are required when doing composition and
  //> inheritance.
  
  
  // Enable compiler warnings:
  //   warning: unused variable 'm_array'
  //> why this is a unused variable? In my original code (Line20 and Line31 /#comment-322336) I use 'm_array'.
  int *m_array{ nullptr };
 
public:
  IntArray(int size = 0)
      // Uniform initialization is preferred
      //> I checked Alex's solution, his code used copy initialization
      //(Line7 and Line8 /#comment-322336). Is this a potential
      //improvement for this question?
    
    
      //> I re-write the initialization list by using uniform initialization
      //> InArray(int size = 0): m_size{size}, *m_array {nullptr} {}
      //> but it won't work, how m_array get proper length of the address?
      //> In this case, the assignment is necessary just as Alex's solution like this:
        //> IntArray(int length):
	//> 	m_length(length)
	//> {
	//> 	assert(length > 0 && "IntArray length should be a positive integer");
 
	//> 	m_array = new int[m_length] { 0 };
	//> }
      //> But why m_array = new int[m_length] { 0 };
      //> Instead of m_array = new int[m_length]; ?
      //> My computer works fine without {0}, what is the function of {0}?
 
          
      : m_size{ size }
  {
    // You're not accessing @m_array, you're creating a new int array that's
    // never used and leaking memory. If you want to access members use this->.
    // int *m_array = new int[m_size];

    //> I don't understand this point. Why I am creating a new int
    //> array (Line12 /#comment-322336)? I thought that I was using a
    //> constructor to initialize *m_array. Do you mean that anything
    //> within the "{}" of the constructor is not the class private
    //> member anymore?
    
    
    this->m_array = new int[this->m_size];
    //> why you use this-> ?
    //> Is your code equivalent to m_array = new int[m_length]?
    
  }
 
  friend std::ostream &operator<<(std::ostream &out, const IntArray &array);
 
  int &operator[](const int index)
  {
    return this->m_array[index];
  }
};
 
std::ostream &operator<<(std::ostream &out, const IntArray &array)
{
  // Again, enable compiler warnings:
  //   warning: statement has no effect
  // out;

  //> thanks for pointing out this "out".
  //> Why VS2017 does not give me this kind of warning?
  //> I use debug x86 with F5 to run my code.
  
  for (int count{ 0 }; count < array.m_size; ++count)
  {
    std::cout << array.m_array[count] << " ";
  }
 
  return out;
}
 
IntArray fillArray()
{
  IntArray a{ 5 };
  a[0] = 5;
  a[1] = 8;
  a[2] = 2;
  a[3] = 3;
  a[4] = 6;
 
  return a;
}
 
int main()
{
  IntArray a{ fillArray() };
  std::cout << a << '\n';
 
  IntArray b{ 1 };
  // This doesn't do anything
  // a = a;

  //> I think this is a line to test weather someone use
  //> self-assignment guard. But I have problem understanding Alex's
  //> code. In the section 9.14 "Detecting and handling
  //> self-assignment", I can understand the overloading of
  //> operator=. In Alex's solution:
  	// IntArray& operator= (const IntArray &array)
	// {
	// 	// self-assignment guard
	// 	if (this == &array)
	// 		return *this;
 
	// 	// If this array already exists, delete it so we don't leak memory
	// 	delete[] m_array;
 
	// 	m_length = array.m_length;
 
	// 	// Allocate a new array
	// 	m_array = new int[m_length];
 
	// 	// Copy elements from original array to new array
	// 	for (int count = 0; count < array.m_length; ++count)
	// 		m_array[count] = array.m_array[count];
 
	// 	return *this;
	// }
  //> Why we need to delete[] m_array? Because, if the program can
  //> execute at this line, then it suggests that this is not a
  //> self-assignment. So, can we just create a new instance without
  //> deleting m_array like the following code?
  
        //   Fraction& Fraction::operator= (const Fraction &fraction)
        // {
        //     // self-assignment guard
        //     if (this == &fraction)
        //         return *this;
 
       //     // do the copy
       //     m_numerator = fraction.m_numerator;
       //     m_denominator = fraction.m_denominator;
 
       //     // return the existing object so we can chain this operator
       //     return *this;
       // }
  
  
  b = a;
 
  // Question 1 and 2: This modifies @b, because @a and @b share one and the
  // same array.
  a[2] = 123;

  //> Yes, I find the problem. The instance "b" in my code is actually
  //> "a"! This is very strange to me. I actually forget to overload
  //> the assignment operator. But C++ seems do some magics to
  //> overload the operator "=". Can someone explain what why the
  //> overload was working?

  //> After I overload operator=, then the code works! But, I really
  //> want to know why it works when I forget to write the overloading
  //> function?
  
 
  std::cout << b << '\n';
 
  std::cout << "Press enter to exit" << std::endl;
  std::cin.get();
 
  return 0;
}


