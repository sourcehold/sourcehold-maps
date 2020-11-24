
import struct

def display_section(process, section, cat_colouring=False):
    import matplotlib.pyplot as plt
    data = process.read_section(section)
    fmt = ["", "B", "H",  "", "I"][len(data) // 80400]

    from sourcehold.world import create_matrix, create_binary_matrix
    matrix = create_matrix()
    i = create_binary_matrix()

    matrix[i] = struct.unpack(f"<80400{fmt}", data)

    if cat_colouring:
        unique = sorted(list(set(matrix[i])))
        matrix[i] = [unique.index(v) for v in matrix[i]]

    plt.imshow(matrix, cmap="rainbow")

    if cat_colouring:
        return unique
    return None
