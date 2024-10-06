import numpy as np
import matplotlib.pyplot as plt



    #Entre '' está o lugar onde o arquivo.npy está salvo:

imagem=np.load('/home/jvfg/Documents/Vs/Python/Numérico/Trabalhos/Trabalho1/ufsc_j.npy')
plt.imshow(imagem)
plt.show()
    


    #Entre '' está o lugar onde o arquivo.npy está salvo:

array=np.load('/home/jvfg/Documents/Vs/Python/Numérico/Trabalhos/Trabalho1/ufsc_j.npy')
imagem_16=array.astype(np.uint16)
np.save("ufsc_16bits.npy",imagem_16)

vet=np.load('/home/jvfg/Documents/Vs/ufsc_16bits.npy')
plt.imshow(vet)
plt.show()