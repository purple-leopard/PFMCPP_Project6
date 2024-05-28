/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
    Not every pointer can be converted.
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference and don't change the return type either.

    You have to ask yourself if each pointer can be converted to a (const) reference.
    Think carefully when making your changes.

 2) revise the 'else' statement in main() that handles when `smaller` is a nullptr. 
 there is only one reason for `compare` to return nullptr. 
 Update this std::cout expression to specify why nullptr was returned.
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T
{
    T(int v, const char* identifier) //1
    {
        value = v; // 2
        name = identifier; // 3
    }

    int value;
    std::string name;
};

struct X // 4
{
    T* compare(T& a, T& b) // 5
    {
        if( a.value < b.value ) return &a;
        if( a.value > b.value ) return &b;
        return nullptr;
    }
};

struct U
{
    float val1 { 2 }, val2 { 3 };
    float changeValue(float& updatedValue)      //12
    {
        std::cout << "U's val1 value: " << val1 << std::endl;
        val1 = updatedValue;
        std::cout << "U's val1 updated value: " << val1 << std::endl;
        while(std::abs(val2 - val1) > 0.001f)
        {
            if (val2 < val1)
            {
                val2 += 0.0005f;
            }
            else
            {
                val2 -= 0.0005f;
            }
        }
        std::cout << "U's val2 updated value: " << val2 << std::endl;
        return val2 * val1;
    }
};

struct W
{
    static float changeValue(U& that, float& updatedValue)        //10
    {
        std::cout << "U's val1 value: " << that.val1 << std::endl;
        that.val1 = updatedValue;
        std::cout << "U's val1 updated value: " << that.val1 << std::endl;
        while( std::abs(that.val2 - that.val1) > 0.001f )
        {
            /*
             write something that makes the distance between that->val2 and that->val1 get smaller
             */
            if (that.val2 < that.val1)
            {
                that.val2 += 0.0005f;
            }
            else
            {
                that.val2 -= 0.0005f;
            }
        }
        std::cout << "U's val2 updated value: " << that.val2 << std::endl;
        return that.val2 * that.val1;
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T version1(5, "five"); // 6
    T version2(3, "three"); // 6
    
    X f; // 7
    auto* smaller = f.compare(&version1 , &version2); // 8
    if (smaller != nullptr)
    {
        std::cout << "the smaller one is " << smaller->name << std::endl;
    }
    else
    {
        std::cout << "smaller == nullptr, either a == b or a/b == nullptr" << std::endl; // 9
    }
    
    U u1;
    float updatedValue = 5.f;
    std::cout << "[static func] u1's multiplied values: " << W::changeValue(&u1, &updatedValue) << std::endl;                  //11
    
    U u2;
    std::cout << "[member func] u2's multiplied values: " << u2.changeValue( &updatedValue ) << std::endl;
}
