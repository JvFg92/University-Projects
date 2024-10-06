def euler_method(f, x0, y0, h, n):
    """

    Argumentos:
    f: função que define a equação diferencial dy/dx = f(x, y)
    x0: valor inicial de x
    y0: valor inicial de y, correspondente a f(x0)
    h: tamanho do passo
    n: número de iterações

    Retorna:
    Uma lista de tuplas (x, y) que representam os pontos aproximados da solução.
    """
    points = [(x0, y0)]
    x = x0
    y = y0
    for _ in range(1, n + 1):
        y += h * f(x, y)
        x += h
        points.append((x, y))
    return points

# Exemplo de uma equação diferencial 
def f(x, y):
    return y**2

# Condições iniciais
x0 = 0
y0 = 1
# Tamanho do passo
h = 0.1
# Número de iterações
n = 5

# Chamada da função
solution = euler_method(f, x0, y0, h, n)

count=0
print("Solução aproximada utilizando o método de Euler:")
for point in solution:
    count+=1
    print(f"x point = {point[0]}, y = {point[1]}", count)


