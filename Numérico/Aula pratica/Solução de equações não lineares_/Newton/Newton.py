def f(x): return x**4-27

def df(x): return 4*(x**3)


def newton(f,df,x,tol=10e-15):
    
    '''
    Método para encontrar raizes da equação:

    f = Função das quais se buscam raizes;
    df = Derivada da função;
    x = Aproximação inicial da raiz
    tol = Número buscado, mais próximo da raiz verdadeira 

    Retorna a raiz.
    '''

    #Testa se a derivada calculada é diferente de 0:
    if(df(x)==0):return None

    #Testa se a primeira aproximação é raiz:
    if(f(x)==0):return x

    #Operacionaliza o método em si:
    y=x-(f(x)/df(x))

    #Condição de termino da recursividade e retorno da raiz:
    if abs(f(y))<tol:return y
    
    #Continuidade do método até encontrar a raiz:
    else: return newton(f,df,y)

print("Newton = ",newton(f,df,1))


