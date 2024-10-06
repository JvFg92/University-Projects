#Exercicio 1:
def Celsius_para_Farenheit(T):
    T=((T*1.8)+32)
    return T

#Exercicio 2:
def minusculo(c):
    if 96 < ord(c) < 123:
        return True
    else:
        return False

#Exercicio 3:
def frase_maiusculo(fr):
    if len(fr) == 0:
        return ''
    x=fr[0]
    if 96 < ord(x) < 123: x=chr(ord(x)-32)
    return x + frase_maiusculo(fr[1:])

#Exercicio 4:
def Fib_gen_in(a,b,n):
    if n<0: return -1
    if n==0: return a
    if n==1: return b
        
    return Fib_gen_in(b,a+b,n-1)

#Exercicio 5:
def cifra_cesar(n,fr):
    if len(fr)==0: return ''
    c=fr[0]
    if 64 < ord(c) < 91:
         c=chr((ord(c)-ord('A')+n)%26+ord('A'))    #equacao de criptografia
       
    if 96 < ord(c) < 123:
         c=chr((ord(c)-ord('a')+n)%26+ord('a'))    
    return c+cifra_cesar(n,fr[1:])
    #letra=letra+(n-1)  