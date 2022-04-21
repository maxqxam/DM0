Appname: DM Problem Solver
Version: 1.0 (Unoptimized)
Platform: Personal Computers
GUI: NO
User Friendly: NO

This is my first C++ vast project , I worked on it for almost a week.

This application solves Discrete Mathemathic's problems. ( like : (p>q)|r )
The functionality of it is almost perfect but it's performance and memory managing rating is almost 0, 
as I am only using std::string in the operation of finding the solution.

Operators table:
  | Or
  & And
  > Conclusion
  % Bidirectional Conclusion
  ~ Not
  = Equals


Example:

Input a Discrete Mathemathics problem: ((p>q)>(q>p))|((p|q)&(p%q))             

This statement contain's 2 variables.

Variables:
    p 1010 a
    q 1100 c

Cells:

    ((p>q)>(q>p))|((p|q)&(p%q))  : 
        p>q  : 
            #d 1101

    (#d>(q>p))|((p|q)&(p%q))  : 
        q>p  : 
            #b 1011

    (#d>#b)|((p|q)&(p%q))  : 
        #d>#b  : 
            #b 1011

    #b|((p|q)&(p%q))  : 
        p|q  : 
            #e 1110

    #b|(#e&(p%q))  : 
        p%q  : 
            #9 1001

    #b|(#e&#9)  : 
        #e&#9  : 
            #8 1000

    #b|#8  : 
        #b 1011





