def ispowerof2(n:int):
    if (n <= 0):
        return False
    return (n & (n - 1)) == 0

print(ispowerof2(8))   # Output: True
print(ispowerof2(10))  # Output: False