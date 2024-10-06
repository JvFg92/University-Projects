import numpy as np
from numpy.linalg import matrix_power 


def solve_matriz(A,n,b):
    contador=int(0)
    matrix_power(A, n)

    L,U,contador=crout_dolittle(A)
    y,cont=solve_triangular_inferior(L,b)
    x,cont_2=solve_triangular_superior(U,y)

    contador=cont+cont_2

    return x , contador


def crout_dolittle(A):
    contador=int(0)
    ''' Decomposição LU de A pelo algoritmo de Crout'''

    m,n = np.shape(A)

    L = np.zeros((n,n))
    U = np.zeros((n,n))
    

    L[0,0] = 1          # Escolha de Dolittle
    U[0,0] = A[0,0]

    for j in range(1,n):
        U[0,j] = A[0,j]/L[0,0]      # Determina a primeira linha de U
        L[j,0] = A[j,0]/U[0,0]      # Determina a primeira coluna de L
        contador+=2
    for i in range(1,n):
        L[i,i]=1        # Escolha de Dolittle
        U[i,i] = A[i,i] - sum([L[i,k]*U[k,i] for k in range(i)])
        contador+=2*i+1
 
        for j in range(i+1,n):
            U[i,j] = (A[i,j] - sum([L[i,k]*U[k,j] for k in range(i)]))/L[i,i]       # Determina a i-ésima linha de U
            L[j,i] = (A[j][i] - sum([L[j,k]*U[k,i] for k in range(i)]))/U[i,i]      # Determina a i-ésima coluna de L
            contador+=2*i+4
            
            
    return L , U , contador


def solve_triangular_superior(U, b):
    contador=int(0)
    """Resolve um sistema triangular superior do tipo Ux = b.

    Parametros obrigatorios
    ----------
    U : Array-like de dimensao 2
        Matriz quadrada triangular superior inversível

    b : Array-like de dimensão 1
        Vetor independente

    Saída
    ----------
    x : Array-like de dimensão 1
        Solução do sistema Ux = b"""
    
    n = U.shape[0]          # Ordem das matrizes
    
    # Cópias usuais para evitar problemas
    x = b.copy().reshape(n)

    # Vai linha-a-linha, de baixo para cima, escalonando a matriz utilizando o pivô na diagonal
                        
    for i in range(n-1,-1,-1):
        x[i] /= U[i,i]     # Normaliza a i-ésima linha

        contador+=1 #Apenas uma operação +
        for j in range(i-1,-1,-1):
            x[j] -= U[j,i]*x[i]     # Pivoteia a i-ésima coluna, utilizando a entrada diagonal como pivô

            contador+=2 #Duas operações - e *

    return x, contador


def solve_triangular_inferior(L, b):
    contador=int(0)
    """Resolve um sistema triangular inferior do tipo Lx = b.

    Parametros obrigatorios
    ----------
    L : Array-like de dimensao 2
        Matriz quadrada triangular superior inversível

    b : Array-like de dimensão 1
        Vetor independente

    Saída
    ----------
    x : Array-like de dimensão 1
        Solução do sistema Lx = b"""
    
    n = L.shape[0]          # Ordem das matrizes
    
    # Cópias usuais para evitar problemas
    y = b.copy().reshape(n)

    # Vai linha-a-linha, de cima para baixo, escalonando a matriz utilizando o pivô na diagonal
                        
    for i in range(n):
        y[i] /= L[i,i]     # Normaliza a i-ésima linha
        contador+=1 #Apenas uma operação +

        for j in range(i+1,n):
            y[j] -= L[j,i]*y[i]     # Pivoteia a i-ésima coluna, utilizando a entrada diagonal como pivô

            contador+=2 #Duas operações - e *

    return y, contador