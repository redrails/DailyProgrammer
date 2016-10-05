def reverseFactorial(n):
    i=2
    while(True):
        if n/i == 1:
            return n
        elif n%i == 0:
            n = n/i
            i+=1
            continue
        else:
            return None

print reverseFactorial(3628800)
print reverseFactorial(479001600)
print reverseFactorial(6)
print reverseFactorial(18)
