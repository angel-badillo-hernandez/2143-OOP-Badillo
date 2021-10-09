# lists
# dict
# tuples
# for loops


def sum(a, b=0):
    if isinstance(a, list):
        total = 0
        for x in a:
            total += x
        return total
    elif isinstance(a, tuple):
        total = 0
        for x in a:
            total += x
        return total

    return a+b


class Point:
    '''
    This is a commment block for Point
    '''

    def __init__(self, x=0, y=None):
        if isinstance(x, tuple):
            self.x = x[0]
            self.y = x[1]
        elif isinstance(x, list):
            self.x = x[0]
            self.y = x[1]
        else:
            self.x = x
            self.y = y

    def print(self):
        print(f"x:{self.x} y:{self.y}")

    def __str__(self):
        return f"x:{self.x} y:{self.y}"

    def __add__(self, other):
        if isinstance(other, tuple):
            x = other[0]
            y = other[1]
        elif isinstance(other, list):
            x = other[0]
            y = other[1]
        else:
            x = other.x
            y = other.y

        return Point(self.x+x, self.y+y)


if __name__ == '__main__':
    print(sum([5, 7, 3, 9, 100000000000000]))

    p1 = Point(2, 3)

    print(p1)

    p1.print()

    print(p1.__doc__)

    p2 = Point(6, 8)

    print(p2)

    p3 = p1 + p2

    print(p3)

    p3 = p3 + (3, 4)
    print(p3)

    p3 = [6, 7] + p3

    print(p3)
