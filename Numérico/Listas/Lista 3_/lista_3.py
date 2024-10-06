#LISTA 3:

#Aux:
def pot(x,y):
    resultado = 1
    for i in range(y):
        resultado = resultado * x
    return resultado


def fat(x):
    f=1
    if x == 0 or x == 1: return 1
    while(x>1):
        f=f*x
        x=x-1
    return f


def int(x):
    if x==0:
        return 1
    if x>1:
        if (x/2)>=1:
            return 1+int(x/2)
        else:
            return 0
    if 0<x<1:
        if (x*2)<1:
            return -1+int(x*2)
        else:
            return -1


#====================================

#Exercicio 1:
def sin(x): 
    n=0
    sen=0
    
    while(n<20):
        sen=sen+((pot(-1,n))*pot(x,((2*n)+1))/fat((2*n)+1))
        n+=1
    return sen


def cos(x): 
    n=0
    cos=0
    
    while(n<20):
        cos=cos+((pot(-1,n))*pot(x,((2*n)))/fat((2*n)))
        n+=1
    return cos


#====================================

#Exercicio 2:
def invsqrt(x):
    if x<=1.5:
        n=0
        erro=1
        inv=0
        while abs(erro)> 9.314e-11:
            erro=pot(-1,n) * fat(2*n) * pot(x-1,n) / (pot(fat(n),2) * pot(4,n))
            inv=inv+erro
            n+=1
        return inv
    else: return invsqrt(x/4) * 0.5


#====================================

#Exercicio 3:
def reversa(L):
    A=L[::-1]

    return A


def reverter(L):
    L[:]=reversa(L)
    return L


#====================================

#Execicio 4:
def ordena(L):
    x=len(L)
    a=L[:]
    while x>0:
        i=0
        while i<(x-1):
            if a[i]>a[i+1]: 
                aux=a[i]
                a[i]=a[i+1]
                a[i+1]=aux
            i+=1
        x-=1
    return a


#====================================

#Exercicio 5:
def logaritmo_base2(x) -> float:
    a=int(x)
    z=1.0
    while x<1:           
        x*=2             
    while x>=2:                 
        x/=2   
    while z>=9.314e-11:
        x*=x
        z/=2
        if x>=2:
            x/=2
            a+=z
    return a


#====================================

#Exercicio 6:
def Collatz(x0):
    i=0
    while x0 >1:
        i+=1
        if (x0%2)==1: x0=((x0*3)+1)
        elif(x0%2)==0: x0=(x0/2)
    return i



x=1.75535723903507
print("oi")
#print(logaritmo_base2(x))

import numpy as np


print(logaritmo_base2(x))


print(np.log2(x))

    

