import lista_3 as lst
import numpy as np
from random import *


def compare(nro_1, nro_2):
    return abs(nro_1 - nro_2)


nro = random() * np.pi
nro_2 = random() + randint(0, 1)

print("######################################")
print("########## teste lista 3 #############")
print("######################################")

print("\n###### teste aproximacao seno ######")

print(f'Input: {nro}')
print(f'Expected: {np.sin(nro)} ')
print(f'Recieved: {lst.sin(nro)}')
print(f'Taxa de erro: {"dentro do limite" if compare(np.sin(nro), lst.sin(nro)) < 9.314e-10 else "fora do limite"}')

print("\n#### teste aproximacao cosseno ####")

print("Input: ")
print(f'Expected: {np.cos(nro)} ')
print(f'Recieved: {lst.cos(nro)}')
print(f'Taxa de erro: {"Dentro do limite" if compare(np.cos(nro), lst.cos(nro)) < 9.312e-10 else "Fora do limite"}')

print("\n## teste aproximacao raiz inversa ##")

print(f'Input: {nro_2}')
print(f'Expected: {1 / np.sqrt(nro_2)} ')
print(f'Recieved: {lst.invsqrt(nro_2)}')
print(f'Taxa de erro: {"Dentro do limite" if compare(np.cos(nro), lst.cos(nro)) < 9.312e-11 else "Fora do limite"}')
