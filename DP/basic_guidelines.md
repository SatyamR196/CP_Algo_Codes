## DP Theory
- DP : recursion + caching(i.e. saving answer for a  state, to use it inside other fxn).
- DP fxn should be of non-void return.
- Anything that changes should be the part of parameter of dp fxn not global. Cache vector can be global.
- What to return in a dp fxn is usually what is asked in the question, but generalised for any state.
- How to decide state ? Identify the DP form will give good idea about level and restriction in the question are also part of states.
## There are 3 key features in a DP 
  - State (usually passed as parameters in dp() like level,cost.
  - Transition & it's cost : In LCCM framework, these are the choices available to us to generate answer
  - Base case : base case and transition are paired, for same problem different pairs of base case logic and transition logic exists
    - Ex : In the jump 2 problem where we are required to find the number of jumps to reach n-1 step :-
    - Base case => if(level == n-1 ) return moves ;  then transition ==> ans = min(ans, dp(level+i,moves+1,nums)) ;  --> 2D cacheing req
    - Base case => if(level == n-1 ) return 0 ;      then transition ==> ans = min(ans, 1 + dp(level+i,nums)) ; --> 1D caching will work

## 5 steps to solve any DP problem
  - Decide the form
  - Decide the state and what dp() will do/ return
  - Decide the transition
  - Once state and transition are decided, check the time complexity as O(# of states * transition cost)
  - If TC, is well within the limits, the code the solution.
