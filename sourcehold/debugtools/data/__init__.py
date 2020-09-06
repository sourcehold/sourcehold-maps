

def compare(d1, d2):
    n = min(len(d1), len(d2))
    for i in range(n):
        if d1[i] != d2[i]:
            yield i, d1[i], d2[i]
