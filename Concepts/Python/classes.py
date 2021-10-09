# Testing out classes in python


class Point:
    """
    This class holds a coordinate pair, (x,y)
    """

    def __init__(self, x=0, y=0) -> None:
        if isinstance(x, tuple):
            self.x = x[0]
            self.y = x[1]
        elif isinstance(x, list):
            self.x = x[0]
            self.y = x[1]
        else:
            self.x = x
            self.y = y

    def __str__(self) -> str:
        return f"x:{self.x} y:{self.y}"

    def __list__(self) -> list:
        x = []
        x.append(self.x)
        x.append(self.y)
        return x

if __name__=='__main__':
    a: list = [1,2]
    
    t: tuple = (3,4)

    p: Point = Point(t)
    print(p)

    a = a +  p.__list__()
    print(a)
    
