def media(lista):
    if len(lista)==0: return 0
    return sum(lista)/len(lista)

def variancia(lista):
    med=media(lista)
    return sum((x-med)**2 for x in lista)/(len(lista)-1)

def desvio_padrao(lista):
    return (variancia(lista))**(1/2)

def variancia_sigma(lista):
    med=media(lista)
    return sum((x**2-med**2) for x in lista)/(len(lista))

def desvio_padrao_sigma(lista):
    return (variancia(lista))**(1/2)

def mediana(lista):
    lista.sort() 
    n = len(lista) 
    meio = n // 2  
    if n % 2 == 1: return lista[meio]
    else: return (lista[meio - 1] + lista[meio]) / 2
