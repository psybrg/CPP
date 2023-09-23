def gcd(a,b):
    if(a==0):
        return b
    if(b==0):
        return a
    if(a>b):
        return gcd(a%b,b)
    else:
        return gcd(a,b%a)

t=int(input())
for i in range(t):
    ar = list(map(int,raw_input().split()))
    x  = ar[0]*gcd(ar[1],ar[2])/(ar[1]*ar[2])
    res=ar[0]/ar[1]+ar[0]/ar[2]-2*x
    print(res)
    if(res<ar[3]):
        print("Lose")
    else:
        print("Win")
