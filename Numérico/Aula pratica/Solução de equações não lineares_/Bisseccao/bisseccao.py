
def f(x): return (x**4-27)



def bissecçao(f,a,b,tolerancia=10e-15):
    
    '''
    Método para encontrar raizes da equação:

    f = função recebida;
    a = menor número do intervalo;
    b = maior número do intervalo;
    tolerancia = número mais próximo do buscado.

    Retorna a raiz.
    '''
    
    #testa se o valor da do produto da função calculada em a e b é maior que 0
    #portanto se o intervalo definido da bissecao esta dentro da imagem da função:
    if (f(a)*f(b))>0: return None

    #testa se parte do intervalo é a raiz
    if(f(a)==0): return a
    if(f(b)==0): return b

    #Calcula a media do intervalo:
    i=(a+b)/2

    #Define condição de retorno do resultado:
    if f(i)==0 or abs(f(i))<tolerancia:return i

    #Calcula a bissecao para o intervalo menor que a média:
    elif (f(a)*f(i))<0: return bissecçao(f,a,i)

    #Calcula a bissecao para o intervalo maior que a média:
    elif (f(b)*f(i))<0: return bissecçao(f,b,i)

print("Bissecçao = ",bissecçao(f,0,3,10e-15))