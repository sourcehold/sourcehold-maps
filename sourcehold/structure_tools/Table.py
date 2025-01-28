class Table(object):

    def __init__(self, rownames, colnames):
        self.rownames = rownames
        self.colnames = colnames
        self.matrix = []
        for row in self.rownames:
            self.matrix.append([None] * len(self.colnames))

    def set(self, row, col, value):
        if row.__class__ == str:
            row = self.rownames.index(row)
        if col.__class__ == str:
            col = self.colnames.index(col)
        self.matrix[row][col] = value

    def get(self, row, col):
        if row.__class__ == str:
            row = self.rownames.index(row)
        if col.__class__ == str:
            col = self.colnames.index(col)
        return self.matrix[row][col]

    def __repr__(self):
        length_r = max([len(v) for v in self.rownames])
        length_c = max([len(v) for v in self.colnames])
        length = length_r if length_r > length_c else length_c
        length += 4
        # print(length)
        field = "{{:{}s}}".format(length)
        # print(field)
        string = field.format(" ") + (field * len(self.colnames)).format(*[str(v) for v in self.colnames]) + "\n"
        for row in range(len(self.matrix)):
            string += field.format(self.rownames[row])
            string += (field * len(self.matrix[row])).format(*[str(v) if v != None else "" for v in self.matrix[row]])
            string += "\n"
        return string

    def as_array(self, rowname="rowname"):
        header = [rowname] + self.colnames
        values = [[self.rownames[i]] + self.matrix[i] for i in range(len(self.matrix))]
        return [header] + values

    def as_dict(self):
        d = {}
        for r in self.rownames:
            for c in self.colnames:
                if not r in d:
                    d[r] = {}
                v = self.get(r, c)
                if v != None:
                    d[r][c] = v
        return d

    def as_dict_array(self):
        a = []
        for r in self.rownames:
            for c in self.colnames:
                v = self.get(r, c)
                if v == None:
                    continue
                a.append({"a": r, "b": c, "value": v})
        return a