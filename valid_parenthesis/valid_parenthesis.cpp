/* 
Given a string s  containing the characters '(',')', '{', '}', '[' and ']'
determine if the string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

Example 1:

 Input S = "()"
 Output = True

Example 2:

 Input: s = "()[]{}"
 Output: True

Example 3:

 Input: s = "(]"
 Output: False

*/
#include <iostream>
//#include <format>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;

bool isValid(string s) {

    unordered_map<char,char> mapping = { {')' , '('}, {']', '['} , {'}', '{'} };
    unordered_set<char> opening = { '(', '[', '{'};
    stack<char> stack;

    //if its uneven, fail fast
    if ( s.size() % 2 > 0 ){
        return false;
    }

    for( auto &chr : s){

        //opening bracket
        if( opening.count(chr) ){
            stack.push(chr);
        }
        //closing bracket
        else {
            if ( mapping.count(chr) && !stack.empty() ) {
                char opening_bracket = stack.top();
                stack.pop();
                //check if the opeing bracket on stack match current closing bracket
                if (mapping.at(chr) != opening_bracket){
                    return false;
                }
            }
            else {
                return false;
            }
        }
    }

    if (stack.size() > 0 ){
        return false;
    }
    else{
        return true;
    }
}

int main() {

    // Basic Examples
   
    //Example 1
    string input = "()";
    cout << "Example 1: s = " << input << '\n';
    cout << "Output: " << isValid(input) << '\n';


    //Example 2
    input = "()[]{}";
    cout << "Example 2: s = " << input << '\n';
    cout << "Output: " << isValid(input) << '\n';

    //Example 3
    input = "(]";
    cout << "Example 3: s = " << input << '\n';
    cout << "Output: " << isValid(input) << '\n';

}