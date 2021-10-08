# from pprint import pprint

# x = 90 # int
# print(x)

# x = "Hello world" # str
# print(x)

# x = [1,2,3,4,5] # List
# print(x)

# L = [1,2,3,4,5, "hello bananas", [88,77,66],(3,4,5), {"name": "jojo", "age": "20"}] # List
# L[1] = 99
# L.append(103)

# D = {           # Dictionary
#     "first" : "Joe",
#     "last"  : "smith",
#     "age"   : 20,
#     "grades" : [34,99,22,100]
# }

# print(D)
# D["first"] = "Samantha"

# T = (3,5) # Tuple

# x,y = T
# print(f"x:{x} y:{y}")

# #=======================================#
# '''
# Block comment (doc string)
# '''
# i = L.index("hello bananas")
# L[i] = "Fortnite: Battle Royale"

# L.extend([6,7,8,9,0]) # Adds each as item
# L.append([6,7,8,9,0]) # appends whole list as an item

# for item in L:
#     print(item, end='\n')

# print(D.items())
# for k,v in D.items():
#     print(f"key: {k} : val : {v}")

# T1 = (3,4,5,3,4,5,7,3,4,5,2,3,4,5)
# print(set(T1))

with open("moby") as f:
    data = f.readlines()

words = {}

for line in data:
    line = data.rstrip().split()
    
    for w in line:
        if not w in words:
            words[w] = 0

        words[w]+= 1
max = 0
maxword = ""

for w,v in words.item():
    if v > mmax:
        mmax = v
        maxword = w
print(f"{maxword} occurs {mmax} times")