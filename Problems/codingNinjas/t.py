def validParenthesis(n: int) -> int:
    ans = []

    s = []

    def solve(idx,cont = 0):
        if cont<0:return 
        if idx == 2*n :
            if cont == 0:
                ans.append("".join(s))
            return 

        s.append('(')
        solve(idx+1,cont+1)
        s.pop()
        s.append(')')
        solve(idx+1,cont-1)
        s.pop()

        return 

    solve(0)
    print(ans)
    return ans

n = int(input())

ans = validParenthesis(n)