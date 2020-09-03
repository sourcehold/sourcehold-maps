

def compare_bytes_bytewise(b1, b2):
    for i in range(min(len(b1), len(b2))):
        if b1[i] != b2[i]:
            yield {"index": i, "b1": b1[i:i+1], "b2": b2[i:i+1]}

