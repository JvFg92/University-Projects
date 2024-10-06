'''

Resolução de sistema triangular superior seguida de sistema triangular inferior

'''

import numpy as np
import matplotlib.pyplot as plt
from time import time
from tqdm import tqdm
import escalonamento as esc


#Dicionários para o armazenamento dos dados:
tempo_sup={}
type(tempo_sup)

tempo_inf={}
type(tempo_inf)

dic_mat_sup={}
type(dic_mat_sup)

dic_mat_inf={}
type(dic_mat_sup)

dic_vet={}
type(dic_vet)

#Auxiliares das chaves dos dicionários:
sup=int(0)
inf=int(0)
vet=int(0)
tsup=int(0)
tinf=int(0)

#função a ser executada:
def solve_triangular_superior(U, b):
    contador=int(0)
    
    # Ordem das matrizes
    n = U.shape[0]  
    
    # Cópias usuais para evitar problemas
    x = b.copy().reshape(n)

    # Vai linha-a-linha, de baixo para cima, escalonando a matriz utilizando o pivô na diagonal   
    for i in range(n-1,-1,-1):
        # Normaliza a i-ésima linha
        x[i] /= U[i,i]    
        contador+=1 

        for j in range(i-1,-1,-1):
            # Pivoteia a i-ésima coluna, utilizando a entrada diagonal como pivô
            x[j] -= U[j,i]*x[i]     

            contador+=2 #Duas operações - e *

    return x, contador

def solve_triangular_inferior(L, b):
    contador=int(0)
    
    # Ordem das matrizes
    n = L.shape[0]          
    
    # Cópias usuais para evitar problemas
    x = b.copy().reshape(n)

    # Vai linha-a-linha, de cima para baixo, escalonando a matriz utilizando o pivô na diagonal
                        
    for i in range(n):
        # Normaliza a i-ésima linha
        x[i] /= L[i,i]    
        contador+=1 

        for j in range(i+1,n):
            # Pivoteia a i-ésima coluna, utilizando a entrada diagonal como pivô
            x[j] -= L[j,i]*x[i]    

            contador+=2

    return x, contador


#Cria matrizes quadradas de ordem 2-12 aleatórias e vetores de mesma ordem para teste:
#Define ordem máxima da matriz quadrada
m=12
for i in range (2,m):

    ''' MATRIZ TRIANGULAR SUPERIOR '''
    #Cria as variáveis aleatórias de teste para triangulação superior
    U = 20*np.random.rand(i,i)-10
    for k in range(i):
        for j in range(k):
            U[k,j]=0.0       


    dic_mat_sup[sup]=U
    sup+=1

    #Finaliza a criação das variáveis de teste para triangulação superior


    ''' MATRIZ TRIANGULAR INFERIOR'''
    #Cria as variáveis aleatórias de teste para triangulação inferior
    L = 20*np.random.rand(i,i)-10
    for k in range(i):
        for j in range(k):
            L[j,k]=0.0       
    dic_vet[vet] = 20*np.random.rand(i)-10
    vet+=1

    dic_mat_inf[inf]=L
    inf+=1
    #Finaliza a criação das variáveis de teste para triangulação inferior

'''
print(dic_vet)
print("#######################################################")
print(dic_mat_sup)
print("#######################################################")
print(dic_mat_inf)
'''
#Número de Iterações:
its=int(0)#Superior
iti=int(0)#Inferior

#Número de componentes do dicionário
n=(m-2)

#Numéro de repetições para medição do tempo
z=10
#Testes n  da função:
for aux in tqdm(range (n)):

    i=0
    j=0

    inicio=time()
    #Teste Matriz superior:
    for i in range(z):
        a,b = solve_triangular_superior(dic_mat_sup[aux],dic_vet[aux]) # Solução pretendida do sistema Ux = b
        if i==(z-1):its+=b
    
    fim=time()
    tempo_sup[tsup]=((fim-inicio)/z)
    tsup+=1
    inicio=0
    fim=0

    inicio=time()
    #Teste Matriz inferior:
    for  j in range(z):
        a,b = solve_triangular_inferior(dic_mat_inf[aux],dic_vet[aux]) # Solução pretendida do sistema Ux = b
        if j==(z-1):iti+=b
   
    fim=time()
    tempo_inf[tinf]=((fim-inicio)/z)
    tinf+=1
    inicio=0
    fim=0

print("\nO número de iterações total para matriz superior é: ",its)
print("\nO número de iterações total para matriz inferior é: ",iti)

#print(tempo_sup,"\n")
#print(tempo_inf)



def regressao(dic):
    #Converte o dicionário em vetores
    x = np.array(list(dic.keys()))
    y = np.array(list(dic.values()))

    # Ajuste de uma curva quadrática (ax^2 + bx + c) aos pontos
    A = np.vstack([x**2, x, np.ones(len(x))]).T
    a, b, c = np.linalg.lstsq(A, y, rcond=None)[0]

    return a, b, c

def f_quadrada(a,b,c,x): return ((a*(x**2))+(b*x)+c)

dic = tempo_sup

a, b, c = regressao(dic)



def reg(dicionario):

    x = np.array(list(dic.keys()))
    y = np.array(list(dic.values()))
    

    m = dados.shape[0]

    print(f"Tamanho do conjunto de dados: {m}")

    # Define a matriz de coeficientes
    A = np.zeros((m,3))
    for i in range(180):
        A[i,0] = 1
        A[i,1] = dados[i,0]
        A[i,2] = dados[i,0]**2

    # Define o vetor independente
    b = dados[:,1]

    # Aplica o método dos mínimos quadrados
    B = A.transpose()@A
    c = A.transpose()@b

    # Resolve o sistema B alpha = c
    M = np.concatenate((B,c.reshape((3,1))),axis = 1) #Matriz aumentada do sistema Bx=c
    alpha = esc.rref(M)[0][:,-1]

