#Resolução da Lista de Exercícios 5
#Voce pode alterar este arquivo como quiser (dentro dos parâmetros de avaliacao,
#obviamente).

import numpy as np


#Exercício 1:
def newton (f , f_p , x):return x-(f(x)/f_p(x))


#Exercício 2:

def lista_5_ex_2 (p):
    t=0
    for i in range(1000):

        if abs(75*np.power(np.e,((-1.5)*t)) + 20*np.power(np.e,(-0.075*t))-(p*95))<10e-16:return t
        if(-112.5*np.e**(-1.5*t)-1.5*np.e**(-0.075*t))==0:break

        t-=(75*np.power(np.e,((-1.5)*t)) + 20*np.power(np.e,(-0.075*t))-(p*95))/(-112.5*np.e**(-1.5*t)-1.5*np.e**(-0.075*t))

    return t


#Exercicío 3:

def f(m, c, v, t):return (9.81*m/c) * (1 - np.e**(-t*c/m)) - v

def df(m,c,t):
    exp = -c*t/m
    return (9.81/c)* (1 - np.e**exp - (c*t*np.e**exp)/m)

def lista_5_ex_3 (c,v,t):
    if c == 0: return None
    m = 50
    aux=100
    while abs(m-aux)>2**-30:
        aux=m
        m-=f(m,c,v,t)/df(m,c,t)
    return m
    

#Exercicio 4:

temp_crit= 532.8 
pres_crit= 3785.0 

def a_ex4(temp_crit, pres_crit):
    return 0.427*(0.268324)*temp_crit**(2.5)/pres_crit

def b_ex4(temp_crit, pres_crit):
    return 0.0866*(0.518)*temp_crit/pres_crit

def f_ex4(a,b,x):
    return (0.518*233.15)/(x-b)-(a)/(x*(x+b)*((233.15)**(1/2)))-65000

def df_ex4(a,b,x):
    return (a*(0.0654911*b+0.130982*x))/(x**(2)*(b+x)**(2))-120.772/((b-x)**(2))


def lista_5_ex_4(temp_crit, pres_crit):
    a=a_ex4(temp_crit, pres_crit)
    b=b_ex4(temp_crit, pres_crit)
    x=b+0.000001
    y=x
    x=x-f_ex4(a,b,x)/df_ex4(a,b,x)
    newt=abs((y-x)/2)
    while newt>2**(-50):
        y=x
        x=x-f_ex4(a,b,x)/df_ex4(a,b,x)
        newt=abs((y-x)/2)
    return 3*(1/x)


#Exercício 5:

def fjuros(x,valor,tempo,prestacao):
    return (1-(1+x)**(-tempo))/x*prestacao-valor

def calculadora_do_cidadao(valor=None, juros=None, tempo=None, prestacao=None):
    '''
    q é o valor financiado (que o consumidor pegou emprestado).
    j é a taxa de juros mensal.
    n é o tempo em meses no qual o financiamento é pago.
    p é o o valor fixo da prestação.
    '''
    
    if valor is None:
        return (((1-((1+juros)**-tempo))/(juros))*prestacao)
    
    if juros==None:
        a=0.00001
        b=1000.0
        fa=fjuros(a,valor,tempo,prestacao)
        fb=fjuros(b,valor,tempo,prestacao)
        c=(a+b)/2
        fc=fjuros(c,valor,tempo,prestacao)
        if fa*fb>0:
            return 0
        while abs(fc)>2e-10:
            if fa*fc<0:
                b=c
                c=(a+c)/2
            if fc*fb<0:
                a=c
                c=(c+b)/2
            fa=fjuros(a,valor,tempo,prestacao)
            fb=fjuros(b,valor,tempo,prestacao)
            fc=fjuros(c,valor,tempo,prestacao)
        return c

    
    if tempo is None: return -(np.log(1-((juros*valor)/prestacao))/np.log(1+juros))
    
    if prestacao is None:return (valor/((1-((1+juros)**-tempo))/(juros)))


#Exercício 6:

t=2887508349

def lista_5_ex_6_lap(t):
    n = 1
    l = 0
    while l <= t*10**8:
        l = (n + 1)*l + 3*n + 2
        n += 1
    return n - 2

def lista_5_ex_6_esc(t):
    n = 1
    while (1/6)*(n-1)*(4*n**2+n+6) <= t*10**8:
        n += 1
    return n - 1


print (lista_5_ex_6_lap(t))
print (lista_5_ex_6_esc(t))




'''valor=6913999
tempo= 208
prestacao=154123.025155536
print("output Esperado:0.02205283834142673")
print("Resultado:",calculadora_do_cidadao(valor,None,tempo,prestacao))

v=612225
ju=0.050122595754803274
p=30686.38975877517

print("Tempo esperado: 262")
print("Resultado:",calculadora_do_cidadao(v,ju,None,p))'''

