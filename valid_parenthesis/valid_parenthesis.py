''' 
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
'''

def isValid(s: str) -> bool:

    # len of string has to be even
    if len(s) % 2:
        return False

    opening = {'(', '[', '{'}
    closing = {')', ']' , '}'}
    matching = { '[' : ']', '(': ')', '{': '}'}

    stack = []
    for char in s:
        # if its an opening
        if char in opening:
            stack.append(char)

        #else if its a closing bracket
        elif char in closing:
            if stack:
                opening_bracket = stack.pop()
            else:
                return False
                
            if matching[opening_bracket] != char:
                return False                    

    if stack: # if the stack is not empty then uneven 
        return False
    else:
        return True


if __name__ == "__main__":

   
    # Basic Examples
   
    #Example 1
    input = "()"
    print("Example 1: s =", input)
    print("Output:", isValid(input))
    
    #Example 2
    input = "()[]{}"
    print("Example 2: s =", input)
    print("Output:", isValid(input))

    #Example 3
    input = "(]"
    print("Example 3: s =", input)
    print("Output:", isValid(input))

