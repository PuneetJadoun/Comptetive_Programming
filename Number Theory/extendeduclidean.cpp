gcd(a, b):
    if b == 0:
        x = 1, y = 0
    else:
        gcd(b, a % b)
        x = y1
        y = x1 - (a / b) * y1
