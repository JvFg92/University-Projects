def f(x): return x**4-27

def df(x): return 4*(x**3)

def df_2(x): return 12*(x**2)


def halley(f,df,df_2,x,tol=10e-15):
    '''
        Método para encontrar raizes da equação:

        f = Função das quais se buscam raizes;
        df = Derivada da função;
        df_2 = Derivada secunária da função;
        x = Aproximação inicial da raiz
        tol = Número buscado, mais próximo da raiz verdadeira 

        Retorna a raiz.
    '''
  
    #Chute inicial é a raiz:
    if(f(x)==0):return x
    
    #Testa se o dividendo é diferente de 0:
    if((2*((df(x))**2))-(f(x)*df_2(x)))==0: return None

    #Calcula o método em si:
    y=x-((2*f(x)*df(x))/((2*((df(x))**2))-(f(x)*df_2(x))))

    #Condição de termino da recursividade e retorno da raiz:
    if abs(f(y))<tol: return y

    #Continuidade do método até encontrar a raiz:
    else: return halley(f,df,df_2,y)


print("Halley = ",halley(f,df,df_2,1))

'''
#Calculo por looping:

    #Looping de calculo do método:
    while(abs(f(x))>tol):

        #Verifica divisão por 0:
        if((2*((df(x))**2))-(f(x)*df_2(x)))==0:break

        #Calcula o método em si:
        x-=((2*f(x)*df(x))/((2*((df(x))**2))-(f(x)*df_2(x))))
        
    return x

'''