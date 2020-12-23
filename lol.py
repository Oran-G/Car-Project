

def solution(a, b):

    #init a list of bools inited to false at the len of the solution set of [-1000, 1000]
    l = [False] * 2000

    #turn indexes where there is a number of that index in the smaller array to true
    for i in (a if len(a) < len(b) else b):
        l[i + 1000] = True

    #check if number in the second list is in the first list in a simpler way
    for i in (b if len(a) < len(b) else a):
        if l[i + 1000] != True:
            return i

 