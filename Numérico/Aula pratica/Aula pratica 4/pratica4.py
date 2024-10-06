import numpy as np

def medianas_linhas(A):
    m,n = np.shape(A)
    vet=np.median(A, axis = 1)
    return np.reshape(vet,(m,1))
    



    
matriz = np.array([[ 0,-7,5,9,6],
                   [ 9,-5,6,1,-4], 
                  ])

print(medianas_linhas(matriz))
         
