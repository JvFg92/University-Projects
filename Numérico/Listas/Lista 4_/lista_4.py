import lista_4_modulo as lm
from lista_4_ex3 import e_par


#Exercicio 1:
def escondida_par(x):
    if (lm.funcao_escondida(x)%2)==1: return False
    elif(lm.funcao_escondida(x)%2)==0:return True 


#Exercicio 2:
def norma_op(A):
    Matriz = np.dot(A.T, A)
    autovalores, _ = np.linalg.eig(Matriz) 
    norma = np.sqrt(max(autovalores)) 
    return norma
