calendario=['0','janeiro','fevereiro','marco','abril','maio','junho','julho','agosto','setembro','outubro','novembro','dezembro']

sla=input("dd/mm/aaaa ")
dia=int(sla[0:2])
mes=int(sla[3:5])
ano=int(sla[6:10])

mes_nome=calendario[mes]
print(mes_nome)