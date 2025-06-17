# Form 2 : Bottom-Up(grid) / start-->end approach
  - _ _ _ ending at index i.
  - Relation is usually , dp(i) = if(_ _ _) x + dp(i-1)
  - This is called start --> end appraoch because first dp(0) --> dp(1).... --> dp(n-1) is called in stack.
  - while in form 1 , end --> start order is there, dp(n-1) --> dp(n-2).... --> dp(0)
