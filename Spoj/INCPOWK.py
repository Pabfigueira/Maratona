import sys

if __name__ == "__main__":
    
    s = input();

    for i in range(1,s+1):
        k, n = map(int, sys.stdin.readline().split())
        binary = "{0:b}".format(n)
        result = 0
        j = len(binary) - 1
        prox = 0

        while j >=0 :
            if binary[j]=='1':
                result += k**prox
            prox+=1
            j-=1
        print result
