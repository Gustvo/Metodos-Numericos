# Métodos numéricos

## Zero de funções

f(x) = x³ - 9x + 3  
ε = 0.001  

|Nome|x->f(x)=0|Iterações|Tempo*
---|---|---|---
Bissecção:|0.3369141|10|1472 µs
Posição Falsa:|0.3376350|3|940 µs
Newton Raphson:|0.3376068|2|350 µs
Secante:|0.3376346|3|635 µs

## Zero de Polinômios

p(x) = x³ - 9x + 3  
ε = 0.001  
x0 = 1

|Nome|x->f(x)=0|Iterações|Tempo*
---|---|---|---
Birge-Vieta:|0.3376031|3|1334 µs

*Tempo que a função demora para encontrar o resultado 10000 vezes
